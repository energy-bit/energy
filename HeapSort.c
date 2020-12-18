#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdbool.h>
#include <assert.h>
#define HeapDataType int

typedef struct Heap
{
	HeapDataType *base;
	int           capacity;
	int           size;
}Heap;
void Swap(int *a, int *b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}

void HeapInit(Heap *php, int n);
void MinHeapInsert(Heap *php, HeapDataType x);
HeapDataType MinHeapRemove(Heap *php);
bool HeapEmpty(Heap *php);
void HeapPrint(Heap *php);

void HeapSort(Heap *php);

void AdjustUp(HeapDataType *base, int start);
void AdjustDown(HeapDataType *base, int start, int n);

void HeapInit(Heap *php, int n)
{
	assert(php != NULL);
	php->base = (HeapDataType*)malloc(sizeof(HeapDataType)* n);
	assert(php->base != NULL);
	php->capacity = n;
	php->size = 0;
}

bool HeapEmpty(Heap *php)
{
	assert(php != NULL);
	return php->size == 0;
}

void MinHeapInsert(Heap *php, HeapDataType x)
{
	assert(php != NULL);
	if (php->size < php->capacity)
	{
		php->base[php->size] = x;

		//����ΪС�ѽṹ  �������ϵ���
		AdjustUp(php->base, php->size);
		php->size++;
	}
}

HeapDataType MinHeapRemove(Heap *php)
{
	assert(php != NULL);
	assert(php->size > 0);

	int heaptop_val = php->base[0];

	php->size--;
	php->base[0] = php->base[php->size];
	AdjustDown(php->base, 0, php->size);

	return heaptop_val;
}

void HeapPrint(Heap *php)
{
	for (int i = 0; i<php->size; ++i)
		printf("%d ", php->base[i]);
	printf("\n");
}

void AdjustUp(HeapDataType *base, int start)
{
	int j = start;
	int i = (j - 1) / 2;

	HeapDataType tmp = base[j];

	while (j > 0)
	{
		if (tmp < base[i])
		{
			base[j] = base[i]; //����
			j = i;
			i = (j - 1) / 2;
		}
		else
			break;
	}
	base[j] = tmp;
}

void AdjustDown(HeapDataType *base, int start, int n)
{
	int i = start;
	int j = 2 * i + 1;
	while (j < n)
	{
		if (j + 1<n && base[j]>base[j + 1]) //�ҳ�����������С��ֵ
			j++;
		if (base[i] > base[j])
		{
			Swap(&base[i], &base[j]);
			i = j;
			j = 2 * i + 1;
		}
		else
			break;
	}
}


void HeapSort(Heap *php, int ar[], int n)
{
	for (int i = 0; i<n; ++i)
		php->base[i] = ar[i];
	php->size = n;

	//������С��
	int curpos = n / 2 - 1; //�ҵ����һ����֧
	while (curpos >= 0)
	{
		AdjustDown(php->base, curpos, n);
		curpos--;
	}

	//����
	int end = n - 1;
	while (end > 0)
	{
		Swap(&php->base[0], &php->base[end]);
		AdjustDown(php->base, 0, end);
		end--;
	}
	//HeapPrint(php);
	int k = php->size - 1;
	for (int i = 0; i<n; ++i)
	{
		ar[i] = php->base[k--];
	}
}

/*
void AdjustUp(HeapDataType *base, int start)
{
int j = start;
int i = (j-1)/2;
while(j > 0)
{
if(base[j] < base[i])
{
Swap(&(base[j]), &(base[i]));
j = i;
i = (j-1)/2;
}
else
break;
}

*/
void main()
{
	int ar[] = { 27, 15, 19, 18, 28, 34, 65, 49, 25, 37 };
	int n = sizeof(ar) / sizeof(ar[0]); //
	Heap minheap;
	HeapInit(&minheap, n);
	for (int i = 0; i<n; ++i)
		MinHeapInsert(&minheap, ar[i]);
	HeapPrint(&minheap);
	while (!HeapEmpty(&minheap))
	{
		printf("%d ", MinHeapRemove(&minheap));
		//HeapPrint(&minheap);
	}
	printf("\n");
}