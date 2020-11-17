#define _CRT_SECURE_NO_WARNINGS 1

/*203. 移除链表元素
删除链表中等于给定值 val 的所有节点。

示例:

输入: 1->2->6->3->4->5->6, val = 6
输出: 1->2->3->4->5*/


/**
* Definition for singly-linked list.
* struct ListNode {
*     int val;
*     struct ListNode *next;
* };
*/


struct ListNode* removeElements(struct ListNode* head, int val){
	if (head == NULL)
		return NULL;
	struct ListNode *p = head;
	struct ListNode *prev = NULL;
	while (p != NULL)
	{
		if (p->val == val)
		{
			if (prev == NULL)//  如果要删除的数刚好在第一个
			{
				head = head->next;
				free(p);
				p = head;
			}
			else//   不在第一个的时候
			{
				prev->next = p->next;
				free(p);
				p = prev->next;
			}
		}
		else
		{
			prev = p;
			p = p->next;

		}
	}
	return head;
}