/*����һ���ַ������ҵ����ĵ�һ�����ظ����ַ���������������������������ڣ��򷵻� -1��

ʾ����

s = "leetcode"
���� 0

s = "loveleetcode"
���� 2

*/

//  ��һ�ַ���
/*
class Solution {
public:
int firstUniqChar(string s)
{
int count[256]={0};//ͳ����Ӧ���ַ�����
for(int i=0;i<s.size();i++)
count[s[i]]++;
for(int i=0;i<s.size();i++)
{
if(count[s[i]]==1)
return i;
}
return-1;
}
};
*/
//   �ڶ��ַ���
//  Ѱ���±�   �����ǰ�ʹӺ��ҵ����±���ͬ ��˵���ǵ�һ�����ظ����ַ�
class Solution {
public:
	int firstUniqChar(string s)
	{
		for (int i = 0; i<s.size(); i++)
		{
			int index = s.find(s[i]);//  ��ǰ��
			int reverse_index = s.rfind(s[i]);//  �Ӻ���
			if (index == reverse_index)
				return i;
		}
		return -1;
	}
};