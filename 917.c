#define _CRT_SECURE_NO_WARNINGS 1
//���n��쳲����������������������
//�õݹ���� ����Ĵ���  Ч�ʺܵͣ����Բ�������
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

//   ����ѭ���ҵ�n��쳲�������   Ч�ʸ���
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
* @param n int����
* @return int����
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

////    ð������
//#include <stdio.h>
//void sort(int* arr[],int sz)
//{
//	
//	int i = 0;
//	//ȷ��ð�����������
//	for (i = 0; i < sz - 1; i++)
//	{
//		//һ��ð������
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
// ��д����ʵ�֣���һ���������ڴ��еĶ�����1�ĸ�����
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
    //��100��200֮�������
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
//    ���ַ������Ŵ�ӡ����
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

//  �ݹ�ʵ�� �������  1234  ���ӡ1+2+3+4=10  ��ӡ��10
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
//}��д����ʵ�֣���һ���������ڴ��еĶ�����1�ĸ�����
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
//�ڶ��ַ���
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
// �����ַ��� ��򵥵ķ���
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

//��������в�ͬλ�ĸ���  �������� 1999  2299  ���Ϊ7
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
//��ӡ�������е�����λ��ż��λ
//��ȡһ�����������������е�����λ��ż��λ�����Ҵ�ӡ��
//#include <stdio.h>
//int main()
//{
//	int n = 0;
//	scanf("%d", &n);
//	int i = 0;
//	//����λ
//	for (i = 30; i >= 0; i -= 2)
//	{
//		printf("%d", (n >> i) & 1);
//	}
//	printf("\n");
//	//ż��λ
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
//   ���ַ�������
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

//     �� Sn=a+aa+aaa+aaaa+aaaa��ǰ����֮��  ����a��һ�����֡�
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
//    ��ӡ���� 
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
//	//��ӡ�ϰ벿��
//	int i = 0;
//	for (i = 0; i < line; i++)
//	{
//		//��ӡһ��
//		//��ӡ�ո�
//		int j = 0;
//		for (j = 0; j < line - 1 - i; j++)
//		{
//			printf(" ");
//		}
//		//��ӡ*
//		for (j = 0; j< 2 * i + 1; j++)
//		{
//			printf("*");
//		}
//		printf("\n");
//	}
//	//��ӡ�°���
//	for (i = 0; i < line-1; i++)
//	{
//		//��ӡһ��
//		//��ӡ�ո�
//		int j = 0;
//		for (j = 0; j <= i; j++)
//		{
//			printf(" ");
//		}
//		//��ӡ*
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
//	int(*pa)[];  //����   ָ��ָ�������
//		int(*pfun)(); //����ָ��   ָ��ָ������
//		pfun = &fun;
//		(*pfun)();
//		pfun = fun;
//		pfun();
//}

/*
int main()
{
	printf("%p\n", fun);//  �����������ŵ�ʱ�� ��ӡ���Ǻ����ĵ�ַ 
	printf("%p\n", &fun);//ȥ�����ĵ�ַ
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

//    ��������   
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
//	qsort(ar,n, sizeof(ar[0]), compare);//    ���ź���
//	PrintfArray(ar, n);
//}

//#include <stdio.h>
//int main()
//{
//	//int arr[3][2] = { (0, 1), (2, 3), (4, 5) };// ���ű��ʽ   ֻȡ������� ����ȡ 1 3  5
//	int  arr[3][2] = { { 0, 1 }, { 2, 3 }, { 4, 5 } };//   ����  p[0]�ʹ�ӡ����0��  
//	int *p;
//	p = arr[0];
//	printf("%d\n", p[0]);//   �� ������ 1  ��
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
//	printf("str len=%d\n", strlen(ar));//����  5
//	printf("str size=%d\n", sizeof(ar));//��С  6 ��\0
//	char ar1[10] = "Holle";
//	printf("str len=%d\n", strlen(ar1));//����  5
//	printf("str size=%d\n", sizeof(ar1));//��С  10
//	char ar2[10] = { 'H', 'o', 'l', 'l', 'e' };
//	printf("str len=%d\n", strlen(ar2));//����  5
//	printf("str size=%d\n", sizeof(ar2));//��С  10
//	char ar3[] = { 'H', 'o', 'l', 'l', 'e' };
//	printf("str len=%d\n", strlen(ar3));//����  ���
//	printf("str size=%d\n", sizeof(ar3));//��С  5
//
//	return 0;
////}
//#include <stdio.h>
//int main()
//{
//	char ar[] = "holle";//  ��ı��ܱ�����  ���ñ���   
//	char *ar1 = "bit";//   һ��Ҫ��* ��Ȼ���ܽ��п���   ����ı�  ��Ҫ��ָ����ַ�������
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
//	char *Src = "xyz";//  ����  xyz 
//	char *res = strstr(Dest, Src);//  strstr �ַ�������  �ҵ�xyz  
//	printf("res=%s\n", res);//  ��ӡxyz������������
//	return 0;
//}
//#include <stdio.h>
//#include <string.h>
//int main()
//{
//	char Dest[] = "abc xyz lmn jl Sre";//Ҫ�ı�ֻ�����������  ������*Destָ�볣�� 
//	char *Src;
//	Src = strstr(Dest, "xyz"); //�ҵ� xyz
//	strncpy(Src, "aaa", 3);// �����ַ���   strncpy   �м��n�ǿ��������ַ� ��aaa�������ҵ���xyz
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
//	//��������Ľ����ʲô��
//	printf("%d\n", sizeof(union Un1));
//	printf("%d\n", sizeof(union Un2));
//}





















































































































































































































