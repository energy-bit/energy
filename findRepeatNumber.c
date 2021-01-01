#define _CRT_SECURE_NO_WARNINGS 1

/*剑指 Offer 03. 数组中重复的数字
找出数组中重复的数字。


在一个长度为 n 的数组 nums 里的所有数字都在 0～n-1 的范围内。
数组中某些数字是重复的，但不知道有几个数字重复了，也不知道每个数字重复了几次。
请找出数组中任意一个重复的数字。

示例 1：

输入：
[2, 3, 1, 0, 2, 5, 3]
输出：2 或 3
*/

//   思想   
//先排序  再根据快慢指针   只要相邻的两个数相等就是 找到了

// 代码还需优化

/*
void Swap(int *a, int *b)
{
int temp = *a;
*a = *b;
*b = temp;
}
int _Partition_1(int *elem, int first, int last)
{
int key = elem[first];
while (first < last)
{
while (first<last && elem[last] >= key)
last--;
Swap(&elem[last], &elem[first]);

while (first<last && elem[first]<key)
first++;
Swap(&elem[last], &elem[first]);
}
return first;
}
void QuickSort_1(int *elem, int first, int last)
{
if (first >= last - 1)
return;

int pos = _Partition_1(elem, first, last - 1);

QuickSort_1(elem, first, pos);   //[   )
QuickSort_1(elem, pos + 1, last);
}

int findRepeatNumber(int* nums, int numsSize)
{
QuickSort_1(nums, 0, numsSize);
int i;
for(i=0;i<numsSize;i++)
{
if(nums[i]==nums[i+1])
return nums[i];
}
return -1;
}
*/





int  com(int *x, int *y)
{
	if (*x>*y)
		return 1;
	else if (*x<*y)
		return -1;
	else
		return 0;
}
int findRepeatNumber(int* nums, int numsSize){
	//先排序，在比较相邻两个
	qsort(nums, numsSize, sizeof(int), com);

	for (int i = 0; i<numsSize - 1; i++)
	{
		if (nums[i] == nums[i + 1])
			return nums[i];
	}
	return nums[0];
}
