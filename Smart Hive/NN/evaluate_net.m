% Cambiamos el tamaño de las imágenes, para que se ajuste al tamaño de
% entrada de la red
%augmented_test_images = augmentedImageDatastore(input_size(1:2), test_data);

% Clasificamos las imágenes de test
%[label_pred,scores] = classify(net,augmented_test_images);

% Vamos a mostrar unas imagenes random para ver si funciona bien la red
idx = randperm(numel(test_data.Files),4);
figure
for i = 1:4
    subplot(2,2,i)
    I = readimage(test_data,idx(i));
    imshow(I)
    label = label_pred(idx(i));
    title(string(label));
end

%%

label_test = test_data.Labels;
accuracy = mean(label_pred == label_test);

c_mat = confusionmat(label_test,label_pred,'Order',{'bee','wasp'});
% Nos muestra en un gráfico la matriz de confusión de manera más bonita
%c_chart = confusionchart(label_test,label_pred);

precision = diag(c_mat) ./ sum(c_mat,2);
% Tenemos que trasponer la matriz devuelta por sum para que haga la
% operación con matrices correctamente
recall = diag(c_mat) ./ sum(c_mat,1)';

f1 = 2.*(1./(1./precision + 1./recall));

% roc_obj guarda el valor AUC y métricas (Threshold, FalsePositiveRate,
% TruePositiveRate) para cada clase
roc_obj = rocmetrics(label_test, scores, [{'bee'}, {'wasp'}]);

%plot(roc_obj)

% NO TIENE SENTIDO PARA REDES DE CLASIFICACIÓN
% Mean Squarred Error
% Convertimos 'bee' a 1 y 'wasp' a 0, para poder hacer la operación
%num_label_test = renamecats(label_test,{'bee', 'wasp'},{'1','0'});
%num_label_pred = renamecats(label_pred,{'bee', 'wasp'},{'1','0'});
%mse = immse(double(num_label_test), double(num_label_pred));