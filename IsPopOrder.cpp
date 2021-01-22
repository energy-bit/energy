/*���������������У���һ�����б�ʾջ��ѹ��˳�����жϵڶ��������Ƿ����Ϊ��ջ�ĵ���˳�򡣼���ѹ��ջ���������־�����ȡ�
��������1,2,3,4,5��ĳջ��ѹ��˳������4,5,3,2,1�Ǹ�ѹջ���ж�Ӧ��һ���������У���4,3,5,1,2�Ͳ������Ǹ�ѹջ���еĵ������С�
��ע�⣺���������еĳ�������ȵģ�
ʾ��1
����
����
[1,2,3,4,5],[4,3,5,1,2]
����ֵ
����
false
*/

class Solution {
public:
	bool IsPopOrder(vector<int> pushV, vector<int> popV)
	{
		if (pushV.size() != popV.size())
			return false;
		stack<int> st;
		int in_index = 0;//  pushV���±�
		int out_index = 0;// popV���±�
		while (out_index<popV.size())
		{
			while (st.empty() || st.top() != popV[out_index])
			{
				if (in_index<pushV.size())
					st.push(pushV[in_index++]);
				else
					return false;
			}
			st.pop();
			out_index++;
		}
		return true;
	}
};