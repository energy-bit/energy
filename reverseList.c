#define _CRT_SECURE_NO_WARNINGS 1
/*
206. 反转链表
反转一个单链表。

示例 :

输入 : 1->2->3->4->5->NULL
输出 : 5->4->3->2->1->NULL
 进阶 :
你可以迭代或递归地反转链表。你能否用两种方法解决这道题？
*/

/**
* Definition for singly-linked list.
* struct ListNode {
*     int val;
*     struct ListNode *next;
* };
*/
// 双指针法

struct ListNode* reverseList(struct ListNode* head)
{
	if (head == NULL || head->next == NULL)
		return head;
	struct ListNode *prv = NULL;
	struct ListNode *q = head;
	while (q)
	{
		struct ListNode *tmp = q->next;
		q->next = prv;// 头先指向空
		prv = q;//在移动prv
		q = tmp;
	}
	return prv;
}

//    递归解法
struct ListNode* reverseList(struct ListNode* head)
{
	if (head == NULL || head->next == NULL)
		return head;
	struct  ListNode *q = reverseList(head->next);
	head->next->next = head;
	head->next = NULL;
	return q;
}