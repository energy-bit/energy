#define _CRT_SECURE_NO_WARNINGS 1
#include "Seqlist.h"
int main()
{
	SeqList mylist;
	 SeqListInit(&mylist);

	 ElemType item;// Ҫ�������
	 int select = 1;
	 while (select)
	 {
		 printf("**************************************\n");
		 printf("***1.push_back         2.push_front***\n");
		 printf("***3.show_list         0.quit_system**\n");
		 printf("**************************************\n");
		 printf("���������ѡ��\n");
		 scanf("%d", &select);
		 if (select == 0)
		 break;
		 switch (select)
		 {
		  case 1:
			  printf("������Ҫ�������[��-1����]");
			  while (scanf("%d", &item), item != -1)
			  {
				  SeqListPushBack(&mylist, item);
			  }
			  
			 break;
		  case 2:
			  printf("������Ҫ�������[��-1����]");
			  while (scanf("%d", &item), item != -1)
			  {
				  SeqListPushFront(&mylist, item);
			  }
			  break;
		  case 3:
			  SeqListShow(&mylist);
			  break;

		 }
	 }
	 SeqListDestroy(&mylist);
	 printf("GoodBye...........\n");
	return  0;
}