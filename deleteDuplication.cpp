#define _CRT_SECURE_NO_WARNINGS 1��

/*��һ������������У������ظ��Ľ�㣬��ɾ�����������ظ��Ľ�㣬
�ظ��Ľ�㲻��������������ͷָ�롣

���磬����1->2->3->3->4->4->5 
�����Ϊ 1->2->5*/

/*
struct ListNode {
int val;
struct ListNode *next;
ListNode(int x) :
val(x), next(NULL) {
}
};
*/
class Solution {
public:
	ListNode* deleteDuplication(ListNode* pHead)
	{
		if (pHead == NULL)
			return NULL;
		ListNode *pPre = NULL;//  ǰ���ڵ�
		ListNode *pCur = pHead;//  ��ǰ�ڵ�
		ListNode *pNext = pCur->next;

		while (pNext != NULL)
		{
			if (pCur->val != pNext->val)
			{
				pPre = pCur;
				pCur = pNext;
				pNext = pNext->next;
			}
			else
			{
				while (pNext != NULL&&pNext->val == pCur->val)
					pNext = pNext->next;
				if (pPre == NULL)    //˵��ǰ��Ϊ��  ��1->1->1->2->6->7 ������� ֱ��
					pHead = pNext;// ��ͷָ�� pNextλ�þͺ���
				else
					pPre->next = pNext;  //1->2->3->3->4->4->5  pPreΪ2  ������һ�����ָ��4�Ǹ�λ��
				while (pCur != pNext)
				{
					ListNode *p = pCur;
					pCur = pNext;
					free(p);
				}
				if (pNext != NULL)
					pNext = pNext->next;
			}
		}
		return pHead;
	}

};

