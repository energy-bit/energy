
/*��ʵ��һ�����������ַ��� s �е�ÿ���ո��滻��"%20"��


ʾ�� 1��

���룺s = "We are happy."
�����"We%20are%20happy."

*/

char* replaceSpace(char* s)
{
	int  len = strlen(s);

	char *res = malloc(3 * len + 1);  //   ���ռ����ȫ���ǿո�
	memset(res, 0, 3 * len + 1);//   ��ʼ��
	int j = 0;
	for (int i = 0; i<len; i++)
	{
		if (s[i] == ' ')
		{
			strcat(res + j, "%20");
			j += 3;
		}
		else
		{
			res[j++] = s[i];
		}

	}
	return res;
}
