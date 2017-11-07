#ifndef RADIX_SORT_H
#define RADIX_SORT_H

#define BUCKET_NUM 10

typedef struct Node {
	int item;
	struct Node *link;
}Node;
typedef struct Queue {
	Node *head, *tail;
}Queue;

void radixSort(int arr[], int len, int criteria);

#endif