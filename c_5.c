#define _CRT_SECURE_NO_WARNINGS 1

// ʵ��һ������ ���������ַ�����K���ַ�
//��  ABCD����һ���ַ��õ�BCDA
//    ABCD���������ַ��õ�CDAB
/*
#include <stdio.h>
#include <assert.h>
#include <string.h>
//  ��������  ������
void LeftRound(char*str, int n)
{
	//1  ��֤�����ĺϷ���
	assert(str != NULL);
	//2  �ƶ��Ĳ���
	int len = strlen(str);
	int step = n%len;  // ����ȡ��  ��Ϊn=13ʱ ���൱������λ 1200�Ǿ����ظ��ƶ� ����ȡ������ƶ��Ĳ���
	//3  �ƶ�
	while (step-- != 0) 
	{
		char tmp = str[0];
		for (int i = 0; i < len - 1; i++)
		{
			str[i] = str[i + 1];
			
		}
		str[len - 1] = tmp;
	}
}
int main()
{
	char str[] = "ABCDEFGHIJK";
	int n = 2;
	LeftRound(str, n);
	printf("str=%s\n", str);
	return 0;
}
*/
/*
#include <stdio.h>
#include <assert.h>
#include <string.h>
void LeftRound(char*str, int n)
{
	assert(str != NULL);
	//2  �ƶ��Ĳ���
	int len = strlen(str);
	int step = n%len;
	//3 �ƶ�
	char *tmp = (char*)malloc(sizeof(char)*len+1);//  ��1  ��Ϊ\0��׼��
	    memset(tmp, 0, sizeof(char)*len);   // ��ʼ��
		strncpy(tmp, str + step, len - step); // ��str+stepλ�ÿ�������� �浽tmp��
		strncat(tmp, str, step);  //��str�е�ǰ���step�����ӵ��¿��ٵ�tmp��
		strncpy(str, tmp, len);//�ٽ�tmp�еĿ�����ȥ
		free(tmp);  //����ͷ��¿��ٵĿռ�
}
int main()
{
		char str[] = "ABCDEFGHIJK";
		int n = 20;
		LeftRound(str, n);
		printf("str=%s\n", str);
		return 0;	
}
*/
/*
#include <stdio.h>
#include <assert.h>
#include <string.h>
void Reverse(char*str, int start, int end)
{
	assert(str != NULL);
	while (start < end)
	{
		char tmp = str[start];
		str[start] = str[end];
		str[end] = tmp;
		start++;
		end--;
	}
}
void LeftRound(char*str, int n)
{
	assert(str != NULL);
	//2  �ƶ��Ĳ���
	int len = strlen(str);
	int step = n%len;
	//3 �ƶ� 
	Reverse(str, 0, step - 1);   // BA CDEFGHIJK  �ȷֳ�������  ǰ����ȷ�ת
	Reverse(str, step, len - 1); // BA KJIHGFEDC   �󲿷ַ�ת
	Reverse(str, 0, len - 1);    // CDEFGHIJK AB   �����ڷ�ת



}
int main()
	{
		char str[] = "ABCDEFGHIJK";
		int n = 2;
		LeftRound(str, n);
		printf("str=%s\n", str);
		return 0;
	}
	*/