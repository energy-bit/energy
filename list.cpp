#include<iostream>
#include<list>
using namespace std;
/*
void main()
{

	list<int>lt1;
	list<int>lt2(10, 5);//放10个值为5的元素
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

	list<int>lt5(lt4.begin(), lt4.end());// 用lt4的左闭右开的区间构造lt5
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
	// 手动定义迭代器
	list<int>::iterator it = lt1.begin();
	while (it!= lt1.end())
	{
		cout << *it<< " ";
		++it;
	}
	cout << endl;

	//自动推导
	auto it1 = lt1.begin();
	while (it1 != lt1.end())
	{
		cout << *it1 << " ";
		++it1;
	}
	cout << endl;

	//反向迭代
	auto it2 = lt1.end();
	--it2;
	while (it2 != lt1.begin())
	{
		cout << *it2 << " ";
		--it2;
	}

	cout << *it2;
	cout << endl;


	//反向迭代器
	list<int>::reverse_iterator rit = lt1.rbegin();
	while (rit != lt1.rend())
	{
		cout << *rit << " ";
		++rit;
	}
	cout << endl;
}
