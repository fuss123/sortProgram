#ifndef FILE_IO_H
#define FILE_IO_H

#include <stdio.h>

typedef enum {NONE = 0, EXIST, EMPTY} status;

status checkFileExistence(FILE *input, int *len);
void importDataFromFile(FILE *input, int arr[], int *len);

#endif