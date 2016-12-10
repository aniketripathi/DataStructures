/*
 * linkedList.c
 *
 *  Created on: 03-Aug-2016
 *      Author: Aniket
 */

#include "../inc/linkedList.h"

/**
 * @brief A function to display error message.
 *
 * This is a static method which prints an error message in standard error stream -stderr. You can create
 * your own error handler and add some more procedures in the function. This function is not displayed in header
 * file.
 *
 * @param	message Message to be displayed.
 * @return	void, Returns nothing.
 */
inline static void showListError(char *message){
	fputs(message, stderr);
}



void addAtListHead(List_t *list, Node_t *node){
	if(isListDestroyed(list) || isNodeDestroyed(node) )
		showListError("Cannot add Node at head. List or node is already destroyed.\n");

	else if(isListEmpty(list)){
		list->head = node;
		list->tail = node;
	}
	else {
		list->head->previousNext = XOR(list->head->previousNext, node);
		node->previousNext = list->head;
		list->head = node;
	}
}



void addAtListTail(List_t *list, Node_t *node){
	if(isListDestroyed(list) || isNodeDestroyed(node) )
		showListError("Cannot add Node at tail. List or node is already destroyed.\n");

	else if(isListEmpty(list)){
		list->head = node;
		list->tail = node;
	}
	else {
		list->tail->previousNext = XOR(list->tail->previousNext, node);
		node->previousNext = list->tail;
		list->tail = node;
	}
}

void addAtListPosition(List_t *list, size_t position, Node_t *node){
	if(isListDestroyed(list) || isNodeDestroyed(node) || isListEmpty(list) )
			showListError("Cannot add Node at position. List or node is already destroyed or list is empty.\n");
	size_t currPos; Node_t *prevNode = NULL; Node_t *currentNode = list->head; int posError = 0;

	/* Finding where to insert the node */
	for(currPos = 0; currPos < position; currPos++){
		if(currentNode == list->tail){
			currentNode = NULL;
			prevNode = list->tail;
		}
		else {
			Node_t *temp = currentNode;
			currentNode = NEXTNODE(prevNode, currentNode);
			prevNode = temp;
		}
		if(currentNode == NULL && (currPos+1) != position)		posError = 1;			/* position is out of list */
	}

	if(posError)
		showListError("Cannot add node. Invalid position entered.\n");
	else {		/*When the position is valid */
				if(prevNode == NULL)		addAtListHead(list, node);
		else	if(currentNode == NULL)		addAtListTail(list, node);
		else{
		node->previousNext = XOR(prevNode, currentNode);
			prevNode->previousNext = XOR( XOR(prevNode->previousNext,currentNode), node);
			currentNode->previousNext 	= XOR( XOR(prevNode, currentNode->previousNext), node);
	}
}

}




Node_t *createListNode(int data){
	Node_t *newNode = malloc(sizeof(Node_t));
	newNode->data = data;
	newNode->previousNext = NULL;
	return newNode;
}


List_t *createListWithNode(Node_t *node){
	List_t *list = malloc(sizeof(List_t));
	list->head = node;
	list->tail = node;
	return list;
}


List_t *createList(size_t number, int data){
	if(!number) {
		showListError("List cannot be created. Number of nodes must be greater than 0.\n");
		return NULL;
	}
	List_t *list = createListWithNode(createListNode(data));
	size_t count = number - 1;
	/* nodes will be added to head using */
	while(count--)		addAtListHead(list, createListNode(data));
	return list;
}



void destroyList(List_t **list){
	if(list != NULL){
	if((*list)->head != NULL || (*list)->tail != NULL)
		showListError("Cannot destroy list. First destroy its node members.\n");
	else {
		free(*list);
		*list = NULL;
	}
	}
}

void destroyListNode(Node_t **node){
	if(node != NULL)
	free(*node);
	*node = NULL;
}




void deleteListHead(List_t *list){
	if(isListDestroyed(list) || isListEmpty(list))
		showListError("Cannot delete head. The list is empty or destroyed");

	else {
		Node_t *prevNode = NULL;
		Node_t *currentNode = list->head;
		Node_t *nextNode = NEXTNODE(prevNode, currentNode);

		if(nextNode != 	NULL)		nextNode->previousNext = XOR(nextNode->previousNext, currentNode);
		else						list->tail = NULL;
		destroyListNode(&currentNode);
		list->head = nextNode;

	}
}


void deleteListTail(List_t *list){
	if(isListDestroyed(list) || isListEmpty(list))
			showListError("Cannot delete tail. The list is empty or destroyed");

		else {
				/* tail will behave similar to head */
			Node_t *prevNode = NULL;
			Node_t *currentNode = list->tail;
			Node_t *nextNode = NEXTNODE(prevNode, currentNode);

			if(nextNode != NULL) 	nextNode->previousNext = XOR(nextNode->previousNext, currentNode);
			else					list->head = NULL;
			destroyListNode(&currentNode);
			list->tail = nextNode;

		}

}


void deleteList(List_t *list){
	if(isListDestroyed(list) || isListEmpty(list))
				showListError("Cannot delete list. The list is empty or destroyed");

			else 		while(list->head != NULL)		deleteListHead(list);
}


Node_t *searchList(List_t *list, int data){
	if(isListDestroyed(list) || isListEmpty(list)){
			showListError("Cannot search in list. The list is empty or destroyed");
			return NULL;
		}

	Node_t *prevNode = NULL;
	Node_t *currentNode = list->head;
	while(currentNode != NULL){
		if(currentNode->data == data)		return currentNode;
		Node_t *temp = currentNode;
		currentNode = NEXTNODE(prevNode, currentNode);
		prevNode = temp;
	}
	return NULL;
}


void reverseList(List_t *list){
	if(isListDestroyed(list) || isListEmpty(list))
		showListError("Cannot reverse the list. The list is empty or destroyed.\n");
/* XOR list is symmetric in nature, only reversing the head and tail will reverse the whole list. */
	else {
		Node_t *swapHead = list ->head;
		list->head = list->tail;
		list->tail = swapHead;
	}
}


void traverseList(List_t *list, char separator, FILE *stream){
	if(isListDestroyed(list) || isListEmpty(list) || stream == NULL)
						showListError("Cannot traverse list. The list is empty or destroyed or the stream is invalid.");
	else {
		Node_t *prevNode = NULL;
		Node_t *currentNode = list->head;
		while(currentNode != NULL){
		/* If the current node is last node, then new line character is used instead of separator character */
			fprintf(stream, "%d%c", currentNode->data, ((currentNode != list->tail)?separator:'\n'));
			Node_t *temp = currentNode;
			currentNode = NEXTNODE(prevNode, currentNode);
			prevNode = temp;
		}
	}
}
