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
		//iv.erase(pos);ɾ������
		cout << "pos=" << *pos << endl;
	else
		cout << "������" << endl;
	iv.resize(5);  //  ���µ�����Ԫ�ش�С  ԭ���ĵ�pos �Ѿ����ǺϷ���  ���Ե�����Ҳ��ʧЧ
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
		//iv.erase(pos);ɾ������
		cout << "pos=" << *pos << endl;
	else
		cout << "������"<<endl;
	iv.reserve(100);
	 pos = find(iv.begin(), iv.end(), 6);  //���  Ԥ���ռ����²���  �����Ͳ��������ʧЧ  ���û���ⲽ�ͻ���ɵ�����ʧЧ


	iv.push_back(100);//  ����ͱ�����   ������ʧЧ
	//��ΪҪ�������ݾ�Ҫ�����µĿռ� �������Ὣԭ�������ݿ������µĿռ� ���ͷŵ�ԭ���Ŀռ�
	//  ����  ����pos ָ�뻹ָ��ԭ���Ŀռ�  Ҫ�������ݳ���ͻ����  Ϊ������ʧЧ
	cout << "pos=" << *pos << endl;
}
*/

//  ����˵��������ʧЧ������ 

//��һ��   �����Ѿ����ǺϷ�����
//�ڶ���   ����ԭ���Ŀռ��Ѿ�ʧЧ��

//����
/*
int main()
{
vector<int> v={ 1, 2, 3, 4 };
auto it = v.begin();
while (it != v.end())
{
if (*it % 2 == 0)
v.erase(it);  //������ʧЧ�� ��Ϊ��2ɾ���� �Ͳ����ڶ�����е���

++it;
}
return 0;
}
*/

//�����������

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