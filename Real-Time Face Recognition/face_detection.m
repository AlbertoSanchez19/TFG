function face_detection() 
%#codegen

rpi = raspi("192.168.1.20", "pi", "raspberry");
cam = cameraboard(rpi, "Resolution", "640x480");
%cam = webcam();

% Cargamos la red neuronal que hemos creado. "net.mat" se ha creado con el
% comando save("net.mat", "net");
net = coder.loadDeepLearningNetwork("./SAVED_OBJECTS/net.mat");

% ---  ESTO ES PARA COD, LO HE CAMBIADO AHORA POR YOLOv4 ---
%load("SAVED_OBJECTS\detector.mat");
detector = coder.loadDeepLearningNetwork("SAVED_OBJECTS\detector.mat");
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
start = tic;
fprintf("Entering into while loop.\n");
bounding_boxes = zeros(1,4,'single');

for i = 1:1000
    % Saca una captura de la cámara
    img = snapshot(cam);

    elapsed_time = toc(start);

    % Procesa un frame cada segundo
    if(elapsed_time > 1)

        % YOLOv4 -> Obtenemos las "cajas" donde se encuentras las caras.
        bounding_boxes = detect(detector,img);

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
            [label,score] = net.classify(img_resized);
            max_score = max(score);
    
            label_str = cellstr(label);
            text2display = sprintf("Label : %s \nScore: %f", label_str{:}, max_score);
        end
        start = tic;
    end

    % Para la generación de código, text2display necesita ser de tipo cell
    % en vez de string
    ctext2display = cellstr(text2display);
    % Insertamos en img, en la posición 0,0, el texto previamente calculado
    img_label = insertText(img, [0,0], ctext2display);
    % Actualizamos el cuadrado solamente si ha detectado una cara.
    if ~isempty(bounding_boxes)
        img_label = insertObjectAnnotation(img_label, "rectangle", bounding_boxes, "Face", "LineWidth", 2);
    end
    %imshow(img_label);
    displayImage(rpi, img_label);
end
