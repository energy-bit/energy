#define _CRT_SECURE_NO_WARNINGS 1
//求二进制中不同位的个数  输入例子 1999  2299  输出为7
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
//打印二进制中的奇数位和偶数位
//获取一个整数二进制序列中的奇数位和偶数位，并且打印。
/*
#include <stdio.h>
int main()
{
	int n = 0;
	scanf("%d", &n);
	int i = 0;
	//奇数位
	for (i = 30; i >= 0; i -= 2)
	{
		printf("%d", (n >> i) & 1);
	}
	printf("\n");
	//偶数位
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