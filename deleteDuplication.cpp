#define _CRT_SECURE_NO_WARNINGS 1、

/*在一个排序的链表中，存在重复的结点，请删除该链表中重复的结点，
重复的结点不保留，返回链表头指针。

例如，链表1->2->3->3->4->4->5 
处理后为 1->2->5*/

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
		ListNode *pPre = NULL;//  前驱节点
		ListNode *pCur = pHead;//  当前节点
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
				if (pPre == NULL)    //说明前驱为空  入1->1->1->2->6->7 这种情况 直接
					pHead = pNext;// 让头指向 pNext位置就好了
				else
					pPre->next = pNext;  //1->2->3->3->4->4->5  pPre为2  它的下一个结点指向4那个位置
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

