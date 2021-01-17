/*剑指 Offer 67. 把字符串转换成整数


示例 1:

输入: "42"
输出: 42
示例 2:

输入: "   -42"
输出: -42
解释: 第一个非空白字符为 '-', 它是一个负号。
     我们尽可能将负号与后面所有连续出现的数字组合起来，最后得到 -42 。
	 示例 3:

	 输入: "4193 with words"
	 输出: 4193
	 解释: 转换截止于数字 '3' ，因为它的下一个字符不为数字。
	 示例 4:

	 输入: "words and 987"
	 输出: 0
	 解释: 第一个非空字符是 'w', 但它不是数字或正、负号。
	 因此无法执行有效的转换。
	 示例 5:

	 输入: "-91283472332"
	 输出: -2147483648
	 解释: 数字 "-91283472332" 超过 32 位有符号整数范围。
	      因此返回 INT_MIN (−231) 。

		*/

class Solution {
public:
	int strToInt(string str) {
		int i = 0, flag = 1;
		long res = 0; //默认flag = 1，正数
		while (str[i] == ' ') i++;
		if (str[i] == '-') flag = -1;
		if (str[i] == '-' || str[i] == '+') i++;
		for (; i < str.size() && isdigit(str[i]); i++)  {
			res = res * 10 + (str[i] - '0');
			if (res >= INT_MAX && flag == 1) return  INT_MAX;
			if (res > INT_MAX && flag == -1) return  INT_MIN;
		}
		return flag * res;
	}
};