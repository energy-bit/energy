#ifndef _SEQLIST_H_
#define _SEQLIST_H_

#include "common.h" 
#define SEQLIST_DEFAULT_SIZE 8  //Ĭ��������С�ռ�   ����8��
// ����˳���ṹ
typedef struct SeqList
{
	ElemType *base;    //int *base
	size_t capacity;   // ����
	size_t size;       // ��С
}SeqList;
////////////////////////////////////////////
//���������ӿ�
void SeqListInit(SeqList*pst);
bool IsFull(SeqList*pst);//�Ƿ�ռ�����
bool IsEmpty(SeqList*pst);//�Ƿ�Ϊ��
void SeqListPushBack(SeqList*pst, ElemType x);//   ����β�庯��
void SeqListPushFront(SeqList*pst, ElemType x);//ͷ��
void SeqListPopBack(SeqList*pst);// βɾ
void SeqListPopFront(SeqList*pst);//  ͷɾ
void SeqListInsertByPos(SeqList*pst, int pos, ElemType x);//��λ�ò���
void SeqListDeleteBypos(SeqList*pst, int pos);     //��λ��ɾ��
void  SeqListInsertByVal(SeqList*pst, ElemType x);// ��ֵ����
void SeqListSort(SeqList*pst);//  ����
int  SeqListFind(SeqList*pst, ElemType key);//����
void SeqListDeleteByval(SeqList*pst, ElemType key);//��ֵɾ��
size_t SeqListLength(SeqList*pst);//  ˳�����
size_t SeqListCapacity(SeqList*pst);// ˳�������
void SeqListClear(SeqList*pst);//  ���
void SeqListShow(SeqList*pst);//  ����չʾ����
void SepListDestroy(SeqList*pst);
////////////////////////////////////////////
//�����ӿ�ʵ��
void SeqListInit(SeqList *pst)
{
	assert(pst != NULL);
	//ElemType ����
	pst->base = (ElemType*)malloc(sizeof(ElemType)*SEQLIST_DEFAULT_SIZE);
	assert(pst->base != NULL);
	memset(pst->base, 0, SEQLIST_DEFAULT_SIZE);
	pst->capacity = SEQLIST_DEFAULT_SIZE;
	pst->size = 0;
}
bool IsFull(SeqList*pst)//�ж��Ƿ�ռ�����ʵ��
{
	assert(pst != NULL);
	return pst->size >= pst->capacity;  //Ԫ�ظ��������˿ռ�������
}
bool IsEmpty(SeqList*pst)//�Ƿ�Ϊ��
{
	assert(pst != NULL);
	return pst->size == 0;  //
}
void SeqListPushBack(SeqList*pst, ElemType x)// ʵ��β�庯��
{
	assert(pst != NULL);
	if (IsFull(pst))
	{
		printf("˳���ռ����������ܲ�������%d\n", x);
		return;
	}
	pst->base[pst->size] = x;
	//  ��������   1 2 3 4 5 . . .    //��СΪ5  ������Ҫ����������±���պ�Ϊ���ݵĴ�Сsize
	//  �±�       0 1 2 3 4 5 6 7 
	pst->size++;//  ��һ����   ���ݴ�Сsize ���
}
void SeqListPushFront(SeqList*pst, ElemType x)//  ͷ��ʵ��
{
	assert(pst != NULL);
	if (IsFull(pst))
	{
		printf("˳���ռ�����������ͷ����������%d\n", x);
		return;
	}
	for (size_t i = pst->size; i > 0; --i)
	{
		pst->base[i] = pst->base[i - 1];   //Ҫͷ�� Ҫ��ǰ������ݶ�������һλ
	}
	pst->base[0] = x;  //����������ݷ��ڵ�һ��
	pst->size++;
}
void SeqListPopBack(SeqList*pst) //  βɾʵ��
{
	assert(pst != NULL);
	if (IsEmpty(pst))
	{
		printf("˳���Ϊ�գ�����β��ɾ��\n");
		return;
	}
	pst->size--;  //  ֻ��Ҫ��С��һ��   ��Ϊ��һ���������������ԭ�������Ǹ�ֵ����
}
void SeqListPopFront(SeqList*pst)//  ͷ��ɾ������ʵ��
{
	assert(pst != NULL);
	if (IsEmpty(pst))
	{
		printf("˳���Ϊ�գ�����ͷ��ɾ��\n");
		return;
	}
	for (size_t i = 0; i < pst->size; i++)
	{
		pst->base[i] = pst->base[i + 1];
	}
	pst->size--;
}
void SeqListInsertByPos(SeqList*pst, int pos, ElemType x) //��λ�ò�������
{
	assert(pst != NULL);
	if (pos<0 || pos>pst->size)
	{
		printf("Ҫ�����λ�÷Ƿ� �����ܲ���\n");
		return;
	}
	if (IsFull(pst))
	{
		printf("˳���ռ����������ܰ�λ�ò�������%d\n", x);
		return;
	}
	for (int i = pst->size; i > pos; --i)
	{
		pst->base[i] = pst->base[i - 1];
	}
	pst->base[pos] = x;
	pst->size++;
}
void SeqListDeleteBypos(SeqList*pst, int pos)
{
	assert(pst != NULL);
	if (IsEmpty(pst))
	{
		printf("˳���Ϊ�գ����ܰ�λɾ��\n");
		return;
	}
	if (pos<0 || pos >= pst->size)
	{
		printf("Ҫɾ����λ�÷Ƿ� ������ɾ��\n");
		return;
	}
	for (int i = pos; i < pst->size - 1; i++)
	{
		pst->base[i] = pst->base[i + 1];
	}
	pst->size--;
}
void  SeqListInsertByVal(SeqList*pst, ElemType x)//  ��ֵ����
{
	/*
	��һ�ַ���
	assert(pst != NULL);
	// ��ǰ����Ƚ�
	if (IsFull(pst))
	{
	printf("˳���ռ����������ܲ�������%d\n", x);
	return;
	}
	int pos = 0;//λ��
	int i;
	for ( i = 0; i < pst->size; i++)
	{

	if (x<pst->base[i])
	{
	pos = i;
	break;
	}
	}
	if (i >= pst->size)
	{
	pos = i;
	}
	SeqListInsertByPos(pst, pos, x);
	*/

	//�ڶ��ַ���
	assert(pst != NULL);
	// �Ӻ���ǰ�Ƚ�
	if (IsFull(pst))
	{
		printf("˳���ռ����������ܲ�������%d\n", x);
		return;
	}
	int end = pst->size;
	while (end > 0 && x < pst->base[end - 1])

	{
		pst->base[end] = pst->base[end - 1];
		end--;
	}
	pst->base[end] = x;
	pst->size++;
}
void SeqListSort(SeqList*pst)//  ˳�������
{
	assert(pst != NULL);
	if (pst->size <= 1)
	{
		return;
	}
	for (int i = 0; i < pst->size - 1; i++)
	{
		for (int j = 0; j < pst->size - i - 1; j++)
		{
			if (pst->base[j]>pst->base[j + 1])
			{
				ElemType tmp = pst->base[j];
				pst->base[j] = pst->base[j + 1];
				pst->base[j + 1] = tmp;
			}
		}
	}
}

