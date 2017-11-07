#include <stdio.h>
#include "showMenu.h"

type selectSortType() 
{
	int ans = 0;

	do {
		fputs("== == == == == == == == == ==\n", stdout);
		fputs("1. selection sort\n", stdout);
		fputs("2. insertion sort\n", stdout);
		fputs("3. bubble sort\n", stdout);
		fputs("4. merge sort\n", stdout);
		fputs("5. heap sort\n", stdout);
		fputs("6. radix sort\n", stdout);
		fputs("7. quick sort\n", stdout);
		fputs("8. shell sort\n", stdout);
		fputs("9. quit program\n", stdout);

		fputs("select sort type: ", stdout);
		fscanf_s(stdin, " %d", &ans);

		fputs("== == == == == == == == == ==\n\n", stdout);
	} while (ans < 1 || ans > 9);

	return ans;
}

criteria selectCriteria() 
{
	int ans = 0;

	do {
		fputs("1: ascending\n", stdout);
		fputs("2: descending\n", stdout);

		fputs("select criteria: ", stdout);
		fscanf_s(stdin, " %d", &ans);
		fputs("\n", stdout);
	} while (ans < 1 || ans > 2);
	
	return ans;
}

boolean myStringCompare(char *first, char *second)
{
	while (*first == *second)
	{
		if (*first == '\0' || *second == '\0')
			break;

		first++;
		second++;
	}

	return (*first == '\0' && *second == '\0') ? TRUE : FALSE;
}

void inputData(int arr[], int *len)
{
	char data[1024] = { 0 };
	int i = 0;

	while (TRUE) 
	{
		fputs("enter number(up to 50, end =): ", stdout);
		fscanf_s(stdin, " %s", data, sizeof(data));
		fgetchar();

		if (myStringCompare(data, "="))
			break;

		arr[i++] = changeStrToInt(data);
	}

	*len = i;
}