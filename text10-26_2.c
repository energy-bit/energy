#define _CRT_SECURE_NO_WARNINGS 1
//猜数字小游戏
#include <stdio.h>
#include <stdlib.h>
#include  <time.h>
void menu()
{
	printf("#####################################");
	printf("###########1.play     2.exit##########");
	printf("######################################");
}
void game()
{
	int guess = 0;
	int ret = rand() % 100 + 1;//rand()产生随机值 产生0到3万多的数字  %一个100  就只能余0到99的数字 在加1  就是产生0到100的数字
	while (1)
	{

		printf("请输入一个0到100之间的数字\n");
		scanf("%d", &guess);
		if (guess > ret)
		{
			printf("猜大了\n");
		}
		else if (guess < ret)
		{
			printf("猜小了\n");
		}
		else
		{
			printf("恭喜你 猜对了\n");
			break;
		}
	}
}

int main()
{
	int input = 0;
	srand((unsigned int)time(NULL));//只能调用一次 不能频繁调用
	do
	{
		menu();
		printf("请输入你的选择\n");
			scanf("%d", &input);
			switch (input)
			{
			case 1:
				game();
				break;
			case 0:
				printf("退出");
					break;
			default:
				printf("请重新选择");
				break;
			}
	} while (input);
	return 0;
}