
/*请实现一个函数，把字符串 s 中的每个空格替换成"%20"。


示例 1：

输入：s = "We are happy."
输出："We%20are%20happy."

*/

char* replaceSpace(char* s)
{
	int  len = strlen(s);

	char *res = malloc(3 * len + 1);  //   最大空间就是全部是空格
	memset(res, 0, 3 * len + 1);//   初始化
	int j = 0;
	for (int i = 0; i<len; i++)
	{
		if (s[i] == ' ')
		{
			strcat(res + j, "%20");
			j += 3;
		}
		else
		{
			res[j++] = s[i];
		}

	}
	return res;
}
