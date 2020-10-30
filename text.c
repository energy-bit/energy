#define _CRT_SECURE_NO_WARNINGS 1
char * modifyString(char * s){
	for (int i = 0; s[i] != '\0'; i++)
	{

		if (s[i] == '?')
		{
			char ch = 'a';

			while ((i > 0 && ch == s[i - 1]) || (s[i + 1] != '\0' && ch == s[i + 1]))          
			{
				ch++;
			}

			s[i] = ch;

		}

	}

	return s;

}