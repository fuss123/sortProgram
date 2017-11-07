#include "fileIO.h"

status checkFileExistence(FILE *input, int *len) 
{
	int tmp = 0;

	if (input == NULL)
		return NONE;

	if (fscanf_s(input, " %d", &tmp) == EOF)
		return EMPTY;
	
	*len = tmp;
	return EXIST;
}

void importDataFromFile(FILE *input, int arr[], int *len) 
{
	int i = 0;

	for (i = 0; i < *len; i++)
	{
		fputs("enter number(up to 50): ", stdout);
		fscanf_s(input, " %d", &arr[i]);
		fprintf_s(stdout, "%d\n", arr[i]);
	}
	fclose(input);
}