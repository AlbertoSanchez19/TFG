function metricOutput = hVerifyDetectionResults(predictionScores, net, dataStore)
% This template function defines a metric for validating a quantized neural
% network. Modify the body of this function to define your own custom
% metric. metricOutput must be a scalar number.
    % Convert struct of results into table
    detectionResults = struct2table(predictionScores);
    
    % Rescale output bounding boxes to the sizes of the images 
    inputSize = net.Layers(1).InputSize;
    testData = dataStore.readall; 
    testImages = testData(:,1);
    
    bboxes = detectionResults.boxes;
    new_bboxes = cell(height(detectionResults),1);
    
    for idx=1:height(detectionResults)
        dataSize = size(testImages{idx});
        rescale = inputSize(1:2)./dataSize(1:2);
        new_bboxes{idx} = bboxresize(round(bboxes{idx}), 1./rescale);
    end
    detectionResults.boxes = new_bboxes;
    
    % convert labels to categorical inputs
    labels = detectionResults.labels;
    newLabels = cellfun(@(x)categorical(x), labels, 'UniformOutput', false);
    detectionResults.labels = newLabels;
    
    % Call evaluate detection precision
    [ap, recall, precision] = evaluateDetectionPrecision(detectionResults, dataStore, 0.5);
    save('DetectionResults_codegen.mat', "detectionResults");
    
    metricOutput = ap;
   
    % Plot ROC: recall (1-FPR) vs precision (TPR)
    figure;
    plot(recall, precision);
    title(sprintf('Average precision = %.1f', ap))
end