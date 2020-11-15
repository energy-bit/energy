#define _CRT_SECURE_NO_WARNINGS 1
/*
232. ��ջʵ�ֶ���
�����ʹ������ջʵ�������ȳ����С�����Ӧ��֧��һ����е�֧�ֵ����в�����push��pop��peek��empty����

ʵ�� MyQueue �ࣺ

void push(int x) ��Ԫ�� x �Ƶ����е�ĩβ
int pop() �Ӷ��еĿ�ͷ�Ƴ�������Ԫ��
int peek() ���ض��п�ͷ��Ԫ��
boolean empty() �������Ϊ�գ����� true �����򣬷��� false


˵����

��ֻ��ʹ�ñ�׼��ջ���� ���� Ҳ����ֻ�� push to top, peek / pop from top, size, �� is empty �����ǺϷ��ġ�
����ʹ�õ�����Ҳ��֧��ջ�������ʹ�� list ���� deque��˫�˶��У���ģ��һ��ջ��ֻҪ�Ǳ�׼��ջ�������ɡ�


���ף�

���ܷ�ʵ��ÿ��������̯ʱ�临�Ӷ�Ϊ O(1) �Ķ��У����仰˵��ִ�� n ����������ʱ�临�Ӷ�Ϊ O(n) ����ʹ����һ���������ܻ��ѽϳ�ʱ�䡣


ʾ����

���룺
["MyQueue", "push", "push", "peek", "pop", "empty"]
[[], [1], [2], [], [], []]
�����
[null, null, null, 1, 1, false]

*/

//  ������ջʵ�ֶ���

typedef char ElemType;
typedef struct LinkStackNode
{
	ElemType data;
	struct LinkStackNode *link; //next
}LinkStackNode;

typedef struct LinkStack
{
	LinkStackNode *top;
}LinkStack;

void LinkStackInit(LinkStack *pst);
bool LinkStackEmpty(LinkStack *pst);
void LinkStackPush(LinkStack *pst, ElemType x);
void LinkStackPop(LinkStack *pst);
ElemType LinkStackTop(LinkStack *pst);
void LinkStackPrint(LinkStack *pst);
void LinkStackDestroy(LinkStack *pst);

void LinkStackInit(LinkStack *pst)
{
	assert(pst != NULL);
	pst->top = NULL;
}
bool LinkStackEmpty(LinkStack *pst)
{
	return pst->top == NULL;
}
void LinkStackPush(LinkStack *pst, ElemType x)
{
	assert(pst != NULL);
	LinkStackNode *node = (LinkStackNode*)malloc(sizeof(LinkStackNode));
	assert(node != NULL);
	node->data = x;

	node->link = pst->top;
	pst->top = node;
}
void LinkStackPop(LinkStack *pst)
{
	assert(pst != NULL);
	LinkStackNode *p = pst->top;
	pst->top = p->link;

	free(p);
}
ElemType LinkStackTop(LinkStack *pst)
{
	assert(pst != NULL);
	/*
	if(pst->top == NULL)
	{
	printf("ջ�ѿգ����ܳ�ջ.\n");
	return;
	}
	*/
	return pst->top->data;
}
void LinkStackPrint(LinkStack *pst)
{
	assert(pst != NULL);
	LinkStackNode *p = pst->top;
	while (p != NULL)
	{
		printf("%d\n", p->data);
		p = p->link;
	}
	printf("\n");
}

void LinkStackDestroy(LinkStack *pst)
{
	assert(pst != NULL);
	while (pst->top != NULL)
	{
		LinkStackNode *p = pst->top;
		pst->top = p->link;
		free(p);
	}
}

///////////////////////////////////////////
typedef struct
{
	LinkStack instack;
	LinkStack outstack;
} MyQueue;

/** Initialize your data structure here. */

MyQueue* myQueueCreate()
{
	MyQueue *pq = (MyQueue*)malloc(sizeof(MyQueue));
	LinkStackInit(&(pq->instack));
	LinkStackInit(&(pq->outstack));
	return pq;
}

/** Push element x to the back of queue. */
void myQueuePush(MyQueue* obj, int x) // ���
{
	LinkStackPush(&(obj->instack), x);

}

/** Removes the element from in front of queue and returns that element. */
int myQueuePop(MyQueue* obj) //����
{
	if (LinkStackEmpty(&(obj->outstack)))
	{
		while (!LinkStackEmpty(&(obj->instack)))
		{
			LinkStackPush(&(obj->outstack), LinkStackTop(&(obj->instack)));
			LinkStackPop(&(obj->instack));
		}
	}
	ElemType val = LinkStackTop(&(obj->outstack));
	LinkStackPop(&(obj->outstack));
	return val;
}

/** Get the front element. */
int myQueuePeek(MyQueue* obj) //ȡ��ͷԪ��
{
	if (LinkStackEmpty(&(obj->outstack))) //�ж�outstack�Ƿ�Ϊ��
	{
		while (!LinkStackEmpty(&(obj->instack)))//��instack�е�Ԫ�ز�Ϊ��ʱ
		{
			LinkStackPush(&(obj->outstack), LinkStackTop(&(obj->instack)));
			//  ��instack���Ԫ�� ��ջ�� outstack��
			LinkStackPop(&(obj->instack)); // instack ��ջ
		}
	}
	ElemType val = LinkStackTop(&(obj->outstack));
	return val;
}

/** Returns whether the queue is empty. */
bool myQueueEmpty(MyQueue* obj)// �ж϶��Ƿ�Ϊ��
{
	return LinkStackEmpty(&(obj->instack)) && LinkStackEmpty(&(obj->outstack));
}

void myQueueFree(MyQueue* obj) //�ͷŶ�
{
	LinkStackDestroy(&(obj->instack));
	LinkStackDestroy(&(obj->outstack));
	free(obj);
}
/**
* Your MyQueue struct will be instantiated and called as such:
* MyQueue* obj = myQueueCreate();
* myQueuePush(obj, x);

* int param_2 = myQueuePop(obj);

* int param_3 = myQueuePeek(obj);

* bool param_4 = myQueueEmpty(obj);

* myQueueFree(obj);
*/