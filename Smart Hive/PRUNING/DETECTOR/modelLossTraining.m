function [loss, gradients, state] = modelLossTraining(net, X, T, anchors, mask, penaltyThreshold)

inputImageSize = size(X,1:2);

% Gather the ground truths for post processing.
YTrain = gather(extractdata(T));

% Extract the predictions from the network.
[YPredCell, state] = yolov3Forward(net,X,mask);

% Gather the activations for post processing and extract dlarray data.
gatheredPredictions = cellfun(@ gather, YPredCell(:,1:6),'UniformOutput',false);
gatheredPredictions = cellfun(@ extractdata, gatheredPredictions, 'UniformOutput', false);

% Convert predictions from grid cell coordinates to box coordinates.
tiledAnchors = generateTiledAnchors(gatheredPredictions(:,2:5),anchors,mask);
gatheredPredictions(:,2:5) = applyAnchorBoxOffsets(tiledAnchors, gatheredPredictions(:,2:5), inputImageSize);

% Generate target for predictions from the ground truth data.
[boxTarget, objectnessTarget, classTarget, objectMaskTarget, boxErrorScale] = generateTargets(gatheredPredictions, YTrain, inputImageSize, anchors, mask, penaltyThreshold);

% Compute the loss.
boxLoss = bboxOffsetLoss(YPredCell(:,[2 3 7 8]),boxTarget,objectMaskTarget,boxErrorScale);
objLoss = objectnessLoss(YPredCell(:,1),objectnessTarget,objectMaskTarget);
clsLoss = classConfidenceLoss(YPredCell(:,6),classTarget,objectMaskTarget);
totalLoss = boxLoss + objLoss + clsLoss;

loss.boxLoss = boxLoss;
loss.objLoss = objLoss;
loss.clsLoss = clsLoss;
loss.totalLoss = totalLoss;

% Differentiate loss w.r.t learnables
gradients = dlgradient(totalLoss, net.Learnables);

end