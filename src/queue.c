/*
 * queue.c
 *
 *  Created on: 25-Jul-2016
 *      Author: Aniket
 */
#include "../inc/queue.h"

 Queue_t *createQueue(unsigned int size){

	Queue_t *queue =  malloc(sizeof(Queue_t));
	queue->items = malloc(sizeof(int) * size);
	queue->head = -1;
	queue->tail = -1;
	queue->size = size;
	return queue;
}


 void destroyQueue(Queue_t *queue){
	free(queue->items);
	free(queue);
	queue = NULL;
}


 inline int isQueueFull(Queue_t *queue){
	return (queue->head != -1 && queue->tail == queue->head);
}

 inline int isQueueEmpty(Queue_t *queue){
	return (queue->head == -1);
}


 void enqueue(Queue_t *queue, int number){
	if(isQueueFull(queue))			fputs("Queue overflow!\n", stderr);
	else {
		if(queue->tail == -1){
					queue->tail = 0;
					queue->head = 0;
				}
		queue->items[queue->tail] = number;
		if(queue->tail == (int)queue->size -1)		queue->tail = 0;
		else									++(queue->tail);
	}

}


int dequeue(Queue_t *queue){
	if(isQueueEmpty(queue)){
		fputs("Queue Underflow!Returning 0.\n", stderr);
		return 0;
	}
	int number = queue->items[queue->head];
	if(queue->head == (int)queue->size -1)		queue->head = 0;
	else									++(queue->head);

	if(queue->head == queue->tail){
		queue->head = -1;
		queue->tail = -1;
	}
	return number;
}
