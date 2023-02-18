
% LLevamos a cabo la detección con el conjunto de test
detection_results = detect(detector,test_set);

% Esta función nos devuelve la 'average precision', 'recall' y 'precision'
[ap,recall,precision] = evaluateDetectionPrecision(detection_results,test_set);

recall_m = cell2mat(recall);
precision_m = cell2mat(precision);

% Calculamos manualmente la F1
f1 = 2.*(1./(1./precision_m + 1./recall_m));

% Mostramos cómo de preciso es el detector según diferentes valores de recall
figure
plot(recall{1,end},precision{1,end})
xlabel("Recall")
ylabel("Precision")
grid on
title(sprintf("Average Precision = %.2f", ap))
%%

[am, fppi, miss_rate] = evaluateDetectionMissRate(detection_results, test_set);

figure;
loglog(cell2mat(fppi), cell2mat(miss_rate));
grid on
title(sprintf('Log Average Miss Rate = %.1f', am))

