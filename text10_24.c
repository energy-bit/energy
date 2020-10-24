#define _CRT_SECURE_NO_WARNINGS 1
//写一个函数，判断一个字符串是否是另外一个字符串旋转之后的字符串
//例如 s1=AABCD和s2=BBDAA 返回真 或1
//    s1=abcd和s2=ABCD   返回假 或0
//     AABCD左旋一个字符得到 ABCDA
#include <stdio.h>
#include <stdbool.h>
#include <assert.h>
bool IsRotate(char*str, char*sub)
{
	assert(*str != NULL);
	assert(*sub!= NULL);
	if (strlen(str) != strlen(sub))  //判断字符串长度是否相等 如果不相等直接返回假
		return false;
	char*tmp = (char*)malloc(sizeof(char)*strlen(str) * 2 + 1);//  开辟一个两个str长度的空间 +1为了给\0做准备
	strcpy(tmp, str);   //将str里的字符串拷贝到tmp中
	strcat(tmp, str);    //  再将str里的字符串链接到tmp中  得  HelloBityHelloBity
	char*res = strstr(tmp, sub);//       通过查找                     BityHello
	free(tmp);
	return  (res != NULL);  // 找了了不为空则就是真   找不到返回空 就为假

}
int main()
{
	char*str = "HelloBity";
	char*sub = "Bityhello";
	bool flag = IsRotate(str, sub);
	if (flag)
		printf("True");
	else
		printf("False");
	return 0;
}