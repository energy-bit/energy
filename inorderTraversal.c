#define _CRT_SECURE_NO_WARNINGS 1
/*94. ���������������
����һ���������ĸ��ڵ� root ���������� ���� ������
���룺root = [1,null,2,3]
�����[1,3,2]
ʾ�� 2��

���룺root = []
�����[]
ʾ�� 3��

���룺root = [1]
�����[1]

���룺root = [1,2]
�����[2,1]

���룺root = [1,null,2]
�����[1,2]*/

/**
* Definition for a binary tree node.
* struct TreeNode {
*     int val;
*     struct TreeNode *left;
*     struct TreeNode *right;
* };
*/


/**
* Note: The returned array must be malloced, assume caller calls free().
*/
int size(struct TreeNode *t)
{
	if (t == NULL)
		return 0;
	else
		return size(t->left) + size(t->right) + 1;
}
void _inorderTraversal(struct TreeNode *t, int* inorfer, int* pi)
{
	if (t != NULL)
	{
		_inorderTraversal(t->left, inorfer, pi);
		inorfer[*pi] = t->val;
		(*pi)++;
		_inorderTraversal(t->right, inorfer, pi);
	}
}
int* inorderTraversal(struct TreeNode* root, int* returnSize)
{
	int n = size(root);
	int* inorfer = (int*)malloc(sizeof(int)*n);
	*returnSize = n;
	int i = 0;
	_inorderTraversal(root, inorfer, &i);
	return inorfer;
}