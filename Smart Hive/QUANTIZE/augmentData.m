function B = augmentData(A)
% Jitter image color. Apply random horizontal flipping, and random X/Y scaling.
% Boxes that get scaled outside the bounds are clipped if the overlap is above 0.25.
B = cell(size(A));

I = A{1};
sz = size(I);
if numel(sz)==3 && sz(3) == 3
    I = jitterColorHSV(I,...
        'Contrast',0.2,...
        'Hue',0,...
        'Saturation',0.1,...
        'Brightness',0.2);
end

% Randomly flip and scale image.
tform = randomAffine2d('XReflection',true,'Scale',[1 1.1]);  
rout = affineOutputView(sz,tform,'BoundsStyle','CenterOutput');    
B{1} = imwarp(I,tform,'OutputView',rout);
    
% Apply same transform to boxes.
[B{2},indices] = bboxwarp(A{2},tform,rout,'OverlapThreshold',0.25);    
B{3} = A{3}(indices);
    
% Return original data only when all boxes are removed by warping.
if isempty(indices)
    B = A;
end
end

function data = preprocessData(data,targetSize)
% Resize image and bounding boxes to the targetSize.
scale = targetSize(1:2)./size(data{1},[1 2]);
data{1} = imresize(data{1},targetSize(1:2));
data{2} = bboxresize(data{2},scale);
end