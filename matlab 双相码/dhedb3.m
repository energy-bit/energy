function y=dhedb3(x)
x=[1 1 1 1 1 0 0 0 0 1 0 0 0 0 1 1 0 0 0 0 0 0 0 0 1 1];
n=length(x);
m=0;
c=1;
y=zeros(size(x));
for i=1:n;
    if x(i)==0
        m=m+1;
    end
    if x(i)~=0
        if (m~=2&&m~=3)
            y(i)=c;
            m=0;
        elseif m==2&&i>3
            if (x(i)==-x(i-4)&&x(i)==x(i-3))
                y(i-3)=0;
                y(i)=0;
                m=0;
            else y(i)=1;
                m=0;
            end
        elseif m==3&&i>4
            if x(i)*x(i-4)==-1;
                y(i)=1;
                m=0;
            else y(i)=0;
                m=0;
            end
        end
    end
end
figure(2);
subplot(2,1,1);
a=x;
i=0:n-1;
stairs(i,a);
axis([0 n -2 2]);
title('HDB3码型');
xlabel('x');ylabel('y');
grid on
subplot(2,1,2);
a=y;
i=0:n-1;
stairs(i,a);
axis([0 n 0 2]);
title('HDB3解码后码型');
xlabel('x');ylabel('y');
grid on
