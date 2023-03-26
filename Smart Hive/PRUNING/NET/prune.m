imdsTrain = training_data;
imdsValidation = validation_data;

inputSize = net.Layers(1).InputSize;

imdsValidation = augmentedImageDatastore(inputSize, imdsValidation, 'ColorPreprocessing','gray2rgb');
imdsTrain = augmentedImageDatastore(inputSize, imdsTrain, 'ColorPreprocessing','gray2rgb');

trueLabels = validation_data.Labels;
classes = categories(trueLabels);

executionEnvironment = "auto";
miniBatchSize = 64;
mbqValidation = minibatchqueue(imdsValidation,1,...
    'MiniBatchSize',miniBatchSize,...
    'MiniBatchFormat','SSCB',...
    'MiniBatchFcn',@preprocessMiniBatch,...
    'OutputEnvironment',executionEnvironment);


lgraph = layerGraph(net);
lgraph = removeLayers(lgraph,["Bee_wasp Classifier"]);
dlnet = dlnetwork(lgraph);

accuracyOriginalNet = evaluateAccuracy(dlnet,mbqValidation,classes,trueLabels)

numTotalParams = sum(cellfun(@numel,dlnet.Learnables.Value))

numNonZeroPerParam = cellfun(@(w)nnz(extractdata(w)),dlnet.Learnables.Value)

initialSparsity = 1-(sum(numNonZeroPerParam)/numTotalParams)

numIterations = 10; 
targetSparsity = 1;
iterationScheme = linspace(0,targetSparsity,numIterations); 

testWeight = [10.4 5.6 0.8 9];

testMask = [1 0 1 0];

testWeightsPruned = testWeight.*testMask

figure
plot(100*iterationScheme([1,end]),100*accuracyOriginalNet*[1 1],'*-b','LineWidth',2,"Color","b")
ylim([0 100])
xlim(100*iterationScheme([1,end]))
xlabel("Sparsity (%)")
ylabel("Accuracy (%)")
legend("Original Accuracy","Location","southwest")
title("Pruning Accuracy")    
grid on

pruningMaskMagnitude = cell(1,numIterations); 
pruningMaskMagnitude{1} = dlupdate(@(p)true(size(p)), dlnet.Learnables);

lineAccuracyPruningMagnitude = animatedline('Color','g','Marker','o','LineWidth',1.5);
legend("Original Accuracy","Magnitude Pruning Accuracy","Location","southwest")

% Compute magnitude scores
scoresMagnitude = calculateMagnitudeScore(dlnet);

for idx = 1:numel(iterationScheme)

    prunedNetMagnitude = dlnet;
    
    % Update the pruning mask
    pruningMaskMagnitude{idx} = calculateMask(scoresMagnitude,iterationScheme(idx));
    
    % Check the number of zero entries in the pruning mask
    numPrunedParams = sum(cellfun(@(m)nnz(~extractdata(m)),pruningMaskMagnitude{idx}.Value));
    sparsity = numPrunedParams/numTotalParams;
    
    % Apply pruning mask to network parameters
    prunedNetMagnitude.Learnables = dlupdate(@(W,M)W.*M, prunedNetMagnitude.Learnables, pruningMaskMagnitude{idx});
    
    % Compute validation accuracy on pruned network
    accuracyMagnitude = evaluateAccuracy(prunedNetMagnitude,mbqValidation,classes,trueLabels);
    
    % Display the pruning progress
    addpoints(lineAccuracyPruningMagnitude,100*sparsity,100*accuracyMagnitude)
    drawnow
end


pruningMaskSynFlow = cell(1,numIterations); 
pruningMaskSynFlow{1} = dlupdate(@(p)true(size(p)),dlnet.Learnables);

dlX = dlarray(ones(net.Layers(1).InputSize),'SSC');
if (executionEnvironment == "auto" && canUseGPU) || executionEnvironment == "gpu"
    dlX = gpuArray(dlX);
end

%lineAccuracyPruningSynflow = animatedline('Color','r','Marker','o','LineWidth',1.5);
%legend("Original Accuracy","Magnitude Pruning Accuracy","Synaptic Flow Accuracy","Location","southwest")

