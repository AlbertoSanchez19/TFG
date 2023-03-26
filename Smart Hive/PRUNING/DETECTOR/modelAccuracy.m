function [ap, recall, precision] = modelAccuracy(net, augimds, anchorBoxes, anchorBoxMasks, classNames, miniBatchSize)
% EVALUATE computes model accuracy on the dataset 'augimds'.
% Create a table to hold the bounding boxes, scores, and labels returned by
% the detector.
results = table('Size', [0 3], ...
    'VariableTypes', {'cell','cell','cell'}, ...
    'VariableNames', {'Boxes','Scores','Labels'});
mbqTest = minibatchqueue(augimds, 1, ...
    "MiniBatchSize", miniBatchSize, ...
    "MiniBatchFormat", "SSCB");

% Run detector on images in the test set and collect results.
while hasdata(mbqTest)
    % Read the datastore and get the image.
    XTest = next(mbqTest);

    % Run the detector.
    [bboxes, scores, labels] = yolov3Detect(net, XTest, net.OutputNames', anchorBoxes, anchorBoxMasks, 0.5, 0.5, classNames);

    % Collect the results.
    tbl = table(bboxes, scores, labels, 'VariableNames', {'Boxes','Scores','Labels'});
    results = [results; tbl];%#ok<AGROW>
end

% Evaluate the object detector using Average Precision metric.
[ap, recall, precision] = evaluateDetectionPrecision(results, augimds);
end