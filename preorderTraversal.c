#define _CRT_SECURE_NO_WARNINGS 1
/*144. 二叉树的前序遍历
输入：root = [1,null,2,3]
输出：[1,2,3]
示例 2：

输入：root = []
输出：[]
示例 3：

输入：root = [1]
输出：[1]

输入：root = [1,2]
输出：[1,2]

输入：root = [1,null,2]
输出：[1,2]
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
		return size(t->left) + size(t->right) + 1;// 左树的个数+右树的个数 在+根
}
void  _preorderTraversal(struct TreeNode*t, int *preorder, int *pi)
{
	if (t != NULL)
	{
		preorder[*pi] = t->val;//把数据保存起来
		(*pi)++;
		_preorderTraversal(t->left, preorder, pi);
		_preorderTraversal(t->right, preorder, pi);
	}
}
int* preorderTraversal(struct TreeNode* root, int* returnSize)
{
	int n = size(root);
	int *preorder = (int*)malloc(sizeof(int)*n);// 前序遍历的空间大小
	*returnSize = n;
	//  进行前序遍历  内部方法
	int i = 0;// 创建一个下标
	_preorderTraversal(root, preorder, &i); //把申请的空间 和下标传进去
	return preorder;
}