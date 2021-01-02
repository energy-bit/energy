#define _CRT_SECURE_NO_WARNINGS 1

#include <iostream>
using namespace std;
class Text
{
public :
	Text(int data=0)  // 构造方法 初始化对象 必须和类名相同 
	{
		m_data = data;  
		cout<< "creat Text obj:" << this << endl;
	}
	//拷贝构造方法
	Text(const Text &t)  // 参数是对象的引用   这里的参数必须是&引用的方式   语法要求
	{
		m_data = t.m_data;
		cout << "Copy Creat Text obj:" << this << endl;
	}

	// 赋值语句  等号的重载
	Text &operator=(const Text &t)
	{
		cout << "Assign:" << this << "=" <<endl;
		if (this != &t)
		{
			m_data = t.m_data;
		}
		return *this;
	}
	// 析构方法 -->收尸   不许重载
	~Text()
	{
		cout << "Free Text obj:" << this << endl;
	}
private:
	int m_data;
};

void main()
{
	Text t0;
	Text t1(10);  //  实例化一个对象
	Text t2(t1);//和Text t2=t1;等价
	t2 = t1;//赋值
}