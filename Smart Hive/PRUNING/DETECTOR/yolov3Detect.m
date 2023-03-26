function [bboxes,scores,labels] = yolov3Detect(net, XTest, networkOutputs, anchors, anchorBoxMask, confidenceThreshold, overlapThreshold, classes)
% The yolov3Detect function detects the bounding boxes, scores, and labels
% in an image.
imageSize = size(XTest, [1,2]);

% To retain 'networkInputSize' in memory and avoid recalculating it,
% declare it as persistent.
persistent networkInputSize

if isempty(networkInputSize)
    networkInputSize = [227 227 3];
end

% Predict and filter the detections based on confidence threshold.
predictions = yolov3Predict(net,XTest,networkOutputs,anchorBoxMask);
predictions = cellfun(@ gather, predictions,'UniformOutput',false);
predictions = cellfun(@ extractdata, predictions, 'UniformOutput', false);
tiledAnchors = generateTiledAnchors(predictions(:,2:5),anchors,anchorBoxMask);
predictions(:,2:5) = applyAnchorBoxOffsets(tiledAnchors, predictions(:,2:5), networkInputSize);

numMiniBatch = size(XTest, 4);

bboxes = cell(numMiniBatch, 1);
scores = cell(numMiniBatch, 1);
labels = cell(numMiniBatch, 1);

for ii = 1:numMiniBatch
    fmap = cellfun(@(x) x(:,:,:,ii), predictions, 'UniformOutput', false);
    [bboxes{ii}, scores{ii}, labels{ii}] = ...
        generateYOLOv3Detections(fmap, confidenceThreshold, overlapThreshold, imageSize, classes);
end

end