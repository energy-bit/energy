/*����һ���������飬ʵ��һ�����������������������ֵ�˳��ʹ����������λ�������ǰ�벿�֣�����ż��λ������ĺ�벿�֡�

?

ʾ����

���룺nums =?[1,2,3,4]
�����[1,3,2,4] 
ע��[3,1,2,4] Ҳ����ȷ�Ĵ�֮һ��

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
