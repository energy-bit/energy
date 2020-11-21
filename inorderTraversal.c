#define _CRT_SECURE_NO_WARNINGS 1
/*94. 二叉树的中序遍历
给定一个二叉树的根节点 root ，返回它的 中序 遍历。
输入：root = [1,null,2,3]
输出：[1,3,2]
示例 2：

输入：root = []
输出：[]
示例 3：

输入：root = [1]
输出：[1]

输入：root = [1,2]
输出：[2,1]

输入：root = [1,null,2]
输出：[1,2]*/

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