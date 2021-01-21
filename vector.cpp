#include <iostream>
#include <vector>
using namespace std;

/*
void main()
{
	vector<int> iv = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
	cout << "size=" << iv.size() << endl;
	cout << "capacity=" << iv.capacity() << endl;
	for (const auto &e : iv)
	{
		cout << e << " ";
	}
	cout << endl;
	auto pos = find(iv.begin(), iv.end(), 6);
	if (pos != iv.end())
		//iv.erase(pos);删除数据
		cout << "pos=" << *pos << endl;
	else
		cout << "不存在" << endl;
	iv.resize(5);  //  重新调整了元素大小  原来的的pos 已经不是合法的  所以迭代器也会失效
	cout << "pos=" << *pos << endl;
}
*/
/*
void main()
{
	vector<int> iv = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
	cout << "size=" << iv.size() << endl;
	cout << "capacity=" << iv.capacity() << endl;
	for (const auto &e : iv)
	{
		cout << e << " ";
	} 
	cout << endl;
	auto pos = find(iv.begin(), iv.end(), 6);
	if (pos != iv.end())
		//iv.erase(pos);删除数据
		cout << "pos=" << *pos << endl;
	else
		cout << "不存在"<<endl;
	iv.reserve(100);
	 pos = find(iv.begin(), iv.end(), 6);  //解决  预留空间重新查找  这样就不会迭代器失效  如果没有这步就会造成迭代器失效


	iv.push_back(100);//  程序就崩溃了   迭代器失效
	//因为要插入数据就要开辟新的空间 编译器会将原来的数据拷贝到新的空间 在释放掉原来的空间
	//  这样  但是pos 指针还指向原来的空间  要插入数据程序就会崩溃  为迭代器失效
	cout << "pos=" << *pos << endl;
}
*/

//  以上说明迭代器失效有两种 

//第一种   就是已经不是合法的了
//第二种   就是原来的空间已经失效了

//比如
/*
int main()
{
vector<int> v={ 1, 2, 3, 4 };
auto it = v.begin();
while (it != v.end())
{
if (*it % 2 == 0)
v.erase(it);  //迭代器失效了 因为将2删除后 就不能在对其进行迭代

++it;
}
return 0;
}
*/

//解决方法如下

int  main()
{
	vector<int> v = { 1, 2, 3, 4 };
	auto it = v.begin();
	while (it != v.end())
	{
		if (*it % 2 == 0)
			it = v.erase(it);
		else
			++it;
	}
	for (const auto &e : v)
	{
		cout << e << " ";
	}
	return 0;
}