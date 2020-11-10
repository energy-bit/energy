#ifndef _STACK_H_
#define _STACK_H_

#include "common.h"
#define SEQ_STACK_DEFAULT_SIZE 8

typedef struct SeqStack
{
	ElemType *base;
	size_t capacity;
	int top;//  栈顶
}SeqStack;
void SeqStackInit(SeqStack *pst);//栈的初始化
bool SeqStackIsFull(SeqStack *pst);//栈是否满了
bool SeqStackIsEmpty(SeqStack *pst);//  栈是否为空
void SeqStackPush(SeqStack *pst, ElemType x);//入栈
void SeqStackPop(SeqStack *pst);// 出栈
ElemType SeqStackTop(SeqStack *pst); // SeqStackPeek();取栈顶元素
void SeqStackPrint(SeqStack *pst);
void SeqStackDestroy(SeqStack *pst);

void SeqStackInit(SeqStack *pst)// 栈的初始化
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
void SeqStackPush(SeqStack *pst, ElemType x)// 入栈
{
	assert(pst!= NULL);
	if (SeqStackIsFull(pst))
	{
		printf("栈已满  无法放入数据");
	}
	pst->base[pst->top] = x;
	pst->top++; 
}
void SeqStackPop(SeqStack *pst)//出栈
{
	assert(pst != NULL);
	if (SeqStackIsEmpty(pst))
	{
		printf("栈已空  不能出栈");
		return;
	}
	pst->top--;
}
ElemType SeqStackTop(SeqStack *pst)//  取栈顶元素
{
	assert(pst != NULL);
	if (SeqStackIsEmpty(pst))
	{
		printf("栈已空  不能取栈顶元素");
		return;
	}
	else
	{
		printf("出栈元素=%d\n", pst->base[pst->top-1]);
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