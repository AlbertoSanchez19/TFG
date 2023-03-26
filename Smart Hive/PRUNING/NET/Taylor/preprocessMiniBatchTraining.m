function [X,T] = preprocessMiniBatchTraining(XCell,TCell)
% Concatenate.
X = cat(4,XCell{1:end});

% Extract label data from cell and concatenate.
T = cat(2,TCell{1:end});

% One-hot encode labels.
T = onehotencode(T,1);
end