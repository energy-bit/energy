/*���ӣ�https://www.nowcoder.com/questionTerminal/8c949ea5f36f422594b306a2300315da

�����ַ������һ�����ʵĳ��ȣ������Կո������
��������:
����һ�У�����Ҫ������ַ������ǿգ�����С��5000��
�������:

���һ����������ʾ�����ַ������һ�����ʵĳ��ȡ�

ʾ��1
����
hello nowcoder
���
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
