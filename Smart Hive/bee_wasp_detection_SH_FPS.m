function bee_wasp_detection_SH_FPS() 
%#codegen

% board = targetHardware('Raspberry Pi');
% board.CoderConfig.TargetLang = 'C++';
% dlcfg = coder.DeepLearningConfig('arm-compute');
% dlcfg.ArmComputeVersion = '20.02.1';
% dlcfg.ArmArchitecture = 'armv7';
% board.CoderConfig.DeepLearningConfig = dlcfg;

rpi = raspi("192.168.1.20", "pi", "raspberry");
cam = cameraboard(rpi, "Resolution", "640x480");
mysensehat = sensehat(rpi);
%cam = webcam();

% Cargamos la red neuronal que hemos creado. "net.mat" se ha creado con el
% comando save("net.mat", "net");
net = coder.loadDeepLearningNetwork("./SAVED_OBJECTS/NET/net.mat");

% ---  ESTO ES PARA COD, LO HE CAMBIADO AHORA POR YOLOv4 ---
%load("SAVED_OBJECTS\detector.mat");
detector = coder.loadDeepLearningNetwork("SAVED_OBJECTS\YOLOTY\2\detector.mat");
% Usamos un Vision Cascade Detector para detectar las caras. Una vez nos
% detecte donde está la cara, usaremos esa información junto a la red que
% hemos creado para saber qué persona es.
%face_detector = vision.CascadeObjectDetector;

% Este parámetro, si lo aumentamos, nos puede ayudar a detectar de una
% manera más precisa las diferentes caras que se encuentren en la imagen
% (en nuestro caso solo una)
%face_detector.MergeThreshold = 4;

input_size = [224,224,3];

text2display = "......";

% tic sirve para medir el tiempo transcurrido. tic devuelve el tiempo
% actual, y toc lo utiliza para ver el tiempo transcurrido.
fprintf("Entering into while loop.\n");
bounding_boxes = zeros(1,4,'single');

fps = 0;

for i = 1:1000
    % Saca una captura de la cámara
    img = snapshot(cam);

    tic;

    % YOLOv4 -> Obtenemos las "cajas" donde se encuentras las caras.
    [bounding_boxes, yolo_score] = detect(detector,img);

    % COD
    %bounding_boxes = face_detector(img);
    
    % Si no es vacío, es decir, ha detectado alguna cara.
    if ~isempty(bounding_boxes)
        % La recortamos para solo quedarnos con la cara detectado.
        img_processed = imcrop(img, bounding_boxes(1,:));
        % Para que cuando lo implemento en la Rasp, sepa que la matriz
        % tiene "dimensión 3" en la tercera dimensión.
        img_processed = img_processed(:,:, 1:3);

        % Adaptamos el tamaño de la imagen a la entrada de la red.
        img_resized = imresize(img_processed, input_size(1:2));
        % Clasificamos la imagen
        [label,net_score] = net.classify(img_resized);

        text2display = sprintf("\nYOLO Score: %.3f\nNet Score: %.3f", max(yolo_score), max(net_score));
    end

    % Calculamos FPS
    time = toc;
    fps = .9*fps + 1*(1/time);

    fps_str = sprintf("FPS %2.2f", fps);
    cfps_str = cellstr(fps_str);

    img = insertText(img, [1, 1],  cfps_str, 'FontSize', 20);

    % Mostramos información sensores

    % Leemos la temperatura del sensor
    temp = readTemperature(mysensehat);
    % Nos la da en Kelvin, por lo que lo pasamos a Celsius.
    temp = temp - 273;

    % Hacemos lo mismo para la humedad y presión.
    humidity = readHumidity(mysensehat);

    pressure = readPressure(mysensehat);

    sensors = sprintf("Temp: %.2fC\nHumidity: %.2f%%\nPressure: %.2f Pa", temp, humidity, pressure);
    csensor = cellstr(sensors);

    [f,~] = size(img);
    img = insertText(img, [f-25, 1],  csensor, 'FontSize', 16);

    % Para la generación de código, text2display necesita ser de tipo cell
    % en vez de string
    ctext2display = cellstr(text2display);

    % Actualizamos el cuadrado solamente si ha detectado una cara.
    if ~isempty(bounding_boxes)
        % Insertamos en img, en la posición 0,0, el texto previamente calculado
        img_label = insertText(img, bounding_boxes(:,1:2), ctext2display);
        img_label = insertObjectAnnotation(img_label, "rectangle", bounding_boxes, label, "LineWidth", 2);
        %imshow(img_label);
        displayImage(rpi, img_label);
    else
        %imshow(img);
        displayImage(rpi, img);
    end
end