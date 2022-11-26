% Usamos la aplicación imageLabeler para crear las bounding boxes de las
% caras de las imágenes. He hecho pocas porque hay que hacerlo manualmente.
% Para hacerlo automático, tendría que crear un algoritmo que lo haga
% automáticamente, que, al menos de momento, no voy a hacer.
%imageLabeler("..\Database\YOLO_dataset\");


% Esta función nos devuelve los datos en el formato correcto para usarlo
% con el algoritmo YOLO.
load("..\SAVED_OBJECTS\gTruth.mat");
training_data_table = objectDetectorTrainingData(gTruth);

rng('default');
% Generamos permutación aleatorias
shuffled_indices = randperm(height(training_data_table));
idx = floor(0.6*length(shuffled_indices));

% Primero guardamos los índices hasta el 60% y luego los mezclamos para
% quedarnos con la parte de entrenamiento. Hacemos lo mismo con validación
% y test.
training_idx = 1:idx;
training_data = training_data_table(shuffled_indices(training_idx),:);

validation_idx = idx+1:idx+1+floor(0.1*length(shuffled_indices));
validation_data = training_data_table(shuffled_indices(validation_idx),:);

test_idx = validation_idx(end) + 1: length(shuffled_indices);
test_data = training_data_table(shuffled_indices(test_idx),:);

% Generamos los imageDatastore y boxLabelDatastore
imds_train = imageDatastore(training_data{:, "imageFilename"});
blds_train = boxLabelDatastore(training_data(:, "face"));

imds_validation = imageDatastore(validation_data{:, "imageFilename"});
blds_validation = boxLabelDatastore(validation_data(:, "face"));

imds_test = imageDatastore(test_data{:, "imageFilename"});
blds_test = boxLabelDatastore(test_data(:, "face"));

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
class_name = "face";

rng('default')
% Transforma el input datastore usando la función de transformación
% especificada.
% La función preprocessData es una función ya definida en el ejemplo de
% MATLAB. Sirve para cambiar los datos al tamaño de entrada especificado.
training_data_estimation = transform(training_set,@(data)preprocessData(data,input_size));
num_anchors = 9;
% Devuelve los diferentes anchors, junto con la media Intersection over
% Union. Está media estima el solapamiento entre las diferentes cajas.
[anchors,mean_IoU] = estimateAnchorBoxes(training_data_estimation,num_anchors);

% Multiplicamos la primera columna por la segunda, para calcular el área de
% CADA anchor
area = anchors(:, 1).*anchors(:,2);
% Lo ordenamos
[~, idx] =  sort(area, "descend");

% Tenemos todos los anchors de nuevo, pero ordenados en sentido descendente
% según su área.
anchors = anchors(idx, :);
anchor_boxes = {anchors(1:3,:);anchors(4:6,:);anchors(7:9,:)};

detector = yolov4ObjectDetector("csp-darknet53-coco", class_name, anchor_boxes, InputSize=input_size);


augmented_training_data = transform(training_set,@augmentData);

options = trainingOptions("adam",...
    GradientDecayFactor=0.9,...
    SquaredGradientDecayFactor=0.999,...
    InitialLearnRate=0.001,...
    LearnRateSchedule="none",...
    MiniBatchSize=4,...
    L2Regularization=0.0005,...
    MaxEpochs=70,...
    BatchNormalizationStatistics="moving",...
    DispatchInBackground=true,...
    ResetInputNormalization=false,...
    Shuffle="every-epoch",...
    VerboseFrequency=20,...
    CheckpointPath=tempdir,...
    ValidationData=validation_set);

% Train the YOLO v4 detector.
[detector,info] = trainYOLOv4ObjectDetector(augmented_training_data,detector,options);
