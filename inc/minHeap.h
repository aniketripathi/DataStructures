/*
 * heap.h
 *
 *  Created on: 09-Dec-2016
 *      Author: Aniket
 */

#ifndef MINHEAP_H_
#define MINHEAP_H_

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

typedef struct{
	long int *arr;
	long int heapSize;
	long int maxSize;
}MinHeap;


/**
 * @brief Creates a heap and returns the address of the heap.
 *
 * Creates the heap by allocating memory to its members using malloc function. The maxSize argument tells the size of array
 * of the heap.
 *
 * @param maxSize Maximum size of heap to be created.
 * @return Address of the memory allocated to heap.
 */
MinHeap *createHeap(long int maxSize);


/**
 * @brief Decreases the key of any index in the heap.
 *
 * This function decreases the key of the given index in the given heap. The final key must be smaller than the original key. If not
 * then an error message is displayed. It automatically modifies the heap so that minimum heap property is not violated.
 *
 * @param heap Heap where operation is to be performed.
 * @param index Index of element whose key is to be decreased.
 * @param key Final value of key after decreasing.
 * @return void. Returns nothing.
 */
void heapDecreaseKey(MinHeap *heap, long int index, long int key);


/**
 * @brief Extracts the minimum element of the heap.
 *
 *	It extracts the minimum element of the heap. Here extraction means that it returns the minimum element and removes it from the heap.
 *	The heap property is maintained after extraction. If the heap is empty then error message is displayed and -1 is returned.
 *
 * @param heap Heap where extraction is to be performed.
 * @return Minimum element of the heap. If heap is empty then -1 is returned.
 */
long int heapExtractMinimum(MinHeap *heap);


/**
 * @brief Inserts a key into the heap.
 *
 * Inserts a key into the given heap and modifies the heap to maintain its property.
 * @param heap Where key is to be inserted.
 * @parem key Key to be inserted.
 */
void heapInsert(MinHeap *heap, long int key);


/**
 * @brief Gives the minimum key of the heap.
 *
 * Returns the minimum key of the heap. The heap is not modified.
 *
 * @param heap Heap whose minimum key is required.
 * @return Minimum key of the heap
 */
long int heapMinimum(MinHeap *heap);


/**
 * @brief Modifies the heap to maintain its property of minimum heap with respect to the given index.
 *
 * MinHeapify is an function that is used to correct the heap whenever a key violates a property of the heap. This function doesn't
 * modifies the whole heap. It just modifies the given index nodes and its children if required so that the sub-heap formed by index
 * node maintains the heap property.
 *
 * @param heap Where the operation is to be performed.
 * @index	Index(or node) which is to be checked and corrected for violating heap property.
 * @return void. Returns nothing.
 */
void minHeapify(MinHeap *heap, long int index);

/**
 *@brief Destroys the heap.
 *
 * It frees up the memory allocated to the array, and to the heap using free function. It also sets the heap pointer to NULL.
 *
 * @param heap Heap that need to be destroyed.
 * @return void. Returns nothing.
 */
void destroyHeap(MinHeap **heap);


#endif /* MINHEAP_H_ */
