#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <string.h>
#include <assert.h>
int mystrlen(const char *string)
{
	int count = 0;
	assert(*string != NULL);
	while (*string++ != NULL)
		count++;
	return count;
}
int main()
{
	char *str = "hollebity";
	int len=strlen(str);
	printf("%d\n", len);
	int len1 = mystrlen(str);
	printf("%d\n", len1);
	return 0;
}