#include <iostream>
using namespace std;

class String
{
public:
	String(const char*str = "")
	{
		m_data = (char*)malloc(sizeof(char)*strlen(str) + 1);
		strcpy(m_data, str);

	}
public:

	void Printf()const
	{
		cout << m_data << endl;
	}

private:

	char *m_data;

};
void main()
{
	String s("holle");
	s. Printf();
}