size_t SeqListLength(SeqList*pst) //����
{
	assert(pst != NULL);
	return pst->size;
}
size_t SeqListCapacity(SeqList*pst)// ����
{
	assert(pst != NULL);
	return pst->capacity;
}
int SeqListFind(SeqList*pst, ElemType key)//  ����
{
	assert(pst != NULL);
	for (int i = 0; i < pst->size; i++)
	{
		if (key == pst->base[i])
		{
			return i;
		}	
	}
	return -1;
}
void SeqListDeleteByval(SeqList*pst, ElemType key)//  ��ֵɾ��ʵ��
{
	assert(pst != NULL);
	if (IsEmpty(pst))
	{
		printf("˳���Ϊ�գ����ܰ�ֵɾ��\n");
		return;
	}
	int pos = SeqListFind(pst, key);// �ҵ��±�
	if (pos == -1)
	{
		printf("Ҫɾ�������ݲ�����  ����ɾ��");
		return;
	}
	SeqListDeleteBypos(pst, pos);
}
void SeqListClear(SeqList*pst)// ˳������
{
	assert(pst != NULL);
	pst->size = 0;
}
void SeqListShow(SeqList*pst)  //show   ����ʵ��
{
	assert(pst != NULL);
	for (size_t i = 0; i < pst->size; ++i)
	{
		printf("%d  ", pst->base[i]);
	}
	printf("\n");
}
void SepListDestroy(SeqList*pst)
{
	assert(pst != NULL);
	if (pst->base)
		free(pst->base);
	pst->base = NULL;
	pst->capacity = pst->size = 0;
}
#endif /*_SEQLIST_H_*/