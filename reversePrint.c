#define _CRT_SECURE_NO_WARNINGS 1

/*����һ�������ͷ�ڵ㣬��β��ͷ����������ÿ���ڵ��ֵ�������鷵�أ���

 

ʾ�� 1��

���룺head = [1,3,2]
�����[2,3,1]
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

	int n = 0;//����������С
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