clear all 
close all
K=round(rand(1,1000));
n=length(K);
for i=1:n
    if K(i)==1
        y(2*i)=0;
        y(2*i-1)=1;
    else
        y(2*i)=1;
        y(2*i-1)=0;
    end
end
figure(1);
subplot(2,1,1);
a=K;
i=0:n-1;
stairs(i,a);
axis([0 n 0 2]);
title('原码型');
xlabel('x');ylabel('y');
axis([0 20 0 2]);
grid on
subplot(2,1,2);
a=y;
i=0:(length(y)-1);
stairs(i,a);
axis([0 n -2 2]);
title('双相码码型');
xlabel('x');ylabel('y');
axis([0 20 0 2]);
grid on
