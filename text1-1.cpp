#define _CRT_SECURE_NO_WARNINGS 1

#include <iostream>
using namespace std;
class Text
{
public :
	Text(int data=0)  // ���췽�� ��ʼ������ �����������ͬ 
	{
		m_data = data;  
		cout<< "creat Text obj:" << this << endl;
	}
	//�������췽��
	Text(const Text &t)  // �����Ƕ��������   ����Ĳ���������&���õķ�ʽ   �﷨Ҫ��
	{
		m_data = t.m_data;
		cout << "Copy Creat Text obj:" << this << endl;
	}

	// ��ֵ���  �Ⱥŵ�����
	Text &operator=(const Text &t)
	{
		cout << "Assign:" << this << "=" <<endl;
		if (this != &t)
		{
			m_data = t.m_data;
		}
		return *this;
	}
	// �������� -->��ʬ   ��������
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
	Text t1(10);  //  ʵ����һ������
	Text t2(t1);//��Text t2=t1;�ȼ�
	t2 = t1;//��ֵ
}