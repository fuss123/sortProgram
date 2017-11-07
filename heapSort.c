#include <stdio.h>
#include <stdlib.h>
#include "common.h"
#include "heapSort.h"

void initHeap(Heap *h, int len) 
{
	h->heapSize = 0;
	h->heap = (int*)malloc(sizeof(int) * len);
	
	if (h->heap == NULL) 
	{
		fputs("memory allocation error!", stdout);
		exit(-1);
	}
}

void pushHeap(Heap *h, int item) 
{
	int i = ++(h->heapSize);

	while (i != 1 && item > h->heap[i / 2]) 
	{
		h->heap[i] = h->heap[i / 2];
		i /= 2;
	}

	h->heap[i] = item;
}

int popHeap(Heap *h) 
{
	int parent = 1, child = 2, item, tmp;
	item = h->heap[1];
	tmp = h->heap[(h->heapSize)--];

	while (child <= h->heapSize) 
	{
		if (child < h->heapSize && h->heap[child] < h->heap[child + 1])
			child++;
		
		if (tmp >= h->heap[child]) 
			break;

		h->heap[parent] = h->heap[child];
		parent = child;
		child *= 2;
	}

	h->heap[parent] = tmp;
	return item;
}

void prtHeap(Heap *h) 
{
	int i = 0;

	for (i = 1; i < h->heapSize; i++)
		fprintf(stdout, "%3d ", h->heap[i]);
	fputs("\n", stdout);
}

void heapSort(int arr[], int len, int criteria) 
{
	int i = 0;
	Heap h;
	initHeap(&h, len);
	
	for (i = 0; i < len; i++)
	{
		pushHeap(&h, arr[i]);
		prtHeap(&h);
	}

	switch (criteria) 
	{
	case ASCENDING:
		for (i = len - 1; i >= 0; i--)
		{
			arr[i] = popHeap(&h);
			prtHeap(&h);
		}
		break;
	case DESCENDING:
		for (i = 0; i < len; i++)
		{
			arr[i] = popHeap(&h);
			prtHeap(&h);
		}
	}
}