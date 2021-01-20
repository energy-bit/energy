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
	public:  // 构造方法
		string(const char* str = " ")
		{
			if (str == nullptr)
			{
				_str = new char[1]; //预防传过来一个空字符串
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
		~string()  //析构函数
		{
			if (_str)
			{
				delete[]_str;
				_str = nullptr;
				_mycapacity = _size = 0;
			}
		}
	public:
		void Push_Back(char c)//尾部插入
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
		}	         string& operator+=(const char*str)  // +=一个字符串
		{
			 int len = strlen(str);
			 if (_size + len > _mycapacity)  //  先判断已有的字符串和要加的字符串会不会超过自身容量
			 {
				 //char*new_str = new char[_mycapacity*2]  有可能不成功
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
		 void oppend(const char*str)//  字符串追加
		 {
			 *this += str;
		 }
		 char& operator[](int pos)//  重载方括号
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
		// 返回c在string中第一次出现的位置
		size_t find(char c, size_t pos = 0) const
		{
			for (size_t i = 0; i < _size; i++)
			{
				if (_str[i] == c)
					return i;
			}
			return -1; 
		}
		// 返回子串s在string中第一次出现的位置
		size_t find(const char* s, size_t pos = 0) const//模式匹配  暴力匹配
		{
			assert(s != nullptr);
				const char*str = _str + pos;//从其实位置
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

		// 在pos位置上插入字符c/字符串str，并返回该字符的位置
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
		// 删除pos位置上的元素，并返回该元素的下一个位置
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
		void resize(size_t newSize, char c = '\0')// 重新调整大小空间
		{
			if (newSize> _size)
			{
				if (newSize > _mycapacity)  //判断调整的大小是否大于容量
				{
					reserve(newSize * 2);
				}
				memset(_str + _size, c, newSize - _size);
			}
			_size = newSize;
			_str[newSize] = '\0';
		}
		void reserve(size_t n = 0)// 重新预留空间
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
		char *_str;// 字符串空间
		size_t _mycapacity;// 容量
		size_t _size;// 字符串有效长度
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
//   测试返回c在string中第一次出现的位置
void main()
{
	bit::string url = "afhagfav";
	size_t index = url.find('g');
	if (index != string::npos)
		cout << "index=" << index << endl;
	else
		cout << "不存在" << endl;

}


//测试返回子串s在string中第一次出现的位置
void main()
{
	bit::string str = "abcdabcdeabcdabcdefg";
	bit::string sub = "abcde";
	size_t index = str.find(sub.c_str());
	cout << index << endl;
}

void main()
{
	// 在pos位置上插入字符c/字符串str，并返回该字符的位置
	bit::string str("abc");
	cout << "str=" << str << endl;
	str.insert(1, 'x');
	cout << "str=" << str << endl;
}



void main()
{
	// 测试删除pos位置上的元素，并返回该元素的下一个位置
	bit::string str = "abcdefg";
	cout << "str=" << str << endl;
	str.erase(2, 2);
	cout << "str=" << str << endl;
}

*/
void main()
{
	// 测试 重新调整大小空间
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