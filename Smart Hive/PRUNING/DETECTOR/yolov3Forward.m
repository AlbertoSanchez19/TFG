function [YPredCell, state] = yolov3Forward(net, X,  anchorBoxMask)
% Predict the output of network.
numNetOutputs = numel(net.OutputNames);
networkOuts = cell(numNetOutputs, 1);

% retrieve pruning activations and network outputs
[networkOuts{:}, state] = forward(net, X);

YPredCell = extractPredictions(networkOuts, anchorBoxMask);

% Append predicted width and height to the end as they are required for
% computing the loss.
YPredCell(:,7:8) = YPredCell(:,4:5);

% Apply sigmoid and exponential activation.
YPredCell(:,1:6) = applyActivations(YPredCell(:,1:6));
end