#ifndef _SEQLIST_H_
#define _SEQLIST_H_

#include "common.h" 
#define SEQLIST_DEFAULT_SIZE 8  //默认容量大小空间   比如8个
// 定义顺序表结构
typedef struct SeqList
{
	ElemType *base;    //int *base
	size_t capacity;   // 容量
	size_t size;       // 大小
}SeqList;
////////////////////////////////////////////
//声明函数接口
void SeqListInit(SeqList*pst);
bool IsFull(SeqList*pst);//是否空间满了
bool IsEmpty(SeqList*pst);//是否为空
void SeqListPushBack(SeqList*pst, ElemType x);//   声明尾插函数
void SeqListPushFront(SeqList*pst, ElemType x);//头插
void SeqListPopBack(SeqList*pst);// 尾删
void SeqListPopFront(SeqList*pst);//  头删
void SeqListInsertByPos(SeqList*pst, int pos, ElemType x);//按位置插入
void SeqListDeleteBypos(SeqList*pst, int pos);     //按位置删除
void  SeqListInsertByVal(SeqList*pst, ElemType x);// 按值插入
void SeqListSort(SeqList*pst);//  排序
int  SeqListFind(SeqList*pst, ElemType key);//查找
void SeqListDeleteByval(SeqList*pst, ElemType key);//按值删除
size_t SeqListLength(SeqList*pst);//  顺序表长度
size_t SeqListCapacity(SeqList*pst);// 顺序表容量
void SeqListClear(SeqList*pst);//  清除
void SeqListShow(SeqList*pst);//  声明展示函数
void SepListDestroy(SeqList*pst);
////////////////////////////////////////////
//函数接口实现
void SeqListInit(SeqList *pst)
{
	assert(pst != NULL);
	//ElemType 类型
	pst->base = (ElemType*)malloc(sizeof(ElemType)*SEQLIST_DEFAULT_SIZE);
	assert(pst->base != NULL);
	memset(pst->base, 0, SEQLIST_DEFAULT_SIZE);
	pst->capacity = SEQLIST_DEFAULT_SIZE;
	pst->size = 0;
}
bool IsFull(SeqList*pst)//判断是否空间满了实现
{
	assert(pst != NULL);
	return pst->size >= pst->capacity;  //元素个数大于了空间容量了
}
bool IsEmpty(SeqList*pst)//是否为空
{
	assert(pst != NULL);
	return pst->size == 0;  //
}
void SeqListPushBack(SeqList*pst, ElemType x)// 实现尾插函数
{
	assert(pst != NULL);
	if (IsFull(pst))
	{
		printf("顺序表空间已满，不能插入数据%d\n", x);
		return;
	}
	pst->base[pst->size] = x;
	//  比如数据   1 2 3 4 5 . . .    //大小为5  则下面要插入的数的下标则刚好为数据的大小size
	//  下标       0 1 2 3 4 5 6 7 
	pst->size++;//  放一个数   数据大小size 会加
}
void SeqListPushFront(SeqList*pst, ElemType x)//  头插实现
{
	assert(pst != NULL);
	if (IsFull(pst))
	{
		printf("顺序表空间已满，不能头部插入数据%d\n", x);
		return;
	}
	for (size_t i = pst->size; i > 0; --i)
	{
		pst->base[i] = pst->base[i - 1];   //要头插 要把前面的数据都往后移一位
	}
	pst->base[0] = x;  //将插入的数据放在第一个
	pst->size++;
}
void SeqListPopBack(SeqList*pst) //  尾删实现
{
	assert(pst != NULL);
	if (IsEmpty(pst))
	{
		printf("顺序表为空，不能尾部删除\n");
		return;
	}
	pst->size--;  //  只需要大小减一下   因为下一个数插进来会把最后原来留的那个值覆盖
}
void SeqListPopFront(SeqList*pst)//  头部删除函数实现
{
	assert(pst != NULL);
	if (IsEmpty(pst))
	{
		printf("顺序表为空，不能头部删除\n");
		return;
	}
	for (size_t i = 0; i < pst->size; i++)
	{
		pst->base[i] = pst->base[i + 1];
	}
	pst->size--;
}
void SeqListInsertByPos(SeqList*pst, int pos, ElemType x) //按位置插入数据
{
	assert(pst != NULL);
	if (pos<0 || pos>pst->size)
	{
		printf("要插入的位置非法 ，不能插入\n");
		return;
	}
	if (IsFull(pst))
	{
		printf("顺序表空间已满，不能按位置插入数据%d\n", x);
		return;
	}
	for (int i = pst->size; i > pos; --i)
	{
		pst->base[i] = pst->base[i - 1];
	}
	pst->base[pos] = x;
	pst->size++;
}
void SeqListDeleteBypos(SeqList*pst, int pos)
{
	assert(pst != NULL);
	if (IsEmpty(pst))
	{
		printf("顺序表为空，不能按位删除\n");
		return;
	}
	if (pos<0 || pos >= pst->size)
	{
		printf("要删除的位置非法 ，不能删除\n");
		return;
	}
	for (int i = pos; i < pst->size - 1; i++)
	{
		pst->base[i] = pst->base[i + 1];
	}
	pst->size--;
}
void  SeqListInsertByVal(SeqList*pst, ElemType x)//  按值插入
{
	/*
	第一种方法
	assert(pst != NULL);
	// 从前往后比较
	if (IsFull(pst))
	{
	printf("顺序表空间已满，不能插入数据%d\n", x);
	return;
	}
	int pos = 0;//位置
	int i;
	for ( i = 0; i < pst->size; i++)
	{

	if (x<pst->base[i])
	{
	pos = i;
	break;
	}
	}
	if (i >= pst->size)
	{
	pos = i;
	}
	SeqListInsertByPos(pst, pos, x);
	*/

	//第二种方法
	assert(pst != NULL);
	// 从后往前比较
	if (IsFull(pst))
	{
		printf("顺序表空间已满，不能插入数据%d\n", x);
		return;
	}
	int end = pst->size;
	while (end > 0 && x < pst->base[end - 1])

	{
		pst->base[end] = pst->base[end - 1];
		end--;
	}
	pst->base[end] = x;
	pst->size++;
}
void SeqListSort(SeqList*pst)//  顺序表排序
{
	assert(pst != NULL);
	if (pst->size <= 1)
	{
		return;
	}
	for (int i = 0; i < pst->size - 1; i++)
	{
		for (int j = 0; j < pst->size - i - 1; j++)
		{
			if (pst->base[j]>pst->base[j + 1])
			{
				ElemType tmp = pst->base[j];
				pst->base[j] = pst->base[j + 1];
				pst->base[j + 1] = tmp;
			}
		}
	}
}

size_t SeqListLength(SeqList*pst) //长度
{
	assert(pst != NULL);
	return pst->size;
}
size_t SeqListCapacity(SeqList*pst)// 容量
{
	assert(pst != NULL);
	return pst->capacity;
}
int SeqListFind(SeqList*pst, ElemType key)//  查找
{
	assert(pst != NULL);
	for (int i = 0; i < pst->size; i++)
	{
		if (key == pst->base[i])
		{
			return i;
		}	
	}
	return -1;
}
void SeqListDeleteByval(SeqList*pst, ElemType key)//  按值删除实现
{
	assert(pst != NULL);
	if (IsEmpty(pst))
	{
		printf("顺序表为空，不能按值删除\n");
		return;
	}
	int pos = SeqListFind(pst, key);// 找到下标
	if (pos == -1)
	{
		printf("要删除的数据不存在  不能删除");
		return;
	}
	SeqListDeleteBypos(pst, pos);
}
void SeqListClear(SeqList*pst)// 顺序表清除
{
	assert(pst != NULL);
	pst->size = 0;
}
void SeqListShow(SeqList*pst)  //show   函数实现
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