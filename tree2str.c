#define _CRT_SECURE_NO_WARNINGS 1

/*606. ���ݶ����������ַ���
����Ҫ����ǰ������ķ�ʽ����һ��������ת����һ�������ź�������ɵ��ַ�����

�սڵ�����һ�Կ����� "()" ��ʾ����������Ҫʡ�����в�Ӱ���ַ�����ԭʼ������֮���һ��һӳ���ϵ�Ŀ����Ŷԡ�

ʾ�� 1:

����: ������: [1,2,3,4]
       1
     /   \
    2     3
   /    
  4     

���: "1(2(4))(3)"

����: ԭ�����ǡ�1(2(4)())(3())����
����ʡ�����в���Ҫ�Ŀ����Ŷ�֮��
�����ǡ�1(2(4))(3)����
ʾ�� 2:

����: ������: [1,2,3,null,4]
       1
     /   \
    2     3
     \  
      4 

���: "1(2()(4))(3)"

����: �͵�һ��ʾ�����ƣ�
�������ǲ���ʡ�Ե�һ�����������ж���������֮���һ��һӳ���ϵ��*/
/**
* Definition for a binary tree node.
* struct TreeNode {
*     int val;
*     struct TreeNode *left;
*     struct TreeNode *right;
* };
*/

void _tree2str(struct TreeNode* t, char *str)
{
	if (t == NULL)
		return;
	char buf[10] = { 0 };
	sprintf(buf, "%d", t->val);
	strcat(str, buf);
	if (t->left == NULL)
	{
		if (t->right != NULL)
			strcat(str, "()");
		else
			return;
	}
	else
	{
		strcat(str, "(");
		_tree2str(t->left, str);
		strcat(str, ")");
	}
	if (t->right == NULL)
		return;
	else
	{
		strcat(str, "(");
		_tree2str(t->right, str);
		strcat(str, ")");
	}
}
char * tree2str(struct TreeNode* t)
{
	int n = 100000;
	char *str = (char*)malloc(sizeof(char)*n);
	memset(str, 0, n);
	_tree2str(t, str);
	return str;
}