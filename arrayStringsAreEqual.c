#define _CRT_SECURE_NO_WARNINGS 1

/*1662. 检查两个字符串数组是否相等
给你两个字符串数组 word1 和 word2 。如果两个数组表示的字符串相同，返回 true ；否则，返回 false 。

数组表示的字符串 是由数组中的所有元素 按顺序 连接形成的字符串。

 

示例 1：

输入：word1 = ["ab", "c"], word2 = ["a", "bc"]
输出：true
解释：
word1 表示的字符串为 "ab" + "c" -> "abc"
word2 表示的字符串为 "a" + "bc" -> "abc"
两个字符串相同，返回 true
示例 2：

输入：word1 = ["a", "cb"], word2 = ["ab", "c"]
输出：false
示例 3：

输入：word1  = ["abc", "d", "defg"], word2 = ["abcddefg"]
输出：true
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