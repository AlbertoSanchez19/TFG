calibrationDataStore = splitEachLabel(imdsTrain,0.1,'randomize');
validationDataStore = imdsValidation;
%%
quantObjPrunedNetwork = dlquantizer(prunedNet,'ExecutionEnvironment','CPU');

calResults = calibrate(quantObjPrunedNetwork, calibrationDataStore)

valResults = validate(quantObjPrunedNetwork, validationDataStore);

valResults.MetricResults.Result
valResults.Statistics

%%

data = imageDatastore('..\Dataset\NN_Dataset\', 'IncludeSubfolders', true, 'LabelSource', 'foldernames');

% Dividimos el dataset en dos conjutnos, para entrenar y para validar.
[calData, valData] = splitEachLabel(data, 0.7, 'randomized');

aug_calData = augmentedImageDatastore([224 224 3], calData, 'ColorPreprocessing', 'gray2rgb');
aug_calData = shuffle(aug_calData).subset(1:200);
aug_valData = augmentedImageDatastore([224 224 3], valData, 'ColorPreprocessing', 'gray2rgb');                                      
aug_valData = shuffle(aug_valData).subset(1:50);

dq = dlquantizer(net, 'ExecutionEnvironment', 'CPU');

dq.calibrate(aug_calData);

save('activityRecognisationQuantObj.mat', 'dq')

cfg = coder.config('lib', 'ecoder', true);
cfg.VerificationMode = 'PIL';
cfg.StackUsageMax = 51200;
cfg.TargetLang = 'C';

dlcfg = coder.DeepLearningConfig('cmsis-nn');
dlcfg.CalibrationResultFile = 'activityRecognisationQuantObj.mat'; 

cfg.DeepLearningConfig = dlcfg;

hw = coder.hardware('STM32 Nucleo F103RB');
hw.PILInterface = 'Serial';
hw.PILCOMPort = 'COM6';

cfg.Hardware = hw;
cfg.BuildConfiguration = 'Faster Builds';
cfg.CodeReplacementLibrary = 'ARM Cortex-M (CMSIS)';

%codegen -config cfg net_predict -args {coder.Constant('trainedNet.mat'),single(zeros(224,224,3))}
%%
data = imageDatastore('..\Dataset\NN_Dataset\', 'IncludeSubfolders', true, 'LabelSource', 'foldernames');

% Dividimos el dataset en dos conjutnos, para entrenar y para validar.
[calData, valData] = splitEachLabel(data, 0.7, 'randomized');

aug_calData = augmentedImageDatastore([224 224 3], calData, 'ColorPreprocessing', 'gray2rgb');
aug_calData = shuffle(aug_calData).subset(1:200);
aug_valData = augmentedImageDatastore([224 224 3], valData, 'ColorPreprocessing', 'gray2rgb');                                      
aug_valData = shuffle(aug_valData).subset(1:50);

cfg = coder.config('lib', 'ecoder', true);
cfg.VerificationMode = 'PIL';
cfg.StackUsageMax = 50000;
cfg.TargetLang = 'C';

dlcfg = coder.DeepLearningConfig('none');

cfg.DeepLearningConfig = dlcfg;

hw = coder.hardware('STM32 Nucleo H743ZI');
hw.PILInterface = 'Serial';
hw.PILCOMPort = 'COM4';

cfg.Hardware = hw;
cfg.BuildConfiguration = 'Faster Builds';
cfg.CodeReplacementLibrary = 'ARM Cortex-M (CMSIS)';

%codegen -config cfg net_predict -args {coder.Constant('net.mat'),uint8(zeros(32,32,3))}

%%
inputSize = [224 224];

augmentedCalibrationData = transform(calData,@augmentData);
augmentedValidationData = transform(valData,@augmentData);

preprocessedCalibrationData = transform(augmentedCalibrationData,@(data)preprocessData(data,inputSize));
preprocessedValidationData = transform(valData,@(data)preprocessData(data,inputSize));
%%
quantObj = dlquantizer(detector);

quantOpts = dlquantizationOptions;
quantOpts = dlquantizationOptions('MetricFcn', ...
    {@(x)hVerifyDetectionResults(x, detector.Network, preprocessedValidationData)});

calResults = calibrate(quantObj,preprocessedCalibrationData)

valResults = validate(quantObj,preprocessedValidationData,quantOpts)

valResults.MetricResults.Result
