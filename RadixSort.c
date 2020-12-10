#define _CRT_SECURE_NO_WARNINGS 1


#include<stdio.h>
#include<assert.h>
#include<stdbool.h>

#define K 3
#define RADIX 10
#include"list.h"

static SList list[RADIX];
//��������

// ���ñȽ� �õ�����  ��λ����  ����3λ��   �ͽ���λ��������Ӧ���������� ��ȡ����  �ڶ�ʮλ  �ڶ԰�λ��������˲���  
//����  278, 109, 63, 930, 589, 184, 505, 269, 8, 83 

///��һ�δӸ�λ��ʼ���ڶ�Ӧ���±�
//                                                         269
//                       83                          278   589
//��һ��  930            63   184  505                8    109      
//�����±�  0   1    2    3    4    5     6     7     8     9  

//  ���Ե�һ�λ��յ���Ϊ   930  63  83  184  505  8   278   109  589  269 
////////////////////////////////////////////////////////////////////////////////////////////////////////

// �ڶ���
//         109                                       589
//          8                            269         184
//         505           930              63   278    83
//�����±�  0   1    2    3    4    5     6     7     8       9   
//�ڶ��λ��յ���Ϊ     505   8    109   930  63   269  278  83   184   589
/////////////////////////////////////////////////////////////////////////////////////////////////////////
// ������
//          83
//          63  184  278            589
//          8   109  269            505                       930
//�����±�  0   1    2    3    4    5     6     7     8       9  
//�����λ��յ��� ��Ϊ    8  63  83  109  184  269  278  505  589  930     ������� 
/////////////////////////////////////////////////////////////////////////////////////////////////////////
void RadixSort(int *elem, int first, int last);

int _GetKey(int value, int k)
{
	int key;
	while (k >= 0)
	{
		key = value % 10; //0
		value /= 10;      //10
		k--;
	}
	return key;
}
void _Distribute(int *elem, int first, int last, int k)
{
	for (int i = first; i<last; ++i)
	{
		int key = _GetKey(elem[i], k);
		SListPushBack(&list[key], elem[i]);
	}
}
void _Collect(int *elem)
{
	int k = 0;
	for (int i = 0; i<RADIX; ++i)
	{
		SListNode *p = list[i].head;
		while (p != NULL)
		{
			elem[k++] = p->data;
			SListPopFront(&list[i]);
			p = list[i].head;
		}
	}
}
void RadixSort(int *elem, int first, int last)
{
	for (int i = 0; i<RADIX; ++i)
	{
		SListInit(&list[0]); //0 1 2 3 4 5 6 7 8 9
	}
	for (int i = 0; i<K; ++i)
	{
		//1 �ַ�
		_Distribute(elem, first, last, i);
		//2 ����
		_Collect(elem);
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
	//int ar[] = {12482, 15804, 6044, 10888, 26446, 2762, 9119, 23855, 14976, 508};
	//int ar[] = {0, 49, 38, 65, 97, 76, 13, 27, 49}; //�ڱ�����
	int ar[] = { 278, 109, 63, 930, 589, 184, 505, 269, 8, 83 };
	int n = sizeof(ar) / sizeof(ar[0]);
	PrintElement(ar, 0, n);
	RadixSort(ar, 0, n);
	PrintElement(ar, 0, n);
}