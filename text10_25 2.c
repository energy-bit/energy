#define _CRT_SECURE_NO_WARNINGS 1
//��������в�ͬλ�ĸ���  �������� 1999  2299  ���Ϊ7
/*
#include <stdio.h>
int Numberof1(int a, int b)
{
	int count = 0;
	int n = a^b;
	while (n)
	{
		n = n&(n - 1);
		count++;
	}
	return count;
}
int main()
{
	int a = 0;
	int b = 0;
	scanf("%d%d", &a, &b);
	int ret = Numberof1(a, b);
	printf("%d",ret );
	return 0;
}
*/
//��ӡ�������е�����λ��ż��λ
//��ȡһ�����������������е�����λ��ż��λ�����Ҵ�ӡ��
/*
#include <stdio.h>
int main()
{
	int n = 0;
	scanf("%d", &n);
	int i = 0;
	//����λ
	for (i = 30; i >= 0; i -= 2)
	{
		printf("%d", (n >> i) & 1);
	}
	printf("\n");
	//ż��λ
	for (i = 31; i >= 1; i -= 2)
	{
		printf("%d", (n >> i) & 1);
	}
	return 0;
}
/*
#include <stdio.h>
int main()
{
	int  arr[10] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
	int *p = arr;
	int i = 0;
	for (i = 0; i < 10; i++)
	{
		printf("%d ",*(p + i));
	}
	
	return 0;
}
*/