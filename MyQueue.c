#define _CRT_SECURE_NO_WARNINGS 1
/*
232. 用栈实现队列
请你仅使用两个栈实现先入先出队列。队列应当支持一般队列的支持的所有操作（push、pop、peek、empty）：

实现 MyQueue 类：

void push(int x) 将元素 x 推到队列的末尾
int pop() 从队列的开头移除并返回元素
int peek() 返回队列开头的元素
boolean empty() 如果队列为空，返回 true ；否则，返回 false


说明：

你只能使用标准的栈操作 —— 也就是只有 push to top, peek / pop from top, size, 和 is empty 操作是合法的。
你所使用的语言也许不支持栈。你可以使用 list 或者 deque（双端队列）来模拟一个栈，只要是标准的栈操作即可。


进阶：

你能否实现每个操作均摊时间复杂度为 O(1) 的队列？换句话说，执行 n 个操作的总时间复杂度为 O(n) ，即使其中一个操作可能花费较长时间。


示例：

输入：
["MyQueue", "push", "push", "peek", "pop", "empty"]
[[], [1], [2], [], [], []]
输出：
[null, null, null, 1, 1, false]

*/

//  用两个栈实现队列

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
	printf("栈已空，不能出栈.\n");
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
void myQueuePush(MyQueue* obj, int x) // 入队
{
	LinkStackPush(&(obj->instack), x);

}

/** Removes the element from in front of queue and returns that element. */
int myQueuePop(MyQueue* obj) //出队
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
int myQueuePeek(MyQueue* obj) //取对头元素
{
	if (LinkStackEmpty(&(obj->outstack))) //判断outstack是否为空
	{
		while (!LinkStackEmpty(&(obj->instack)))//当instack中的元素不为空时
		{
			LinkStackPush(&(obj->outstack), LinkStackTop(&(obj->instack)));
			//  将instack里的元素 入栈到 outstack中
			LinkStackPop(&(obj->instack)); // instack 出栈
		}
	}
	ElemType val = LinkStackTop(&(obj->outstack));
	return val;
}

/** Returns whether the queue is empty. */
bool myQueueEmpty(MyQueue* obj)// 判断队是否为空
{
	return LinkStackEmpty(&(obj->instack)) && LinkStackEmpty(&(obj->outstack));
}

void myQueueFree(MyQueue* obj) //释放队
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