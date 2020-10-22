#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdbool.h>
#define ROW 5
#define COL 5
bool FindNum(int ar[ROW][COL], int key)
{
	int r = 0;
	int c = COL - 1;  //最后一列
	while (r < ROW&&c >= 0)
	{
		if (key < ar[r][c - 1])
		{
			c--;
		}
		else if (key>ar[r][c - 1])
		{
			r++;
		}
		else
			return true;
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
			printf("key%d not found.\n", key);
		return 0;
	}
