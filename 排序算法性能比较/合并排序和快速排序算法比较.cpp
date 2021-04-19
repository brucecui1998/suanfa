#include<iostream>
#include<cstdlib>
#include<time.h>
#include"MergeSort1.h"//合并排序的递归算法
#include"MergeSort2.h"//合并排序的非递归算法
#include"RandomQuickSort.h"//快速排序
#include"InsertSort.h"//由大到小排序
using namespace std;
const int MaxN = 100000;
const int N = 50000;//改变数据个数
int a[MaxN], b[N];
int main()
{
	//若生成无重复N个1-MaxN个数，使用A段代码,注释B段代码
//A段代码------------------------------------
	srand(unsigned(time(NULL)));
	for (int i = 0; i < MaxN; i++)
		a[i] = i + 1;
	int index, temp, rest = 100000;
	for (int i = 0; i < N; i++)
	{
		index = rand() % rest;
		b[i] = a[index];
		temp = a[index];
		a[index] = a[rest - 1];
		a[rest - 1] = temp;
		rest--;
	}*/
		//A段代码------------------------------------

		//B段代码------------------------------------
		//若生成N个30%重复数据，使用B段代码，注释A段代码
		srand(unsigned(time(NULL)));
	int index, temp, rest = 100000, n = 0;
	for (int i = 0; i < MaxN; i++)
		a[i] = i + 1;
	for (int i = 0; n < N*0.3 / 2; i = i + 2)//n为计数器，当n计数至30%重复数据时退出循环
	{
		index = rand() % rest;
		b[i] = a[index];
		b[i + 1] = b[i];
		n++;
	}
	for (int i = N * 0.3; i < N; i++)//接着开始进行不重复元素的赋值
	{
		index = rand() % rest;
		b[i] = a[index];
		temp = a[index];
		a[index] = a[rest - 1];
		a[rest - 1] = temp;
		rest--;
	}
	//B段代码------------------------------------

	MergeSort2(b, N);//顺序排列选择取消注释此行
	//insertSort(b, N);//逆序排列选择取消注释此行
	//完全随机的话注释上面两行

	/*for (int i = 0; i < N; i++)//输出排序前的数组
		printf("%d\t", b[i]);
	printf("\n");*/

	//排序 
	int c[N];//合并排序需要的数组
	clock_t start_time = clock();
	RandomQuickSort(b, 0, N);//快速排序
	//MergeSort1(b, c, 0, N-1);//合并排序的递归算法
	//MergeSort2(b,N);//合并排序的非递归算法
	//QuickSort(b, 0, N);//基准元素是第一个的快速排序
	clock_t end_time = clock();

	/*for (int i = 0; i < N; i++)//输出排序后的数组
		cout << b[i] << "\t";
	cout << endl;*/

	printf("Running time is:%lfms\n", static_cast<double>(end_time - start_time) / CLOCKS_PER_SEC * 1000);

	return 0;
}

