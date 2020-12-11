#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
//Ï£¶ûÅÅÐò
void ShellSort(int *elem, int first, int last)
{
	int dk = last - first;
	while (dk > 1)
	{
		dk = dk / 3 + 1;
		for (int i = first; i<last - dk; ++i)
		{
			if (elem[i + dk] < elem[i])
			{
				int end = i;
				int tmp = elem[end + dk];
				while (end >= first && tmp<elem[end])
				{
					elem[end + dk] = elem[end];
					end -= dk;
				}
				elem[end + dk] = tmp;
			}
		}
	}
}
void PrintElement(int *elem, int first, int last)
{
	for (int i = first; i<last; ++i)
		printf("%d ", elem[i]);
	printf("\n");
}

void main()
{
	//int ar[] = {10, 6, 7, 1, 3, 9, 4, 2};
	//int ar[] = {49, 38, 5, 65, 97, 76, 13, 27, 49};
	int ar[] = {12482, 15804, 6044, 10888, 26446, 2762, 9119, 23855, 14976, 508};
	//int ar[] = {0, 49, 38, 65, 97, 76, 13, 27, 49}; //ÉÚ±øÊý¾Ý
	//int ar[] = { 278, 109, 63, 930, 589, 184, 505, 269, 8, 83 };
	int n = sizeof(ar) / sizeof(ar[0]);
	PrintElement(ar, 0, n);
	ShellSort(ar, 0, n);
	PrintElement(ar, 0, n);
	
}
