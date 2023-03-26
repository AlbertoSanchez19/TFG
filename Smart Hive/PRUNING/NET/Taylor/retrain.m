prunedLayerGraph = layerGraph(prunedNet);
outputLayerName = string(trainedNet.OutputNames{1});
outputLayerIdx = {trainedNet.Layers.Name} == outputLayerName;
prunedLayerGraph = addLayers(prunedLayerGraph,trainedNet.Layers(outputLayerIdx));
prunedLayerGraph = connectLayers(prunedLayerGraph,prunedNet.OutputNames{1},outputLayerName);

options = trainingOptions("sgdm", ...
    MaxEpochs = 5, ...
    MiniBatchSize = 64, ...
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

prunedDAGNet = trainNetwork(augimdsTrain,prunedLayerGraph,options);
%%

layers = [
    imageInputLayer([32 32 3], 'Mean', net3.Layers(1).Mean(1:32, 1:32, :))
    fullyConnectedLayer(2, 'Name', 'Bee_wasp Learner1','WeightsInitializer', 'he', 'WeightLearnRateFactor', 10, 'BiasLearnRateFactor', 10')
    softmaxLayer()
    classificationLayer()
];

% layers(2).Weights = randn([512 224*224*3]) * 0.1;
% layers(2).Bias = zeros(512,1);net
% layers(4).Weights = randn([256 512]) * 0.1;
% layers(4).Bias = zeros(256,1);
% layers(6).Weights = randn([128 256]) * 0.1;
% layers(6).Bias = zeros(128,1);
% layers(8).Weights = randn([64 128]) * 0.1;
% layers(8).Bias = zeros(64,1);
% layers(10).Weights = randn([32 64]) * 0.1;
% layers(10).Bias = zeros(32,1);
% layers(12).Weights = randn([16 32]) * 0.1;
% layers(12).Bias = zeros(16,1);
% layers(14).Weights = randn([8 16]) * 0.1;
% layers(14).Bias = zeros(8,1);
% layers(16).Weights = randn([4 8]) * 0.1;
% layers(16).Bias = zeros(4,1);
% layers(18).Weights = randn([2 4]) * 0.1;
% layers(18).Bias = zeros(2,1);


layers(2).Weights = randn([2 32*32*3]) * 0.1;
layers(2).Bias = zeros(2,1);
% layers(3).Weights = randn([2 8]) * 0.1;
% layers(3).Bias = zeros(2,1);
% layers(4).Weights = randn([2 8]) * 0.1;
% layers(4).Bias = zeros(2,1);
% layers(5).Weights = randn([32 128]) * 0.1;
% layers(5).Bias = zeros(32,1);
% layers(6).Weights = randn([32 32]) * 0.1;
% layers(6).Bias = zeros(32,1);
% layers(7).Weights = randn([8 32]) * 0.1;
% layers(7).Bias = zeros(8,1);
% layers(8).Weights = randn([2 8]) * 0.1;
% layers(8).Bias = zeros(2,1);