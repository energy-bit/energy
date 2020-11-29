#define _CRT_SECURE_NO_WARNINGS 1

/*����һ�����ͷָ�� ListNode* pHead����һ��ֵx��
��дһ�δ��뽫����С��x�Ľ������������֮ǰ��
�Ҳ��ܸı�ԭ��������˳�򣬷����������к�������ͷָ�롣*/

/*
struct ListNode {
int val;
struct ListNode *next;
ListNode(int x) : val(x), next(NULL) {}
};*/
//  ���������ֵΪ5
//  ˼·  �������  3->7->8->9->5->2->1->0->NULL;
//��  ��С��5�ĸ�less���� ���ڵ���5�� ��Great����
//lessList  3->2->1->0
//Greatlist 7->8->9->5
//�����������ϲ�  ��ͷָ��lessList��ͷ
class Partition {
public:
	ListNode* partition(ListNode* pHead, int x)
	{
		// write code here
		if (pHead == NULL)
			return NULL;
		ListNode *pLessHead, *pLessTail;// ������������ һ����xֵС  ��ΪС����  ����һ��ͷ��β
		ListNode *pGreatHead, *pGreatTail;//�����xֵ���  Ϊ������
		pLessHead = pLessTail = (ListNode*)malloc(sizeof(ListNode));
		pGreatHead = pGreatTail = (ListNode*)malloc(sizeof(ListNode));
		while (pHead != NULL)   //  �ָ�����
		{
			if (pHead->val<x)
			{
				pLessTail->next = pHead;
				pLessTail = pHead;

			}
			else
			{
				pGreatTail->next = pHead;
				pGreatTail = pHead;
			}
			pHead = pHead->next;
		}
		//�����������
		pLessTail->next = pGreatHead->next;
		pGreatTail->next = NULL;
		pHead = pLessHead->next;

		free(pLessHead);
		free(pGreatHead);
		return pHead;
	}
};