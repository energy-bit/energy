#define _CRT_SECURE_NO_WARNINGS 1
// д��һ������ ����һ������ĸ��������ɵ��ַ�������һ���ַ�
//Ȼ����������ַ��к��и��ַ��ĸ����������ִ�Сд��
//�� ����ABCDEF  A  ����� 1
#include<stdio.h>
#include<assert.h>
int Findchar(char*str, char*ch)
{
	assert(str != NULL);
	int count = 0;
	while (*str != '\0')
	{
		if (*str >= 'A'&&*str <= 'Z')
			*str = *str + 32;
		if (ch >= 'A'&&ch <= 'Z')
			ch += 32;
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
	char str[100] = { 0 };
	gets(str);
	char ch;
	scanf("%c", &ch);
	int count = Findchar(str, ch);
	printf("%d\n", count);
	return 0;
}