/*�������������ͷָ���һ��Ҫɾ���Ľڵ��ֵ������һ������ɾ���ýڵ㡣

����ɾ����������ͷ�ڵ㡣

ע�⣺����Ա�ԭ���иĶ�

ʾ�� 1:

����: head = [4,5,1,9], val = 5
���: [4,1,9]
����: ������������ֵΪ?5?�ĵڶ����ڵ㣬��ô�ڵ�������ĺ���֮�󣬸�����Ӧ��Ϊ 4 -> 1 -> 9.
ʾ�� 2:

����: head = [4,5,1,9], val = 1
���: [4,5,9]
����: ������������ֵΪ?1?�ĵ������ڵ㣬��ô�ڵ�������ĺ���֮�󣬸�����Ӧ��Ϊ 4 -> 5 -> 9.

��*/

/**
* Definition for singly-linked list.
* struct ListNode {
*     int val;
*     struct ListNode *next;
* };
*/
//  ˫ָ��

struct ListNode* deleteNode(struct ListNode* head, int val)
{
	if (head == NULL)
		return NULL;
	if (head->val == val)
		return head->next;
	struct ListNode  *p = head;
	struct ListNode *q = head;
	while ((p->next != NULL) && (p->val != val))
	{

		q = p;
		p = p->next;
	}

	if (p->next == NULL)
	{
		q->next = NULL;
	}

	else  if (p->val == val)
	{
		p->val = p->next->val;  //�����ֵ����ǰһ�� 
		p->next = p->next->next; // 
	}



	return head;
}