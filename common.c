#include <stdio.h>
#include "common.h"

void swap(int *x, int *y) 
{
	if (x != y) 
	{
		*x ^= *y;
		*y ^= *x;
		*x ^= *y;
	}
}

void prtArr(int arr[], int len)
{
	int i = 0;

	for (i = 0; i < len; i++)
		fprintf(stdout, "%3d ", arr[i]);
	fputs("\n", stdout);
}

void prtBeforeArr(int arr[], int len) 
{
	fputs("\nbefore ", stdout);
	prtArr(arr, len);
	fputs("\n", stdout);
}

void prtAfterArr(int arr[], int len) 
{
	fputs("\nafter ", stdout);
	prtArr(arr, len);
	fputs("\n", stdout);
}

int changeStrToInt(char *str) 
{
	int i = 0, integer = 0;

	for (i = 0; str[i] != '\0'; i++) 
		integer = integer * 10 + (int)(str[i] - '0');

	return integer;
}