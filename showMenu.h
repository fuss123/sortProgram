#ifndef SHOW_MENU_H
#define SHOW_MENU_H

#include "common.h"
typedef enum {SELECTION = 1, INSERTION, BUBBLE, MERGE, HEAP, RADIX, QUICK, SHELL, QUIT} type;

type selectSortType();
criteria selectCriteria();
void inputData(int arr[], int *len);

#endif