#define _DCLIST_H_

#include"DcCommon.h"
///////////////////////////////////////////////////////////////////////////////
//��ͷ��˫ѭ������
typedef struct DCListNode
{
	ElemType data;
	struct DCListNode *next;
	struct DCListNode *prev;
}DCListNode;

typedef struct DCList
{
	DCListNode *head;
}DCList;

static DCListNode* _Buydnode(ElemType x);
void DCListInit(DCList *plist);
void DCListPushBack(DCList *plist, ElemType x);
void DCListPushFront(DCList *plist, ElemType x);
void DCListShow(DCList *plist);
void DCListPopBack(DCList *plist);
void DCListPopFront(DCList *plist);
DCListNode* DCListFind(DCList *plist, ElemType key);
size_t DCListLength(DCList *plist);
void DCListClear(DCList *plist);
void DCListDestroy(DCList *plist);
void DCListDeleteByVal(DCList *plist, ElemType key);
void DCListInsertByVal(DCList *plist, ElemType x);
void DCListReverse(DCList *plist);
void DCListSort(DCList *plist);

static DCListNode* _Buydnode(ElemType x)
{
	DCListNode *s = (DCListNode*)malloc(sizeof(DCListNode));
	assert(s != NULL);
	s->data = x;
	s->next = s->prev = s;
	return s;
}
void DCListInit(DCList *plist)
{
	plist->head = _Buydnode(0);
}

void DCListPushBack(DCList *plist, ElemType x)
{
	assert(plist != NULL);
	DCListNode *s = _Buydnode(x);

	s->prev = plist->head->prev;
	s->prev->next = s;
	s->next = plist->head;
	plist->head->prev = s;
}

void DCListPushFront(DCList *plist, ElemType x)
{
	assert(plist != NULL);
	DCListNode *s = _Buydnode(x);

	s->next = plist->head->next;
	s->prev = plist->head;
	s->next->prev = s;
	plist->head->next = s;
}

void DCListShow(DCList *plist)
{
	assert(plist != NULL);
	DCListNode *p = plist->head->next;
	while (p != plist->head)
	{
		printf("%d->", p->data);
		p = p->next;
	}
	printf("Over.\n");
}

void DCListPopBack(DCList *plist)
{
	assert(plist != NULL);
	DCListNode *p = plist->head->prev;
	if (p == plist->head)
		return;

	plist->head->prev = p->prev;
	p->prev->next = plist->head;
	free(p);
}
void DCListPopFront(DCList *plist)
{
	assert(plist != NULL);
	DCListNode *p = plist->head->next;
	if (p == plist->head)
		return;
	plist->head->next = p->next;
	p->next->prev = plist->head;
	free(p);
}

DCListNode* DCListFind(DCList *plist, ElemType key)
{
	assert(plist != NULL);
	DCListNode *p = plist->head->next;
	while (p != plist->head && p->data != key)
		p = p->next;
	if (p != plist->head)
		return p;
	return NULL;
}

size_t DCListLength(DCList *plist)
{
	assert(plist != NULL);
	size_t len = 0;
	DCListNode *p = plist->head->next;
	while (p != plist->head)
	{
		len++;
		p = p->next;
	}
	return len;
}

void DCListClear(DCList *plist)
{
	assert(plist != NULL);
	DCListNode *p = plist->head->next;
	while (p != plist->head)
	{
		p->next->prev = p->prev;
		p->prev->next = p->next;
		free(p);
		p = plist->head->next;
	}
}

void DCListDestroy(DCList *plist)
{
	DCListClear(plist);
	free(plist->head); //�ͷ�ͷ���
	plist->head = NULL;
}

void DCListDeleteByVal(DCList *plist, ElemType key)
{
	assert(plist != NULL);
	DCListNode *p = DCListFind(plist, key);
	if (p == NULL)
		return;

	p->next->prev = p->prev;
	p->prev->next = p->next;
	free(p);
}

void DCListInsertByVal(DCList *plist, ElemType x)
{
	assert(plist != NULL);
	DCListNode *p = plist->head->next;

	while (p != plist->head && p->data<x)
		p = p->next;

	DCListNode *s = _Buydnode(x);
	s->next = p;
	s->prev = p->prev;
	p->prev->next = s;
	p->prev = s;
}

void DCListReverse(DCList *plist)
{
	assert(plist != NULL);
	DCListNode *p = plist->head->next;
	DCListNode *q = p->next;

	//�Ͽ�����
	p->next = plist->head;
	plist->head->prev = p;
	while (q != plist->head)
	{
		p = q;
		q = q->next;

		p->next = plist->head->next;
		p->prev = plist->head;
		p->next->prev = p;
		p->prev->next = p; // plist->head->next = p;
	}
}

void DCListSort(DCList *plist)
{
	assert(plist != NULL);
	DCListNode *p = plist->head->next;
	DCListNode *q = p->next;

	p->next = plist->head;
	plist->head->prev = p;

	while (q != plist->head)
	{
		p = q;
		q = q->next;

		//Ѱ��p�Ĳ���λ��
		DCListNode *t = plist->head->next;
		while (t != plist->head && t->data<p->data)
			t = t->next;

		p->next = t;
		p->prev = t->prev;
		p->next->prev = p;
		p->prev->next = p;

		p = q;
	}
}
