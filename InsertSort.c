#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
//≤Â»Î≈≈–Ú
void InsertSort(int *elem, int first, int last);
void InsertSort_1(int *elem, int first, int last);
void InsertSort_2(int *elem, int first, int last);
void BinInsertSort(int *elem, int first, int last);
void TwoWayInsertSort(int *elem, int first, int last);
void ShellSort(int *elem, int first, int last);

void Swap(int *a, int *b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}
//≤Â»Î≈≈–Ú
//÷±Ω”≤Â»Î≈≈–Ú - Ωªªª∞Ê
void InsertSort(int *elem, int first, int last)
{
	for (int i = first + 1; i<last; ++i)
	{
		int end = i;
		while (end>first && elem[end]<elem[end - 1])
		{
			Swap(&(elem[end]), &(elem[end - 1]));
			end--;
		}
	}
}
//÷±Ω”≤Â»Î≈≈–Ú - “∆∂Ø∞Ê
void InsertSort_1(int *elem, int first, int last)
{
	for (int i = first + 1; i<last; ++i)
	{
		int end = i;
		int tmp = elem[end];
		while (end>first && tmp<elem[end - 1])
		{
			elem[end] = elem[end - 1];
			end--;
		}
		elem[end] = tmp;
	}
}
//÷±Ω”≤Â»Î≈≈–Ú - …⁄±¯∞Ê
void InsertSort_2(int *elem, int first, int last)
{
	//int ar[] = {0, 49, 38, 65, 97, 76, 13, 27, 49}; //…⁄±¯ ˝æ›
	for (int i = first + 1; i<last; ++i)
	{
		elem[0] = elem[i];
		int end = i;
		while (elem[0] < elem[end - 1])
		{
			elem[end] = elem[end - 1];
			end--;
		}
		elem[end] = elem[0];
	}
}
//’€∞Î≤Â»Î≈≈–Ú
void BinInsertSort(int *elem, int first, int last)
{
	//int ar[] = {49, 38, 65, 97, 76, 13, 27, 49};
	for (int i = first + 1; i<last; ++i)
	{
		int tmp = elem[i];
		int low = first;
		int high = i - 1;
		while (low <= high)
		{
			int mid = (low + high) / 2;
			if (elem[mid] > tmp)
				high = mid - 1;
			if (elem[mid] <= tmp)
				low = mid + 1;
		}

		for (int j = i; j>low; --j)
			elem[j] = elem[j - 1];
		elem[low] = tmp;
	}
}

//∂˛¬∑≤Â»Î≈≈–Ú
void TwoWayInsertSort(int *elem, int first, int last)
{
	int n = last - first;
	int *tmp = (int*)malloc(sizeof(int)* n);
	tmp[0] = elem[0];
	int start, end;
	start = end = 0;

	for (int i = first + 1; i<last; ++i)
	{
		if (elem[i] < tmp[start])
		{
			start = (start - 1 + n) % n; //
			tmp[start] = elem[i];
		}
		else if (elem[i] >= tmp[end])
		{
			tmp[++end] = elem[i];
		}
		else
		{
			int j = end;
			while (elem[i] < tmp[j])
			{
				tmp[(j + 1) % n] = tmp[j];
				j = (j - 1 + n) % n;
			}
			tmp[(j + 1) % n] = elem[i];
			end++;
		}
	}

	int k = 0;
	for (int i = start; k<n; i = (i + 1) % n)
		elem[k++] = tmp[i];

	free(tmp);
}
//œ£∂˚≈≈–Ú
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
	int ar[] = {10, 6, 7, 1, 3, 9, 4, 2};
	//int ar[] = {49, 38, 5, 65, 97, 76, 13, 27, 49};
	//int ar[] = { 12482, 15804, 6044, 10888, 26446, 2762, 9119, 23855, 14976, 508 };
	//int ar[] = {0, 49, 38, 65, 97, 76, 13, 27, 49}; //…⁄±¯ ˝æ›
	//int ar[] = { 278, 109, 63, 930, 589, 184, 505, 269, 8, 83 };
	int n = sizeof(ar) / sizeof(ar[0]);
	PrintElement(ar, 0, n);
	ShellSort(ar, 0, n);
	PrintElement(ar, 0, n);
	
	InsertSort(ar, 0, n);
	PrintElement(ar, 0, n);
	
	InsertSort_1(ar, 0, n);
	PrintElement(ar, 0, n);
	
	InsertSort_2(ar, 0, n);
	PrintElement(ar, 0, n);
	/*
	BinInsertSort(ar, 0, n);
	PrintElement(ar, 0, n);

	TwoWayInsertSort(ar, 0, n);
	PrintElement(ar, 0, n);

	ShellSort(ar, 0, n);
	PrintElement(ar, 0, n);
	*/
}
