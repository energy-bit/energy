#define _CRT_SECURE_NO_WARNINGS 1
//ģ��ʵ��atoi
/*
#include <stdio.h>
int main()
{
	char*str = "4194";//�ַ���
	int res = atoi(str);// �⺯�� ��һ���ַ�תת����һ������
	printf("res=%d\n", res);
	return 0;
}
*/
//  ģ��ʵ��
/*
#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
int my_atoi(const char*str)
{
	assert(str != NULL);
	//�����ո�  ����� ��  4194���������
	while (*str == ' ')// �����ո�
	{
		str++;
	}
	int flag = 1;// ����λ 
	if (*str == '-')
	{
		flag = -1;  //�����-  ����-1   ���Ƿ��Ǹ���
		str++;  //str++ �жϺ�����ַ��Ƿ�������
	}
		
	else if (*str == '+')
		str++;  // str++ �жϺ�����ַ��Ƿ�������
	long long res = 0;
	while (*str != '\0')
	{
		if (*str<'0' || *str>'9')// �Ǹ��ַ� ��Ч���ַ���
			break;
		res = res * 10 + (*str - '0');//�ַ�4��52-�ַ�0�����������4��   �ַ�0��48
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
//��һ����ά���飬�������ÿ�д������ǵ����ģ�ÿ�д��ϵ����ǵ�����
//�������������в���һ�������Ƿ���ڡ� 
//Ҫ����ʱ�临�Ӷ�С��O��N);
 //��������
// 1 3 5 7
// 2 4 6 8
// 3 5 7 9
// 7 8 9 10
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