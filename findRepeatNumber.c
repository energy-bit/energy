#define _CRT_SECURE_NO_WARNINGS 1

/*��ָ Offer 03. �������ظ�������
�ҳ��������ظ������֡�


��һ������Ϊ n ������ nums ����������ֶ��� 0��n-1 �ķ�Χ�ڡ�
������ĳЩ�������ظ��ģ�����֪���м��������ظ��ˣ�Ҳ��֪��ÿ�������ظ��˼��Ρ�
���ҳ�����������һ���ظ������֡�

ʾ�� 1��

���룺
[2, 3, 1, 0, 2, 5, 3]
�����2 �� 3
*/

//   ˼��   
//������  �ٸ��ݿ���ָ��   ֻҪ���ڵ���������Ⱦ��� �ҵ���

// ���뻹���Ż�

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
	//�������ڱȽ���������
	qsort(nums, numsSize, sizeof(int), com);

	for (int i = 0; i<numsSize - 1; i++)
	{
		if (nums[i] == nums[i + 1])
			return nums[i];
	}
	return nums[0];
}
