#define _CRT_SECURE_NO_WARNINGS 1
/**
83. ɾ�����������е��ظ�Ԫ��
����һ����������ɾ�������ظ���Ԫ�أ�ʹ��ÿ��Ԫ��ֻ����һ�Ρ�

ʾ�� 1:

���� : 1->1->2
��� : 1->2
	 ʾ�� 2 :

 ���� : 1->1->2->3->3
  ��� : 1->2->3
	  
	   * Definition for singly-linked list.
	   * struct ListNode {
	   *     int val;
	   *     struct ListNode *next;
	   * };
	   */

//�ݹ鷽��ʵ��

	 struct ListNode* deleteDuplicates(struct ListNode* head){
		 if (!head || !head->next)
			 return head;
		 head->next = deleteDuplicates(head->next);
		 if (head->val == head->next->val)
		 {
			 head = head->next;

		 }
		 return head;

	 }