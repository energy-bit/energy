#define _CRT_SECURE_NO_WARNINGS 1

// 实现一个函数 可以左旋字符串中K个字符
//如  ABCD左旋一个字符得到BCDA
//    ABCD左旋两个字符得到CDAB
/*
#include <stdio.h>
#include <assert.h>
#include <string.h>
//  常规做法  不够快
void LeftRound(char*str, int n)
{
	//1  验证参数的合法性
	assert(str != NULL);
	//2  移动的步长
	int len = strlen(str);
	int step = n%len;  // 步数取余  因为n=13时 就相当左移两位 1200是就在重复移动 所以取余就是移动的步数
	//3  移动
	while (step-- != 0) 
	{
		char tmp = str[0];
		for (int i = 0; i < len - 1; i++)
		{
			str[i] = str[i + 1];
			
		}
		str[len - 1] = tmp;
	}
}
int main()
{
	char str[] = "ABCDEFGHIJK";
	int n = 2;
	LeftRound(str, n);
	printf("str=%s\n", str);
	return 0;
}
*/
/*
#include <stdio.h>
#include <assert.h>
#include <string.h>
void LeftRound(char*str, int n)
{
	assert(str != NULL);
	//2  移动的步长
	int len = strlen(str);
	int step = n%len;
	//3 移动
	char *tmp = (char*)malloc(sizeof(char)*len+1);//  加1  是为\0做准备
	    memset(tmp, 0, sizeof(char)*len);   // 初始化
		strncpy(tmp, str + step, len - step); // 从str+step位置拷贝到最后 存到tmp中
		strncat(tmp, str, step);  //把str中的前面的step步链接到新开辟的tmp中
		strncpy(str, tmp, len);//再将tmp中的拷贝回去
		free(tmp);  //最后释放新开辟的空间
}
int main()
{
		char str[] = "ABCDEFGHIJK";
		int n = 20;
		LeftRound(str, n);
		printf("str=%s\n", str);
		return 0;	
}
*/
/*
#include <stdio.h>
#include <assert.h>
#include <string.h>
void Reverse(char*str, int start, int end)
{
	assert(str != NULL);
	while (start < end)
	{
		char tmp = str[start];
		str[start] = str[end];
		str[end] = tmp;
		start++;
		end--;
	}
}
void LeftRound(char*str, int n)
{
	assert(str != NULL);
	//2  移动的步长
	int len = strlen(str);
	int step = n%len;
	//3 移动 
	Reverse(str, 0, step - 1);   // BA CDEFGHIJK  先分成两部分  前面的先反转
	Reverse(str, step, len - 1); // BA KJIHGFEDC   后部分反转
	Reverse(str, 0, len - 1);    // CDEFGHIJK AB   整体在反转



}
int main()
	{
		char str[] = "ABCDEFGHIJK";
		int n = 2;
		LeftRound(str, n);
		printf("str=%s\n", str);
		return 0;
	}
	*/