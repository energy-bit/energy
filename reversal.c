#define _CRT_SECURE_NO_WARNINGS 1
int reverse(int x)
{
	int pop;
	long sum = 0;      //long类型也是2^-31到2^31-1.
	while (x != 0)
	{
		pop = x % 10;
		sum = sum * 10 + pop;
		x = x / 10;           //反转整数

	}
	if ((int)sum != sum)       // 将得到的long类型的sum和int类型性的sum进行比较若不同则溢出返回0
	{
		return 0;
	}
	return (int)sum;
}

