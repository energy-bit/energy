#define _CRT_SECURE_NO_WARNINGS 1
//������С��Ϸ
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
	int ret = rand() % 100 + 1;//rand()�������ֵ ����0��3��������  %һ��100  ��ֻ����0��99������ �ڼ�1  ���ǲ���0��100������
	while (1)
	{

		printf("������һ��0��100֮�������\n");
		scanf("%d", &guess);
		if (guess > ret)
		{
			printf("�´���\n");
		}
		else if (guess < ret)
		{
			printf("��С��\n");
		}
		else
		{
			printf("��ϲ�� �¶���\n");
			break;
		}
	}
}

int main()
{
	int input = 0;
	srand((unsigned int)time(NULL));//ֻ�ܵ���һ�� ����Ƶ������
	do
	{
		menu();
		printf("���������ѡ��\n");
			scanf("%d", &input);
			switch (input)
			{
			case 1:
				game();
				break;
			case 0:
				printf("�˳�");
					break;
			default:
				printf("������ѡ��");
				break;
			}
	} while (input);
	return 0;
}