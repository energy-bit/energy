#define _CRT_SECURE_NO_WARNINGS 1
#include "common.h"
#include "Queue.h"
void main()
{
	/*SeqQueue Q;
	SeqQueueInit(&Q);

	SeqQueueEnque(&Q, 1);
	SeqQueueEnque(&Q, 2);
	SeqQueueEnque(&Q, 3);
	SeqQueueEnque(&Q, 4);
	ElemType a = SeqQueueFront(&Q);
	printf("³ö¶Ó=%d\n ", a);
	SeqQueueDeque(&Q);
	SeqQueuePrint(&Q);
	*/
	SeqQueue Q;
	SeqQueueInit(&Q);
	SeqQueueEnque(&Q, 1);
	SeqQueueEnque(&Q, 2);
	SeqQueueEnque(&Q, 3);
	SeqQueueEnque(&Q, 4);
	SeqQueueEnque(&Q, 5);
	SeqQueueEnque(&Q, 6);
	SeqQueueEnque(&Q, 7);
	SeqQueueEnque(&Q, 8);
	SeqQueueDeque(&Q);
	SeqQueueEnque(&Q, 9);
	SeqQueuePrint(&Q);
}