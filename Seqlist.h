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
void SeqListPushFront(SeqList*pst, ElemType x);
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
		printf("顺序表空间已满，不能插入数据%d\n", x);
		return;
	}
	for (size_t i = pst->size; i > 0; --i)
	{
		pst->base[i] = pst->base[i - 1];   //要头插 要把前面的数据都往后移一位
	}
		pst->base[0] = x;  //将插入的数据放在第一个
		pst->size++;
	
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