#define _CRT_SECURE_NO_WARNINGS 1
#define ElemType int
//��ͷ������
typedef struct SListNode
{
	ElemType data;
	struct SListNode *next;
}SListNode;

typedef struct SList
{
	SListNode *head;
}SList;
static SListNode* _Buynode(ElemType x);
void SListInit(SList *plist);
void SListPopFront(SList *plist);
void SListPushBack(SList *plist, ElemType x);



static SListNode* _Buynode(ElemType x)
{
	SListNode *s = (SListNode*)malloc(sizeof(SListNode));
	assert(s != NULL);
	s->data = x;
	s->next = NULL;
	return s;
}
void SListInit(SList *plist)
{
	plist->head = NULL;
}
void SListPushBack(SList *plist, ElemType x)
{
	assert(plist != NULL);

	SListNode *s = _Buynode(x);

	//����Ľڵ�Ϊ��һ���ڵ�
	if (plist->head == NULL)
	{
		plist->head = s;
		return;
	}

	//O(n)
	SListNode *p = plist->head;
	//���������β���ڵ� 
	while (p->next != NULL)
		p = p->next;
	p->next = s;
}
void SListPopFront(SList *plist)
{
	assert(plist != NULL);
	SListNode *p = plist->head;
	if (plist->head == NULL)
		return;

	plist->head = p->next;
	free(p);
}