#define _CRT_SECURE_NO_WARNINGS 1

/*输入一个链表的头节点，从尾到头反过来返回每个节点的值（用数组返回）。

 

示例 1：

输入：head = [1,3,2]
输出：[2,3,1]
*/

/**
* Definition for singly-linked list.
* struct ListNode {
*     int val;
*     struct ListNode *next;
* };
*/


/**
* Note: The returned array must be malloced, assume caller calls free().
*/

int* reversePrint(struct ListNode* head, int* returnSize){
	struct ListNode* p = head;

	int n = 0;//计算出链表大小
	while (p != NULL){
		n++;
		p = p->next;
	}
	*returnSize = n;
	int * a = (int*)malloc(sizeof(int)*n);
	p = head;
	while (n--){
		a[n] = p->val;
		p = p->next;
	}
	return a;
}