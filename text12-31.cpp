#define _CRT_SECURE_NO_WARNINGS 1

#include <iostream>
using namespace std;

//��������
int fun(int a, int b)
{
	return a + b;
}

/*
//const ֻ������   --> ����
//const *
//const &
//const ����
void main()
{
int &&a = 10; //��ֵ����
}
/*
int& fun(const int &a, const int &b)
{
int result = a + b;
return result;
}
void main()
{
int &res = fun(10,20);
fun(100,200);
cout<<"result = "<<res<<endl;
}
/*
int fun( int a,int b)
{
int result = a + b;
return result;
}
void main()
{
int res = fun(10,20);
cout<<"result = "<<res<<endl;
}
/*
int& fun(const int &a, const int &b)
{
int result = a + b;
return result;
}
void main()
{
int &res = fun(10,20);
fun(100,200);
cout<<"result = "<<res<<endl;
}
/*
struct Student
{
char name[10];
int age;
};
void main()
{
int a = 10;
int &b = a;
int *p = &a;
int *&q = p;  //ָ���Ӧ��
int ar[10] = {1,2,3,4,5,6,7,8,9,10};
int (&br)[10] = ar;   //& []  ��������
Student s;
Student &rs = s;
}
/*
void main()
{
const int a = 10;
const int &b = a; //�﷨Ҫ��
}
/*
void main()
{
int a = 10;
const int &b = a; //����Ҫ��
}
/*
void main()
{
int a = 10;
const int &b = a;
a = 100;
b = 20;
}
/*
void main()
{
int a = 10;
const int *p = &a;
}
/*
void main()
{
int a = 10;
int b = 20;
//ָ��
const int *const p = &a;
*p = 100;
p = &b;
//a = 100;
}
/*
void main()
{
int a = 10;
int &b = a;
int &c = a;
int &d = b;
int x = 100;
int &b = x;
}
/*
void Swap(int &x, int &y)
{
int tmp = x;
x = y;
y = tmp;
}
void main()
{
int a = 10;
int b = 20;
cout<<"a = "<<a<<", b = "<<b<<endl;
Swap(a, b);
cout<<"a = "<<a<<", b = "<<b<<endl;
}
/*
void Swap(int *x, int *y)
{
int tmp = *x;
*x = *y;
*y = tmp;
}
void main()
{
int a = 10;
int b = 20;
cout<<"a = "<<a<<", b = "<<b<<endl;
Swap(&a, &b);
cout<<"a = "<<a<<", b = "<<b<<endl;
}
/*
void main()
{
int a = 10;
int &b = a; //��ʼ��
int *ptr = NULL;
ptr = &a;
}
/*
void main()
{
int a = 10;
//&a; //ȡ��ַ
int &b = a; //����
b = 100;
cout<<a<<endl;
}
/*
void TestFunc(int a = 10)
{
cout << "void TestFunc(int)" << endl;
}
void TestFunc(int a)
{
cout << "void TestFunc(int)" << endl;
}
void main()
{
TestFunc(1);
}
/*
int Max(int a, int b);   //?Max@@YAHHH@Z
int Max(int a, int b)    //?Max@@YAHHH@Z
{
return a > b ? a : b;
}
void main()
{
cout<<Max(10, 20)<<endl;
}
