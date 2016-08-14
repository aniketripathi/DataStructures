/*
 * stack.h
 *
 *  Created on: 22-Jul-2016
 *      Author: Aniket Kumar Tripathi
 */


#ifndef STACK_H_
#define STACK_H_


#include <stdio.h>
#include <stdlib.h>

/**
 *
 * @brief 	Structure to create stack. The structure contains three member. The size of the stack is the number of is the elements in the stack.
 *
 *
 * @brief	Type definition for structure Stack
 * */
typedef struct{
	/** @brief Pointer to hold integer numbers like array. **/
	 int *items;

	 /** @brief Position of top most or current element of stack.**/
	 int top;

	 /** @brief Number of elements allowed in stack. **/
	 unsigned int size;
}Stack_t;

/**
 * Checks whether the given stack is full or not.
 * @param stack Pointer to a stack.
 * @return returns 1 if stack is full else 0.
 */
inline int isStackFull(Stack_t *stack);


/**
 * Checks whether the given stack is empty or not.
 * @param stack Pointer to a stack.
 * @return returns 1 if stack is empty else 0.
 */
inline int isStackEmpty(Stack_t *stack);


/**
 * Creates a stack with capacity of size. Memory from heap is allocated.
 * @param size length or capacity of the stack.
 * @return returns a pointer to stack. NULL is returned if stack cannot be created.
 */
Stack_t* createStack(unsigned int size);


/**
 * Destroys a stack. The memory allocated to stack will be released.
 * @param stack Stack to be destroyed.
 */
void destroyStack(Stack_t *stack);


/**
 * Inserts an element number into the stack. If the stack if full an error message is displayed.
 * @param stack	stack in which number needs to be inserted.
 * @param number number to be inserted.
 */
void push(Stack_t *stack, int number);


/**
 * Deletes an element from the stack and returns that element.
 * @param stack	Stack where this operation is to be performed.
 * @return Most recently added element. If stack is empty 0 is returned and an error message
 * 			is displayed
 */
int pop(Stack_t *stack);

/**
 * Resizes the stack and changes its maximum capacity. If the size is 0, stack is destroyed.
 * If size is less than maximum size of stack then elements are at the top end are truncated
 * and top is set to the max limit if it is greater or equal to size.
 * @param stack	Stack to be resized
 * @param size	New size of stack
 * @return pointer to the resized stack.
 */
Stack_t* resize(Stack_t* stack, unsigned int size);

#endif /* STACK_H_ */
