/*
 * singlyLinkedList.h
 *
 *  Created on: 01-Aug-2016
 *      Author: Aniket
 */


#ifndef LINKEDLIST_H_
#define LINKEDLIST_H_

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

/**
 *@brief Macro defined to check whether the node is NULL.
 */
#define isNodeDestroyed(x)  	(x == NULL)

/**
 * @brief Macro defined to check whether the list is NULL.
 */
#define isListDestroyed(x)		(x == NULL)

/**
 * @brief Macro defined to check whether the list is empty or not.
 */
#define isListEmpty(x) 			(x->head == NULL && x->tail == NULL)

/**
 * @brief Macro defined to perform XOR operations on two pointers.
 */
#define XOR(p,q)				((void*) ( (uintptr_t)(p) ^ (uintptr_t)(q) ))

/**
 * @brief Macro defined to find the next node given the address of current and previous nodes.
 */
#define	NEXTNODE(prev, curr)	(XOR((prev),(curr)->previousNext))


/**
 *@brief Structure defining the node of a XOR linked list.
 */
typedef struct ListNode{
	/**
	 * @brief Stores the integer value.
	 */
	int data;

	/** @brief Stores the XOR of address of previous and next node.
	 *
	 */
	struct ListNode *previousNext;
}Node_t;


/**
 * @brief Structure to define the XOR linked list.
 */
typedef struct {
	/**
	 *@brief Stores the address of the first node of the linked list.
	 */
	Node_t *head;

	/**
	 * @brief Stores the address of the last node of the linked list.
	 */
	Node_t *tail;
}List_t;


/**
 * @brief Adds a node at the head of the linked list.
 *
 * Adds a node at the head of the linked list, even if the list is empty. If the list or node is destroyed
 * appropriate error message is displayed.
 *
 * @param  list List to which the node should be added.
 * @param  node Node to be added.
 * @return void, Returns nothing.
 */
void 		addAtListHead(List_t* list, Node_t* node);


/**
 * @brief Adds a node at the tail of the linked list.
 *
 * Adds a node at the tail of the linked list, even if the list is empty. If the list or node is destroyed
 * appropriate error message is displayed.
 *
 * @param  list List to which the node should be added.
 * @param  node Node to be added.
 * @return void, Returns nothing.
 */
void 		addAtListTail(List_t* list, Node_t* node);


/**
 * @brief Adds a node at a specific position in the linked list.
 *
 * Adds a node at the specific position of the linked list. If the list or node is destroyed or the list is empty
 * appropriate error message is displayed. The position follows zero index rule, that is the head is at zero position.
 * If the position lies outside the list, appropriate error message is displayed.
 *
 * @param  list List to which the node should be added.
 * @param  pos	Position at which the node is to be added. Zero denotes head.
 * @param  node Node to be added.
 * @return void, Returns nothing.
 */
void		addAtListPosition(List_t* list, size_t pos, Node_t *node);


/**
 * @brief Creates a node of linked list.
 *
 * Creates a node of linked list type and stores the given data. Returns NULL if memory is not allocated successfully.
 *
 * @param	data Integer number to be stored in the node.
 * @return	Address of the node created.
 */
Node_t*		createListNode(int data);



/**
 * @brief Creates a linked list with a given node.
 *
 * Creates a linked list with a given node. If the node is NULL, empty linked list is created.
 *
 * @param	node Given node.
 * @return	Address of the linked list created.
 */
List_t*		createListWithNode(Node_t* node);


/**
 * @brief Creates a linked list with given number of nodes and data.
 *
 * Creates a list with given number of nodes and stores the given data in each of the node. If the number of nodes passed is zero
 * then appropriate error message is displayed and NULL is returned.
 *
 * @param	number Number of nodes to be created along with the new linked list.
 * @param	data   Integer number to be stored in each node.
 * @return	Address of the linked list created. If the number of nodes is zero, NULL is returned.
 */
List_t*		createList(size_t number, int data);


/**
 * @brief Destroys a node.
 *
 * Destroys a node and sets that node pointer to null.
 *
 * @param 	node Address of the node pointer.
 * @return	void, Returns nothing.
 */
void		destroyListNode(Node_t **node);


/**
 * @brief Destroys an empty list.
 *
 * Destroys an empty list. If the list is not, an appropriate error message is displayed and list is not destroyed.
 *
 * @param	list Linked list to be destroyed
 * @return	void, Returns nothing.
 */
void		destroyList(List_t **list);


/**
 * @brief Reverses the linked list.
 *
 * Reverses the entire linked list. The head and tail will change their positions.
 *
 * @param	list Linked list to be reversed.
 * @return	void, Returns nothing.
 */
void		reverseList(List_t* list);



/**
 * @brief Deletes the head node of the linked list.
 *
 * Deletes the head node of the linked list. If the list is empty or destroyed, an appropriate error message
 * is displayed.
 *
 * @param 	list Linked list whose head is to be deleted.
 * @return	void, Returns nothing.
 *
 */
void		deleteListHead(List_t* list);


/**
 * @brief Deletes the tail node of the linked list.
 *
 * Deletes the tail node of the linked list. If the list is empty or destroyed, an appropriate error message
 * is displayed.
 *
 * @param 	list Linked list whose tail is to be deleted.
 * @return	void, Returns nothing.
 *
 */
void		deleteListTail(List_t* list);


/**
 * @brief Deletes all the nodes of the linked list.
 *
 * Deletes the entire list. If the list is destroyed or empty, an appropriate message is displayed.
 * Note that the list is not destroyed and nodes can be added to it later.
 *
 * @param	list Linked list to be made empty.
 * @return	void, Return nothings.
 */
void		deleteList(List_t* list);


/**
 * @brief Searches a node based on its data in the linked list.
 *
 * Gives the address of the first occurrence of the node containing the given data in the linked list.
 * In all the other conditions, it returns NULL. If the list is empty or destroyed, an appropriate error message
 * is displayed.
 *
 * @param	list Linked list where the node is to be searched.
 * @param	data Node containing this data will be searched.
 * @return	Returns the node containing the given data. In all other conditions, NULL is returned.
 */
Node_t*		searchList(List_t* list, int data);


/**
 * @brief Traverses the list from head to tail.
 *
 * Prints the items of the given list in the given file stream. If the list is destroyed or empty or the stream is NULL,
 *  an appropriate error message is displayed. The data of list will be separated by the given separator and a new line character
 *  will be printed after the last data.
 *
 *  @param	list Linked list to be traversed.
 *  @param	separator Character which will be printed between two consecutive data items.
 *  @param	stream	 File stream where the data will be traversed. Use stdout to display on output stream.
 *  @return void, Returns nothing.
 */
void		traverseList(List_t* list, char separator, FILE *stream);


#endif /* LINKEDLIST_H_ */
