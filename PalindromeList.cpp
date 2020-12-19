#define _CRT_SECURE_NO_WARNINGS 1
/*
对于一个链表，请设计一个时间复杂度为O(n), 额外空间复杂度为O(1)的算法，判断其是否为回文结构。

给定一个链表的头指针A，请返回一个bool值，代表其是否为回文结构。保证链表长度小于等于900。

测试样例：
1->2->2->1
返回：true

struct ListNode {
int val;
struct ListNode *next;
ListNode(int x) : val(x), next(NULL) {}
};*/
class PalindromeList {
public:
	bool chkPalindrome(ListNode* A)
	{
		// write code here
		if (A == NULL)
			return true;
		int ar[900];
		ListNode *p = A;
		int i = 0;
		while (p != NULL)
		{
			ar[i++] = p->val;
			p = p->next;
		}

		int start = 0;
		int end = i - 1;
		while (start < end)
		{
			if (ar[start] != ar[end])
				return false;
			start++;
			end--;
		}
		return true;
	}
};