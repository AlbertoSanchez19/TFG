function [bboxes,scores,labels] = generateYOLOv3Detections(detections, confidenceThreshold, overlapThreshold, imageSize, classes)
% Apply following post processing steps to filter the detections:
% * Filter detections based on threshold.
% * Convert bboxes from spatial to pixel dimension.

% Combine the prediction from different heads.
detections(:,1:5) = cellfun(@ reshapePredictions,detections(:,1:5), 'UniformOutput', false);
detections(:,6) = cellfun(@(a,b) reshapeClasses(a,b),detections(:,6),repmat({numel(classes)}, size(detections(:,6))),'UniformOutput', false);
detections = cell2mat(detections);

% Keep detections whose objectness score is greater than thresh.
confidenceTmp = detections(:,1);
detections = detections(confidenceTmp>confidenceThreshold,:);

% Initialize bboxes,scores,labels.
bboxes = zeros(0,'single');
scores = zeros(0,'single');
labels = categorical(cell(0,1));

% Filter the classes based on (confidence score * class probability).
if ~isempty(detections)
    [classProbs, classIdx] = max(detections(:,6:end),[],2);
    detections(:,1) = detections(:,1).*classProbs;
    detections(:,6) = classIdx;
    detections = detections(detections(:,1)>=confidenceThreshold,:);
    if ~isempty(detections)
        
        bboxes = detections(:,2:5);       
        scale = [imageSize(2) imageSize(1) imageSize(2) imageSize(1)];
        bboxes = bboxes.*scale;
        
        % Convert x and y position of detections from centre to top-left.
        % Resize boxes to image size.
        bboxes = convertCenterToTopLeft(bboxes);
        
        scores = detections(:,1);
        labels = detections(:,6);
        classes = classes';
        labels = categorical(classes(labels));
        
        % Apply suppression to the detections to filter out multiple overlapping
        % detections.
        if ~isempty(scores)
            [bboxes, scores, labels] = selectStrongestBboxMulticlass(bboxes, scores, labels ,...
                'RatioType', 'Union', 'OverlapThreshold', overlapThreshold);
        end
    end
end
end

