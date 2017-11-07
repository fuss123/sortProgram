#ifndef COMMON_H
#define COMMON_H

typedef enum {ASCENDING = 1, DESCENDING} criteria;
typedef enum {FALSE = 0, TRUE} boolean;

void swap(int *x, int *y);
void prtArr(int arr[], int len);
void prtBeforeArr(int arr[], int len);
void prtAfterArr(int arr[], int len);
int changeStrToInt(char *str);

#endif