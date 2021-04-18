#pragma once
void Swap(int *x, int *y)//交换两个数
{
	int t;
	t = *x;
	*x = *y;
	*y = t;
}
int Partition(int a[], int p, int r)
{
	int x = a[p];
	int i = p, j = r + 1;
	while (1)
	{
		while (a[++i] < x);
		while (a[--j] > x);
		if (i >= j) break;
		Swap(&a[i], &a[j]);
	}
	a[p] = a[j];
	a[j] = x;
	return j;
}
void QuickSort(int a[], int p, int r)
{
	int q;
	if (p < r)
	{
		 q = Partition(a, p, r);
		QuickSort(a, p, q - 1);
		QuickSort(a, q + 1, r);
	}
}

int RandomPartition(int a[], int p, int r)
{
	int i = p + rand() % (r - p + 1);
	Swap(&a[i], &a[r]);
	return Partition(a, p, r);
}
void RandomQuickSort(int a[], int p, int r)
{
	if (p < r)
	{
		int q = RandomPartition(a, p, r);
		RandomQuickSort(a, p, q - 1);
		RandomQuickSort(a, q + 1, r);
	}
}
