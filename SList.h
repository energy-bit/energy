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
//  ���������ӿ�����
static SListNode*_Buynode(ElemType x);// ������
void SListInit(SList *plist);
void SListPushBack(SList *plist, ElemType x);//������β��
void SListPushFront(SList *plist, ElemType x);//������ͷ��  Ч�ʺܸ� ��β��ߵĶ�
void SListPopBack(SList *plist);// β��ɾ��
void SListPopFront(SList *plist);// ͷɾ
void SListDestroy(SList *plist);//
size_t SListLength(SList *plist);//  �󳤶�
void SListClear(SList *plist);// ���
void SListShow(SListNode *plist);// ��ʾ����
//////////////////////////////////////////////////////
// ������ӿ�ʵ��
static SListNode*_Buynode(ElemType x)//   ������ʵ��
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
void SListPushBack(SList *plist, ElemType x)// ������β��ʵ��
{
	assert(plist != NULL);
	SListNode *s = _Buynode(x);
	//  ����Ľ��Ϊ��һ�����
	if (plist->head == NULL)
	{
		plist->head = s;
		return;
	}
	SListNode *p = plist->head;//  ���������ʼ���
	// β������󲿷�ʱ�䶼�� ���������β�����
	//ʱ�临�Ӷ�λO��n��
	while (p->next != NULL)
		p = p->next;
	p->next = s;
}
void SListPushFront(SList *plist, ElemType x)//  ͷ�� Ч�ʸ�
{
	assert(plist != NULL);
	SListNode *s = _Buynode(x);// ������
	// ʱ�临�Ӷ�ΪO��1��
	s->next = plist->head;
	plist->head = s;
}
void SListPopBack(SList *plist)//  β��ɾ��
{
	assert(plist != NULL);
	SListNode*p, *prev;
	//  ����Ϊ��
	if (plist->head == NULL)
	{
		return;
	}
	p = plist->head;
	//  ����ֻ��һ����� 
	if (p->next == NULL)
	{
		plist->head = NULL;
	}
	else
	{ //  �����������������
		while (p->next!= NULL)
		{
			prev = p;
			p = p->next;	
		}
		prev->next = NULL;
	}
	free(p);
}
void SListPopFront(SList *plist)//  ͷ��ɾ��ʵ��
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
size_t SListLength(SList *plist)//  ��ĳ���
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
void SListShow(SList *plist)// ��ʾ
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

#endif/*_SLIST_H_*/



