function iou = getMaxIOUPredictedWithGroundTruth(predx,predy,predw,predh,truth)
% getMaxIOUPredictedWithGroundTruth computes the maximum intersection over
%  union scores for every pair of predictions and ground-truth boxes.

[h,w,c,n] = size(predx);
iou = zeros([h w c n],'like',predx);

% For each batch prepare the predictions and ground-truth.
for batchSize = 1:n
    truthBatch = truth(:,1:4,1,batchSize);
    truthBatch = truthBatch(all(truthBatch,2),:);
    predxb = predx(:,:,:,batchSize);
    predyb = predy(:,:,:,batchSize);
    predwb = predw(:,:,:,batchSize);
    predhb = predh(:,:,:,batchSize);
    predb = [predxb(:),predyb(:),predwb(:),predhb(:)];
    
    % Convert from center xy coordinate to topleft xy coordinate.
    predb = [predb(:,1)-predb(:,3)./2, predb(:,2)-predb(:,4)./2, predb(:,3), predb(:,4)];
    
    % Compute and extract the maximum IOU of predictions with ground-truth.
    try 
        overlap = bboxOverlapRatio(predb, truthBatch);
    catch me
        if(any(isnan(predb(:))|isinf(predb(:))))
            error(me.message + " NaN/Inf has been detected during training. Try reducing the learning rate.");
        elseif(any(predb(:,3)<=0 | predb(:,4)<=0))
            error(me.message + " Invalid predictions during training. Try reducing the learning rate.");
        else
            error(me.message + " Invalid groundtruth. Check that your ground truth boxes are not empty and finite, are fully contained within the image boundary, and have positive width and height.");
        end
    end
    
    maxOverlap = max(overlap,[],2);
    iou(:,:,:,batchSize) = reshape(maxOverlap,h,w,c);
end
end