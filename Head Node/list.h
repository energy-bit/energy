#ifndef _LIST_H_
#define _LIST_H_

#include "common.h"
// 定义链表节点  
typedef struct ListNode
{
	int data;
	struct ListNode *next;//  指向自身类型的指针

}ListNode;
typedef ListNode *List;


// 单链表带头结点
void ListInit(List *plist)
{
	*plist = (ListNode*)malloc(sizeof(ListNode));
	assert(*plist != NULL);
	(*plist)->next = NULL;
}


// 尾插法创建单链表 
void ListCreate_Tail(List*plist)
{
	assert(*plist != NULL);
	ListNode *p = *plist;
	for (int i = 0; i <= 10; ++i)
	{
		ListNode*s = (ListNode*)malloc(sizeof(ListNode));
		assert(s != NULL);
		s->data = i;
		s->next = NULL;
		p->next = s;
		p = s;
	}
}


// 头插法创建单链表
void ListCreate_Head(List *plist)
{
	assert(*plist != NULL);
	for (int i = 0; i <= 10; ++i)
	{
		ListNode*s = (ListNode*)malloc(sizeof(ListNode));
		assert(s != NULL);
		s->data = i;
		s->next = (*plist)->next;
		(*plist)->next = s;
	}
}


void ListShow(List plist)
{
	ListNode*p = plist->next;
	while (p != NULL)
	{
		printf("%d->", p->data);
		p = p->next;
	}
	printf("Over.\n");
}
#endif // !_LIST_H_