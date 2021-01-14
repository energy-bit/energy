#include<iostream>
#include<list>
using namespace std;
/*
void main()
{

	list<int>lt1;
	list<int>lt2(10, 5);//��10��ֵΪ5��Ԫ��
	list<int>lt3 = lt2;
	for (const auto &e : lt2)
	{
		cout << e << " ";
	}
	cout << endl;


	int ar[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9,10 };
	list<int>lt4(ar, ar + 10);
	for (const auto &e : lt4)
	{
		cout << e << " ";
	}
	cout << endl;

	list<int>lt5(lt4.begin(), lt4.end());// ��lt4������ҿ������乹��lt5
	for (const auto &e : lt5)
	{
		cout << e << " ";

	}
	cout << endl;
}
*/



void main()
{

	list<int> lt1 = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
	for (const auto &e : lt1)   //begin()  end()   ++
		cout << e << " ";
	cout << endl;
	// �ֶ����������
	list<int>::iterator it = lt1.begin();
	while (it!= lt1.end())
	{
		cout << *it<< " ";
		++it;
	}
	cout << endl;

	//�Զ��Ƶ�
	auto it1 = lt1.begin();
	while (it1 != lt1.end())
	{
		cout << *it1 << " ";
		++it1;
	}
	cout << endl;

	//�������
	auto it2 = lt1.end();
	--it2;
	while (it2 != lt1.begin())
	{
		cout << *it2 << " ";
		--it2;
	}

	cout << *it2;
	cout << endl;


	//���������
	list<int>::reverse_iterator rit = lt1.rbegin();
	while (rit != lt1.rend())
	{
		cout << *rit << " ";
		++rit;
	}
	cout << endl;
}
