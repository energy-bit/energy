/*链接：https://www.nowcoder.com/questionTerminal/8c949ea5f36f422594b306a2300315da

计算字符串最后一个单词的长度，单词以空格隔开。
输入描述:
输入一行，代表要计算的字符串，非空，长度小于5000。
输出描述:

输出一个整数，表示输入字符串最后一个单词的长度。

示例1
输入
hello nowcoder
输出
8
*/

#include <iostream>
#include <string>
using namespace std;

int lengthOfLastWord(string s)
{
	if (s.size() == 0)
		return 0;
	int n = s.rfind(' ');
	if (n == string::npos)
		return s.size();
	return s.size() - n - 1;
}
int main()
{
	string s;
	getline(cin, s);
	int len = lengthOfLastWord(s);
	cout << len;
}
