#define _CRT_SECURE_NO_WARNINGS 1
int reverse(int x)
{
	int pop;
	long sum = 0;      //long����Ҳ��2^-31��2^31-1.
	while (x != 0)
	{
		pop = x % 10;
		sum = sum * 10 + pop;
		x = x / 10;           //��ת����

	}
	if ((int)sum != sum)       // ���õ���long���͵�sum��int�����Ե�sum���бȽ�����ͬ���������0
	{
		return 0;
	}
	return (int)sum;
}

