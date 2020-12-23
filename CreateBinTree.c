#define _CRT_SECURE_NO_WARNINGS 1
/*��Ŀ����
��һ�����򣬶����û������һ����������ַ��������ݴ��ַ�������һ������������ָ�뷽ʽ�洢����
�������µ���������ַ����� ABC##DE#G##F### ���С�#����ʾ���ǿո񣬿ո��ַ����������
������˶������Ժ��ٶԶ������������������������������
��������:
�������1���ַ��������Ȳ�����100��
�������:
�����ж���������ݣ�����ÿ�����ݣ�
����������ַ���������������������������У�ÿ���ַ����涼��һ���ո�
ÿ��������ռһ�С�
ʾ��1
����
abc##de#g##f###

���
c b e g d f a */
#include<stdio.h>
#include<assert.h>
#include<malloc.h>

typedef struct BinTreeNode
{
	char data;
	struct BinTreeNode *left;
	struct BinTreeNode *right;
}BinTreeNode;

typedef BinTreeNode* BinTree;

BinTree CreateBinTree(const char *str, int *pi)
{
	if (str[*pi] == '#' || str[*pi] == '\0')
		return NULL;
	else
	{
		BinTreeNode *t = (BinTreeNode*)malloc(sizeof(BinTreeNode));
		assert(t != NULL);
		t->data = str[*pi];
		(*pi)++;
		t->left = CreateBinTree(str, pi);
		(*pi)++;
		t->right = CreateBinTree(str, pi);
		return t;
	}
}
void InOrder(BinTree t)
{
	if (t != NULL)
	{
		InOrder(t->left);
		printf("%c ", t->data);
		InOrder(t->right);
	}
}
int main()
{
	BinTree bt = NULL;
	char str[100] = { 0 };
	scanf("%s", str);
	int i = 0;
	bt = CreateBinTree(str, &i);
	InOrder(bt);

	return 0;
}