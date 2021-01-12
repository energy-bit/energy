/*
实现一个算法，确定一个字符串 s 的所有字符是否全都不同。

示例 1：

输入: s = "leetcode"
输出: false
示例 2：

输入: s = "abc"
输出: true

*/
//第一种方法  排序找相邻
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