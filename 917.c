#define _CRT_SECURE_NO_WARNINGS 1
//求第n个斐波那契数。（不考虑溢出）
//用递归就是 下面的代码  效率很低，所以不建议用
//#include <stdio.h>
//int Fib(int n)
//{
//	if (n <= 2)
//		return 1;
//	else
//		return Fib(n - 1) + Fib(n - 2);
//
//}
//int main()
//{
//	int n = 0;
//	scanf("%d", &n);
//	int ret = Fib(n);
//	printf("%d\n", ret);
//	return 0;
//}

//   利用循环找第n个斐波那契数   效率更高
//
//#include <stdio.h>
//int Fib(int n)
//{
//	int a = 1;
//	int b = 1;
//	int c = 1;
//	while (n > 2)
//	{
//		c = a + b;
//		a = b;
//		b = c;
//		n--;
//	}
//	return c;
//}
//int main()
//{
//	int n = 0;
//	scanf("%d", &n);
//	int ret = Fib(n);
//	printf("%d\n", ret);
//	return 0;
//}
//
/**
*
* @param n int整型
* @return int整型
*/
//int Fibonacci(int n) {
//	// write code here
//	if (n == 0) return 0;
//	if (n == 1) return 1;
//
//	int first = 0;
//	int second = 1;
//	int ret = 0;
//
//	for (int i = 2; i <= n; ++i){
//		ret = first + second;
//		first = second;
//		second = ret;
//	}
//
//	return ret;
//}
//int main()
//{
//	int n = 0;
//	scanf("%d", &n);
//	int ret=Fibonacci(n);
//	printf("%d\n", ret);
//}
//#include <stdio.h>
//int main()
//{
//	int arr[3][4] = { { 1, 2 }, { 3, 4 }, { 5 } };
//	int i = 0;
//	for (i = 0; i < 3; i++)
//	{
//		int j = 0;
//		for (j = 0; j < 4; j++)
//		{
//			printf("%d ", arr[i][j]);
//
//		}
//		printf("\n");
//	}
//	return 0;
//}

////    冒泡排序
//#include <stdio.h>
//void sort(int* arr[],int sz)
//{
//	
//	int i = 0;
//	//确定冒泡排序的趟数
//	for (i = 0; i < sz - 1; i++)
//	{
//		//一趟冒泡排序
//		int j = 0;
//		for (j = 0; j<sz - 1 - i; j++)
//		{
//
//			if (arr[j]>arr[j + 1])
//			{
//				int tmp = arr[j];
//				arr[j] = arr[j + 1];
//				arr[j + 1] = tmp;
//			}
//		}
//	}	
//}
//void printArr(int*arr, int sz)
//{
//	int i = 0;
//	for (i = 0; i < sz; i++)
//	{
//		printf("%d ", arr[i]);
//	}
//	printf("\n");
//}
//int main()
//{
//	int arr[10] = { 10, 9, 8, 7, 6, 5, 4, 3, 2, 1 };
//	int sz = sizeof(arr) / sizeof(arr[0]);
//	printArr(arr, sz);
//	sort(arr,sz);
//	printArr(arr, sz);
//	return 0;
//}
// 编写代码实现，求一个整数在内存中的二进制1的个数。
//#include <stdio.h>
//int main()
//{
//	int n = 0;
//	int count = 0;
//	scanf("%d", &n);
//	int i = 0;
//	for (i = 0; i < 32;i++)
//	{
//		if ((n>>i& 1)==1)
//		{
//			count++;	
//		}
//		
//	}
//	printf("%d", count);
//	return 0;
//}

//#include <stdio.h>
//int main()
//{
//	int i = 0;
//	for (i = 100; i <= 200; i++)
//	{
//		int j = 0;
//		for (j = 2; j <= i; j++)
//		{
//			if (i%j == 0)
//			{
//				break;
//			}
//			 
//		}
//		if (i == j)
//		{
//			printf("%d ", i);
//		}
//	}
//	return 0;
//}
    //求100到200之间的素数
