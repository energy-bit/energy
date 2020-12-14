#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
//快速排序
void QuickSort_1(int *elem, int first, int last);
void QuickSort_2(int *elem, int first, int last);
void QuickSort_3(int *elem, int first, int last);

//hoare版本

void Swap(int *a, int *b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}


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
//挖坑法
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

//前后指针法
//三数取中法改进快速排序
int GetMidIndex(int *elem, int first, int last)
{
	int mid = (first + last) / 2;
	if (elem[first]>elem[last] && elem[first]<elem[mid])
		return first;
	else if (elem[last]>elem[first] && elem[last]<elem[mid])
		return last;
	return mid;
}

#define M 25

int _Partition_3(int *elem, int first, int last)
{
	int index = GetMidIndex(elem, first, last);
	if (index != first)
		Swap(&elem[index], &elem[first]);

	int key = elem[first];
	int pos = first;
	for (int i = first + 1; i <= last; ++i)
	{
		if (elem[i] < key)
		{
			pos++;
			if (pos != i)
			{
				Swap(&elem[pos], &elem[i]);
			}
		}
	}
	Swap(&elem[first], &elem[pos]);
	return pos;
}
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
void QuickSort_3(int *elem, int first, int last)
{
	if (first >= last - 1)
		return;

	if (last - first <= M)
		InsertSort_1(elem, first, last);
	else
	{
		int pos = _Partition_3(elem, first, last - 1);

		QuickSort_3(elem, first, pos);   //[   )
		QuickSort_3(elem, pos + 1, last);
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
	int ar[] = { 10, 6, 7, 1, 3, 9, 4, 2 };
	//int ar[] = {49, 38, 5, 65, 97, 76, 13, 27, 49};
	//int ar[] = { 12482, 15804, 6044, 10888, 26446, 2762, 9119, 23855, 14976, 508 };
	//int ar[] = {0, 49, 38, 65, 97, 76, 13, 27, 49}; //哨兵数据
	//int ar[] = { 278, 109, 63, 930, 589, 184, 505, 269, 8, 83 };
	int n = sizeof(ar) / sizeof(ar[0]);
	PrintElement(ar, 0, n);
	//QuickSort_3(ar, 0, n);
	//QuickSort_2(ar, 0, n);
	QuickSort_1(ar, 0, n);
	PrintElement(ar, 0, n);
}