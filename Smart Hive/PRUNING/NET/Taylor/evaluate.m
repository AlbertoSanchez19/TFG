[originalNetFilters,layerNames] = numConvLayerFilters(trainedNet);
prunedNetFilters = numConvLayerFilters(prunedDAGNet);

figure("Position",[10,10,900,900])
bar([originalNetFilters,prunedNetFilters])
xlabel("Layer")
ylabel("Number of Filters")
title("Number of Filters Per Layer")
xticks(1:(numel(layerNames)))
xticklabels(layerNames)
xtickangle(90)
ax = gca;
ax.TickLabelInterpreter = "none";
legend("Original Network Filters","Pruned Network Filters","Location","southoutside")
%%
YPredOriginal = classify(trainedNet,augimdsTest);
accuOriginal = mean(YPredOriginal == TTest)

YPredPruned = classify(prunedDAGNet,augimdsTest);
accuPruned = mean(YPredPruned == TTest)

figure
confusionchart(TTest,YPredOriginal,Normalization = "row-normalized");
title("Original Network")

figure
confusionchart(TTest,YPredPruned,Normalization = "row-normalized");
title("Pruned Network")

analyzeNetworkMetrics(trainedNet,prunedDAGNet,accuOriginal,accuPruned)