prunedNetSynFlow = dlnet;

% Iteratively increase sparsity
for idx = 1:numel(iterationScheme)
    % Compute SynFlow scores
    scoresSynFlow = calculateSynFlowScore(prunedNetSynFlow,dlX);
    
    % Update the pruning mask
    pruningMaskSynFlow{idx} = calculateMask(scoresSynFlow,iterationScheme(idx));
    
    % Check the number of zero entries in the pruning mask
    numPrunedParams = sum(cellfun(@(m)nnz(~extractdata(m)),pruningMaskSynFlow{idx}.Value));
    sparsity = numPrunedParams/numTotalParams;
    
    % Apply pruning mask to network parameters
    prunedNetSynFlow.Learnables = dlupdate(@(W,M)W.*M, prunedNetSynFlow.Learnables, pruningMaskSynFlow{idx});
    
    % Compute validation accuracy on pruned network
    accuracySynFlow = evaluateAccuracy(prunedNetSynFlow,mbqValidation,classes,trueLabels);
     
    % Display the pruning progress
    %addpoints(lineAccuracyPruningSynflow,100*sparsity,100*accuracySynFlow)
    %drawnow
end

pruningMethod = "SynFlow";
selectedIteration = 10;

prunedDLNet = createPrunedNet(dlnet,selectedIteration,pruningMaskSynFlow,pruningMaskMagnitude,pruningMethod);

[sparsityPerLayer,prunedChannelsPerLayer,numOutChannelsPerLayer,layerNames] = pruningStatistics(prunedDLNet);

figure
bar(sparsityPerLayer*100)
title("Sparsity per layer")
xlabel("Layer")
ylabel("Sparsity (%)")
xticks(1:numel(sparsityPerLayer))
xticklabels(layerNames)
xtickangle(45)
set(gca,'TickLabelInterpreter','none')

figure
bar([prunedChannelsPerLayer,numOutChannelsPerLayer-prunedChannelsPerLayer],"stacked")
xlabel("Layer")
ylabel("Number of filters")
title("Number of filters per layer")
xticks(1:(numel(layerNames)))
xticklabels(layerNames)
xtickangle(45)
legend("Pruned number of channels/neurons" , "Original number of channels/neurons","Location","southoutside")
set(gca,'TickLabelInterpreter','none')

prunedLayerGraph = layerGraph(prunedDLNet);
outputLayerName = string(net.OutputNames{1});
outputLayerIdx = {net.Layers.Name} == outputLayerName;
prunedLayerGraph = addLayers(prunedLayerGraph,net.Layers(outputLayerIdx));
prunedLayerGraph = connectLayers(prunedLayerGraph,prunedDLNet.OutputNames{1},outputLayerName);

options = trainingOptions("sgdm", ...
    MaxEpochs = 10, ...
    MiniBatchSize = 256, ...
    InitialLearnRate = 1e-2, ...
    LearnRateSchedule = "piecewise", ...
    LearnRateDropFactor = 0.1, ...
    LearnRateDropPeriod = 2, ...
    L2Regularization = 0.02, ...
    ValidationData = augimdsTest, ...
    ValidationFrequency = 200, ...
    Verbose = false, ...
    Shuffle = "every-epoch", ...
    Plots = "training-progress");

augimdsValidation = imdsValidation;
augimdsTrain = imdsTrain;

prunedDAGNet = trainNetwork(augimdsTrain,prunedLayerGraph,options);

function X = preprocessMiniBatch(XCell)
% Extract image data from cell and concatenate.
X = cat(4,XCell{1:end});
end

function accuracy = evaluateAccuracy(dlnet,mbqValidation,classes,trueLabels)
YPred = modelPredictions(dlnet,mbqValidation,classes);
accuracy = mean(YPred == trueLabels);
end

function score = calculateSynFlowScore(dlnet,dlX)
dlnet.Learnables = dlupdate(@abs, dlnet.Learnables);
gradients = dlfeval(@modelGradients,dlnet,dlX);
score = dlupdate(@(g,w)g.*w, gradients, dlnet.Learnables);
end

