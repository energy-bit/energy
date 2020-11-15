#define _CRT_SECURE_NO_WARNINGS 1
/*622. ���ѭ������
������ѭ������ʵ�֡�
ѭ��������һ���������ݽṹ����������ֻ��� FIFO���Ƚ��ȳ���
ԭ���Ҷ�β�������ڶ���֮�����γ�һ��ѭ������Ҳ����Ϊ�����λ���������

ѭ�����е�һ���ô������ǿ��������������֮ǰ�ù��Ŀռ䡣
��һ����ͨ�����һ��һ���������ˣ����ǾͲ��ܲ�����һ��Ԫ�أ���ʹ�ڶ���ǰ�����пռ䡣

����ʹ��ѭ�����У�������ʹ����Щ�ռ�ȥ�洢�µ�ֵ��

���ʵ��Ӧ��֧�����²�����

MyCircularQueue(k): �����������ö��г���Ϊ k ��
Front: �Ӷ��׻�ȡԪ�ء��������Ϊ�գ����� -1 ��
Rear: ��ȡ��βԪ�ء��������Ϊ�գ����� -1 ��
enQueue(value): ��ѭ�����в���һ��Ԫ�ء�����ɹ������򷵻��档
deQueue(): ��ѭ��������ɾ��һ��Ԫ�ء�����ɹ�ɾ���򷵻��档
isEmpty(): ���ѭ�������Ƿ�Ϊ�ա�
isFull(): ���ѭ�������Ƿ�������
 

ʾ����

MyCircularQueue circularQueue = new MyCircularQueue(3); // ���ó���Ϊ 3
circularQueue.enQueue(1);  // ���� true
circularQueue.enQueue(2);  // ���� true
circularQueue.enQueue(3);  // ���� true
circularQueue.enQueue(4);  // ���� false����������
circularQueue.Rear();  // ���� 3
circularQueue.isFull();  // ���� true
circularQueue.deQueue();  // ���� true
circularQueue.enQueue(4);  // ���� true
circularQueue.Rear();  // ���� 4*/

typedef struct
{
	int *base;
	int capacity;
	int front;
	int rear;
} MyCircularQueue;
bool myCircularQueueIsEmpty(MyCircularQueue* obj);
/** Initialize your data structure here. Set the size of the queue to be k. */

MyCircularQueue* myCircularQueueCreate(int k)
{
	MyCircularQueue* pcp = (MyCircularQueue*)malloc(sizeof(MyCircularQueue));
	pcp->base = (int*)malloc(sizeof(int)*(k + 1));
	pcp->capacity = k + 1;
	pcp->front = pcp->rear = 0;
	return pcp;
}
/** Insert an element into the circular queue. Return true if the operation is successful. */
bool myCircularQueueEnQueue(MyCircularQueue* obj, int value){
	if ((obj->rear + 1) % obj->capacity == obj->front)
		return false;
	obj->base[obj->rear] = value;
	obj->rear = (obj->rear + 1) % obj->capacity;
	return true;
}

/** Delete an element from the circular queue. Return true if the operation is successful. */
bool myCircularQueueDeQueue(MyCircularQueue* obj)
{
	if (obj->rear == obj->front)
		return false;
	obj->front = (obj->front + 1) % obj->capacity;
	return true;
}

/** Get the front item from the queue. */
int myCircularQueueFront(MyCircularQueue* obj)
{
	if (myCircularQueueIsEmpty(obj))
		return -1;
	return obj->base[obj->front];
}

/** Get the last item from the queue. */
int myCircularQueueRear(MyCircularQueue* obj)
{
	if (myCircularQueueIsEmpty(obj))
		return -1;
	return obj->base[(obj->rear - 1 + obj->capacity) % obj->capacity];//  ��ֹ�����
}

/** Checks whether the circular queue is empty or not. */
bool myCircularQueueIsEmpty(MyCircularQueue* obj)
{
	return obj->front == obj->rear;
}

/** Checks whether the circular queue is full or not. */
bool myCircularQueueIsFull(MyCircularQueue* obj)
{
	return ((obj->rear + 1) % obj->capacity == obj->front);

}

void myCircularQueueFree(MyCircularQueue* obj)
{
	free(obj->base);
	free(obj);
}

/**
* Your MyCircularQueue struct will be instantiated and called as such:
* MyCircularQueue* obj = myCircularQueueCreate(k);
* bool param_1 = myCircularQueueEnQueue(obj, value);

* bool param_2 = myCircularQueueDeQueue(obj);

* int param_3 = myCircularQueueFront(obj);

* int param_4 = myCircularQueueRear(obj);

* bool param_5 = myCircularQueueIsEmpty(obj);

* bool param_6 = myCircularQueueIsFull(obj);

* myCircularQueueFree(obj);
*/