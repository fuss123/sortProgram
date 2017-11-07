#include "common.h"
#include "bubbleSort.h"

void bubbleSort(int arr[], int len, int criteria)
{
	int i = 0, j = 0;

	for (i = len - 1; i >= 1; i--)
	{
		prtArr(arr, len);

		for (j = 0; j < i; j++)
		{
			switch (criteria) 
			{
			case ASCENDING:
				if (arr[j] > arr[j + 1])
					swap(&arr[j], &arr[j + 1]);
				break;
			case DESCENDING:
				if (arr[j] < arr[j + 1])
					swap(&arr[j], &arr[j + 1]);
			}
		}
	}
}