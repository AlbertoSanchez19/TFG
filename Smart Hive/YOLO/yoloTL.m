% Usamos la aplicación imageLabeler para crear las bounding boxes de las
% bees/wasps de las imágenes.
%imageLabeler("..\Dataset\");


% Esta función nos devuelve los datos en el formato correcto para usarlo
% con el algoritmo YOLO.
load("..\SAVED_OBJECTS\gTruthF3.mat");
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

basenet = resnet50;

%analyzeNetwork(basenet)
%basenet.Layers(1)

image_size = basenet.Layers(1).InputSize;
layer_name = basenet.Layers(1).Name;
new_input_layer = imageInputLayer(image_size,'Normalization','none','Name',layer_name);

lgraph = layerGraph(basenet);
lgraph = removeLayers(lgraph,'ClassificationLayer_fc1000');
lgraph = replaceLayer(lgraph,layer_name,new_input_layer);
dlnet = dlnetwork(lgraph);
feature_extraction_layers = ["activation_22_relu","activation_40_relu"];

% Nombre de la clase a detectar
class_names = {'bee', 'wasp'};

rng('default')
% Transforma el input datastore usando la función de transformación
% especificada.
% La función preprocessData es una función ya definida en el ejemplo de
% MATLAB. Sirve para cambiar los datos al tamaño de entrada especificado.
training_data_estimation = transform(training_set,@(data)preprocessData(data,image_size));
num_anchors = 24;
% Devuelve los diferentes anchors, junto con la media Intersection over
% Union. Está media estima el solapamiento entre las diferentes cajas.
[anchors,mean_IoU] = estimateAnchorBoxes(training_data_estimation,num_anchors);

%maxNumAnchors = 50;
%meanIoU = zeros([maxNumAnchors,1]);
%anchorBoxes = cell(maxNumAnchors, 1);
%for k = 1:maxNumAnchors
    % Estimate anchors and mean IoU.
    %[anchorBoxes{k},meanIoU(k)] = estimateAnchorBoxes(training_data_estimation,k);    
%end

%figure
%plot(1:maxNumAnchors,meanIoU,'-o')
%ylabel("Mean IoU")
%xlabel("Number of Anchors")
%title("Number of Anchors vs. Mean IoU")

% Multiplicamos la primera columna por la segunda, para calcular el área de
% CADA anchor
area = anchors(:, 1).*anchors(:,2);
% Lo ordenamos
[~, idx] =  sort(area, "descend");

% Tenemos todos los anchors de nuevo, pero ordenados en sentido descendente
% según su área.
anchors = anchors(idx, :);
anchor_boxes = {anchors(1:12,:);anchors(13:24,:)};

% Vamos a entrenar un detector YOLO a partir de un detector YOLO v4 creado
% con una pequeña red neuronal, usando el dataset COCO. Usamos esta versión
% (tiny) en vez de la normal ya que para un reconocimiento en tiempo real,
% esta versión es más rápida, a costa de perder precisión. Si no fuese en
% tiempo real, el tiempo de detección no sería crítico y podríamos usar la
% version YOLOv4 normal.
detector = yolov4ObjectDetector(dlnet, class_names, anchor_boxes, DetectionNetworkSource=feature_extraction_layers);

augmented_training_data = transform(training_set,@augmentData);

options = trainingOptions("adam",...
    InitialLearnRate=0.0003,...
    GradientDecayFactor=0.9,...
    SquaredGradientDecayFactor=0.999,...
    LearnRateSchedule="piecewise",...
    MiniBatchSize=16,...
    L2Regularization=0.005,...
    MaxEpochs=60,...
    BatchNormalizationStatistics="moving",...
    LearnRateDropPeriod=28,...
    DispatchInBackground=true,...
    ResetInputNormalization=false,...
    Shuffle="every-epoch",...
    VerboseFrequency=20,...
    CheckpointPath=tempdir,...
    ValidationData=validation_set,...
    ExecutionEnvironment='auto');

% Train the YOLO v4 detector.
[detector,info] = trainYOLOv4ObjectDetector(augmented_training_data,detector,options);
