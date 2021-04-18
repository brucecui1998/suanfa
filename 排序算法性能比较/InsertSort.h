#pragma once
//插入排序  由大到小排序
void swap(int *b, int *c)
{

	int temp = *c;
	*c = *b;
	*b = temp;
}
void insertSort(int *e, int n)
{
	for (int i = 1; i < n; i++)
	{

		for (int j = i; j > 0; j--)
		{
			if (e[j] > e[j - 1])
			{
				swap(&e[j], &e[j - 1]);
			}
			else
			{
				break;
			}
		}

	}
}

