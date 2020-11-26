#define _CRT_SECURE_NO_WARNINGS 1
/*��ָ Offer 68 - II. �������������������
����һ��������, �ҵ�����������ָ���ڵ������������ȡ�

�ٶȰٿ�������������ȵĶ���Ϊ���������и��� T ��������� p��q������������ȱ�ʾΪһ����� x��
���� x �� p��q �������� x ����Ⱦ����ܴ�һ���ڵ�Ҳ���������Լ������ȣ�����

���磬�������¶�����:  root = [3,5,1,6,2,0,8,null,null,7,4]

ʾ�� 1:

����: root = [3,5,1,6,2,0,8,null,null,7,4], p = 5, q = 1
���: 3
����: �ڵ� 5 �ͽڵ� 1 ��������������ǽڵ� 3��
ʾ�� 2:

����: root = [3,5,1,6,2,0,8,null,null,7,4], p = 5, q = 4
���: 5
����: �ڵ� 5 �ͽڵ� 4 ��������������ǽڵ� 5����Ϊ���ݶ�������������Ƚڵ����Ϊ�ڵ㱾��*/

/**
* Definition for a binary tree node.
* struct TreeNode {
*     int val;
*     struct TreeNode *left;
*     struct TreeNode *right;
* };
//��һ�ַ���
bool findNode(struct TreeNode*t,struct TreeNode*x)//   ���ҽ��
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


//  �ڶ��ַ���
struct TreeNode* lowestCommonAncestor(struct TreeNode* root, struct TreeNode* p, struct TreeNode* q)
{
	/* ������Ϊ�ջ��߽�� p/q Ϊ����� */
	if (root == NULL || root == p || root == q)
	{
		return root;
	}

	/* �ڸ����������������� */
	struct TreeNode *left = lowestCommonAncestor(root->left, p, q);
	struct TreeNode *right = lowestCommonAncestor(root->right, p, q);

	/* ��� p/q �����������У������������в��ң�������ҵ����ͷ��������������ҵ��Ľ�㣨��֮��Ȼ�� */
	/* ��� p/q �ֱ������������������ �����Ϊ����������� */
	/* ��� p/q �������������Ҳ�����������û������������� */
	return left == NULL ? right : right == NULL ? left : root;
}