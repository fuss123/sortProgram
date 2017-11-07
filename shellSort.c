#include "common.h"
#include "shellSort.h"

void insertionSort_Shell(int arr[], int first, int last, int gap, int criteria) 
{
	int i = 0, j = 0, insData = 0;

	for (i = first + gap; i <= last; i += gap) 
	{
		insData = arr[i];
		for (j = i - gap; j >= first; j -= gap) 
		{
			if (criteria == ASCENDING) 
			{
				if (insData < arr[j])
					arr[j + gap] = arr[j];
				else
					break;
			}
			else if (criteria == DESCENDING) 
			{
				if (insData > arr[j])
					arr[j + gap] = arr[j];
				else
					break;
			}
		}
		arr[j + gap] = insData;
	}
}

void shellSort(int arr[], int len, int criteria) 
{
	int i = 0, gap = 0;

	for (gap = len / 2; gap >= 1; gap /= 2) 
	{
		prtArr(arr, len);

		if (gap % 2 == 0)
			gap++;

		for (i = 0; i < gap; i++)
			insertionSort_Shell(arr, i, len - 1, gap, criteria);
	}
}