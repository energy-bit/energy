#define _CRT_SECURE_NO_WARNINGS 1

/*����һ����������������е�����k����㡣
ʾ��1
����

1,{1,2,3,4,5}
����ֵ

{5}*/
/* struct ListNode {
//	*int val;
//	*struct ListNode *next;
//	*
//};
//*/

/**
*
* @param pListHead ListNode��
* @param k int����
* @return ListNode��
*/
struct ListNode* FindKthToTail(struct ListNode* pListHead, int k)
{
	// write code here
	if (pListHead == NULL || k == 0)
		return NULL;
	struct ListNode *fast, *slow;
	fast = slow = pListHead;
	while (k-->0)
	{
		if (fast == NULL)
			return NULL;
		fast = fast->next;
	}
	while (fast != NULL)
	{
		fast = fast->next;
		slow = slow->next;
	}
	return slow;
}
