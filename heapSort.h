#ifndef HEAP_SORT_H
#define HEAP_SORT_H

typedef struct Heap {
	int *heap;
	int heapSize;
}Heap;

void heapSort(int arr[], int len, int criteria);

#endif