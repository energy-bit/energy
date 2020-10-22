#define _CRT_SECURE_NO_WARNINGS 1
//模拟实现atoi
/*
#include <stdio.h>
int main()
{
	char*str = "4194";//字符串
	int res = atoi(str);// 库函数 把一个字符转转换成一个整形
	printf("res=%d\n", res);
	return 0;
}
*/
//  模拟实现
/*
#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
int my_atoi(const char*str)
{
	assert(str != NULL);
	//跳过空格  如果是 ‘  4194’这种情况
	while (*str == ' ')// 跳过空格
	{
		str++;
	}
	int flag = 1;// 符号位 
	if (*str == '-')
	{
		flag = -1;  //如果有-  则置-1   看是否是负数
		str++;  //str++ 判断后面的字符是否是数字
	}
		
	else if (*str == '+')
		str++;  // str++ 判断后面的字符是否是数字
	long long res = 0;
	while (*str != '\0')
	{
		if (*str<'0' || *str>'9')// 是个字符 无效的字符串
			break;
		res = res * 10 + (*str - '0');//字符4是52-字符0就是真的数字4了   字符0是48
		if (res > INT_MAX || -res < INT_MAX)
			return 0;
		str++;
	}
	return flag*res;
}
int main()
{
	char*str = "-4194";
	int res1 = atoi(str);
	printf("res1=%d\n", res1);
	int res2 =my_atoi(str);
	printf("res2=%d\n", res2);
	return 0;
}
*/
//有一个二维数组，在数组的每行从左到右是递增的，每列从上到下是递增的
//在这样的数组中查找一个数字是否存在。 
//要求是时间复杂度小于O（N);
 //杨氏数组
// 1 3 5 7
// 2 4 6 8
// 3 5 7 9
// 7 8 9 10
//  暴力解法  不符合时间复杂度
#include <stdio.h>
#include <stdbool.h>
#define ROW 5
#define COL 5
bool FindNum(int ar[ROW][COL], int key)
{
	for (int i = 0; i < ROW; i++)
	{
		for (int j = 0; j < COL; j++)
		{
			if (ar[i][j] == key)
				return true;
		}
	}
	return false;
}
int main()
{
	int ar[ROW][COL] = {
		{ 1, 3, 5, 7, 9, },
		{ 2, 4, 6, 8, 10 },
		{ 11, 13, 15, 17, 19 },
		{ 21, 23, 25, 27, 29 },
		{ 31, 33, 35, 37, 39 }
	};
	int key = 23;
	bool flag = FindNum(ar, key);
	if (flag)
	{
		printf("key%d found.\n", key);
	}
	else
		printf("key%d not found.\n",key);
	return 0;
}
