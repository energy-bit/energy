#define _CRT_SECURE_NO_WARNINGS 1

/*剑指 Offer 58 - II. 左旋转字符串
字符串的左旋转操作是把字符串前面的若干个字符转移到字符串的尾部。
请定义一个函数实现字符串左旋转操作的功能。
比如，输入字符串"abcdefg"和数字2，该函数将返回左旋转两位得到的结果"cdefgab"。
示例 1：

输入: s = "abcdefg", k = 2
输出: "cdefgab"
示例 2：

输入: s = "lrloseumgh", k = 6
输出: "umghlrlose"*/





//指针   取余精妙思想
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



//三次反转
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