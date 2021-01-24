/*有效的运算符包括 +, -, *, / 。每个运算对象可以是整数，也可以是另一个逆波兰表达式。
说明：

整数除法只保留整数部分。
给定逆波兰表达式总是有效的。换句话说，表达式总会得出有效数值且不存在除数为 0 的情况。
示例 1：

输入: ["2", "1", "+", "3", "*"]
输出: 9
解释: 该算式转化为常见的中缀算术表达式为：((2 + 1) * 3) = 9
示例 2：

输入: ["4", "13", "5", "/", "+"]
输出: 6
解释: 该算式转化为常见的中缀算术表达式为：(4 + (13 / 5)) = 6
示例 3：

输入: ["10", "6", "9", "3", "+", "-11", "*", "/", "*", "17", "+", "5", "+"]
输出: 22
*/

class Solution {
public:
	int evalRPN(vector<string>& tokens)
	{
		int len = tokens.size();
		stack<int> st;
		for (size_t i = 0; i<len; i++)
		{
			if (!(tokens[i] == "+" || tokens[i] == "-" || tokens[i] == "*" || tokens[i] == "/"))
				st.push(atoi(tokens[i].c_str()));
			else
			{
				int left_val, right_val;
				right_val = st.top();
				st.pop();
				left_val = st.top();
				st.pop();
				if (tokens[i] == "+")
				{
					st.push(right_val + left_val);
				}
				else if (tokens[i] == "-")
				{
					st.push(left_val - right_val);
				}
				else if (tokens[i] == "*")
				{
					st.push(left_val*right_val);
				}
				else
				{
					st.push(left_val / right_val);
				}

			}

		}
		return st.top();
	}
};