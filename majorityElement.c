/*��������һ�����ֳ��ֵĴ����������鳤�ȵ�һ�룬���ҳ�������֡�

?

����Լ��������Ƿǿյģ����Ҹ������������Ǵ��ڶ���Ԫ�ء�

?

ʾ��?1:

����: [1, 2, 3, 2, 2, 2, 5, 4, 2]
���: 2

*/
//��һ�ַ���
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