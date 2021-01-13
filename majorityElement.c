/*数组中有一个数字出现的次数超过数组长度的一半，请找出这个数字。

?

你可以假设数组是非空的，并且给定的数组总是存在多数元素。

?

示例?1:

输入: [1, 2, 3, 2, 2, 2, 5, 4, 2]
输出: 2

*/
//第一种方法
int  com(int *x, int *y)
{
	if (*x>*y)
		return 1;
	else if (*x<*y)
		return -1;
	else
		return 0;
}
int majorityElement(int* nums, int numsSize)
{
	qsort(nums, numsSize, sizeof(int), com);
	return nums[numsSize / 2];
}