function convFilters = numConvLayerFilters(net)
numLayers = numel(net.Layers);
convNames = [];
numFilters = [];
% Check for convolution layers and extract the number of filters.
for cnt = 1:numLayers
    if isa(net.Layers(cnt),"nnet.cnn.layer.Convolution2DLayer")
        sizeW = size(net.Layers(cnt).Weights);
        numFilters = [numFilters; sizeW(end)];%#ok<AGROW>
        convNames = [convNames; string(net.Layers(cnt).Name)];%#ok<AGROW>
    end
end
convFilters = table(numFilters,RowNames=convNames);
end