#define _CRT_SECURE_NO_WARNINGS 1

/*105. ��ǰ��������������й��������
����һ������ǰ�������������������������

ע��:
����Լ�������û���ظ���Ԫ�ء�

���磬����

ǰ����� preorder = [3,9,20,15,7]
������� inorder = [9,3,15,20,7]
�������µĶ�������

    3
   / \
  9  20
    /  \
	15   7*/

/**
* Definition for a binary tree node.
* struct TreeNode {
*     int val;
*     struct TreeNode *left;
*     struct TreeNode *right;
* };
*/


struct TreeNode* buildTree(int* preorder, int preorderSize, int* inorder, int inorderSize)
{
	if (preorderSize == 0)
		return NULL;
	int k = 0;
	while (inorder[k] != preorder[0])
	{
		k++;
	}

	struct  TreeNode*t = (struct TreeNode*)malloc(sizeof(struct TreeNode));
	t->val = preorder[0];
	t->left = buildTree(preorder + 1, k, inorder, k);
	t->right = buildTree(preorder + k + 1, preorderSize - k - 1, inorder + k + 1, inorderSize - k - 1);
	return t;
}