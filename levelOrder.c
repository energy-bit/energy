#define _CRT_SECURE_NO_WARNINGS 1

/*102. 二叉树的层序遍历
给你一个二叉树，请你返回其按 层序遍历 得到的节点值。 （即逐层地，从左到右访问所有节点）。

 

示例：
二叉树：[3,9,20,null,null,15,7],

    3
   / \
  9  20
    /  \
   15   7
返回其层次遍历结果：

[
  [3],
  [9,20],
  [15,7]
  ]*/

/**
* Definition for a binary tree node.
* struct TreeNode {
*     int val;
*     struct TreeNode *left;
*     struct TreeNode *right;
* };
*/


/**
* Return an array of arrays of size *returnSize.
* The sizes of the arrays are returned as *returnColumnSizes array.
* Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
*/
int maxDepth(struct TreeNode* root)//求树的高度
{
	if (root == NULL)
		return 0;
	else
	{
		int left_h = maxDepth(root->left);
		int right_h = maxDepth(root->right);
		return (left_h>right_h ? left_h : right_h) + 1;
	}
}

int** levelOrder(struct TreeNode* root, int* returnSize, int** returnColumnSizes)
{
	if (root == NULL)
	{
		*returnSize = 0;
		return NULL;
	}
	int max_level = maxDepth(root);
	*returnSize = max_level;
	int**levelArray = (int**)malloc(sizeof(int*)*max_level);  
	*returnColumnSizes = (int*)malloc(sizeof(int)*max_level);
	struct TreeNode* q1[1000], *q2[1000];
	int q1_size = 0, q2_size = 0;
	q1[0] = root;
	q1_size++;

	int level = 0;
	while (level<max_level)
	{
		levelArray[level] = (int*)malloc(sizeof(int)*q1_size);
		for (int i = 0; i<q1_size; i++)
			levelArray[level][i] = q1[i]->val;
		(*returnColumnSizes)[level] = q1_size;
		for (int i = 0; i<q1_size; i++)
		{
			if (q1[i]->left != NULL)
				q2[q2_size++] = q1[i]->left;
			if (q1[i]->right != NULL)
				q2[q2_size++] = q1[i]->right;
		}
		memcpy(q1, q2, sizeof(struct TreeNode*)*q2_size);
		q1_size = q2_size;
		q2_size = 0;
		level++;
	}
	return levelArray;
}