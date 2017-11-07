#include <stdio.h>
#include <stdlib.h>
#include "common.h"
#include "radixSort.h"

void initQueue(Queue *q) 
{
	q->head = q->tail = NULL;
}

boolean isEmpty(Queue *q) 
{
	return (q->head == NULL);
}

void pushQueue(Queue *q, int item) 
{
	Node *newNode = (Node*)malloc(sizeof(Node));
	if (newNode == NULL)
	{
		fputs("memory allocation error!", stdout);
		exit(-1);
	}

	newNode->item = item;
	newNode->link = NULL;

	if (isEmpty(q))
		q->head = q->tail = newNode;
	else 
	{
		q->tail->link = newNode;
		q->tail = newNode;
	}
}

int popQueue(Queue *q) 
{
	Node *tmp = q->head;
	int item = 0;

	if (isEmpty(q))
		exit(-1);

	item = tmp->item;
	q->head = q->head->link;

	if (q->head == NULL)
		q->tail = NULL;

	free(tmp);
	return item;
}

int getDigit(int arr[], int len) 
{
	int i = 0, digit = 0, max;
	max = arr[0];

	for (i = 1; i < len; i++)
	{
		if (max < arr[i])
			max = arr[i];
	}

	while (max) 
	{
		digit++;
		max /= 10;
	}

	return digit;
}

void radixSort(int arr[], int len, int criteria)
{
	Queue bucket[BUCKET_NUM];
	int i, j, k, radix, digit, factor = 1;
	i = j = k = radix = 0;
	digit = getDigit(arr, len);

	for (i = 0; i < BUCKET_NUM; i++)
		initQueue(&bucket[i]);

	for (j = 0; j < digit; j++) 
	{
		for (k = 0; k < len; k++) 
		{
			radix = (arr[k] / factor) % BUCKET_NUM;
			pushQueue(&bucket[radix], arr[k]);
		}

		switch (criteria) 
		{
		case ASCENDING:
			for (i = 0, k = 0; i < BUCKET_NUM; i++)
			{
				while (!isEmpty(&bucket[i]))
					arr[k++] = popQueue(&bucket[i]);
			}
			break;
		case DESCENDING:
			for (i = BUCKET_NUM - 1, k = 0; i >= 0; i--)
			{
				while (!isEmpty(&bucket[i]))
					arr[k++] = popQueue(&bucket[i]);
			}
		}

		prtArr(arr, len);
		factor *= 10;
	}
}