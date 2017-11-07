#include "common.h"
#include "insertionSort.h"

void insertionSort(int arr[], int len, int criteria)
{
	int i = 0, j = 0, insData = 0;

	for (i = 1; i < len; i++) 
	{
		insData = arr[i];
		prtArr(arr, len);

		for (j = i - 1; j >= 0; j--)
		{
			if (criteria == ASCENDING) 
			{
				if (insData < arr[j])
					arr[j + 1] = arr[j];
				else
					break;
			}
			else if (criteria == DESCENDING) 
			{
				if (insData > arr[j])
					arr[j + 1] = arr[j];
				else
					break;
			}
		}

		arr[j + 1] = insData;
	}
}