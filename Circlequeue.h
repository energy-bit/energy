/*
#ifndef _CIRCLEQUEUE_H_
#define _CIRCLEQUEUE_H_
#include "common.h"

#define CIRCLE_QUEUE_DEFAULT_SIZE 8
typedef struct CircleQueue
{
	ElemType *base;
	int capacity;
	int front;//ͷָ��
	int rear;  //βָ��
}CircleQueue;


//   ����
void CircleQueueInit(CircleQueue *psq);
bool CircleQueueIsFull(CircleQueue *psq);
bool CircleQueueIsEmpty(CircleQueue *psq);
void CircleQueueEnque(CircleQueue *psq, ElemType x);
void CircleQueueDeque(CircleQueue *psq);
ElemType CircleQueueFront(CircleQueue *psq);
void CircleQueuePrint(CircleQueue *psq);


void CircleQueueInit(CircleQueue *psq)
{
	assert(psq != NULL);
	psq->base = (ElemType*)malloc(sizeof(ElemType)*CIRCLE_QUEUE_DEFAULT_SIZE+1);
	assert(psq->base != NULL);
	psq->capacity = CIRCLE_QUEUE_DEFAULT_SIZE+1;
	psq->front = psq->rear = 0;
}
bool CircleQueueIsFull(CircleQueue *psq)
{
	assert(psq != NULL);
	return ((psq->rear + 1) % psq->capacity) == psq->front;
}
bool CircleQueueIsEmpty(CircleQueue *psq)
{
	assert(psq != NULL);
	return psq->front == psq->rear;
}
void CircleQueueEnque(CircleQueue *psq, ElemType x)
{
	assert(psq != NULL);
	if (CircleQueueIsFull(psq))
	{
		printf("ѭ����������, %d �������.\n", x);
		return;
	}
	psq->base[psq->rear] = x;
	psq->rear = (psq->rear + 1) % psq->capacity;
}
void CircleQueueDeque(CircleQueue *psq)
{
	assert(psq != NULL);
	if (CircleQueueIsEmpty(psq))
	{
		printf("ѭ�������ѿ�  ���ܳ���");
		return;
	}
	psq->front = (psq->front + 1) % psq->capacity;
}

ElemType CircleQueueFront(CircleQueue *psq)//ȡ��ͷԪ��
{
	assert(psq != NULL);
	if (CircleQueueIsEmpty(psq))
	{
		printf("ѭ�������ѿ�  ����ȡ��ͷԪ��");
		return;
	}
	return psq->base[psq->front];
}
void CircleQueuePrint(CircleQueue *psq)
{
	assert(psq != NULL);
	while (psq->rear != psq->front)
	{
		printf("%d\n  ", psq->base[psq->front]);
		psq->front = (psq->front + 1) % psq->capacity;
	}
}
#endif/*_CIRCLEQUEUE_H*/
