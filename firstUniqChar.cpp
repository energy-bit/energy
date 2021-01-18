/*给定一个字符串，找到它的第一个不重复的字符，并返回它的索引。如果不存在，则返回 -1。

示例：

s = "leetcode"
返回 0

s = "loveleetcode"
返回 2

*/

//  第一种方法
/*
class Solution {
public:
int firstUniqChar(string s)
{
int count[256]={0};//统计相应的字符次数
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
//   第二种方法
//  寻找下标   如果从前和从后找到的下标相同 就说明是第一个不重复的字符
class Solution {
public:
	int firstUniqChar(string s)
	{
		for (int i = 0; i<s.size(); i++)
		{
			int index = s.find(s[i]);//  从前找
			int reverse_index = s.rfind(s[i]);//  从后找
			if (index == reverse_index)
				return i;
		}
		return -1;
	}
};