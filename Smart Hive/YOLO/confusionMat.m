testObjects = testData.UnderlyingDatastores{1, 1}.Files  ; %'C:\Users\admin\Desktop\Img_Data\Flower1\Flower101.jpg'
testObjects = erase(testObjects,fullfile(pwd,imgFolderName)); %'\Flower1\Flower101.jpg'
testObjects = categorical(extractBetween(testObjects, "\","\")); % Flower1 - array

predLabels = zeros(2,1);  
predLabels = categorical(predLabels); % Prelocation
for iPred = 1:length(testObjects)  
    [~, idxx] = max(cell2mat(detectionResults.Scores(iPred))); % max of all the bounding box scores
    multiLabels = detectionResults.Labels{iPred,1};  % find label of max score
    if isempty(multiLabels) == 1  
        predLabels(iPred,1) = {'NaN'};  
        predLabels(iPred,1) = standardizeMissing(predLabels(iPred,1),{'NaN'});  
    else  
       predLabels(iPred,1) = (multiLabels(idxx,1));  
    end  
end  
predLabels = removecats(predLabels);

plotconfusion (testObjects,predLabels) %confusionchart(testAsts,predLabels)