function bee_wasp_detection() 
%#codegen

%rpi = raspi("192.168.1.20", "pi", "raspberry");
%cam = cameraboard(rpi, "Resolution", "640x480");
cam = webcam();

% Cargamos la red neuronal que hemos creado. "net.mat" se ha creado con el
% comando save("net.mat", "net");
net = coder.loadDeepLearningNetwork("./SAVED_OBJECTS/NET/net.mat");

% ---  ESTO ES PARA COD, LO HE CAMBIADO AHORA POR YOLOv4 ---
%load("SAVED_OBJECTS\detector.mat");
detector = coder.loadDeepLearningNetwork("SAVED_OBJECTS\YOLOTF\2\detector.mat");
% Usamos un Vision Cascade Detector para detectar las caras. Una vez nos
% detecte donde está la cara, usaremos esa información junto a la red que
% hemos creado para saber qué persona es.
%face_detector = vision.CascadeObjectDetector;

% Este parámetro, si lo aumentamos, nos puede ayudar a detectar de una
% manera más precisa las diferentes caras que se encuentren en la imagen
% (en nuestro caso solo una)
%face_detector.MergeThreshold = 4;

input_size = [224,224,3];

text2display = strings(20,1);
label = strings([1, 20]);
bboxes_pos = zeros(20,4);

fps = 0;
avgfps = [];

% tic sirve para medir el tiempo transcurrido. tic devuelve el tiempo
% actual, y toc lo utiliza para ver el tiempo transcurrido.
%start = tic;
fprintf("Entering into while loop.\n");
bounding_boxes = zeros(10,4,'single');

for i = 1:1000
    % Saca una captura de la cámara
    img = snapshot(cam);

    %elapsed_time = toc(start);

    % Procesa un 10 frames cada segundo
    %if(elapsed_time > 1)

    tic;

        % YOLOv4 -> Obtenemos las "cajas" donde se encuentras las bees/wasps.
        [bounding_boxes, yolo_score] = detect(detector,img);

        % COD
        %bounding_boxes = face_detector(img);
        
        % Si no es vacío, es decir, ha detectado alguna.
        if ~isempty(bounding_boxes)
            
            bboxes_pos = zeros(20,4);
            % Iteramos por cada una de las bounding_boxes detectadas
            for b = 1:size(bounding_boxes)
                % La recortamos para solo quedarnos con la bee/wasp detectada.
                img_processed = imcrop(img, bounding_boxes(b,:));
                % Para que cuando lo implemento en la Rasp, sepa que la matriz
                % tiene "dimensión 3" en la tercera dimensión.
                img_processed = img_processed(:,:, 1:3);
    
                % Adaptamos el tamaño de la imagen a la entrada de la red.
                img_resized = imresize(img_processed, input_size(1:2));
                % Clasificamos la imagen
                [label(b),net_score] = net.classify(img_resized);
                %max_score = max(net_score);
        
                text2display(b) = sprintf("\nYOLO Score: %f\nNet Score: %f", max(yolo_score), max(net_score));

                % Para la generación de código, text2display necesita ser de tipo cell
                % en vez de string
                %ctext2display(b) = text2display;
 
                bboxes_pos(b,:) = bounding_boxes(b,:);
            end
        end
        %start = tic;
    %end
    start = toc;
    fps = .9*fps + 1*(1/start);

    img = insertText(img, [1, 1],  sprintf('FPS %2.2f', fps), 'FontSize', 22, 'BoxColor', 'y');
    ctext2display = cellstr(text2display);
    % Actualizamos el cuadrado solamente si ha detectado una cara.
    if ~isempty(bounding_boxes)
        % Insertamos en img, en la posición 0,0, el texto previamente calculado
        img_label = insertText(img, bboxes_pos(:, 1:2), ctext2display);
        img_label = insertObjectAnnotation(img_label, "rectangle", bboxes_pos, label, "LineWidth", 2);
        imshow(img_label);
        %displayImage(rpi, img_label);
    else
        imshow(img);
        %displayImage(rpi, img);
    end

end
