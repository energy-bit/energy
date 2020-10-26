#define _CRT_SECURE_NO_WARNINGS 1
//接受一个由字母和数字组成的字符串，和一个字符，然后输出输入字符串中含有该字符的个数。不区分大小写
#include<stdio.h>
#include<assert.h>
int Findchar(char*str, char*ch)
{
	assert(str != NULL);
	int count = 0;
	while (*str != '\0')
	{
		if (*str >= 'A'&&*str <= 'Z')  
			*str = *str + 32;  // 将字符串里的大写都转成小写
		if (ch >= 'A'&&ch <= 'Z')
			ch += 32;    // 将输入的字符转化成小写
		if (*str == ch)
		{
			count++;
		}
		str++;
	}
	return count;
}
int main()
{
	char str[10000] = { 0 };  
	gets(str);
	char ch;
	scanf("%c", &ch);
	int count = Findchar(str, ch);
	printf("%d\n", count);
	return 0;
}