#include "fileIO.h"
#include "showMenu.h"
#include "sort.h"

int main(void)
{
	FILE *input = NULL;
	int arr[50] = { 0 }, len = 0, sortType, criteria;
	
	sortType = selectSortType();
	if (sortType == QUIT)
		return 0;

	criteria = selectCriteria();

	fopen_s(&input, "data.txt", "rt");
	switch (checkFileExistence(input, &len))
	{
	case EXIST:
		importDataFromFile(input, arr, &len);
		break;
	case EMPTY:
	case NONE:
		inputData(arr, &len);
	}

	while (TRUE) 
	{
		prtBeforeArr(arr, len);

		switch (sortType)
		{
		case SELECTION:
			selectionSort(arr, len, criteria);
			break;
		case INSERTION:
			insertionSort(arr, len, criteria);
			break;
		case BUBBLE:
			bubbleSort(arr, len, criteria);
			break;
		case MERGE:
			mergeSort(arr, 0, len - 1, criteria, len);
			break;
		case HEAP:
			heapSort(arr, len, criteria);
			break;
		case RADIX:
			radixSort(arr, len, criteria);
			break;
		case QUICK:
			// consider the case where a nearly aligned array comes in as an argument.
			setArrLeftToMedian(arr, len);
			quickSort(arr, 0, len - 1, criteria, len);
			break;
		case SHELL:
			shellSort(arr, len, criteria);
			break;
		}

		prtAfterArr(arr, len);

		sortType = selectSortType();
		if (sortType == QUIT) 
			return 0;
		
		criteria = selectCriteria();
	}

	return 0;
}