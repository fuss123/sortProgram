#include "common.h"
#include "selectionSort.h"

void selectionSort(int arr[], int len, int criteria)
{
	int i = 0, j = 0, idx = 0;

	for (i = 0; i < len - 1; i++)
	{
		idx = i;
		for (j = i + 1; j < len; j++)
		{
			switch (criteria) 
			{
			case ASCENDING: 
				if (arr[idx] > arr[j])
					idx = j;
				break;
			case DESCENDING:
				if (arr[idx] < arr[j])
					idx = j;
			}
		}
		if (i != idx) 
			swap(&arr[i], &arr[idx]);

		prtArr(arr, len);
	}
}