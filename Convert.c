#define _CRT_SECURE_NO_WARNINGS 1

/*����һ�ö��������������ö���������ת����һ�������˫������Ҫ���ܴ����κ��µĽ�㣬ֻ�ܵ������н��ָ���ָ��*/


/**
* struct TreeNode {
*	int val;
*	struct TreeNode *left;
*	struct TreeNode *right;
* };
*/

/**
*
* @param pRootOfTree TreeNode��
* @return TreeNode��
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