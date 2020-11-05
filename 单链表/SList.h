#define _CRT_SECURE_NO_WARNINGS 1
#ifndef _SLIST_H_
#define _SLIST_H_
#include "_head.h"
typedef struct SListNode
{
	ElemType data;
	struct SListNode *next;
}SListNode;
typedef struct SList
{
	SListNode *head;
}SList;
//////////////////////////////////////////////////////
//  单链表函数接口声明
static SListNode*_Buynode(ElemType x);// 购买结点
void SListInit(SList *plist);
void SListPushBack(SList *plist, ElemType x);//单链表尾插
void SListPushFront(SList *plist, ElemType x);//单链表头插  效率很高 比尾插高的多
void SListPopBack(SList *plist);// 尾部删除
void SListPopFront(SList *plist);// 头删
void SListDestroy(SList *plist);//
void SListInsertByVal(SList*plist, ElemType x);// 按值插入
SListNode *SListFind(SList*plist, ElemType key);// 按值查找
void SListDeleteByval(SList*plist, ElemType key);// 按值删除
size_t SListLength(SList *plist);//  求长度
void SListSort(SList *plist);// 排序
void SListReverse(SList *plist);//  转置
void SListClear(SList *plist);// 清除
void SListShow(SListNode *plist);// 显示函数
//////////////////////////////////////////////////////
// 单链表接口实现
static SListNode*_Buynode(ElemType x)//   购买结点实现
{
	SListNode *s = (SListNode*)malloc(sizeof(SListNode));
	assert(s != NULL);
	s->data = x;
	s->next = NULL;
}
void SListInit(SList *plist)
{
	plist->head = NULL;
}
void SListPushBack(SList *plist, ElemType x)// 单链表尾插实现
{
	assert(plist != NULL);
	SListNode *s = _Buynode(x);
	//  插入的结点为第一个结点
	if (plist->head == NULL)
	{
		plist->head = s;
		return;
	}
	SListNode *p = plist->head;//  代表的是起始结点
	// 尾部插入大部分时间都在 查找链表的尾部结点
	//时间复杂对位O（n）
	while (p->next != NULL)
		p = p->next;
	p->next = s;
}
void SListPushFront(SList *plist, ElemType x)//  头插 效率高
{
	assert(plist != NULL);
	SListNode *s = _Buynode(x);// 购买结点
	// 时间复杂度为O（1）
	s->next = plist->head;
	plist->head = s;
}
void SListPopBack(SList *plist)//  尾部删除
{
	assert(plist != NULL);
	SListNode*p, *prev;
	//  链表为空
	if (plist->head == NULL)
	{
		return;
	}
	p = plist->head;
	//  链表只有一个结点 
	if (p->next == NULL)
	{
		plist->head = NULL;
	}
	else
	{ //  链表至少有两个结点
		while (p->next!= NULL)
		{
			prev = p;
			p = p->next;	
		}
		prev->next = NULL;
	}
	free(p);
}
void SListPopFront(SList *plist)//  头部删除实现
{
	assert(plist != NULL);
	SListNode*p=plist->head;
	if (plist->head == NULL)
	{
		return;
	}
	plist->head = p->next;
	free(p);
}
SListNode *SListFind(SList*plist, ElemType key)//  按值查找
{
	//优化的查找 减少代码量
	assert(plist != NULL);
	SListNode *p = plist->head;
	while (p != NULL&&p->data!= key)
		p = p->next;
	return p;


	/*  
	assert(plist != NULL);
	SListNode *p = plist->head;
	while (p != NULL)
	{
		if (p->data == key)
			return p;
		p = p->next;
	}
	return NULL;
	*/
}
void SListDeleteByval(SList*plist, ElemType key)
{
	assert(plist != NULL);
	SListNode *prev=NULL;// 前驱结点
	SListNode *p = SListFind(plist, key);
	if (p ==NULL)
	{
		printf("要删除的节点不存在\n");
		return;
	}
	if (p == plist->head)
	{
		plist->head = p->next;
	}
	else
	{
		prev = plist->head;
		while (prev->next != p)
		
			prev = prev->next;
		
		prev->next = p->next;
	}
	free(p);
}
size_t SListLength(SList *plist)//  表的长度
{
	assert(plist != NULL);
	size_t len = 0;
	SListNode*p = plist->head;
	while (p != NULL)
	{
		len++;
		p = p->next;
	}

	return len;
}
void SListShow(SList *plist)// 显示
{
	SListNode *p=plist->head;
	while (p != NULL)
	{
		printf("%d->", p->data);
		p = p->next;
	}
	printf("Over.\n");
}
void SListDestroy(SList *plist)// 
{
	SListClear(plist);
	plist->head = NULL;
}
void SListClear(SList *plist)
{
	assert(plist != NULL);
	SListNode *p = plist->head;
	while (p != NULL)
	{
		plist->head = p->next;
		free(p);
		p = plist->head;
	}
}
void SListReverse(SList *plist)
{
	assert(plist != NULL);
	SListNode *p = plist->head->next;
	SListNode *q;
	if (p->next == NULL)
	{
		return;
	}
	//断开第一个结点
	plist->head->next = NULL;
	while (p != NULL)
	{
		q = p->next;
		p->next = plist->head;
		plist->head = p;
		p = q;
	}

}
void SListInsertByVal(SList*plist, ElemType x)//  按值插入
{
	assert(plist != NULL);
	SListNode *prev = NULL;
	SListNode *p = plist->head;
	SListNode *s = _Buynode(x);// 如果要插入的数比第一个小的话   要进行头插 要申请节点
	while (p != NULL&&x > p->data)
	{
		prev = p;
		p = p->next;
	}
	if (prev == NULL)// 需要进行头插
	{
		s->next = p;
		plist->head = s;
	}
	else
	{
		s->next = prev->next;
		prev->next = s;
	}
}
void SListSort(SList *plist)
{
	assert(plist != NULL);
	SListNode *p = plist->head->next;
	SListNode *q, *t,*prev = NULL;
	plist->head->next = NULL;// 断开链表
	t = plist->head;
	while (p != NULL)
	{
		q = p->next;
		// 把节点摘除进行按值插入，升序
		while (t!=NULL&&p->data > t->data)

		{
			prev = t;
			t = t->next;
		}
		if (prev == NULL)
		{
			p->next = plist->head;
			plist->head = p;

		}
		else
		{
			p->next = prev->next;
			prev->next = p;
		}
		p = q;
		t = plist->head;

	}

}
#endif/*_SLIST_H_*/



