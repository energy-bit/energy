#define _CRT_SECURE_NO_WARNINGS 1
/*
����һ�����������һ��ʱ�临�Ӷ�ΪO(n), ����ռ临�Ӷ�ΪO(1)���㷨���ж����Ƿ�Ϊ���Ľṹ��

����һ�������ͷָ��A���뷵��һ��boolֵ���������Ƿ�Ϊ���Ľṹ����֤������С�ڵ���900��

����������
1->2->2->1
���أ�true

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