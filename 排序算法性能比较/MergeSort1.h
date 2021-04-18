#pragma once
void Merge1(int a[], int b[], int left, int mid, int right)
{
	int i = left, j = mid + 1, k = left;//’‚¿Ôk=left 
	while (i <= mid && j <= right)
	{
		if (a[i] <= a[j])
			b[k++] = a[i++];
		else
			b[k++] = a[j++];
	}
	while (i <= mid)
		b[k++] = a[i++];
	while (j <= right)
		b[k++] = a[j++];
}
void Copy(int a[], int b[], int left, int right)
{

	for (int i = left; i <= right; i++)
		a[i] = b[i];
}
void MergeSort1(int a[], int b[], int left, int right)
{

	if (left < right)
	{
		int mid = (left + right) / 2;
		MergeSort1(a, b, left, mid);
		MergeSort1(a, b, mid + 1, right);
		Merge1(a, b, left, mid, right);
		Copy(a, b, left, right);
	}
}