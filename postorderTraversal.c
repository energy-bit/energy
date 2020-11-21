#define _CRT_SECURE_NO_WARNINGS 1
/*145. 二叉树的后序遍历
给定一个二叉树，返回它的 后序 遍历。

示例:

输入: [1,null,2,3]  
   1
    \
     2
    /
   3 

   输出: [3,2,1]*/
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
void _postorderTraversal(struct TreeNode *t, int *postorder, int*pi)
{
	if (t != NULL)
	{
		_postorderTraversal(t->left, postorder, pi);
		_postorderTraversal(t->right, postorder, pi);
		postorder[*pi] = t->val;
		(*pi)++;
	}
}
int* postorderTraversal(struct TreeNode* root, int* returnSize)
{
	int n = size(root);
	int*postorder = (int*)malloc(sizeof(int)*n);
	*returnSize = n;
	int i = 0;
	_postorderTraversal(root, postorder, &i);
	return postorder;
}