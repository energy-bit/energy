#define _CRT_SECURE_NO_WARNINGS 1
/*144. ��������ǰ�����
���룺root = [1,null,2,3]
�����[1,2,3]
ʾ�� 2��

���룺root = []
�����[]
ʾ�� 3��

���룺root = [1]
�����[1]

���룺root = [1,2]
�����[1,2]

���룺root = [1,null,2]
�����[1,2]
*/
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
		return size(t->left) + size(t->right) + 1;// �����ĸ���+�����ĸ��� ��+��
}
void  _preorderTraversal(struct TreeNode*t, int *preorder, int *pi)
{
	if (t != NULL)
	{
		preorder[*pi] = t->val;//�����ݱ�������
		(*pi)++;
		_preorderTraversal(t->left, preorder, pi);
		_preorderTraversal(t->right, preorder, pi);
	}
}
int* preorderTraversal(struct TreeNode* root, int* returnSize)
{
	int n = size(root);
	int *preorder = (int*)malloc(sizeof(int)*n);// ǰ������Ŀռ��С
	*returnSize = n;
	//  ����ǰ�����  �ڲ�����
	int i = 0;// ����һ���±�
	_preorderTraversal(root, preorder, &i); //������Ŀռ� ���±괫��ȥ
	return preorder;
}