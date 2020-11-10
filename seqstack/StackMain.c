#define _CRT_SECURE_NO_WARNINGS 1
#include "stack.h"
#include "common.h"

void main()
{
	SeqStack st;
	SeqStackInit(&st);
	SeqStackPush(&st, 1);
	SeqStackPush(&st, 2);
	SeqStackPush(&st, 3);
	SeqStackPush(&st, 4);
	SeqStackPush(&st, 5);
	SeqStackPush(&st, 6);
	
	SeqStackPrint(&st);

	SeqStackPop(&st);
	SeqStackTop(&st);
	SeqStackPrint(&st);
	
	//SeqStackDestroy(&st);
}