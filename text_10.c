#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#define MAX_SIZE 10

/***************˳�����********************/
int Search_Seg(int* array, int key)
{
	//�����һ��Ԫ����ǰ����˳�����.
	//���ҵ����򷵻�Ԫ���±�;��δ�ҵ����򷵻�-1��
	int i;
	for (i = MAX_SIZE - 1; i >= 0; i--)
	if (array[i] == key)
		return i;
	return i;
}

/***************�۰���ҵĵݹ�ʵ��************/
int Search_Bin_Recursion(int* array, int key, int start, int end)
{
	//������array�±�Ϊ[start,end]�����в��ҹؼ���Ϊkey��Ԫ��.
	//���ҵ����򷵻�Ԫ���±�;��δ�ҵ����򷵻�-1��
	if (start <= end)
	{
		int mid = (start + end) / 2;
		if (array[mid] == key)//�ҵ�����Ԫ��
			return mid;
		else if (array[mid]>key)
			return Search_Bin_Recursion(array, key, start, mid - 1);//�ݹ�����۰���Һ�����������ǰ��������в���
		else
			return Search_Bin_Recursion(array, key, mid + 1, end);//�ݹ�����۰���Һ����������ں��������в���
	}
	return -1;
}

/**************�۰���ҵķǵݹ�ʵ��***********/
int Search_Bin_nonRecursion(int* array, int key)
{
	//������array�в��ҹؼ���Ϊkey��Ԫ��.
	//���ҵ����򷵻�Ԫ���±�;��δ�ҵ����򷵻�-1��
	int low = 0, high = MAX_SIZE - 1;
	while (low <= high)
	{
		int mid = (low + high) / 2;
		if (array[mid] == key)//�ҵ�����Ԫ��
			return mid;
		else if (array[mid]>key)//������ǰ��������в���
			high = mid - 1;
		else
			low = mid + 1;//�����ں��������в���
	}
	return -1;
}

/*************ѡ������**************/
void sort(int* array)
{
	int i, j, minNo;
	for (i = 0; i<MAX_SIZE - 1; i++)
	{
		minNo = i;
		for (j = i + 1; j<MAX_SIZE; j++)
		if (array[minNo]>array[j])
			minNo = j;
		if (minNo != i)
		{
			int t = array[i];
			array[i] = array[minNo];
			array[minNo] = t;
		}
	}
}

int main()
{
	srand((unsigned)time(NULL));//��ʱ����Ϊ���������
	int i = 0, key, n;
	int array[MAX_SIZE];

	/**************��������������ݣ��������������д���ļ�*************/
	FILE *in = fopen("datafile.txt", "w");
	if (in == NULL)
	{
		printf("Open file erroe!\n");
		exit(0);
	}
	while (!feof(in) && i != MAX_SIZE)
	{
		fprintf(in, "%d ", rand() % 100);//��ʱ��Ϊ���Ӳ���100���ڵ������
		i++;
	}
	fclose(in);//ע�������

	/**************���ļ��ж�ȡ�������ݵ�������********************/
	i = 0;//��i����Ϊ0
	FILE *out = fopen("datafile.txt", "r");
	if (out == NULL)
	{
		printf("Open file error!\n");
		exit(0);
	}
	while (!feof(out) && (i != MAX_SIZE))
	{
		fscanf(out, "%d", &array[i]);
		i++;
	}
	fclose(out);


	printf("�ļ��е������Ϊ:");
	for (i = 0; i<MAX_SIZE; i++)
		printf("%d ", array[i]);
	printf("\n");

	printf("---------------����˳�����-------------------\n");
	printf("��������Ҫ���ҵ�Ԫ��:");
	scanf("%d", &key);
	n = Search_Seg(array, key);
	if (n == -1)
		printf("����ʧ�ܡ�\n\n");
	else
		printf("���ҳɹ�������Ԫ�ص��±�Ϊ%d��\n\n", n);


	sort(array);//�۰����ǰ�ȶ������������
	printf("�����������Ϊ:");
	for (i = 0; i<MAX_SIZE; i++)
		printf("%d ", array[i]);
	printf("\n");

	printf("---------------���Եݹ��۰����---------------\n");
	printf("��������Ҫ���ҵ�Ԫ��:");
	scanf("%d", &key);
	n = Search_Bin_Recursion(array, key, 0, MAX_SIZE - 1);
	if (n == -1)
		printf("����ʧ�ܡ�\n\n");
	else
		printf("���ҳɹ�������Ԫ�ص��±�Ϊ%d��\n\n", n);

	printf("---------------���Էǵݹ��۰����-----------------\n");
	printf("��������Ҫ���ҵ�Ԫ��:");
	scanf("%d", &key);
	n = Search_Bin_nonRecursion(array, key);
	if (n == -1)
		printf("����ʧ�ܡ�\n");
	else
		printf("���ҳɹ�������Ԫ�ص��±�Ϊ%d��\n", n);

	return 0;
}
