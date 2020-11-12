#ifndef _QUEUE_H_
#define _QUEUE_H_
#include "common.h"
#define SEQ_QUEUE_DEFAULT_SIZE 8

typedef struct SeqQueue
{
	ElemType *base;
	int       capacity;
	int       front;
	int       rear;
}SeqQueue;

void SeqQueueInit(SeqQueue *pst);
bool SeqQueueIsFull(SeqQueue*pst);
bool SeqQueueIsEmpty(SeqQueue *pst);
void SeqQueueEnque(SeqQueue *pst, ElemType x);
void SeqQueueDeque(SeqQueue *pst);
ElemType SeqQueueFront(SeqQueue *pst);
void SeqQueuePrint(SeqQueue *pst);

//  实现
void SeqQueueInit(SeqQueue *pst)
{
	assert(pst != NULL);
	pst->base = (ElemType*)malloc(sizeof(ElemType)*SEQ_QUEUE_DEFAULT_SIZE);
	assert(pst->base != NULL);
	pst->capacity = SEQ_QUEUE_DEFAULT_SIZE;
	pst->front = pst->rear = 0;
}
bool SeqQueueIsFull(SeqQueue*pst)
{
	assert(pst != NULL);
	return pst->rear >= pst->capacity;
}
bool SeqQueueIsEmpty(SeqQueue *pst)
{
	assert(pst != NULL);
	return pst->front == pst->rear;
}
void SeqQueueEnque(SeqQueue *pst, ElemType x)
{
	assert(pst!= NULL);
	if (SeqQueueIsFull(pst))
	{
		printf("队已满 不能入队\n");
		return;
	}
	pst->base[pst->rear++] = x;
}
void SeqQueueDeque(SeqQueue *pst)
{
	assert(pst != NULL);
	if (SeqQueueIsEmpty(pst))
	{
		printf("队已空  不能出队\n");
		return;
	}
	pst->front++;
}
ElemType SeqQueueFront(SeqQueue *pst)
{
	assert(pst != NULL);
	if (SeqQueueIsEmpty(pst))
	{
		printf("队已空  不能出队\n");
	}
	return pst->base[pst->front];
}
void SeqQueuePrint(SeqQueue *pst)
{
	assert(pst != NULL);
	for (int i = pst->front; i <pst->rear; i++)
	{
		printf("%d ", pst->base[i]);
	}
}
#endif // QUEUE_H_
