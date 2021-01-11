/*输入一个整数数组，实现一个函数来调整该数组中数字的顺序，使得所有奇数位于数组的前半部分，所有偶数位于数组的后半部分。

?

示例：

输入：nums =?[1,2,3,4]
输出：[1,3,2,4] 
注：[3,1,2,4] 也是正确的答案之一。

*/

/**
* Note: The returned array must be malloced, assume caller calls free().
*/

int* exchange(int* nums, int numsSize, int* returnSize)
{
	int *arr = malloc(sizeof(int)*numsSize);
	//   memset(arr, 0, numsSize);
	int i = 0, j = 0, k = numsSize - 1;
	for (i = 0; i<numsSize; i++)
	{
		if (nums[i] % 2 == 1)
		{
			arr[j++] = nums[i];
		}
		else
			arr[k--] = nums[i];
	}
	*returnSize = numsSize;
	return arr;
}
