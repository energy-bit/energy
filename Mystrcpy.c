#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <string.h>
#include <assert.h>
                //  拷贝目标                  拷贝源
char *Mystrcpy(char *strDestination, const char *strSource)
{
	assert(strDestination != NULL&&strSource != NULL); // 判断参数有效性
	char*p = strDestination;//  用指针p 保存目标
	while (*strSource != NULL)
	{
		*p++ = *strSource++;
	}
	*p = '\0';
	return strDestination;
}
int main()
{
	char str1[20] = "HolleBity";
	char str2[20] = "cpp";
	//strcpy(str1, str2);
	//printf("%s\n", str1);
	Mystrcpy(str1, str2);
	printf("%s\n", str1);
	return 0;
}