//#include <stdio.h>
//int is_prime(int n)
//{
//	int i = 0;
//	for (i = 2; i < n; i++)
//	{
//		if (n%i == 0)
//			return 0;
//	}
//	return 1;
//}
//int main()
//{
//	int i = 0;
//	for (i = 100; i <= 200; i++)
//	{
//		if (is_prime(i) == 1)
//		{
//			printf("%d ", i);
//		}
//	}
//	return 0;
//}
//#include <stdio.h>
//int main()
//{
//	int line = 0;
//	scanf("%d", &line);
//	int i = 0;
//	for (i = 1; i <= line; i++)
//	{
//		int j = 0;
//		for(j = 1; j <=i; j++)
//		{
//			printf("% d*%d=% -2d", i, j, i*j);
//		}
//		printf("\n");
//	}
//	return 0;
//}
//    是字符串反着打印出来
//#include <stdio.h>
//#include <string.h>
//char reverse_string(char arr[],int sz)
//{
//	int left = 0;
//	int right = sz - 1;
//	while (left < right)
//	{
//		char tmp = arr[left];
//		arr[left] = arr[right];
//		arr[right] = tmp;
//		left++;
//		right--;
//	}
//	
//}
//int main()
//{
//	char arr[]="holle bit";
//	int sz = strlen(arr);
//	printf("%d\n", sz);
//	reverse_string(arr,sz);
//	printf("%s", arr);
//	return 0;
//}
//#include<stdio.h>
//#include <string.h>
//char reverse_string(char arr[1000], int sz)
//{
//	int left = 0;
//	int right = sz - 1;
//	while (left<right)
//	{
//		char tmp = arr[left];
//		arr[left] = arr[right];
//		arr[right] = tmp;
//		left++;
//		right--;
//	}
//}
//int main()
//{
//	char arr[1000] = "abcd";
//	int sz = strlen(arr);
//
//	reverse_string(arr, sz);
//	printf("%s\n", arr);
//
//	return 0;
//}

//  递归实现 如果输入  1234  则打印1+2+3+4=10  打印出10
//#include <stdio.h>
//unsigned Digitsum(int n)
//{
//	if (n > 9)
//	{
//		return Digitsum(n / 10) + n % 10;
//	}
//	else
//	{
//		return n;
//	}
//}
//int main()
//{
//	unsigned int n = 0;
//	scanf("%d", &n);
//	int ret = Digitsum(n);
//	printf("%d", ret);
//	return 0;
//}
//}编写代码实现，求一个整数在内存中的二进制1的个数。
//#include <stdio.h>
//int find(int n)
//{
//	int count = 0;
//	int i = 0;
//	for (i = 0; i < 32; i++)
//	{
//		if ((n >> i & 1) == 1)
//		{
//			count++;
//		}
//	}
//	printf("%d", count);
//}
//int main()
//{
//	int n = 0;
//	scanf("%d", &n);
//	 find(n);
//	return 0;
//}
//
//第二种方法
//#include <stdio.h>
//int Numberof1(unsigned int n)
//{
//	int count = 0;
//	while (n)
//	{
//
//		if (n % 2 != 0)
//		{
//			count++;
//		}
//		n /= 2;
//	}
//		return count;
//}
//	int main()
//	{
//	int n = 0;
//	scanf("%d", &n);
//	int ret = Numberof1(n);
//	printf("%d", ret);
//	return 0;
//}
// 第三种方法 最简单的方法
//#include <stdio.h>
//int Numberof1(int n)
//{
//	int count=0;
//	while (n)
//	{
//		n = n&(n - 1);	
//			count++;
//	}
//	return count;
//}
//
//int main()
//{
//	int n = 0;
//	scanf("%d", &n);
//	int ret = Numberof1(n);
//	printf("%d", ret);
//}

