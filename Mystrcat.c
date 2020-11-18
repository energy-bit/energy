#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <string.h>
#include <assert.h>
char *my_strcat(char *strDestination, const char *strSource)
{
	assert(strDestination != NULL&&strSource != NULL);
	char *p = strDestination;
	while (p != NULL)
		*p++;
	while (strSource != NULL)
		*p++ = *strSource++;
	return strDestination;
}
int main()
{
	char str1[20] = "holle";
	char str2[20] = "bity";
	strcat(str1, str2);
	printf("%s\n", str1);
	my_strcat(str1, str2);
	printf("%s\n", str1);
	return 0;
}