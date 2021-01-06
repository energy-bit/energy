#include <iostream>
#include <assert.h>
using namespace std;

/*
int globalVar = 1;
static int staticGlobalVar = 1;
void Text()
{
	static int staticVar = 1;
	int localVar = 1;
	int num1[10] = { 1, 2, 3, 4 };
	char char2[] = "abcd";
	int a = sizeof(char2);
	cout << a << endl;
	char* pChar3 = "abcd";
	int b = sizeof(pChar3);
	cout << b << endl;
	int * ptr1 = (int*)malloc(sizeof(int)* 4);
	int n1 = sizeof(ptr1);
	cout << n1 << endl;
	int * ptr2 = (int*)calloc(4, sizeof(int));
	int n2 = sizeof(ptr1);
	cout << n2 << endl;
	int *ptr3 = (int*)realloc(ptr2, sizeof(int)* 4);
	int n3 = sizeof(ptr1);
	cout << n3 << endl;
	free(ptr1);
	free(ptr3);
}
void main()
{
	Text();
}
*/


class Test
{
public :
	Test(int data = 0) :m_data(data)
	{
		cout << "obj" << endl;

	}
	~Test()
	{
		cout << "jbo" << endl;
	}
public:
	int GetData()const
	{
		return m_data;
	}
private:
	int m_data;
};
void Use_new()
{
	Test*p = new Test;   // ˵��   
	//   1 ����ռ�     2  �������
	//   3 ��������     4  �ͷſռ�
	cout << p->GetData() << endl;
	delete p;
}
void main()
{
	Use_new();  //   �����   obj  0  jbo  ˵��
}

/*
void main()
{

	//C++ һ���������ٿռ�  ��new�ؼ���  �����ж�
	int *p1 = new int;
	cout << *p1 << endl;
	delete p1;  //  ��free��Ч��


	int *p2 = new int(1);//   ������ �����ٵĿռ��ʼ�� C���԰첻��
	cout << *p2 << endl;
	delete p2;

	int *p3 = new int[10]{1, 2, 3, 4, 5, 6, 7, 8, 10, 9};//  c++11

	Test *p4 = new Test;
	cout << p4->GetData() << endl;//   Ĭ��ֵ0

	Test *p5 = new Test(100); //  ��ʼ�� Ϊ100
	cout << p5->GetData() << endl;

	delete[]p3;
	delete p4;
	delete p5;
}


*/
/*
void main()
{

	//   C������   �������ַ�ʽ���ٿռ�  �ж� �ͷ� ����
	int *p1 = (int*)malloc(sizeof(int));
	assert(p1 != nullptr);
	
	int *p3 = (int*)malloc(sizeof(int)*10);
	assert(p3 != nullptr);
	

	Test *p2 = (Test*)malloc(sizeof(Test));
	assert(p2 != nullptr);
	cout << p2->GetData() << endl; //   û�н��г�ʼ��  �Ǹ������
	cout << (*p2).GetData() << endl;//

	Test *p4 = (Test*)malloc(sizeof(Test)*10);
	assert(p4 != nullptr);
	cout << p4[0].GetData() << endl;

	free(p1);
	free(p2);
	free(p3);
	free(p4);
}
*/