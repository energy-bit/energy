#define _CRT_SECURE_NO_WARNINGS 1
//回文数，第一种解法转置 用时很长
bool isPalindrome(int x){
	if (x<0 || x>INT_MAX)
	{
		return false;
	}
	else
	{
		int res = 0;
		int tmp = x;
		while (tmp != 0)
		{
			res = res * 10 + tmp % 10;
			tmp / 10;
		}
		if (res == x || x == 0)
			return true;
		else
			return false;
	}

}
//第二种  不用转置 

bool isPalindrome(int x){
	int s[100] = {};
	int i = 0;
	int j = 0;
	if (x<0 || x>INT_MAX)
	{
		return false;
	}
	while (x)
	{
		s[i] = x % 10;
		x = x / 10;
		i += 1;
	}
	while (j != i / 2)
	{
		if (s[j] != s[i - 1 - j])
			return false;
		j += 1;
	}
	return true;


}