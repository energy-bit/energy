#define _CRT_SECURE_NO_WARNINGS 1
/*������ 02.03. ɾ���м�ڵ�
ʵ��һ���㷨��ɾ�����������м��ĳ���ڵ㣨�����ǵ�һ�������һ���ڵ㣩���ٶ���ֻ�ܷ��ʸýڵ㡣

 

ʾ����

���룺��������a->b->c->d->e->f�еĽڵ�c
������������κ����ݣ����������Ϊa->b->d->e->f*/
/**
* Definition for singly-linked list.
* struct ListNode {
*     int val;
*     struct ListNode *next;
* };
*/


/*
void deleteNode(struct ListNode* node)
{
node->val=node->next->val;
node->next=node->next->next;
}
*/
void deleteNode(struct ListNode* node)
{
	struct ListNode *p = node->next;
	node->val = p->val;
	node->next = p->next;
	free(p);
}