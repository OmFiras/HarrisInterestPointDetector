%%%%%%%%%%%%%%%%%%%-- Image Derivate--%%%%%%%%%%%%%%%%%%%
clear all
i=imread('Photo0353.jpg');
[rows,columns,channel]=size(i);
x=[1,-1];
y=[1;-1];
test=uint8(zeros(rows,columns));
ix=test;
iy=test;
for r1=1:rows
    for c1=1:columns
        test(r1,c1)=i(r1,c1,1)+i(r1,c1,2)+i(r1,c1,3);
    end
end
figure;imshow(i);
figure;imshow(ix);
figure;imshow(iy);

        


