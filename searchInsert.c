#define _CRT_SECURE_NO_WARNINGS 1
/*
��������λ��
����һ�����������һ��Ŀ��ֵ�����������ҵ�Ŀ��ֵ�������������������Ŀ��ֵ�������������У����������ᱻ��˳������λ�á�
����Լ������������ظ�Ԫ�ء�
ʾ�� 1:
���� : [1, 3, 5, 6], 5
��� : 2
	 ʾ�� 2 :
 ���� : [1, 3, 5, 6], 2
  ��� : 1
	   ʾ�� 3 :
   ���� : [1, 3, 5, 6], 7
	��� : 4
		 ʾ�� 4 :
	 ���� : [1, 3, 5, 6], 0
	  ��� : 0
	  */
//���۰�������Ч��
int searchInsert(int* nums, int numsSize, int target){
	int right = numsSize - 1;
	int left = 0;
	if (nums[right]<target)
		return right + 1; 
	while (left<right)
	{
		 int mid = (left + right) / 2;
		if (nums[mid]<target)
			left = mid + 1;
		else
			right = mid;
	}
	return left;
}