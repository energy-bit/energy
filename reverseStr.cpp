/*给定一个字符串 s 和一个整数 k，你需要对从字符串开头算起的每隔 2k 个字符的前 k 个字符进行反转。

如果剩余字符少于 k 个，则将剩余字符全部反转。
如果剩余字符小于 2k 但大于或等于 k 个，则反转前 k 个字符，其余字符保持原样。
 

示例:

输入: s = "abcdefg", k = 2
输出: "bacdfeg"

*/

class Solution {
public:
	void reverse(string &s, int start, int end)
	{
		while (start<end)
		{
			char tmp = s[start];
			s[start] = s[end];
			s[end] = tmp;
			start++;
			end--;
		}
	}
	string reverseStr(string s, int k)
	{
		int len = s.size();
		for (int i = 0; i<len; i += 2 * k)
		{
			if (i + k<len)
				reverse(s, i, i + k - 1);
			else
				reverse(s, i, len - 1);
		}
		return s;
	}
};