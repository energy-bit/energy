#ifndef _LIST_H_
#define _LIST_H_

#include "common.h"
// ��������ڵ�  
typedef struct ListNode
{
	int data;
	struct ListNode *next;//  ָ���������͵�ָ��

}ListNode;
typedef ListNode *List;


// �������ͷ���
void ListInit(List *plist)
{
	*plist = (ListNode*)malloc(sizeof(ListNode));
	assert(*plist != NULL);
	(*plist)->next = NULL;
}


// β�巨���������� 
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


// ͷ�巨����������
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