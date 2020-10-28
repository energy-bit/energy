#define _CRT_SECURE_NO_WARNINGS 1
#include "Seqlist.h"
int main()
{
	SeqList mylist;
	SeqListInit(&mylist);

	ElemType item, key;// 要插入的数  要查找的数
	int select = 1;
	int pos = 0;

	while (select)
	{
		printf("***************************************\n");
		printf("***1.push_back         2.push_front ***\n");
		printf("***3.show_list         0.quit_system **\n");
		printf("***4.pop_back          5.pop_front  ***\n");
		printf("***6.insert_pos        7.insert_val  **\n");
		printf("***8.delete_pos        9.delete_val  **\n");
		printf("***10.Find_val         11.length     **\n");
		printf("***12.capacity         13.sort       **\n");
		printf("***14.reverse          15.clear      **\n");
		printf("***************************************\n");
		printf("请输入你的选择\n");
		scanf("%d", &select);
		if (select == 0)
			break;
		switch (select)
		{
		case 1:
			printf("请输入要插入的数[以-1结束]");
			while (scanf("%d", &item), item != -1)
			{
				SeqListPushBack(&mylist, item);
			}

			break;
		case 2:
			printf("请输入要插入的数[以-1结束]");
			while (scanf("%d", &item), item != -1)
			{
				SeqListPushFront(&mylist, item);
			}
			break;
		case 3:
			SeqListShow(&mylist);
			break;
		case 4:
			SeqListPopBack(&mylist);
			break;
		case 5:
			SeqListPopFront(&mylist);
			break;
		case 6:
			printf("请输入要插入的位置");
			scanf("%d", &pos);
			printf("请输入要插入的数据");
			scanf("%d", &item);
			SeqListInsertByPos(&mylist, pos, item);// 按位置插入
			SeqListShow(&mylist);
			break;
		case 7:
			SeqListSort(&mylist);
			printf("请输入要插入的数据");
			scanf("%d", &item);
			SeqListInsertByVal(&mylist, item);
			printf("按值插入成功");
			SeqListShow(&mylist);
			break;
		case 8:
			printf("请输入要删除的位置");
			scanf("%d", &pos);
			SeqListDeleteBypos(&mylist, pos);
			SeqListShow(&mylist);
			break;
		case 9:
			printf("请输入要删除的值");
			scanf("%d", key);
			SeqListDeleteByval(&mylist, key);
			break;
		case 10:
			printf("请输入要查找的值");
			scanf("%d", &key);
			pos = SeqListFind(&mylist, key);
			if (pos == -1)
			{
				printf("要查找的值不存在\n");
			}
			else
			{
				printf("要查找的值位置为%d\n", pos);
			}
			break;
		case 11:
			printf("seqlist len=%d\n", SeqListLength(&mylist));
			break;
		case 12:
			printf("seqlist capacity=%d\n", SeqListCapacity(&mylist));
			break;
		case 13:
			SeqListSort(&mylist);
			printf("排序完成..........\n");
			SeqListShow(&mylist);
			break;
		case 15:
			SeqListClear(&mylist);
			printf("顺序表清除成功\n");
			break;
		}
	}
	SepListDestroy(&mylist);
	printf("GoodBye...........\n");
	return  0;
}