//求二进制中不同位的个数  输入例子 1999  2299  输出为7
//#include <stdio.h>
//int Numberof1(int a, int b)
//{
//	int count = 0;
//	int n = a^b;
//	while (n)
//	{
//		n = n&(n - 1);
//		count++;
//	}
//	return count;
//}
//int main()
//{
//	int a = 0;
//	int b = 0;
//	scanf("%d%d", &a, &b);
//	int ret = Numberof1(a, b);
//	printf("%d",ret );
//	return 0;
//}
//打印二进制中的奇数位和偶数位
//获取一个整数二进制序列中的奇数位和偶数位，并且打印。
//#include <stdio.h>
//int main()
//{
//	int n = 0;
//	scanf("%d", &n);
//	int i = 0;
//	//奇数位
//	for (i = 30; i >= 0; i -= 2)
//	{
//		printf("%d", (n >> i) & 1);
//	}
//	printf("\n");
//	//偶数位
//	for (i = 31; i >= 1; i -= 2)
//	{
//		printf("%d", (n >> i) & 1);
//	}
//	return 0;
//}
//#include <stdio.h>
//int main()
//{
//	int  arr[10] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
//	int *p = arr;
//	int i = 0;
//	for (i = 0; i < 10; i++)
//	{
//		printf("%d ",*(p + i));
//	}
//	
//	return 0;
//}
//   让字符串逆序
//#include <stdio.h>
//void reverse(char* str)
//{
//	int len = strlen(str);
//	char* left = str;
//	char*right = str+len - 1;
//	char temp=0;
//	while (left < right)
//	{
//		temp = *left;
//		*left = *right;
//		*right = temp;
//		left++;
//		right--;
//	}
//}
//int main()
//{
//	char arr[] = "abcdef";
//	reverse(arr);
//	printf("%s",arr);
//	return 0;
//}

//     求 Sn=a+aa+aaa+aaaa+aaaa的前五项之和  其中a是一个数字。
//#include <stdio.h>
//int main()
//{
//	int a = 0;
//	int n = 0;
//	int sum = 0;
//	int ret = 0;
//	int i = 0;
//	scanf("%d%d", &a, &n);
//	for (i = 0; i <= n; i++)
//	{
//		ret = ret * 10 + a;
//		sum = sum + ret;
//	}
//	printf("%d", sum);
//	return 0;
//}
//    打印菱形 
//          *
//         ***
//        *****
//         ***
//          *
//#include <stdio.h>
//int main()
//{
//	int line = 0;
//	scanf("%d", &line);
//	//打印上半部分
//	int i = 0;
//	for (i = 0; i < line; i++)
//	{
//		//打印一行
//		//打印空格
//		int j = 0;
//		for (j = 0; j < line - 1 - i; j++)
//		{
//			printf(" ");
//		}
//		//打印*
//		for (j = 0; j< 2 * i + 1; j++)
//		{
//			printf("*");
//		}
//		printf("\n");
//	}
//	//打印下半行
//	for (i = 0; i < line-1; i++)
//	{
//		//打印一行
//		//打印空格
//		int j = 0;
//		for (j = 0; j <= i; j++)
//		{
//			printf(" ");
//		}
//		//打印*
//		for (j = 0; j< 2 * (line-1-i)-1; j++)
//		{
//			printf("*");
//		}
//		printf("\n");
//	}
//	return 0;
//}
//#include <stdio.h>
//int fun()
//{
//	printf("Holle bit\n");
//}
//int Max(int a, int b)
//{
//	return (a > b ? a : b);
//}
//void main()
//{
//	int(*pa)[];  //数组   指针指向数组的
//		int(*pfun)(); //函数指针   指针指向函数的
//		pfun = &fun;
//		(*pfun)();
//		pfun = fun;
//		pfun();
//}

/*
int main()
{
	printf("%p\n", fun);//  函数不带括号的时候 打印的是函数的地址 
	printf("%p\n", &fun);//去函数的地址
}
*/
//#include <stdio.h>
//int main()
//{
//	int a;
//	int *a;
//	int **a;
//	int a[10];
//	int *a[10];
//	int(*a)[10];
//	int(*a)(int);
//	int(*a[10])(int);
//}

//    快速排序   
//#include <stdio.h>
//#include <stdlib.h>
//PrintfArray(int ar[], int n)
//{
//	int i = 0;
//	for (i = 0; i < n; i++)
//	{
//		printf("%d ", ar[i]);
//	}
//	printf("\n");
//}
//int compare(const void *elem1, const void *elem2)
//{
//	return (*(int*)elem1 - *(int*)elem2);
//}
//int main() 
//{
//	int ar[] = { 3, 4, 5, 73, 32, 6, 7, 31, 22, 8, 9, 10, 2, 1 };
//	int n = sizeof(ar) / sizeof(ar[0]);
//	PrintfArray(ar, n);
//	qsort(ar,n, sizeof(ar[0]), compare);//    快排函数
//	PrintfArray(ar, n);
//}

