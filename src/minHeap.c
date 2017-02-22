/*
 * heap.c
 *
 *  Created on: 09-Dec-2016
 *      Author: Aniket
 */
#include "../inc/minHeap.h"



MinHeap_t *createHeap(long int maxSize){
	MinHeap_t *heap = malloc(sizeof(MinHeap_t));

	if(heap != NULL){
	 heap->arr =  malloc(sizeof(long int) * maxSize);
	 heap->maxSize = maxSize;
	 heap->heapSize = 0;
	}
	 return heap;
}


void minHeapify(MinHeap_t *heap, long int index){

	/* get right, left index of parent index */
	long int rightIndex = (index << 1) + 1, leftIndex = (index << 1) + 2, smallestIndex;

	if(rightIndex < heap->heapSize && heap->arr[rightIndex] < heap->arr[index])			smallestIndex = rightIndex;
	else																				smallestIndex = index;

	if(leftIndex < heap->heapSize && heap->arr[leftIndex] < heap->arr[smallestIndex])	smallestIndex = leftIndex;

	/* only heapify if it is required */
	if(smallestIndex != index){
		long int temp 		= heap->arr[index];
		heap->arr[index] 			= heap->arr[smallestIndex];
		heap->arr[smallestIndex] 	= temp;
		minHeapify(heap, smallestIndex);
	}

}



long int heapMinimum(MinHeap_t *heap){
	return (heap->arr[0]);
}


long int heapExtractMinimum(MinHeap_t *heap){
/* if heap is empty */
	if(heap->heapSize < 1)	{
		fputs("Underflow! No element in heap. Returning -1.\n", stderr);
		return -1;
	}

/* extract the first element, remove it from heap by overwriting, reduce heap size and heapify */
	long int min = heap->arr[0];
	heap->arr[0] = heap->arr[heap->heapSize - 1];
	--(heap->heapSize) ;
	minHeapify(heap, 0);
	return min;
}


void heapDecreaseKey(MinHeap_t *heap, long int index, long int key){

#define PARENT(i)	(( (i) - 1)/2)

	if(key >= heap->arr[index])			fputs("The key is greater than or equal to the original key\n.", stderr);

	else {
		heap->arr[index] = key;

		/* replace the ancestors of index with index if they violate minimum heap property */
		while(index > 0 && heap->arr[PARENT(index)] > heap->arr[index]){
			long int temp = heap->arr[PARENT(index)];
			heap->arr[PARENT(index)] = heap->arr[index];
			heap->arr[index] = temp;

			index = PARENT(index);
		}

	}
#undef PARENT
}



void heapInsert(MinHeap_t *heap, long int key){
	if(heap->heapSize >= heap->maxSize)		fputs("Cannot insert into heap. Heap is full.\n", stderr);
	else {
		 ++(heap->heapSize);
		 /* assume the key to be infinite - here LONG_MAX */
		 heap->arr[heap->heapSize-1] = LONG_MAX;
		 /* decrease to the required key */
		heapDecreaseKey(heap, heap->heapSize - 1, key);
	}
}




void destroyHeap(MinHeap_t **heap){

	free((*heap)->arr);
	free(*heap);
	heap = NULL;
}
