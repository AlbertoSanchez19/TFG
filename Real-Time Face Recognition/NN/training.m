% La función imageDatastore, guarda en data las diferentes imágenes que
% tenemos en "Database\", clasificando cada imagen con el título de su
% subcarpeta (nombre de la persona").
data = imageDatastore("Database\", "IncludeSubfolders", true, "LabelSource", "foldernames");

% Dividimos el dataset en dos conjutnos, para entrenar y para validar.
[training_data, validation_data] = splitEachLabel(data, 0.8);

% Vamos a usar una red "googlenet".
net = googlenet;

% Guardamos el tamaño de entrada de la red.
input_size = net.Layers(1).InputSize;

% La capa que aprende y la capa de clasificación.
% Podemos verlo ejectuando el comando analyzeNetwork(net)
% La learner_layer tiene pesos mucho más grandes que el resto.
learner_layer = net.Layers(142);
classify_layer = net.Layers(144);

% Categories para que no haya repetidos (?)
num_of_classes = numel(categories(training_data.Labels));

new_learner_layer = fullyConnectedLayer(num_of_classes, "Name", "Facial Learner", "WeightLearnRateFactor", 10, "BiasLearnRateFactor", 10);
new_classify_layer = classificationLayer("Name", "Facial Classifier");

% Sustituimos en la red las nuevas neuronas que hemos creado
% Para sustituirlas, las "referenciamos" con su nombre (.Name)
layer_graph = layerGraph(net);
layer_graph = replaceLayer(layer_graph, learner_layer.Name, new_learner_layer);
layer_graph = replaceLayer(layer_graph, classify_layer.Name, new_classify_layer);

% Para que no se produzca un sobreaprendizaje en la red, vamos a modificar
% un poco el dataset de imagenes.
% Usamos la función imageDataAugmenter. El parámetro RandXReflection
% refleja la imágen con una probabilidad del 50%. De la misma forma, existe
% la opción RandYReflection. Las otras opciones son para trasladar la
% imagen y escalarla.
pixel_range = [-30 30];
scale_range = [0.9 1.1];
image_augmenter = imageDataAugmenter(RandXReflection=true, RandXTranslation=pixel_range, RandYTranslation=pixel_range, RandXScale=scale_range, RandYScale=scale_range);

% El primer argumento es el tamaño necesario para la red que vamos a usar
% (224x224)
augmented_training_images = augmentedImageDatastore(input_size(1:2), training_data, "DataAugmentation",image_augmenter);
augmented_validation_images = augmentedImageDatastore(input_size(1:2), validation_data, "DataAugmentation",image_augmenter);

% Ahora, tenemos que establecer las opciones con las que vamos a entrenar a
% la red.
size_of_minibatch = 3;
validation_frequency = floor(numel(augmented_training_images.Files)/size_of_minibatch);

% sgdm hace referencia a "Stochastic Gradient Descent with Momentum". Es el
% algoritmo que se va a usar para calcular los pesos.
% Con shuffle, en cada época se va a "barajear" el conjunto de datos, tanto
% entrenamiento como validación, lo que va a reducri el sobreaprendizaje.
% Plots es para decir que información se nos va a mostrar.
training_options = trainingOptions("sgdm", "MiniBatchSize", size_of_minibatch, "MaxEpochs",6, "InitialLearnRate",3e-5, "Shuffle", "every-epoch", "ValidationData", augmented_validation_images, "ValidationFrequency", validation_frequency, "Verbose",false, "Plots", "training-progress");

net = trainNetwork(augmented_training_images, layer_graph, training_options);
