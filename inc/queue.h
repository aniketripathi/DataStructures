/*
 * cqueue.h
 *
 *  Created on: 24-Jul-2016
 *      Author: Aniket
 */

#ifndef QUEUE_H_
#define QUEUE_H_

#include <stdio.h>
#include <stdlib.h>

/**
 *
 * @brief Structure to create queue. The structure contains four elements. The size of the queue is the number of elements in the stack.
 *
 * @brief Type definition for structure Queue_t
 */
typedef struct{
	/**@brief Pointer to hold integer numbers like array. **/
	int *items;
	/** @brief Position from where the elements will be deleted.**/
	int head;
	/** @brief position at which the element will be inserted. **/
	int tail;
	/** @brief Number of elements allowed in queue. **/
	unsigned int size;
}Queue_t;


 /**
  * Creates a queue with capacity of size. Memory from heap is allocated.
  * @param size length or capacity of queue.
  * @return returns a pointer to queue. NULL is returned if queue cannot be created.
  */
 Queue_t *createQueue(unsigned int size);



 /**
  * Destroys a queue. The memory allocated to queue will be released.
  * @param queue Queue to be destroyed.
  */
 void destroyQueue(Queue_t *queue);


 /**
  * Checks whether the given queue is full or not.
  * @param queue Pointer to a queue.
  * @return returns 1 if stack is full else 0.
  */
 int isQueueFull(Queue_t *queue);

 /**
  * Checks whether the given queue is empty or not.
  * @param queue Pointer to a queue.
  * @return returns 1 if stack is empty else 0.
  */
 int isQueueEmpty(Queue_t *queue);

 /**
  * Inserts an element number into the queue at position tail. If the stack if full an error message is displayed.
  * @param queue	queue in which number needs to be inserted.
  * @param number number to be inserted.
  */
 void enqueue(Queue_t *queue, int number);

 /**
  * Deletes an element from the queue from the position head and returns that element.
  * @param queue	Queue where this operation is to be performed.
  * @return 		Element which was added first among the numbers. If stack is empty 0 is returned and an error message
  * 			is displayed
  */
 int dequeue(Queue_t *queue);

#endif /* QUEUE_H_ */
