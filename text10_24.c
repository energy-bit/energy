#define _CRT_SECURE_NO_WARNINGS 1
//дһ���������ж�һ���ַ����Ƿ�������һ���ַ�����ת֮����ַ���
//���� s1=AABCD��s2=BBDAA ������ ��1
//    s1=abcd��s2=ABCD   ���ؼ� ��0
//     AABCD����һ���ַ��õ� ABCDA
#include <stdio.h>
#include <stdbool.h>
#include <assert.h>
bool IsRotate(char*str, char*sub)
{
	assert(*str != NULL);
	assert(*sub!= NULL);
	if (strlen(str) != strlen(sub))  //�ж��ַ��������Ƿ���� ��������ֱ�ӷ��ؼ�
		return false;
	char*tmp = (char*)malloc(sizeof(char)*strlen(str) * 2 + 1);//  ����һ������str���ȵĿռ� +1Ϊ�˸�\0��׼��
	strcpy(tmp, str);   //��str����ַ���������tmp��
	strcat(tmp, str);    //  �ٽ�str����ַ������ӵ�tmp��  ��  HelloBityHelloBity
	char*res = strstr(tmp, sub);//       ͨ������                     BityHello
	free(tmp);
	return  (res != NULL);  // �����˲�Ϊ���������   �Ҳ������ؿ� ��Ϊ��

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