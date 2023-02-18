% La función imageDatastore, guarda en data las diferentes imágenes que
% tenemos en 'Database\', clasificando cada imagen con el título de su
% subcarpeta (nombre de la persona').
data = imageDatastore('..\Dataset\NN_Dataset\', 'IncludeSubfolders', true, 'LabelSource', 'foldernames');

% Dividimos el dataset en dos conjutnos, para entrenar y para validar.
[training_data, validation_data, test_data] = splitEachLabel(data, 0.7,0.15, 'randomized');

% Vamos a usar una red 'googlenet'.
net = googlenet;

% Guardamos el tamaño de entrada de la red.
input_size = net.Layers(1).InputSize;

% La capa que aprende y la capa de clasificación.
% Podemos verlo ejectuando el comando analyzeNetwork(net)
% La learner_layer tiene pesos mucho más grandes que el resto.
%learner_layer = net.Layers(142);
%classify_layer = net.Layers(144);

% Categories para que no haya repetidos
num_of_classes = numel(categories(training_data.Labels));

new_learnable_layer = fullyConnectedLayer(num_of_classes, 'Name', 'Bee_wasp Learner', 'WeightLearnRateFactor', 10, 'BiasLearnRateFactor', 10);
new_classify_layer = classificationLayer('Name', 'Bee_wasp Classifier');

% Sustituimos en la red las nuevas neuronas que hemos creado
% Para sustituirlas, las 'referenciamos' con su nombre (.Name)
layer_graph = layerGraph(net);
layer_graph = replaceLayer(layer_graph, 'loss3-classifier', new_learnable_layer);
layer_graph = replaceLayer(layer_graph, 'output', new_classify_layer);

% Para que no se produzca un sobreaprendizaje en la red, vamos a modificar
% un poco el dataset de imagenes.
image_augmenter = imageDataAugmenter( ...
    'RandXReflection',true, ...
    'RandRotation',[-20,20], ...
    'RandXTranslation',[-30 30], ...
    'RandYTranslation',[-30 30], ...
    'RandScale',[0.9 1.1]);
% El primer argumento es el tamaño necesario para la red que vamos a usar
% (224x224)
augmented_training_images = augmentedImageDatastore(input_size(1:2), training_data, 'DataAugmentation',image_augmenter, 'ColorPreprocessing','gray2rgb');
augmented_validation_images = augmentedImageDatastore(input_size(1:2), validation_data, 'ColorPreprocessing','gray2rgb');

% sgdm hace referencia a 'Stochastic Gradient Descent with Momentum'. Es el
% algoritmo que se va a usar para calcular los pesos.
% Con shuffle, en cada época se va a 'barajear' el conjunto de datos, tanto
% entrenamiento como validación, lo que va a reducri el sobreaprendizaje.
% Plots es para decir que información se nos va a mostrar en un gráfico.
training_options = trainingOptions('adam', ...
    'GradientDecayFactor', 0.9,...
    'SquaredGradientDecayFactor',0.999,...
    'MiniBatchSize', 32, ...
    'LearnRateSchedule','piecewise', ...
    'MaxEpochs',30, ...
    'InitialLearnRate',0.001, ...
    'LearnRateDropPeriod', 13,...
    'L2Regularization', 0.01,...
    'BatchNormalizationStatistics', 'moving',...
    'DispatchInBackground', true,...
    'ResetInputNormalization',false,...
    'Shuffle', 'every-epoch', ...
    'ValidationData', augmented_validation_images, ...
    'Verbose',true, ...
    'Plots', 'training-progress', ...
    'ExecutionEnvironment','auto');

net = trainNetwork(augmented_training_images, layer_graph, training_options);

