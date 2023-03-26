
augmentedTrainingData = transform(trainingData, @augmentData);
augimdsTrain = transform(augmentedTrainingData, @(data)preprocessData(data, networkInputSize));

augmentedTestData = transform(testData, @augmentData);
augimdsTest = transform(augmentedTestData, @(data)preprocessData(data, networkInputSize));

networkInputSize = [227 227 3];
trainingDataForEstimation = transform(trainingData, @(data)preprocessData(data, networkInputSize));
numAnchors = 6;
[anchorBoxes, meanIoU] = estimateAnchorBoxes(trainingDataForEstimation, numAnchors);

area = anchorBoxes(:, 1).*anchorBoxes(:, 2);
[~, idx] = sort(area, 'descend');
anchorBoxes = anchorBoxes(idx, :);
anchorBoxMasks = {[1:3] [4:6]};
classNames = {'bee_wasp'};

results = detect(detector,testData,MiniBatchSize=16);
[apTrainedNet, recallTrainedNet, precisionTrainedNet] = evaluateDetectionPrecision(results,testData);
accuracyTrainedNet = mean(apTrainedNet)*100

prunableNet = taylorPrunableNetwork(net)

maxPrunableFilters = prunableNet.NumPrunables;
%%
maxPruningIterations = 60;
maxToPrune = 64;
validationFrequency = 5;

numMinibatchUpdates = 50;
learnRate = 1e-5;
momentum = 0.9;
l2Regularization = 0.0005;
penaltyThreshold = 0.5;
miniBatchSize = 16;

mbq = minibatchqueue(augimdsTrain, 2,...
    MiniBatchSize=miniBatchSize,...
    MiniBatchFcn=@(images, boxes, labels) preprocessMiniBatch(images, boxes, labels, classNames), ...
    MiniBatchFormat=["SSCB", ""],...
    OutputCast=["", "double"]);

figure("Position",[10,10,700,700])
tl = tiledlayout(3,1);
lossAx = nexttile;
lineLossFinetune = animatedline(Color=[0.85 0.325 0.098]);
ylim([0 inf])
xlabel("Fine-Tuning Iteration")
ylabel("Loss")
grid on
title("Mini-Batch Loss during Pruning")
xTickPos = [];

accuracyAx = nexttile;
lineAccuracyPruning = animatedline(Color=[0.098 0.325 0.85]);
ylim([0 60])
xlabel("Pruning Iteration")
ylabel("Accuracy")
grid on
addpoints(lineAccuracyPruning, 0, accuracyTrainedNet)
title("Validation Accuracy After Pruning")

numPrunablesAx = nexttile;
lineNumPrunables = animatedline(Color=[0.4660 0.6470 0.1880]);
ylim([200 3600])
xlabel("Pruning Iteration")
ylabel("Prunable Filters")
grid on
addpoints(lineNumPrunables, 0, double(maxPrunableFilters))
title("Number of Prunable Convolution Filters After Pruning")

start = tic;
iteration = 0;

for pruningIteration = 1:maxPruningIterations

    % Shuffle the data in the minibatch.
    shuffle(mbq);

    % Reset the velocity parameter for the SGDM solver in every pruning
    % iteration.
    velocity = [];

    % Loop over mini-batches.
    fineTuningIteration = 0;
    while hasdata(mbq)
        iteration = iteration + 1;
        fineTuningIteration = fineTuningIteration + 1;

        % Read mini-batch of data.
        [X, T] = next(mbq);

        % Evaluate the pruning activations, gradients of the pruning
        % activations, model gradients, state, and loss using dlfeval and
        % modelLossPruning functions.
        [loss, pruningGradients, netGradients, pruningActivations, state] = ...
            dlfeval(@modelLossPruning, prunableNet, X, T, anchorBoxes, ...
            anchorBoxMasks, penaltyThreshold);

        % Update the network state.
        prunableNet.State = state;

        % Apply L2 regularization.
        netGradients = dlupdate(@(g,w) g + l2Regularization*w, ...
            netGradients, prunableNet.Learnables);

        % Update the network parameters using the SGDM optimizer.
        [prunableNet, velocity] = sgdmupdate(prunableNet, ...
            netGradients, velocity, learnRate, momentum);

        % Compute first-order Taylor scores and accumulate the score across
        % previous mini-batches of data.
        prunableNet = updateScore(prunableNet, pruningActivations, pruningGradients);

        % Display the training progress.
        D = duration(0,0,toc(start),'Format','hh:mm:ss');
        if isvalid(lineLossFinetune)
        addpoints(lineLossFinetune, iteration, double(loss.totalLoss))
        end
        title(tl,"Processing Pruning Iteration: " + pruningIteration + " of " + maxPruningIterations + ...
            ", Elapsed Time: " + string(D))
        % Synchronize the x-axis of the accuracy plot with the loss plot.
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

    % Show results on validation data set in a subset of pruning
    % iterations.
    isLastPruningIteration = pruningIteration == maxPruningIterations;
    if (mod(pruningIteration, validationFrequency) == 0 || isLastPruningIteration)
        [ap,~,~] = modelAccuracy(prunableNet, augimdsTest, anchorBoxes, anchorBoxMasks, classNames, 16);
        accuracy = mean(ap)*100;
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
