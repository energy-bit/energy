#define _CRT_SECURE_NO_WARNINGS 1

/**
* Definition for a binary tree node.
* struct TreeNode {
*     int val;
*     struct TreeNode *left;
*     struct TreeNode *right;
* };
*/


struct TreeNode* buildTree(int* inorder, int inorderSize, int* postorder, int postorderSize)
{
	if (inorderSize == 0)
		return NULL;
	int k = 0;
	while (inorder[k] != postorder[postorderSize - 1])
		k++;

	struct TreeNode *t = (struct TreeNode*)malloc(sizeof(struct TreeNode));
	t->val = inorder[k];

	t->right = buildTree(inorder + k + 1, inorderSize - k - 1, postorder + k, postorderSize - k - 1);
	t->left = buildTree(inorder, k, postorder, k);

	return t;
}