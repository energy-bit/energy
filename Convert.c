#define _CRT_SECURE_NO_WARNINGS 1

/*输入一棵二叉搜索树，将该二叉搜索树转换成一个排序的双向链表。要求不能创建任何新的结点，只能调整树中结点指针的指向*/


/**
* struct TreeNode {
*	int val;
*	struct TreeNode *left;
*	struct TreeNode *right;
* };
*/

/**
*
* @param pRootOfTree TreeNode类
* @return TreeNode类
*/
void ConvertList(struct TreeNode *t, struct TreeNode **pre)
{
	if (t == NULL)
		return;
	ConvertList(t->left, pre);
	t->left = *pre;
	if (*pre != NULL)
		(*pre)->right = t;
	*pre = t;
	ConvertList(t->right, pre);
}


struct TreeNode* Convert(struct TreeNode* pRootOfTree)
{
	// write code here
	if (pRootOfTree == NULL)
		return NULL;
	struct TreeNode *pre = NULL;
	ConvertList(pRootOfTree, &pre);
	struct TreeNode *pHead = pre;
	while (pHead->left != NULL)
		pHead = pHead->left;
	return pHead;
}