#define _CRT_SECURE_NO_WARNINGS 1
/*
剑指 Offer 55 - I.二叉树的深度

输入一棵二叉树的根节点，求该树的深度。从根节点到叶节点依次经过的节点（含根、叶节点）形成树的一条路径，最长路径的长度为树的深度。

例如：

给定二叉树[3, 9, 20, null, null, 15, 7]，

3
/ \
9  20
/ \
15   7
返回它的最大深度 3 。

*/

/**
* Definition for a binary tree node.
* struct TreeNode {
*     int val;
*     struct TreeNode *left;
*     struct TreeNode *right;
* };
*/


int maxDepth(struct TreeNode* root)
{
	if (root == NULL)
		return 0;
	else
	{
		int left_h = maxDepth(root->left);
		int right_h = maxDepth(root->right);
		return (left_h > right_h ? left_h : right_h) + 1;
	}
}
