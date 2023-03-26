function x = reshapeClasses(pred,numclasses)
[h,w,c,n] = size(pred);
numanchors = c/numclasses;
x = reshape(pred,h*w,numclasses,numanchors,n);
x = permute(x,[1,3,2,4]);
[h,w,c,n] = size(x);
x = reshape(x,h*w,c,n);
end