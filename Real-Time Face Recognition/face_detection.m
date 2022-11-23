cam = webcam(1);

% Cargamos la red neuronal que hemos creado. "net.mat" se ha creado con el
% comando save("net.mat", "net");
net = coder.loadDeepLearningNetwork("net.mat");

% Usamos un Vision Cascade Detector para detectar las caras. Una vez nos
% detecte donde está la cara, usaremos esa información junto a la red que
% hemos creado para saber qué persona es.
face_detector = vision.CascadeObjectDetector;

% Este parámetro, si lo aumentamos, nos puede ayudar a detectar de una
% manera más precisa las diferentes caras que se encuentren en la imagen
% (en nuestro caso solo una)
face_detector.MergeThreshold = 4;

input_size = [224,224,3];

text2display = "......";

% tic sirve para medir el tiempo transcurrido. tic devuelve el tiempo
% actual, y toc lo utiliza para ver el tiempo transcurrido.
start = tic;
fprintf("Entering into while loop.\n");
while true
    % Capture image from webcam
    img = snapshot(cam);

    elapsed_time = toc(start);

    % Process frames at 1 per second
    if(elapsed_time > 1)

        % Obtenemos las "cajas" donde se encuentras las caras.
        bounding_boxes = face_detector(img);

        if ~isempty(bounding_boxes)
            img_processed = imcrop(img, bounding_boxes(1,:));
            % Resize the image
            img_resized = imresize(img_processed, input_size(1:2));

            % Classify the input image
            [label,score] = net.classify(img_resized);
            max_score = max(score);
    
            label_str = cellstr(label);
            text2display = sprintf("Label : %s \nScore: %f", label_str{:}, max_score);
            start = tic;
        end
    end

    % Display the predicted label
    % Insertamos en img, en la posición 0,0, el texto previamente calculado
    img_label = insertText(img, [0,0], text2display);
    img_label = insertObjectAnnotation(img_label, "rectangle", bounding_boxes, "Face", "LineWidth", 2);
    imshow(img_label);
end
