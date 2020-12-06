function m=hdb3(x)
x=[1 1 1 1 1 0 0 0 0 1 0 0 0 0 1 1 0 0 0 0 0 0 0 0 1 1];
n=length(x);
y=zeros(size(x));
count=0;
for i=1:n
    if x(i)==1
        count=count+1;
        y(i)=(-1)^count;
    else
        y(i)=x(i)
    end
end
n=length(y);
last_V=-1;
last_one=-1;
m=zeros(size(y));
count=0;
for i=1:n
    if (y(i)==1||y(i)==(-1))
        m(i)=y(i);
        last_one=m(i);
        cout=0;
    else
        count=count+1;
        if count==4
            count=0;
            m(i)=last_V;
            last_V=-m(i);
            if m(i)*last_one==-1
                m(i-3)=m(i);
                last_one=m(i);
            end
        end
    end
end
figure(1);
subplot(2,1,1);
a=x;
i=0:n-1;
stairs(i,a);
axis([0 n 0 2]);
title('Ô­ÂëÐÍ');
xlabel('x');ylabel('y');
grid on
subplot(2,1,2);
a=y;
i=0:n-1;
stairs(i,a);
axis([0 n -2 2]);
title('HDB3ÂëÐÍ');
xlabel('x');ylabel('y');
grid on
