#define _CRT_SECURE_NO_WARNINGS 1
/*
��д����ʵ�֣���һ���������ڴ��еĶ�����1�ĸ�����
#include <stdio.h>
int find(int n)
{
	int count = 0;
	int i = 0;
	for (i = 0; i < 32; i++)
	{
		if ((n >> i & 1) == 1)
		{
			count++;
		}
	}
	printf("%d", count);
}
int main()
{
	int n = 0;
	scanf("%d", &n);
	 find(n);
	return 0;
}

�ڶ��ַ���
#include <stdio.h>
int Numberof1(unsigned int n)
{
	int count = 0;
	while (n)
	{

		if (n % 2 != 0)
		{
			count++;
		}
		n /= 2;
	}
		return count;
}
	int main()
	{
	int n = 0;
	scanf("%d", &n);
	int ret = Numberof1(n);
	printf("%d", ret);
	return 0;
}
*/
// �����ַ��� ��򵥵ķ���
/*
#include <stdio.h>
int Numberof1(int n)
{
	int count=0;
	while (n)
	{
		n = n&(n - 1);	
			count++;
	}
	return count;
}

int main()
{
	int n = 0;
	scanf("%d", &n);
	int ret = Numberof1(n);
	printf("%d", ret);
}
*/