clear all
close all
%建立原信号
t=0:0.0125:10;%8000个数
vm1=-70:1:0;%输入的正弦信号的幅度不同
vm=10.^(vm1/20);%db--10进制
figure(1)
for k=1:length(vm)
    for m=1:2
        x=vm(k)*sin(2*pi*t+2*pi*rand(1));%x方程
        v=1;
        xx=x;%normalize
        sxx= floor(xx*4096);%段内编码floor
        y= pcm_encode(sxx);%PCM编码
        yy= pcm_decode(y,v);%PCM解码
        
        nq(m)=sum((x-yy).*(x-yy))/length(x);%噪声功率
        sq(m)=mean(yy.^2);%信号功率
        snr(m)=(sq(m)/nq(m));%信噪比
        
        drawnow
        subplot(2,1,1)
        plot(t,x);
        title('未编码信号波形');
        subplot(2,1,2)
        plot(t,yy);
        title('编译码后得到的信号波形');
    end
    snrq(k)=10*log10(mean(snr));
end

figure(2)
drawnow
subplot(2,1,1)
plot(t,x);
axis([0,0.8,-1,1]);
title('未编码信号波形');
subplot(2,1,2)
plot(t,yy);
axis([0,1.1,-1,1]);
title('编译码后得到的信号波形');

figure(3)
plot(vm1,snrq);
axis([-60,0,0,60]);
title('序列的量化信噪比');
grid on
