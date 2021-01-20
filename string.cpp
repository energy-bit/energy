#include <iostream>
#include <string>
#include <assert.h>
using namespace std;
namespace bit
{
	class string
	{
		static size_t npos; 
		friend ostream& operator<<(ostream &out, const string &s);
	public:  // ���췽��
		string(const char* str = " ")
		{
			if (str == nullptr)
			{
				_str = new char[1]; //Ԥ��������һ�����ַ���
				_str[0] = '\0';
				_mycapacity = _size = 0;
			}
			else
			{
				_mycapacity = _size = strlen(str);
				_str = new char[_mycapacity + 1];
				strcpy(_str, str);
			}
		}
		string(const string&s) : _str(nullptr), _mycapacity(0), _size(0)
		{
			string tmp_str(s._str);
			swap(tmp_str);
		}
		string &operator=(string s)
		{
			swap(s);
			return *this;
		}
		~string()  //��������
		{
			if (_str)
			{
				delete[]_str;
				_str = nullptr;
				_mycapacity = _size = 0;
			}
		}
	public:
		void Push_Back(char c)//β������
		{
			if (_size >= _mycapacity)
				reserve(_mycapacity * 2);
				_str[_size++] = c;
				_str[_size] = '\0';
			
		}
	public:
		string& operator+=(char c)
		{
			Push_Back(c);
			return *this;
		}	         string& operator+=(const char*str)  // +=һ���ַ���
		{
			 int len = strlen(str);
			 if (_size + len > _mycapacity)  //  ���ж����е��ַ�����Ҫ�ӵ��ַ����᲻�ᳬ����������
			 {
				 //char*new_str = new char[_mycapacity*2]  �п��ܲ��ɹ�
				 reserve((_size + len) * 2);
			 }
			 strcat(_str, str);
			 _size += len;
			 return *this;
			/*while (*str != '\0')
			{
				Push_Back(*str);
				str++;	
			}
			return *this;*/
		}
		 void oppend(const char*str)//  �ַ���׷��
		 {
			 *this += str;
		 }
		 char& operator[](int pos)//  ���ط�����
		 {
			 assert(pos >= 0 && pos < _size);
			 return _str[pos];
		 }
	public:
		bool operator<(const string& s)
		{
			return (strcmp(_str, s._str)<0);
		}
		bool operator>=(const string& s)
		{
			return (*this < s);
		}
	public:
		// ����c��string�е�һ�γ��ֵ�λ��
		size_t find(char c, size_t pos = 0) const
		{
			for (size_t i = 0; i < _size; i++)
			{
				if (_str[i] == c)
					return i;
			}
			return -1; 
		}
		// �����Ӵ�s��string�е�һ�γ��ֵ�λ��
		size_t find(const char* s, size_t pos = 0) const//ģʽƥ��  ����ƥ��
		{
			assert(s != nullptr);
				const char*str = _str + pos;//����ʵλ��
			while (*str!='\0')
			{
				const char*sub = s;
				const char*cur = str;
				while (*sub != '\0'&&*sub == *cur)
				{
					sub++;
					cur++;
				}
				if (*sub == '\0')
				{
					return str-_str;
				}
				else
					str++;
			}
		}

		// ��posλ���ϲ����ַ�c/�ַ���str�������ظ��ַ���λ��
		string& insert(size_t pos, char c)
		{
			assert(pos >= 0 && pos <= _size);
			if (_size + 1 > _mycapacity)
				reserve(_mycapacity * 2);
			for (size_t i=_size; i >=pos; --i)
			
				_str[i + 1] = _str[i];
				_str[pos] = c;
				_size++;
			return *this;
		}
		string& insert(size_t pos, const char* str)
		{

		}
		// ɾ��posλ���ϵ�Ԫ�أ������ظ�Ԫ�ص���һ��λ��
		string& erase(size_t pos, size_t len)
		{
			if (pos + len >= _size)
			{
				_str[pos] = '\0';
				_size = pos;
			}
			else
			{
				strcpy(_str + pos, _str + pos + len);
				_size -= len;
			}
			return *this;
		}
	public:
		size_t size()const
		{
			return _size;
		}
		size_t _capacity()const
		{
			return _mycapacity;
		}
		bool empty()const
		{
			return _size == 0;
		}
		void clear()
		{
			_str[0] = '\0';
			_size = 0;
		}
		const char* c_str()const		{			return _str;		}
	public:
		void swap(string&s)
		{
			std::swap(_str, s._str);
			std::swap(_mycapacity, s._mycapacity);
			std::swap(_size, s._size);
		}
		
	public:
		void resize(size_t newSize, char c = '\0')// ���µ�����С�ռ�
		{
			if (newSize> _size)
			{
				if (newSize > _mycapacity)  //�жϵ����Ĵ�С�Ƿ��������
				{
					reserve(newSize * 2);
				}
				memset(_str + _size, c, newSize - _size);
			}
			_size = newSize;
			_str[newSize] = '\0';
		}
		void reserve(size_t n = 0)// ����Ԥ���ռ�
		{
			if (n > _mycapacity)
			{
				char *new_str = new char[n + 1];
				strcpy(new_str, _str);
				delete[]_str;
				_str = new_str;
				_mycapacity = n;
			}
		}
	private:
		char *_str;// �ַ����ռ�
		size_t _mycapacity;// ����
		size_t _size;// �ַ�����Ч����
	};
	 ostream& operator<<(ostream &out, const string &s)
	{
		out << s._str;
		return out;
	}
	 size_t string::npos = (size_t)(-1);
};

/*
void main()
{
	bit::string str("abc");
	cout << "size=" << str.size() << endl;
	cout << "_mycapacity=" << str._capacity() << endl;
	str.reserve(20);
	cout << "_mycapacity=" << str._capacity() << endl;
	str.Push_Back('x');
	str += "yz";
	str += 'a';
	str.oppend("aaabbb");
	//str.clear();
	strlen(str.c_str());
	cout << str[0] << endl;
	cout << "str=" << str <<endl;
}
*/


/*
//   ���Է���c��string�е�һ�γ��ֵ�λ��
void main()
{
	bit::string url = "afhagfav";
	size_t index = url.find('g');
	if (index != string::npos)
		cout << "index=" << index << endl;
	else
		cout << "������" << endl;

}


//���Է����Ӵ�s��string�е�һ�γ��ֵ�λ��
void main()
{
	bit::string str = "abcdabcdeabcdabcdefg";
	bit::string sub = "abcde";
	size_t index = str.find(sub.c_str());
	cout << index << endl;
}

void main()
{
	// ��posλ���ϲ����ַ�c/�ַ���str�������ظ��ַ���λ��
	bit::string str("abc");
	cout << "str=" << str << endl;
	str.insert(1, 'x');
	cout << "str=" << str << endl;
}



void main()
{
	// ����ɾ��posλ���ϵ�Ԫ�أ������ظ�Ԫ�ص���һ��λ��
	bit::string str = "abcdefg";
	cout << "str=" << str << endl;
	str.erase(2, 2);
	cout << "str=" << str << endl;
}

*/
void main()
{
	// ���� ���µ�����С�ռ�
	bit::string str("abc");
	cout << "str=" << str << endl;
	str.resize(10);
	cout << "str=" << str << endl;
}
/*
void  main()
{
	bit::string str("abc");
	bit::string str1("xyz");
	str = str1;
}
*/