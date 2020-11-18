#define _CRT_SECURE_NO_WARNINGS 1

/*输入一个链表，输出该链表中倒数第k个结点。
示例1
输入

1,{1,2,3,4,5}
返回值

{5}*/
/* struct ListNode {
//	*int val;
//	*struct ListNode *next;
//	*
//};
//*/

/**
*
* @param pListHead ListNode类
* @param k int整型
* @return ListNode类
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
