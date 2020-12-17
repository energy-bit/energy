#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdbool.h>
void BubbleSort(int *elem, int first, int last);
void BubbleSort_1(int *elem, int first, int last);
void QuickSort_1(int *elem, int first, int last);
void QuickSort_2(int *elem, int first, int last);
void QuickSort_3(int *elem, int first, int last);
void Swap(int *a, int *b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}

//Ã°ÅÝÅÅÐò
void BubbleSort(int *elem, int first, int last)
{
	for (int i = first; i<last - 1; ++i)
	{
		for (int j = first; j<last - i - 1; ++j)
		{
			if (elem[j] > elem[j + 1])
				Swap(&elem[j], &elem[j + 1]);
		}
	}
}

//Ã°ÅÝÅÅÐò_½»»»¸Ä½ø°æ
void BubbleSort_1(int *elem, int first, int last)
{
	bool is_swap = false;
	for (int i = first; i<last - 1; ++i)
	{
		for (int j = first; j<last - i - 1; ++j)
		{
			if (elem[j] > elem[j + 1])
			{
				Swap(&elem[j], &elem[j + 1]);
				is_swap = true;
			}
		}

		if (!is_swap)
			break;
		else
			is_swap = false;
	}
}

//¿ìËÙÅÅÐò
//hoare°æ±¾
int _Partition_1(int *elem, int first, int last)
{
	int key = elem[first];
	while (first < last)
	{
		while (first<last && elem[last] >= key)
			last--;
		Swap(&elem[last], &elem[first]);

		while (first<last && elem[first]<key)
			first++;
		Swap(&elem[last], &elem[first]);
	}
	return first;
}
void QuickSort_1(int *elem, int first, int last)
{
	if (first >= last - 1)
		return;

	int pos = _Partition_1(elem, first, last - 1);

	QuickSort_1(elem, first, pos);   //[   )
	QuickSort_1(elem, pos + 1, last);
}
//ÍÚ¿Ó·¨
int _Partition_2(int *elem, int first, int last)
{
	int key = elem[first];
	while (first < last)
	{
		while (first<last && elem[last] >= key)
			last--;
		elem[first] = elem[last];

		while (first<last && elem[first]<key)
			first++;
		elem[last] = elem[first];
	}
	elem[first] = key;
	return first;
}
void QuickSort_2(int *elem, int first, int last)
{
	if (first >= last - 1)
		return;

	int pos = _Partition_2(elem, first, last - 1);

	QuickSort_2(elem, first, pos);   //[   )
	QuickSort_2(elem, pos + 1, last);
}

void PrintElement(int *elem, int first, int last)
{
	for (int i = first; i<last; ++i)
		printf("%d ", elem[i]);
	printf("\n");
}
void main()
{
	int ar[] = { 10, 6, 7, 1, 3, 9, 4, 2 };
	//int ar[] = {49, 38, 5, 65, 97, 76, 13, 27, 49};
	//int ar[] = { 12482, 15804, 6044, 10888, 26446, 2762, 9119, 23855, 14976, 508 };
	//int ar[] = {0, 49, 38, 65, 97, 76, 13, 27, 49}; //ÉÚ±øÊý¾Ý
	//int ar[] = { 278, 109, 63, 930, 589, 184, 505, 269, 8, 83 };
	int n = sizeof(ar) / sizeof(ar[0]);
	PrintElement(ar, 0, n);
	//QuickSort_3(ar, 0, n);
	//QuickSort_2(ar, 0, n);
	BubbleSort(ar, 0, n);
	PrintElement(ar, 0, n);
}