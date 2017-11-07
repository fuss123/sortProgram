#include <stdio.h>
#include <stdlib.h>
#include "common.h"
#include "mergeSort.h"

void merge(int arr[], int left, int mid, int right, int criteria)
{
	int i = left, j = mid + 1, k = left, l = 0;
	int *sortArr = (int *)malloc(sizeof(int) * (right + 1));
	if (sortArr == NULL)
	{
		fputs("memory allocation error!", stdout);
		exit(-1);
	}

	while (i <= mid && j <= right) 
	{
		switch (criteria) 
		{
		case ASCENDING:
			if (arr[i] <= arr[j])
				sortArr[k++] = arr[i++];
			else
				sortArr[k++] = arr[j++];
			break;
		case DESCENDING:
			if (arr[i] >= arr[j])
				sortArr[k++] = arr[i++];
			else
				sortArr[k++] = arr[j++];
		}
	}

	if (i > mid)
		for (l = j; l <= right; l++)
			sortArr[k++] = arr[l];
	else
		for (l = i; l <= mid; l++)
			sortArr[k++] = arr[l];

	for (l = left; l <= right; l++)
		arr[l] = sortArr[l];

	free(sortArr);
}

void mergeSort(int arr[], int left, int right, int criteria, int len)
{
	int mid = 0;

	if (left < right) 
	{
		mid = (left + right) / 2;
		mergeSort(arr, left, mid, criteria, len);
		mergeSort(arr, mid + 1, right, criteria, len);
		merge(arr, left, mid, right, criteria);
		prtArr(arr, len);
	}
}