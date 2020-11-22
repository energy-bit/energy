#define _CRT_SECURE_NO_WARNINGS 1
/*面试题 02.03. 删除中间节点
实现一种算法，删除单向链表中间的某个节点（即不是第一个或最后一个节点），假定你只能访问该节点。

 

示例：

输入：单向链表a->b->c->d->e->f中的节点c
结果：不返回任何数据，但该链表变为a->b->d->e->f*/
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