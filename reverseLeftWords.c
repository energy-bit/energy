#define _CRT_SECURE_NO_WARNINGS 1

/*��ָ Offer 58 - II. ����ת�ַ���
�ַ���������ת�����ǰ��ַ���ǰ������ɸ��ַ�ת�Ƶ��ַ�����β����
�붨��һ������ʵ���ַ�������ת�����Ĺ��ܡ�
���磬�����ַ���"abcdefg"������2���ú�������������ת��λ�õ��Ľ��"cdefgab"��
ʾ�� 1��

����: s = "abcdefg", k = 2
���: "cdefgab"
ʾ�� 2��

����: s = "lrloseumgh", k = 6
���: "umghlrlose"*/





//ָ��   ȡ�ྫ��˼��
/*char* reverseLeftWords(char* s, int n)
{
int len = strlen(s);
int i = 0;
char *ans = malloc(sizeof(char) * (len + 1));
while(i < len)
{
*(ans++) = s[(n + i++)%len];
}
*ans= '\0';
return ans - len;
}



//���η�ת
void reverse(char* s,int start,int end)
{
while(start<end-1)
{
char tmp=s[start];
s[start]=s[end-1];
s[end-1]=tmp;
start++;
end--;
}
}

char* reverseLeftWords(char* s, int n)
{
int len=strlen(s);
reverse(s,0,n);
reverse(s,n,len);
reverse(s,0,len);
return s;
}
*/


char* reverseLeftWords(char* s, int n)
{
	int len = strlen(s);
	char *arr = (char*)malloc(sizeof(char)*(len + 1));
	arr[len] = '\0';
	strncpy(arr, s + n, len - n);
	strncpy(arr + len - n, s, n);
	return arr;
}