inputSize = net.Layers(1).InputSize;
augimdsTrain = augmentedImageDatastore(inputSize,training_data, 'ColorPreprocessing','gray2rgb');
augimdsTest  = augmentedImageDatastore(inputSize,test_data, 'ColorPreprocessing','gray2rgb');

classes = categories(test_data.Labels);

%YTest = classify(net,augimdsTest);
accuracyOfTrainedNet = mean(YTest == test_data.Labels)*100

% Convertimos la red en un objeto dlnetwork
layerG = layerGraph(net);
layerG = removeLayers(layerG,layerG.OutputNames);
net = dlnetwork(layerG);


maxPruningIterations = 5;
maxToPrune = 10;

learnRate = 1e-2;
momentum = 0.9;
miniBatchSize = 64;
numMinibatchUpdates  = 20;
validationFrequency = 1;

prunableNet = taylorPrunableNetwork(net);
maxPrunableFilters = prunableNet.NumPrunables;
%%

mbqTrain = minibatchqueue(augimdsTrain, ...
    MiniBatchSize = miniBatchSize, ...
    MiniBatchFcn = @preprocessMiniBatchTraining, ...
    OutputAsDlarray = [1 1], ...
    OutputEnvironment = ["auto","auto"], ...
    PartialMiniBatch = "return", ...
    MiniBatchFormat = ["SSCB",""]);
mbqTest = minibatchqueue(augimdsTest,...
    MiniBatchSize = miniBatchSize,...
    MiniBatchFcn = @preprocessMiniBatchTraining, ...
    OutputAsDlarray = [1 1], ...
    OutputEnvironment = ["auto","auto"], ...
    PartialMiniBatch = "return", ...
    MiniBatchFormat = ["SSCB",""]);

figure("Position",[10,10,700,700])
tl = tiledlayout(3,1);
lossAx = nexttile;
lineLossFinetune = animatedline(Color=[0.85 0.325 0.098]);
ylim([0 inf])
xlabel("Fine-Tuning Iteration")
ylabel("Loss")
grid on
title("Mini-Batch Loss During Pruning")
xTickPos = [];

accuracyAx = nexttile;
lineAccuracyPruning = animatedline(Color=[0.098 0.325 0.85],LineWidth=2,Marker="o");
ylim([50 100])
xlabel("Pruning Iteration")
ylabel("Accuracy")
grid on
addpoints(lineAccuracyPruning,0,accuracyOfTrainedNet)
title("Validation Accuracy After Pruning")

numPrunablesAx = nexttile;
lineNumPrunables = animatedline(Color=[0.4660 0.6740 0.1880],LineWidth=2,Marker="^");
ylim([0 500])
xlabel("Pruning Iteration")
ylabel("Prunable Filters")
grid on
addpoints(lineNumPrunables,0,double(maxPrunableFilters))
title("Number of Prunable Convolution Filters After Pruning")

start = tic;
iteration = 0;

for pruningIteration = 1:maxPruningIterations

    % Shuffle data.
    shuffle(mbqTrain);

    % Reset the velocity parameter for the SGDM solver in every pruning
    % iteration.
    velocity = [];

    % Loop over mini-batches.
    fineTuningIteration = 0;
    while hasdata(mbqTrain)
        iteration = iteration + 1;
        fineTuningIteration = fineTuningIteration + 1;

        % Read mini-batch of data.
        [X, T] = next(mbqTrain);

        % Evaluate the pruning activations, gradients of the pruning
        % activations, model gradients, state, and loss using the dlfeval and
        % modelLossPruning functions.
        [loss,pruningActivations, pruningGradients, netGradients, state] = ...
            dlfeval(@modelLossPruning, prunableNet, X, T);

        % Update the network state.
        prunableNet.State = state;

        % Update the network parameters using the SGDM optimizer.
        [prunableNet, velocity] = sgdmupdate(prunableNet, netGradients, velocity, learnRate, momentum);

        % Compute first-order Taylor scores and accumulate the score across
        % previous mini-batches of data.
        prunableNet = updateScore(prunableNet, pruningActivations, pruningGradients);

        % Display the training progress.
        D = duration(0,0,toc(start),Format="hh:mm:ss");
        addpoints(lineLossFinetune, iteration, double(loss))
        title(tl,"Processing Pruning Iteration: " + pruningIteration + " of " + maxPruningIterations + ...
            ", Elapsed Time: " + string(D))
        % Synchronize the x-axis of the accuracy and numPrunables plots with the loss plot.
        xlim(accuracyAx,lossAx.XLim)
        xlim(numPrunablesAx,lossAx.XLim)
        drawnow

        % Stop the fine-tuning loop when numMinibatchUpdates is reached.
        if (fineTuningIteration > numMinibatchUpdates)
            break
        end
    end

    % Prune filters based on previously computed Taylor scores.
    prunableNet = updatePrunables(prunableNet, MaxToPrune = maxToPrune);

    % Show results on the validation data set in a subset of pruning iterations.
    isLastPruningIteration = pruningIteration == maxPruningIterations;
    if (mod(pruningIteration, validationFrequency) == 0 || isLastPruningIteration)
        accuracy = modelAccuracy(prunableNet, mbqTest, classes, augimdsTest.NumObservations);
        addpoints(lineAccuracyPruning, iteration, accuracy)
        addpoints(lineNumPrunables,iteration,double(prunableNet.NumPrunables))
    end

    % Set x-axis tick values at the end of each pruning iteration.
    xTickPos = [xTickPos, iteration]; %#ok<AGROW>
    xticks(lossAx,xTickPos)
    xticks(accuracyAx,[0,xTickPos])
    xticks(numPrunablesAx,[0,xTickPos])
    xticklabels(accuracyAx,["Unpruned",string(1:pruningIteration)])
    xticklabels(numPrunablesAx,["Unpruned",string(1:pruningIteration)])
    drawnow
end

prunedNet = dlnetwork(prunableNet);

