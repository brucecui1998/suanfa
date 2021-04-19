//合并c[n:m]和c[m+1:r]到d[n:r]
void Merge2(int c[], int d[], int n, int m, int r)
{
	int i = n, j = m + 1, k = n;
	while ((i <= m) && (j <= r))
	{
		if (c[i] <= c[j])
			d[k++] = c[i++];
		else
			d[k++] = c[j++];
	}
	if (i > m)
	{
		for (int q = j; q <= r; q++)
			d[k++] = c[q];
	}
	else
	{
		for (int q = i; q <= m; q++)
			d[k++] = c[q];
	}
}


void MergePass2(int x[], int y[], int s, int n)
{//合并大小为s的相邻子数组
	int i = 0;
	while (i <= n - 2 * s)
	{
		//合并大小为s的相邻2段子数组
		Merge2(x, y, i, i + s - 1, i + 2 * s - 1);
		i = i + 2 * s;
	}
	//剩下的元素个数少于2s
	if (i + s < n)
		Merge2(x, y, i, i + s - 1, n - 1);
	else
		for (int j = i; j <= n - 1; j++)
			y[j] = x[j];
}

void MergeSort2(int a[], int n)
{
	int *b = new int[n];
	int s = 1;
	while (s < n)
	{
		MergePass2(a, b, s, n);//合并到数组b
		s += s;
		MergePass2(b, a, s, n);//合并到数组a
		s += s;
	}

}