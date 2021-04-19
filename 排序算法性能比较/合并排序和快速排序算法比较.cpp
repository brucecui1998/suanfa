#include<iostream>
#include<cstdlib>
#include<time.h>
#include"MergeSort1.h"//�ϲ�����ĵݹ��㷨
#include"MergeSort2.h"//�ϲ�����ķǵݹ��㷨
#include"RandomQuickSort.h"//��������
#include"InsertSort.h"//�ɴ�С����
using namespace std;
const int MaxN = 100000;
const int N = 50000;//�ı����ݸ���
int a[MaxN], b[N];
int main()
{
	//���������ظ�N��1-MaxN������ʹ��A�δ���,ע��B�δ���
//A�δ���------------------------------------
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
		//A�δ���------------------------------------

		//B�δ���------------------------------------
		//������N��30%�ظ����ݣ�ʹ��B�δ��룬ע��A�δ���
		srand(unsigned(time(NULL)));
	int index, temp, rest = 100000, n = 0;
	for (int i = 0; i < MaxN; i++)
		a[i] = i + 1;
	for (int i = 0; n < N*0.3 / 2; i = i + 2)//nΪ����������n������30%�ظ�����ʱ�˳�ѭ��
	{
		index = rand() % rest;
		b[i] = a[index];
		b[i + 1] = b[i];
		n++;
	}
	for (int i = N * 0.3; i < N; i++)//���ſ�ʼ���в��ظ�Ԫ�صĸ�ֵ
	{
		index = rand() % rest;
		b[i] = a[index];
		temp = a[index];
		a[index] = a[rest - 1];
		a[rest - 1] = temp;
		rest--;
	}
	//B�δ���------------------------------------

	MergeSort2(b, N);//˳������ѡ��ȡ��ע�ʹ���
	//insertSort(b, N);//��������ѡ��ȡ��ע�ʹ���
	//��ȫ����Ļ�ע����������

	/*for (int i = 0; i < N; i++)//�������ǰ������
		printf("%d\t", b[i]);
	printf("\n");*/

	//���� 
	int c[N];//�ϲ�������Ҫ������
	clock_t start_time = clock();
	RandomQuickSort(b, 0, N);//��������
	//MergeSort1(b, c, 0, N-1);//�ϲ�����ĵݹ��㷨
	//MergeSort2(b,N);//�ϲ�����ķǵݹ��㷨
	//QuickSort(b, 0, N);//��׼Ԫ���ǵ�һ���Ŀ�������
	clock_t end_time = clock();

	/*for (int i = 0; i < N; i++)//�������������
		cout << b[i] << "\t";
	cout << endl;*/

	printf("Running time is:%lfms\n", static_cast<double>(end_time - start_time) / CLOCKS_PER_SEC * 1000);

	return 0;
}

