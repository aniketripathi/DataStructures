/*
 * stack.c
 *
 *  Created on: 22-Jul-2016
 *      Author: Aniket
 */

/*
 * This file contains the implementation of stack.h
 *
 */

#include "../inc/stack.h"
inline int isStackFull(Stack_t *stack){
	return (stack->top == stack->size-1);
}


inline int isStackEmpty(Stack_t *stack){
	return (stack->top == -1);
}



Stack_t *createStack(unsigned int size){

	Stack_t *stack = malloc(sizeof(Stack_t));
	if(stack != NULL) {
		stack->items   = malloc(sizeof(int) * size);
		stack->top	   = -1; /* empty by default */
		stack->size = size;
	}
	return stack;
}


void destroyStack(Stack_t *stack){
	free(stack->items);
	free(stack);
	stack = NULL;
}


Stack_t *resize(Stack_t *stack, unsigned int size){
		if(size == 0){
			destroyStack(stack);
			return stack;
		}
	realloc(stack, size * sizeof(unsigned int));
		if(stack->top >= size)		stack->top = size-1;
		stack->size = size;
		return stack;
}


void push(Stack_t *stack, int number){
			if(stack == NULL)		fputs("Stack is NULL!\n", stderr);
	else	if(isStackFull(stack))	fputs("Stack is full. Overflow!\n", stderr);
	else							stack->items[++stack->top] = number;
}


int pop(Stack_t *stack){
	if(stack == NULL){
		fputs("Stack is NULL! Returning 0.\n", stderr);
		return 0;
	}
	if(isStackEmpty(stack)){
		fputs("Stack is empty. Underflow! Returning 0.\n", stderr);
		return 0;
	}
	return stack->items[stack->top--];
}

