/*�������� n����˳���ӡ���� 1 ������ n λʮ���������������� 3�����ӡ�� 1��2��3 һֱ������ 3 λ�� 999��

ʾ�� 1:

����: n = 1
���: [1,2,3,4,5,6,7,8,9]
?
*/

/**
* Note: The returned array must be malloced, assume caller calls free().
*/
int* printNumbers(int n, int* returnSize)
{
	int len = pow(10, n) - 1;
	int* res = (int*)malloc(sizeof(int)*len);
	for (int i = 0; i<len; i++)
	{
		res[i] = i + 1;
	}
	*returnSize = len;
	return res;
}