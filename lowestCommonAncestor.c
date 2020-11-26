#define _CRT_SECURE_NO_WARNINGS 1
/*剑指 Offer 68 - II. 二叉树的最近公共祖先
给定一个二叉树, 找到该树中两个指定节点的最近公共祖先。

百度百科中最近公共祖先的定义为：“对于有根树 T 的两个结点 p、q，最近公共祖先表示为一个结点 x，
满足 x 是 p、q 的祖先且 x 的深度尽可能大（一个节点也可以是它自己的祖先）。”

例如，给定如下二叉树:  root = [3,5,1,6,2,0,8,null,null,7,4]

示例 1:

输入: root = [3,5,1,6,2,0,8,null,null,7,4], p = 5, q = 1
输出: 3
解释: 节点 5 和节点 1 的最近公共祖先是节点 3。
示例 2:

输入: root = [3,5,1,6,2,0,8,null,null,7,4], p = 5, q = 4
输出: 5
解释: 节点 5 和节点 4 的最近公共祖先是节点 5。因为根据定义最近公共祖先节点可以为节点本身。*/

/**
* Definition for a binary tree node.
* struct TreeNode {
*     int val;
*     struct TreeNode *left;
*     struct TreeNode *right;
* };
//第一种方法
bool findNode(struct TreeNode*t,struct TreeNode*x)//   查找结点
{
if(t==NULL)
return false;
if(t==x)
return true;
return findNode(t->left,x)||findNode(t->right,x);
}

struct TreeNode* lowestCommonAncestor(struct TreeNode* root, struct TreeNode* p, struct TreeNode* q)
{
if(root==NULL)
return false;
if(p==root||q==root)
return root;
bool pInleft,pInright,qInleft,qInright;
if(findNode(root->left,p))
{
pInleft=true;
pInright=false;
}
else
{
pInleft=false;
pInright=true;
}
if(findNode(root->right,q))
{
qInleft=false;
qInright=true;
}
else
{
qInleft=true;
qInright=false;
}
if(pInleft&&qInleft)
return lowestCommonAncestor(root->left,p,q);
else if(pInright&&qInright)
return lowestCommonAncestor(root->right,p,q);

return root;
}
*/


//  第二种方法
struct TreeNode* lowestCommonAncestor(struct TreeNode* root, struct TreeNode* p, struct TreeNode* q)
{
	/* 二叉树为空或者结点 p/q 为根结点 */
	if (root == NULL || root == p || root == q)
	{
		return root;
	}

	/* 在根结点的左右子树查找 */
	struct TreeNode *left = lowestCommonAncestor(root->left, p, q);
	struct TreeNode *right = lowestCommonAncestor(root->right, p, q);

	/* 结点 p/q 不在左子树中，就在右子树中查找，如果能找到，就返回在右子树中找到的结点（反之亦然） */
	/* 结点 p/q 分别存在左右两颗子树， 根结点为最近公共祖先 */
	/* 结点 p/q 在左右子树都找不到，则它们没有最近公共祖先 */
	return left == NULL ? right : right == NULL ? left : root;
}