#define _CRT_SECURE_NO_WARNINGS 1
/*题目描述
编一个程序，读入用户输入的一串先序遍历字符串，根据此字符串建立一个二叉树（以指针方式存储）。
例如如下的先序遍历字符串： ABC##DE#G##F### 其中“#”表示的是空格，空格字符代表空树。
建立起此二叉树以后，再对二叉树进行中序遍历，输出遍历结果。
输入描述:
输入包括1行字符串，长度不超过100。
输出描述:
可能有多组测试数据，对于每组数据，
输出将输入字符串建立二叉树后中序遍历的序列，每个字符后面都有一个空格。
每个输出结果占一行。
示例1
输入
abc##de#g##f###

输出
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