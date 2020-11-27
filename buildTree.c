#define _CRT_SECURE_NO_WARNINGS 1

/*105. 从前序与中序遍历序列构造二叉树
根据一棵树的前序遍历与中序遍历构造二叉树。

注意:
你可以假设树中没有重复的元素。

例如，给出

前序遍历 preorder = [3,9,20,15,7]
中序遍历 inorder = [9,3,15,20,7]
返回如下的二叉树：

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