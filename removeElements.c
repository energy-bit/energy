#define _CRT_SECURE_NO_WARNINGS 1

/*203. �Ƴ�����Ԫ��
ɾ�������е��ڸ���ֵ val �����нڵ㡣

ʾ��:

����: 1->2->6->3->4->5->6, val = 6
���: 1->2->3->4->5*/


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
			if (prev == NULL)//  ���Ҫɾ�������պ��ڵ�һ��
			{
				head = head->next;
				free(p);
				p = head;
			}
			else//   ���ڵ�һ����ʱ��
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