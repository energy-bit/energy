#define _CRT_SECURE_NO_WARNINGS 1

/*1662. ��������ַ��������Ƿ����
���������ַ������� word1 �� word2 ��������������ʾ���ַ�����ͬ������ true �����򣬷��� false ��

�����ʾ���ַ��� ���������е�����Ԫ�� ��˳�� �����γɵ��ַ�����

 

ʾ�� 1��

���룺word1 = ["ab", "c"], word2 = ["a", "bc"]
�����true
���ͣ�
word1 ��ʾ���ַ���Ϊ "ab" + "c" -> "abc"
word2 ��ʾ���ַ���Ϊ "a" + "bc" -> "abc"
�����ַ�����ͬ������ true
ʾ�� 2��

���룺word1 = ["a", "cb"], word2 = ["ab", "c"]
�����false
ʾ�� 3��

���룺word1  = ["abc", "d", "defg"], word2 = ["abcddefg"]
�����true
*/

bool arrayStringsAreEqual(char ** word1, int word1Size, char ** word2, int word2Size)
{
	char arr1[1000] = { 0 };
	char arr2[1000] = { 0 };
	int i, j;
	for (i = 0; i<word1Size; i++)
	{
		strcat(arr1, word1[i]);
	}
	for (j = 0; j<word2Size; j++)
	{
		strcat(arr2, word2[j]);
	}
	int len1 = strlen(arr1);
	int len2 = strlen(arr2);
	if (len1<len2 || len1>len2)
	{
		return false;
	}
	if (strcmp(arr1, arr2) == 0)
	{
		return true;
	}
	else
		return false;
}