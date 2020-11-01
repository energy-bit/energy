#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#define MAX_SIZE 10

/***************顺序查找********************/
int Search_Seg(int* array, int key)
{
	//从最后一个元素往前进行顺序查找.
	//若找到，则返回元素下标;若未找到，则返回-1。
	int i;
	for (i = MAX_SIZE - 1; i >= 0; i--)
	if (array[i] == key)
		return i;
	return i;
}

/***************折半查找的递归实现************/
int Search_Bin_Recursion(int* array, int key, int start, int end)
{
	//在数组array下标为[start,end]区间中查找关键字为key的元素.
	//若找到，则返回元素下标;若未找到，则返回-1。
	if (start <= end)
	{
		int mid = (start + end) / 2;
		if (array[mid] == key)//找到待查元素
			return mid;
		else if (array[mid]>key)
			return Search_Bin_Recursion(array, key, start, mid - 1);//递归调用折半查找函数，继续在前半区间进行查找
		else
			return Search_Bin_Recursion(array, key, mid + 1, end);//递归调用折半查找函数，继续在后半区间进行查找
	}
	return -1;
}

/**************折半查找的非递归实现***********/
int Search_Bin_nonRecursion(int* array, int key)
{
	//在数组array中查找关键字为key的元素.
	//若找到，则返回元素下标;若未找到，则返回-1。
	int low = 0, high = MAX_SIZE - 1;
	while (low <= high)
	{
		int mid = (low + high) / 2;
		if (array[mid] == key)//找到待查元素
			return mid;
		else if (array[mid]>key)//继续在前半区间进行查找
			high = mid - 1;
		else
			low = mid + 1;//继续在后半区间进行查找
	}
	return -1;
}

/*************选择排序**************/
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
	srand((unsigned)time(NULL));//以时间作为随机数种子
	int i = 0, key, n;
	int array[MAX_SIZE];

	/**************随机产生测试数据，将产生的随机数写入文件*************/
	FILE *in = fopen("datafile.txt", "w");
	if (in == NULL)
	{
		printf("Open file erroe!\n");
		exit(0);
	}
	while (!feof(in) && i != MAX_SIZE)
	{
		fprintf(in, "%d ", rand() % 100);//以时间为种子产生100以内的随机数
		i++;
	}
	fclose(in);//注意别忘记

	/**************从文件中读取测试数据到数组中********************/
	i = 0;//将i重置为0
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


	printf("文件中的随机数为:");
	for (i = 0; i<MAX_SIZE; i++)
		printf("%d ", array[i]);
	printf("\n");

	printf("---------------测试顺序查找-------------------\n");
	printf("请输入需要查找的元素:");
	scanf("%d", &key);
	n = Search_Seg(array, key);
	if (n == -1)
		printf("查找失败。\n\n");
	else
		printf("查找成功，查找元素的下标为%d。\n\n", n);


	sort(array);//折半查找前先对数组进行排序
	printf("排序后的随机数为:");
	for (i = 0; i<MAX_SIZE; i++)
		printf("%d ", array[i]);
	printf("\n");

	printf("---------------测试递归折半查找---------------\n");
	printf("请输入需要查找的元素:");
	scanf("%d", &key);
	n = Search_Bin_Recursion(array, key, 0, MAX_SIZE - 1);
	if (n == -1)
		printf("查找失败。\n\n");
	else
		printf("查找成功，查找元素的下标为%d。\n\n", n);

	printf("---------------测试非递归折半查找-----------------\n");
	printf("请输入需要查找的元素:");
	scanf("%d", &key);
	n = Search_Bin_nonRecursion(array, key);
	if (n == -1)
		printf("查找失败。\n");
	else
		printf("查找成功，查找元素的下标为%d。\n", n);

	return 0;
}
