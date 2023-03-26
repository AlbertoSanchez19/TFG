fileID = fopen('bee_tags.txt','rt');
data = textscan(fileID,'%s','delimiter','\n');
C = data{1} ;
fclose(fileID);

num_images = length(C);
ret = cell(65,2);
for i = 1:num_images
    a = strsplit(C{i});
    ret{i,1} = [a{1}, ' ', a{2}];
    c = [];
    b = [];
    for j = 3:length(a)-1
        b = str2double(strsplit(a{j}, ','));
        b=b(1:end-1);
        b(b==0) = 1;
        b(3) = b(3) - b(1);
        b(4) = b(4) - b(2);
        c = [c ; b];
    end
    ret{i,2} = c;
    %ret{i,3} = 'bee';
end

tableCarnolian = array2table(ret,'VariableNames',{'imageFilename','bee'});
tableCarnolian.wasp = cell(65,1)
