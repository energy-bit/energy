#define _CRT_SECURE_NO_WARNINGS 1
#include"list.h"
void Test_list()//  ����List
{
	List mylist;
	ListInit(&mylist);
	//ListCreate_Tail(&mylist); //β�巨
	ListCreate_Head(&mylist);
	ListShow(mylist);
}
void main()
{
	Test_list();
}