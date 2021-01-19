/*给定一个字符串 S，返回 “反转后的” 字符串，其中不是字母的字符都保留在原地，而所有字母的位置发生反转。

 

示例 1：

输入："ab-cd"
输出："dc-ba"
示例 2：

输入："a-bC-dEf-ghIj"
输出："j-Ih-gfE-dCba"
示例 3：

输入："Test1ng-Leet=code-Q!"
输出："Qedo1ct-eeLg=ntse-T!"

*/
class Solution {
public:
	string reverseOnlyLetters(string S)
	{
		if (S.size() <= 1)
			return S;

		char *start = (char*)S.c_str();
		char *end = start + S.size() - 1;
		while (start<end)
		{
			// 寻找左边第一个字母
			while (start<end)
			{
				if ((*start >= 'A'&&*start <= 'Z') || (*start >= 'a'&&*start <= 'z'))
					break;
				start++;
			}
			//寻找右边第一个字母
			while (start<end)
			{
				if ((*end >= 'A'&&*end <= 'Z') || (*end >= 'a'&&*end <= 'z'))
					break;
				end--;
			}
			//交换位置
			char tmp = *start;
			*start = *end;
			*end = tmp;
			start++;
			end--;
		}
		return S;
	}
};