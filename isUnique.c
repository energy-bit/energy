/*
ʵ��һ���㷨��ȷ��һ���ַ��� s �������ַ��Ƿ�ȫ����ͬ��

ʾ�� 1��

����: s = "leetcode"
���: false
ʾ�� 2��

����: s = "abc"
���: true

*/
//��һ�ַ���  ����������
int cmp(const void *a, const void *b) {
	return (*(char*)a > *(char*)b) ? 1 : -1;
}

bool isUnique(char* astr)
{
	if (astr == NULL)
		return true;

	int len = strlen(astr);
	if (len == 0 || len == 1)
		return true;


	qsort(astr, len, sizeof(astr[0]), cmp);
	for (int i = 0; i < len - 1; i++)
	{
		if (astr[i] == astr[i + 1])
			return false;

	}

	return true;
}