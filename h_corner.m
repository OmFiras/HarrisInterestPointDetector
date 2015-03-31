clc
close all;
clear all;
tic;
i=imread('test3.jpg');
%i=imresize(i,0.25);
sig=0.5;
k=.5;
[rows,columns,channels]=size(i);
hx = [-1,0,1];
hy = -hx';
ix = imfilter(double(i),hx);
iy = imfilter(double(i),hy);
m1=ix.*ix;
m2=iy.*iy;
m3=ix.*iy;
for r1=1:rows-1
    for c1=1:columns-1
        a=[m1(r1,c1),m3(r1,c1);m3(r1,c1),m2(r1,c1)];
        m=conv2(a,gaussian2d(3,sig),'same');
        [v,d]=eig(m);
        r(r1,c1)=(d(1,1)*d(2,2))+(k*(sum(sum(d))));
    end
end
thres=0.80*max(max(r));
for r2=6:rows-6
    for c2=6:columns-6
        if r(r2,c2)>thres
            for y=-3:3
                i(r2+3,c2+y)=255;
                i(r2-3,c2+y)=255;
                i(r2+y,c2+3)=255;
                i(r2+y,c2-3)=255;
            end
                
                    
        else
            r_final(r2,c2)=255;
        end
    end
end
toc;
imshow(i)