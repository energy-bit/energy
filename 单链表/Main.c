#define _CRT_SECURE_NO_WARNINGS 1
#include "SList.h"
#include "_head.h"
int main()
{
	SList mylist;
	SListInit(&mylist);

	ElemType item, key;// Ҫ�������  Ҫ���ҵ���
	int select = 1;
	SListNode *p;

	while (select)
	{
		printf("***************************************\n");
		printf("***1.push_back         2.push_front ***\n");
		printf("***3.show_list         0.quit_system **\n");
		printf("***4.pop_back          5.pop_front  ***\n");
		printf("***6.insert_val         9.delete_val **\n");
		printf("***                                  **\n");
		printf("***10.Find_val         11.length     **\n");
		printf("***13.sort                           **\n");
		printf("***14.reverse          15.clear      **\n");
		printf("***************************************\n");
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
				SListPushBack(&mylist, item);
			}

			break;
		case 2:
			printf("������Ҫ�������[��-1����]");
			while (scanf("%d", &item), item != -1)
			{
				SListPushFront(&mylist, item);
			}
			break;
		case 3:
			SListShow(&mylist);
			break;
		case 4:
			SListPopBack(&mylist);
			break;
		case 5:
			SListPopFront(&mylist);
			break;
		case 6:
			printf("������Ҫ���������");
			scanf("%d", &item);
			SListInsertByVal(&mylist, item);// ��ֵ����
			printf("��ֵ����ɹ�");
			//SeqListShow(&mylist);
			break;
		case 7:
			//SeqListSort(&mylist);
			
			break;
		case 8:
			printf("������Ҫɾ����λ��");
			//scanf("%d", &pos);
			//SeqListDeleteBypos(&mylist, pos);
			//SeqListShow(&mylist);
			break;
		case 9:
			printf("������Ҫɾ����ֵ");
			scanf("%d", &key);
			SListDeleteByval(&mylist, key);//��ֵɾ��
			break;
		case 10:
			printf("������Ҫ���ҵ�ֵ");
			scanf("%d", &key);
			p=SListFind(&mylist, key);
			if (p == NULL)
			{
				printf("Ҫ���ҵ�ֵ������\n");
			}
			else
			{
				printf("Ҫ���ҵ�ֵΪ%d\n", p->data);
			}
			break;
		case 11:
			printf("slist len=%d\n", SListLength(&mylist));
			break;
		case 12:
			//printf("seqlist capacity=%d\n", SeqListCapacity(&mylist));
			break;
		case 13:
			SListSort(&mylist);
			printf("�������..........\n");
			SListShow(&mylist);
			break;
		case 14:
			SListReverse(&mylist);//  ת��
			SListShow(&mylist);
			break;
		case 15:
			SListClear(&mylist);
			printf("˳�������ɹ�\n");
			break;
		}
	}
	SListDestroy(&mylist);
	printf("GoodBye...........\n");
	return  0;
}