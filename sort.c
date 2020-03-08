#include <stdio.h>

//√∞≈›≈≈–Ú

void bubble_sort(int* arr,int len)
{
	for (int i = 0; i < len - 1; i++)
	{
		int j = 0;
		for (; j < len - 1 - i; j++)
		{
			//µπ–

			if (arr[j] > arr[j + 1])
			{
				int temp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = temp;
			}
		}
	}
}

//≤Â»Î≈≈–Ú

void insertion_sort(int* arr, int len)
{
	for (int i = 1; i < len; i++)
	{
		int temp = arr[i];
		int j = i - 1;
		while (j >= 0 && temp < arr[j])
		{
			arr[j + 1] = arr[j];
			j--;
		}
		if (j != i - 1)
		{
			arr[j + 1] = temp;
		}
	}
}

//øÏÀŸ≈≈–Ú

void fast_sort(int* arr, int left, int right)
{
	if (left >= right)
	{
		return;
	}
	int i = left;
	int j = right;
	int temp = arr[left];

	while (i < j)
	{
		while (i < j && temp <= arr[j])
		{
			j--;
		}
		arr[i] = arr[j];
		while (i<j && temp>=arr[i])
		{
			i++;
		}
		arr[j] = arr[i];
	}
	arr[i] = temp;
	fast_sort(arr, left, i - 1);
	fast_sort(arr, i + 1, right);
}