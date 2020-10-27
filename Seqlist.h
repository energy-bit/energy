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
void SeqListPushFront(SeqList*pst, ElemType x);
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
		printf("˳���ռ����������ܲ�������%d\n", x);
		return;
	}
	for (size_t i = pst->size; i > 0; --i)
	{
		pst->base[i] = pst->base[i - 1];   //Ҫͷ�� Ҫ��ǰ������ݶ�������һλ
	}
		pst->base[0] = x;  //����������ݷ��ڵ�һ��
		pst->size++;
	
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