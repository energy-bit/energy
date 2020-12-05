clear all
close all
%����ԭ�ź�
t=0:0.0125:10;%8000����
vm1=-70:1:0;%����������źŵķ��Ȳ�ͬ
vm=10.^(vm1/20);%db--10����
figure(1)
for k=1:length(vm)
    for m=1:2
        x=vm(k)*sin(2*pi*t+2*pi*rand(1));%x����
        v=1;
        xx=x;%normalize
        sxx= floor(xx*4096);%���ڱ���floor
        y= pcm_encode(sxx);%PCM����
        yy= pcm_decode(y,v);%PCM����
        
        nq(m)=sum((x-yy).*(x-yy))/length(x);%��������
        sq(m)=mean(yy.^2);%�źŹ���
        snr(m)=(sq(m)/nq(m));%�����
        
        drawnow
        subplot(2,1,1)
        plot(t,x);
        title('δ�����źŲ���');
        subplot(2,1,2)
        plot(t,yy);
        title('�������õ����źŲ���');
    end
    snrq(k)=10*log10(mean(snr));
end

figure(2)
drawnow
subplot(2,1,1)
plot(t,x);
axis([0,0.8,-1,1]);
title('δ�����źŲ���');
subplot(2,1,2)
plot(t,yy);
axis([0,1.1,-1,1]);
title('�������õ����źŲ���');

figure(3)
plot(vm1,snrq);
axis([-60,0,0,60]);
title('���е����������');
grid on
