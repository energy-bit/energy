#define _CRT_SECURE_NO_WARNINGS 1
/*
206. ��ת����
��תһ��������

ʾ�� :

���� : 1->2->3->4->5->NULL
��� : 5->4->3->2->1->NULL
 ���� :
����Ե�����ݹ�ط�ת�������ܷ������ַ����������⣿
*/

/**
* Definition for singly-linked list.
* struct ListNode {
*     int val;
*     struct ListNode *next;
* };
*/
// ˫ָ�뷨

struct ListNode* reverseList(struct ListNode* head)
{
	if (head == NULL || head->next == NULL)
		return head;
	struct ListNode *prv = NULL;
	struct ListNode *q = head;
	while (q)
	{
		struct ListNode *tmp = q->next;
		q->next = prv;// ͷ��ָ���
		prv = q;//���ƶ�prv
		q = tmp;
	}
	return prv;
}

//    �ݹ�ⷨ
struct ListNode* reverseList(struct ListNode* head)
{
	if (head == NULL || head->next == NULL)
		return head;
	struct  ListNode *q = reverseList(head->next);
	head->next->next = head;
	head->next = NULL;
	return q;
}