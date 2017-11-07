#include "common.h"
#include "quickSort.h"

void setArrLeftToMedian(int arr[], int len) 
{
	int left = 0, mid = len / 2, right = len - 1;

	if (arr[left] > arr[mid])
		swap(&left, &mid);
	
	if (arr[mid] > arr[right])
		swap(&mid, &right);

	if (arr[left] > arr[mid])
		swap(&left, &mid);

	swap(&arr[0], &arr[mid]);
}

int partition(int arr[], int left, int right, int criteria) 
{
	int pivot, low, high, i = 0;
	pivot = arr[left];
	low = left + 1;
	high = right;

	while (low <= high) 
	{
		switch (criteria) 
		{
		case ASCENDING:
			while (pivot >= arr[low] && low <= right)
				low++;
			while (pivot <= arr[high] && high >= (left + 1))
				high--;
			break;
		case DESCENDING:
			while (pivot <= arr[low] && low <= right)
				low++;
			while (pivot >= arr[high] && high >= (left + 1))
				high--;
		}

		if (low <= high)
			swap(&arr[low], &arr[high]);
	}

	swap(&arr[left], &arr[high]);
	return high;
}

void quickSort(int arr[], int left, int right, int criteria, int len) 
{
	if(left <= right)
	{
		int pivot = partition(arr, left, right, criteria);

		prtArr(arr, len);
		quickSort(arr, left, pivot - 1, criteria, len);
		quickSort(arr, pivot + 1, right, criteria, len);
	}
}