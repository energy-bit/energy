#define _CRT_SECURE_NO_WARNINGS 1
/*160. �ཻ����
��дһ�������ҵ������������ཻ����ʼ�ڵ㡣

���������������



�ڽڵ� c1 ��ʼ�ཻ��

 

ʾ�� 1��



���룺intersectVal = 8, listA = [4,1,8,4,5], listB = [5,0,1,8,4,5], skipA = 2, skipB = 3
�����Reference of the node with value = 8
������ͣ��ཻ�ڵ��ֵΪ 8 ��ע�⣬������������ཻ����Ϊ 0����
�Ӹ��Եı�ͷ��ʼ�������� A Ϊ [4,1,8,4,5]��
                      ���� B Ϊ [5,0,1,8,4,5]��
		�� A �У��ཻ�ڵ�ǰ�� 2 ���ڵ㣻�� B �У��ཻ�ڵ�ǰ�� 3 ���ڵ㡣
 

ʾ�� 2��



���룺intersectVal = 2, listA = [0,9,1,2,4], 
                        listB = [3,2,4], 
				skipA = 3, skipB = 1
�����Reference of the node with value = 2
������ͣ��ཻ�ڵ��ֵΪ 2 ��ע�⣬������������ཻ����Ϊ 0����
�Ӹ��Եı�ͷ��ʼ�������� A Ϊ [0,9,1,2,4]��
                     ���� B Ϊ [3,2,4]���� A �У��ཻ�ڵ�ǰ�� 3 ���ڵ㣻�� B �У��ཻ�ڵ�ǰ�� 1 ���ڵ㡣
 

ʾ�� 3��



���룺intersectVal = 0, listA = [2,6,4], listB = [1,5], skipA = 3, skipB = 2
�����null
������ͣ��Ӹ��Եı�ͷ��ʼ�������� A Ϊ [2,6,4]������ B Ϊ [1,5]�����������������ཻ������ intersectVal ����Ϊ 0���� skipA �� skipB ����������ֵ��
���ͣ������������ཻ����˷��� null��*/

/**
* Definition for singly-linked list.
* struct ListNode {
*     int val;
*     struct ListNode *next;
* };
*/

int getLength(struct ListNode *head)
{
	if (head == NULL)
		return 0;
	int len = 0;
	struct ListNode * cur = head;
	while (cur != NULL)
	{
		len++;
		cur = cur->next;
	}
	return len;
}
struct ListNode *getIntersectionNode(struct ListNode *headA, struct ListNode *headB) {
	if (headA == NULL || headB == NULL)
		return false;
	int lenA = getLength(headA);
	int lenB = getLength(headB);
	struct ListNode *shortList;
	struct ListNode  *longList;
	int k = abs(lenA - lenB);
	if (lenA>lenB)
	{
		longList = headA;
		shortList = headB;
	}
	else
	{
		longList = headB;
		shortList = headA;
	}
	while (k--)
		longList = longList->next;

	while (shortList != NULL&&longList != NULL)
	{
		if (longList == shortList)
			return longList;
		longList = longList->next;
		shortList = shortList->next;
	}
	return false;
}