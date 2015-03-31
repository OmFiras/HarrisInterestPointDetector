%%%%%%%%%%%%%%%%%%%-- Image Derivate--%%%%%%%%%%%%%%%%%%%
function[ix,iy]=my_derivative(i)
[rows,columns,channel]=size(i);
image=i;
test=zeros(rows,columns);
ix=test;
iy=test;
if(channel~=1)
    for r1=1:rows
        for c1=1:columns
            test(r1,c1)=(image(r1,c1,1)+image(r1,c1,2)+image(r1,c1,3))/3;
        end
    end
else
    test=image;
end
for r2=1:rows-1
    for c2=1:columns-1
        ix(r2,c2)=abs(test(r2,(c2+1))-test(r2,c2));
    end
end
for c3=1:columns-1
    for r3=1:rows-1
        iy(r3,c3)=abs(test((r3+1),c3)-test(r3,c3));
    end
end
end

