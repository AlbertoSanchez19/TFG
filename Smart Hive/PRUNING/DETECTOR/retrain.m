velocity = [];
momentum = 0.9;
numEpochs = 100;
l2Regularization = 0.0005;
mbq = minibatchqueue(augimdsTrain, 2,...
    MiniBatchSize=miniBatchSize,...
    MiniBatchFcn=@(images, boxes, labels) preprocessMiniBatch(images, boxes, labels, classNames), ...
    MiniBatchFormat=["SSCB", ""],...
    OutputCast=["", "double"]);

figure
lineLossTrain = animatedline('Color',[0.85 0.325 0.098]);
ylim([0 inf])
xlabel("Iteration")
ylabel("Loss")
grid on

iteration = 0;
start = tic;
prunedDetectorNet = prunedNet;

for i = 1:numEpochs
    % Shuffle the data in the minibatch.
    shuffle(mbq);

    % Loop over mini-batches.
    while hasdata(mbq)
        iteration = iteration + 1;

        % Read mini-batch of data.
        [X, T] = next(mbq);

        % Evaluate the model gradients, state, and loss using dlfeval and the
        % modelGradients function and update the network state.
        [loss, gradients, state] = dlfeval(@modelLossTraining, prunedDetectorNet,...
            X, T, anchorBoxes, anchorBoxMasks, penaltyThreshold);

        % Update the network state.
        prunedDetectorNet.State = state;

        % Apply L2 regularization.
        gradients = dlupdate(@(g,w) g + l2Regularization*w, gradients, prunedNet.Learnables);

        % Update the network parameters using the SGDM optimizer.
        [prunedDetectorNet, velocity] = sgdmupdate(prunedDetectorNet, gradients, velocity, learnRate, momentum);

        % Display the training progress.
        D = duration(0,0,toc(start),'Format','hh:mm:ss');
        addpoints(lineLossTrain,iteration,double(loss.totalLoss))
        title("Retraining After Pruning" + newline + "Epoch: " + numEpochs + ", Elapsed: " + string(D))
        drawnow
    end
end

prunedyolov3ObjectDetector = yolov3ObjectDetector(prunedDetectorNet,classNames,yolov3Detector.AnchorBoxes);

originalNetFilters = numConvLayerFilters(net);
prunedNetFilters = numConvLayerFilters(prunedDetectorNet);
convFilters = join(originalNetFilters,prunedNetFilters,Keys="Row");

figure("Position",[10,10,900,900])
bar([convFilters.(1),convFilters.(2)])
xlabel("Layer")
ylabel("Number of Filters")
title("Number of Filters Per Layer")
xticks(1:(numel(convFilters.Row)))
xticklabels(convFilters.Row)
xtickangle(90)
ax = gca;
ax.TickLabelInterpreter = "none";
legend("Original Network Filters","Pruned Network Filters","Location","southoutside")

[apPrunedNet,recallPrunedNet,precisionPrunedNet] = modelAccuracy(prunedDetectorNet, augimdsTest, anchorBoxes, anchorBoxMasks, classNames, 16);
accuracyPrunedNet = mean(apPrunedNet)*100

figure
plot(recallTrainedNet,precisionTrainedNet,recallPrunedNet,precisionPrunedNet)
xlabel("Recall")
ylabel("Precision")
grid on
title("Precision Comparison of Original and Pruned Network")
legend("Original Network","Pruned Network");

analyzeNetworkMetrics(net,prunedDetectorNet,accuracyTrainedNet,accuracyPrunedNet)