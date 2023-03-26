function x = reshapePredictions(pred)
[h,w,c,n] = size(pred);
x = reshape(pred,h*w*c,1,n);
end