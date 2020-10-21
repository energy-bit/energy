#define _CRT_SECURE_NO_WARNINGS 1
/*
#include <stdio.h>
int*twoSum(int* nums, int numsSize, int target, int*returnSize)
{
	for (int i = 0; i < numsSize; i++)
	{
		for (int j = i + 1; j < numsSize; j++)
		{
			if (nums[i] + nums[j] == target)
			{
				int *ret = malloc(sizeof(int) * 2);
				ret[0] = i;
				ret[1] = j;
				return ret;
			}
		}
	}
	*returnSize = 0;
	return 0;
}
int main()

{
	int *a;
	int nums[4] = { 2, 7, 11, 15 };
	a = twoSum(nums, 4, 9, 2);
	printf("%d %d ", a[0], a[1]);
	return 0;
}
/*
#include <stdio.h>
int *runningSum(int*nums, int numsSize, int*returnSize)
{
	int*ret = malloc(sizeof(int)* 5);
	ret[0] = nums[0];
	for (int j = 1; j < numsSize; j++)
	{
		
		ret[j] = nums[j] + ret[j-1];
	}
	return ret;
	*returnSize = 5;
	return NULL;
}
int main()
{
	int *a;
	int nums[5] = { 3,1,2,10,1 };
	a = runningSum(nums, 5, 5);
	printf("%d %d %d %d %d\n", a[0], a[1], a[2], a[3],a[4]);

	return 0;
}
/*
#include<stdio.h>
#define swapintbit(n)(((n)&0x55555555)<<1)|(((n)&0xaaaaaaaa)>>1)//实现奇数位和偶数位的交换
int main()
{
	int n = -5;
	printf("%d", swapintbit(n));
	// 1000 0000 0000 0000 0000 0000 0000 1001  -9
	// 1111 1111 1111 1111 1111 1111 1111 0111  -9的补码

	// 1000 0000 0000 0000 0000 0000 0000 0101  -5
	// 1111 1111 1111 1111 1111 1111 1111 1011  -5的补码
	return 0;
}
/*
一个数组中只有1个数字是出现一次，其他的所有数字都出现了两次。
编写一个函数找出这1个只出现一次的数字

# include <stdio.h>
int FindNumber(int ar[], int n)
{
	int j = 0;
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < n; ++j)
		{
			if (i != j && ar[i] == ar[j])
				break;
		}
		if (j>=n)
			return ar[i];
	}
	
}
int main()
{
	int ar[] = { 1, 2, 3, 4, 5, 4, 3, 2, 1 };
	int n = sizeof(ar) / sizeof(ar[0]);
	printf("value=%d\n", FindNumber(ar, n));
	return 0;
}
/*
第二种解法
#include <stdio.h>t
int FindNumber(int ar[], int n)
{
	int res = 0;
	for (int i = 0; i < n; i++)
	{
		res ^= ar[i];
	}
	return res;
}
int main()
{
	//0011  3^3=0 相同的数异或之后为0
	//0011
	int ar[] = { 1, 2, 3, 4, 5, 4, 3, 2, 1 };
		int n = sizeof(ar) / sizeof(ar[0]);
		printf("value=%d\n", FindNumber(ar, n));
		return 0;
	return 0;
}
/*
一个数组中只有两个数字是出现一次，其他的所有数字都出现了两次。
编写一个函数找出这两个只出现一次的数字
/*
#include <stdio.h>
void FindNumber(int ar[], int n, int*num1, int*num2)
{
	int res = 0;
	for (int i = 0; i < n; i++)
	{
		res ^= ar[i];
	}
	//分割结果
	int pos = 0;
	for (int i = 0; i < 32; i++)
	{
		if (res&(1 << i))
		{
			pos = i;
			break;
		}
	}
	*num1 = 0;
	*num2 = 0;
	for (int i = 0; i < n; i++)
	{
		if (ar[i] & (1 << pos)) //假如这里分割的是   1 1 5 5 3
		{
			*num1 ^= ar[i];     //  异或后11 55就为0了    所以就只剩3了
		}
		else                       //假如这里分割的是 2 2 4 4 6
		{
			*num2 ^= ar[i];      // 同理 相同的都异或了  只剩下6   就是我们的结果了
		}
	}
}
int  main()
{
	//0011 3
	//0110 6
	//0101  异或
	int ar[] = { 1, 2, 4, 6, 5, 5, 4, 3, 2, 1 };
	int n = sizeof(ar) / sizeof(ar[0]);
	int num1, num2;
	FindNumber(ar, n, &num1, &num2);
	printf("num1=%d num2=%d \n",num1,num2 );
	return 0;
}
*/