//#include <stdio.h>
//int main()
//{
//	//int arr[3][2] = { (0, 1), (2, 3), (4, 5) };// 逗号表达式   只取后面的数 所以取 1 3  5
//	int  arr[3][2] = { { 0, 1 }, { 2, 3 }, { 4, 5 } };//   这样  p[0]就打印的是0了  
//	int *p;
//	p = arr[0];
//	printf("%d\n", p[0]);//   第 不就是 1  了
//}
//#include<stdio.h>
//int main()
//{
//	int a[4] = { 1, 2, 3, 4 };
//	int *ptr1 = (int*)(&a + 1);
//	int *ptr2 = (int*)((int)a + 1);
//	printf("%x,%x", ptr1[-1], *ptr2);
//}
//
//
//#include <stdio.h>
//int main()
//{
//	char ar[] = "Holle";
//	printf("str len=%d\n", strlen(ar));//长度  5
//	printf("str size=%d\n", sizeof(ar));//大小  6 有\0
//	char ar1[10] = "Holle";
//	printf("str len=%d\n", strlen(ar1));//长度  5
//	printf("str size=%d\n", sizeof(ar1));//大小  10
//	char ar2[10] = { 'H', 'o', 'l', 'l', 'e' };
//	printf("str len=%d\n", strlen(ar2));//长度  5
//	printf("str size=%d\n", sizeof(ar2));//大小  10
//	char ar3[] = { 'H', 'o', 'l', 'l', 'e' };
//	printf("str len=%d\n", strlen(ar3));//长度  随机
//	printf("str size=%d\n", sizeof(ar3));//大小  5
//
//	return 0;
////}
//#include <stdio.h>
//int main()
//{
//	char ar[] = "holle";//  想改变能被拷贝  就用变量   
//	char *ar1 = "bit";//   一定要加* 不然不能进行拷贝   不想改变  就要用指针成字符串常量
//	printf("%s\n", ar);
//	strcpy(ar, ar1);
//	printf("%s\n", ar);
//
//	return 0;
//}
//#include <stdio.h>
//#include <string.h>
//int main()
//{
//	char *Dest = "abc xyz lmn jl Sre";
//	char *Src = "xyz";//  查找  xyz 
//	char *res = strstr(Dest, Src);//  strstr 字符串查找  找到xyz  
//	printf("res=%s\n", res);//  打印xyz及其后面的内容
//	return 0;
//}
//#include <stdio.h>
//#include <string.h>
//int main()
//{
//	char Dest[] = "abc xyz lmn jl Sre";//要改变只能是数组变量  不能是*Dest指针常量 
//	char *Src;
//	Src = strstr(Dest, "xyz"); //找到 xyz
//	strncpy(Src, "aaa", 3);// 拷贝字符串   strncpy   中间的n是拷贝几个字符 用aaa代替了找到的xyz
//	puts(Dest);
//	return 0;
//}

//#include < stdio.h>
//#include <stdlib.h>
//#include <time.h>
//int main()
//{
//	int count;
//	srand((unsigned)time(NULL));
//	for (count = 0; count < 10; count++)
//	{
//		srand(count + 1);
//		printf("%d\n", rand());
//	}
//	printf("\n");
//	return 0;
//}
//#include <stdio.h>
//typedef struct Test
//{
//	double q;
//	short w;
//	char r;
//}Test;
//int main()
//{
//	printf("%d\n", sizeof(Test));
//	return 0;
//}
//#include <stdio.h>
//#include <stdlib.h>
//int main()
//{
//	int n;
//	printf("input n:>");
//	scanf("%d", &n);
//	int *ar =(int *) malloc(sizeof(int)*n);
//	return 0;
//}
//#include <stdio.h>
//
//
//int main()
//{
//	int i = 0;
//	int arr[10] = { 0 };
//	int sz = sizeof(arr) / sizeof(arr[0]);
//	for (i = 0; i < sz; i++)
//	{
//		scanf("%d", &arr[i]);
//	}
//	int tep = arr[0];
//	printf("%d", arr[0]);
//	for (i = 0; i < sz-1; i++)
//	{
//		tep = tep + arr[i + 1];
//		
//		printf("%d ", tep);	
//	}
//
//}
//#include <stdio.h>
//int main()
//{
//	union Un1
//	{
//		char c[5];
//		int i;
//	};
//	union Un2
//	{
//		short c[7];
//		int i;
//	};
//	//下面输出的结果是什么？
//	printf("%d\n", sizeof(union Un1));
//	printf("%d\n", sizeof(union Un2));
//}





















































































































































































































