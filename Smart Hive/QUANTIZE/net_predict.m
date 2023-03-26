function out = net_predict(netFile, in)
    net = coder.loadDeepLearningNetwork(netFile);
    out = net.classify(in);
end