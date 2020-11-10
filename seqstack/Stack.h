#ifndef _STACK_H_
#define _STACK_H_

#include "common.h"
#define SEQ_STACK_DEFAULT_SIZE 8

typedef struct SeqStack
{
	ElemType *base;
	size_t capacity;
	int top;//  ջ��
}SeqStack;
void SeqStackInit(SeqStack *pst);//ջ�ĳ�ʼ��
bool SeqStackIsFull(SeqStack *pst);//ջ�Ƿ�����
bool SeqStackIsEmpty(SeqStack *pst);//  ջ�Ƿ�Ϊ��
void SeqStackPush(SeqStack *pst, ElemType x);//��ջ
void SeqStackPop(SeqStack *pst);// ��ջ
ElemType SeqStackTop(SeqStack *pst); // SeqStackPeek();ȡջ��Ԫ��
void SeqStackPrint(SeqStack *pst);
void SeqStackDestroy(SeqStack *pst);

void SeqStackInit(SeqStack *pst)// ջ�ĳ�ʼ��
{
	pst->base = (ElemType*)malloc(sizeof(ElemType)*SEQ_STACK_DEFAULT_SIZE);
	assert(pst->base != NULL);
		pst->capacity = SEQ_STACK_DEFAULT_SIZE;
		pst->top = 0;
}
bool SeqStackIsFull(SeqStack *pst)
{
	assert(pst != NULL);
	return pst->top >= pst->capacity;	
}
bool SeqStackIsEmpty(SeqStack *pst)
{
	assert(pst != NULL);
	return pst ->top== 0;
}
void SeqStackPush(SeqStack *pst, ElemType x)// ��ջ
{
	assert(pst!= NULL);
	if (SeqStackIsFull(pst))
	{
		printf("ջ����  �޷���������");
	}
	pst->base[pst->top] = x;
	pst->top++; 
}
void SeqStackPop(SeqStack *pst)//��ջ
{
	assert(pst != NULL);
	if (SeqStackIsEmpty(pst))
	{
		printf("ջ�ѿ�  ���ܳ�ջ");
		return;
	}
	pst->top--;
}
ElemType SeqStackTop(SeqStack *pst)//  ȡջ��Ԫ��
{
	assert(pst != NULL);
	if (SeqStackIsEmpty(pst))
	{
		printf("ջ�ѿ�  ����ȡջ��Ԫ��");
		return;
	}
	else
	{
		printf("��ջԪ��=%d\n", pst->base[pst->top-1]);
	}
}
void SeqStackPrint(SeqStack *pst)
{
	assert(pst != NULL);
	for (int i = pst->top - 1; i >= 0; --i)
	{
		printf("%d\n",pst->base[i]);
	}
}
void SeqStackDestroy(SeqStack *pst)
{
	assert(pst != NULL);
	free(pst->base);
	pst->base = NULL;
	pst->capacity = pst->top = 0;
}
#endif/*_STACK_H_*/