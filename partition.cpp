#define _CRT_SECURE_NO_WARNINGS 1

/*现有一链表的头指针 ListNode* pHead，给一定值x，
编写一段代码将所有小于x的结点排在其余结点之前，
且不能改变原来的数据顺序，返回重新排列后的链表的头指针。*/

/*
struct ListNode {
int val;
struct ListNode *next;
ListNode(int x) : val(x), next(NULL) {}
};*/
//  比如给定的值为5
//  思路  比如给定  3->7->8->9->5->2->1->0->NULL;
//则  将小于5的给less链表 大于等于5的 给Great链表
//lessList  3->2->1->0
//Greatlist 7->8->9->5
//最后将两个链表合并  将头指向lessList的头
class Partition {
public:
	ListNode* partition(ListNode* pHead, int x)
	{
		// write code here
		if (pHead == NULL)
			return NULL;
		ListNode *pLessHead, *pLessTail;// 定义两个链表 一个比x值小  成为小链表  定义一个头和尾
		ListNode *pGreatHead, *pGreatTail;//定义比x值大的  为大链表
		pLessHead = pLessTail = (ListNode*)malloc(sizeof(ListNode));
		pGreatHead = pGreatTail = (ListNode*)malloc(sizeof(ListNode));
		while (pHead != NULL)   //  分割链表
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
		//重新组合链表
		pLessTail->next = pGreatHead->next;
		pGreatTail->next = NULL;
		pHead = pLessHead->next;

		free(pLessHead);
		free(pGreatHead);
		return pHead;
	}
};