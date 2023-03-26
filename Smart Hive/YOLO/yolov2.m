% Usamos la aplicación imageLabeler para crear las bounding boxes de las
% bees/wasps de las imágenes.
%imageLabeler("..\Dataset\");


% Esta función nos devuelve los datos en el formato correcto para usarlo
% con el algoritmo YOLO.
load("..\SAVED_OBJECTS\gTruthBee_wasp.mat");
training_data_table = objectDetectorTrainingData(gTruth);

rng('default');
% Generamos permutación aleatorias
shuffled_indices = randperm(height(training_data_table));
idx = floor(0.6*length(shuffled_indices));

% Primero guardamos los índices hasta el 60% y luego los mezclamos para
% quedarnos con la parte de entrenamiento. Hacemos lo mismo con validación
% y test.
% Validación vamos a usar un 10%. El resto para test.
training_idx = 1:idx;
training_data = training_data_table(shuffled_indices(training_idx),:);

validation_idx = idx+1:idx+1+floor(0.1*length(shuffled_indices));
validation_data = training_data_table(shuffled_indices(validation_idx),:);

test_idx = validation_idx(end) + 1: length(shuffled_indices);
test_data = training_data_table(shuffled_indices(test_idx),:);

% Generamos los imageDatastore y boxLabelDatastore
imds_train = imageDatastore(training_data{:, "imageFilename"});
blds_train = boxLabelDatastore(training_data(:, 2:end));

imds_validation = imageDatastore(validation_data{:, "imageFilename"});
blds_validation = boxLabelDatastore(validation_data(:, 2:end));

imds_test = imageDatastore(test_data{:, "imageFilename"});
blds_test = boxLabelDatastore(test_data(:, 2:end));

% Combinamos los dos datastores
training_set = combine(imds_train, blds_train);
validation_set = combine(imds_validation, blds_validation);
test_set = combine(imds_test, blds_test);

% Validamos los datos de entrada para que no haya ninguna imagen sin
% bounding box, sin categoría o en un formato malo.
validateInputData(training_set);
validateInputData(validation_set);
validateInputData(test_set);

reset(training_set);

% Tamaño de entrada de la red usada para entrenamiento
input_size = [224 224 3];

% Nombre de la clase a detectar
class_name = {'bee_wasp'};

rng('default')
% Transforma el input datastore usando la función de transformación
% especificada.
% La función preprocessData es una función ya definida en el ejemplo de
% MATLAB. Sirve para cambiar los datos al tamaño de entrada especificado.
training_data_estimation = transform(training_set,@(data)preprocessData(data,input_size));
num_anchors = 24;
% Devuelve los diferentes anchors, junto con la media Intersection over
% Union. Está media estima el solapamiento entre las diferentes cajas.
[anchors,mean_IoU] = estimateAnchorBoxes(training_data_estimation,num_anchors);

featureExtractionNetwork = resnet50;
featureLayer = 'activation_40_relu';
lgraph = yolov2Layers(input_size,length(class_name),anchors,featureExtractionNetwork,featureLayer);

augmented_training_data = transform(training_set,@augmentData);

preprocessed_training_data = transform(augmented_training_data,@(data)preprocessData(data,input_size));
preprocessed_validation_data = transform(validation_set,@(data)preprocessData(data,input_size));

options = trainingOptions("adam",...
    InitialLearnRate=0.0003,...
    GradientDecayFactor=0.9,...
    SquaredGradientDecayFactor=0.999,...
    LearnRateSchedule="piecewise",...
    MiniBatchSize=32,...
    L2Regularization=0.01,...
    MaxEpochs=60,...
    BatchNormalizationStatistics="moving",...
    LearnRateDropPeriod=25,...
    DispatchInBackground=false,...
    ResetInputNormalization=false,...
    Shuffle="every-epoch",...
    VerboseFrequency=20,...
    CheckpointPath=tempdir,...
    ValidationData=preprocessed_validation_data,...
    ExecutionEnvironment='auto');

% Train the YOLO v4 detector.
[detector,info] = trainYOLOv2ObjectDetector(preprocessed_training_data,lgraph,options);