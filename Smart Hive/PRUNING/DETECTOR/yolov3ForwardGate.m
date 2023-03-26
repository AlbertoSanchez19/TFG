function [YPredCell, state, activations] = yolov3ForwardGate(prunableNet, X,  anchorBoxMask)
% Predict the output of network.
numNetOutputs = numel(prunableNet.OutputNames);
networkOuts = cell(numNetOutputs, 1);

% retrieve outputs of activations and network outputs
[networkOuts{:}, state, activations] = forward(prunableNet, X);

YPredCell = extractPredictions(networkOuts, anchorBoxMask);

% Append predicted width and height to the end as they are required for
% computing the loss.
YPredCell(:,7:8) = YPredCell(:,4:5);

% Apply sigmoid and exponential activation.
YPredCell(:,1:6) = applyActivations(YPredCell(:,1:6));
end