function gradients = modelGradients(dlNet,inputArray)
% Evaluate the gradients on a given input to the dlnetwork
dlYPred = predict(dlNet,inputArray);
pseudoloss = sum(dlYPred,'all');
gradients = dlgradient(pseudoloss,dlNet.Learnables);
end


function mask = calculateMask(scoresMagnitude,sparsity)
% Compute a binary mask based on the parameter-wise scores such that the mask contains a percentage of zeros as specified by sparsity.

% Flatten the cell array of scores into one long score vector
flattenedScores = cell2mat(cellfun(@(S)extractdata(gather(S(:))),scoresMagnitude.Value,'UniformOutput',false));
% Rank the scores and determine the threshold for removing connections for the
% given sparsity
flattenedScores = sort(flattenedScores);
k = round(sparsity*numel(flattenedScores));
if k==0
    thresh = 0;
else
    thresh = flattenedScores(k);
end
% Create a binary mask 
mask = dlupdate( @(S)S>thresh, scoresMagnitude);
end

function score = calculateMagnitudeScore(dlnet)
score = dlupdate(@abs, dlnet.Learnables);
end

function predictions = modelPredictions(dlnet,mbq,classes)
predictions = [];
while hasdata(mbq)
    dlXTest = next(mbq);
    dlYPred = softmax(predict(dlnet,dlXTest));
    YPred = onehotdecode(dlYPred,classes,1)';
    predictions = [predictions; YPred];
end
reset(mbq)
end

function prunedNet = createPrunedNet(dlnet,selectedIteration,pruningMaskSynFlow,pruningMaskMagnitude,pruningMethod)
switch pruningMethod
    case "Magnitude"
        prunedNet = dlupdate(@(W,M)W.*M, dlnet, pruningMaskMagnitude{selectedIteration});
    case "SynFlow"
        prunedNet = dlupdate(@(W,M)W.*M, dlnet, pruningMaskSynFlow{selectedIteration});
end
end

function [sparsityPerLayer,prunedChannelsPerLayer,numOutChannelsPerLayer,layerNames] = pruningStatistics(dlnet)

layerNames = unique(dlnet.Learnables.Layer,'stable');
numLayers = numel(layerNames);
layerIDs = zeros(numLayers,1);
for idx = 1:numel(layerNames)
    layerIDs(idx) = find(layerNames(idx)=={dlnet.Layers.Name});
end

sparsityPerLayer = zeros(numLayers,1);
prunedChannelsPerLayer = zeros(numLayers,1);
numOutChannelsPerLayer = zeros(numLayers,1);

numParams = zeros(numLayers,1);
numPrunedParams = zeros(numLayers,1);
for idx = 1:numLayers
    layer = dlnet.Layers(layerIDs(idx));
    
    % Calculate the sparsity
    paramIDs = strcmp(dlnet.Learnables.Layer,layerNames(idx));
    paramValue = dlnet.Learnables.Value(paramIDs);
    for p = 1:numel(paramValue)
        numParams(idx) = numParams(idx) + numel(paramValue{p});
        numPrunedParams(idx) = numPrunedParams(idx) + nnz(extractdata(paramValue{p})==0);
    end

    % Calculate channel statistics
    sparsityPerLayer(idx) = numPrunedParams(idx)/numParams(idx);
    switch class(layer)
        case "nnet.cnn.layer.FullyConnectedLayer"
            numOutChannelsPerLayer(idx) = layer.OutputSize;
            prunedChannelsPerLayer(idx) = nnz(all(layer.Weights==0,2)&layer.Bias(:)==0);
        case "nnet.cnn.layer.Convolution2DLayer"
            numOutChannelsPerLayer(idx) = layer.NumFilters;
            prunedChannelsPerLayer(idx) = nnz(reshape(all(layer.Weights==0,[1,2,3]),[],1)&layer.Bias(:)==0);
        case "nnet.cnn.layer.GroupedConvolution2DLayer"
            numOutChannelsPerLayer(idx) = layer.NumGroups*layer.NumFiltersPerGroup;
            prunedChannelsPerLayer(idx) = nnz(reshape(all(layer.Weights==0,[1,2,3]),[],1)&layer.Bias(:)==0);
        otherwise
            error("Unknown layer: "+class(layer))
    end
end
end