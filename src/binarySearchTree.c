/*
 * binarySearchTree.c
 *
 *  Created on: 04-Nov-2016
 *      Author: Aniket
 */

#include "../inc/binarySearchTree.h"


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

inline static void showBSTError(char *message){
	fputs(message, stderr);
}


Node_t *createBSTNode(int data){
	Node_t *newNode = malloc(sizeof(Node_t));
	if(newNode == NULL)			showBSTError("Unable to create a new node.\n");

/** set default attributes **/
	DATA(newNode) = data;
	LEFT(newNode) = NULL;
	RIGHT(newNode) = NULL;
	PARENT(newNode) = NULL;

	return newNode;
}


void deleteBSTNode(Node_t **node){
	free(*node);
	*node = NULL;
}



void insertNodeBST(Node_t *root, Node_t *node){
	if(node == NULL)	showBSTError("Cannot insert an empty node.\n");

	/** valid node **/
	else {

		if(root == NULL)		root = node;
		else {

			/** search for parent node where node is to be inserted **/
			Node_t *temp = root, *parent;
			while(temp != NULL){
				parent = temp;
				if(DATA(node) <= DATA(temp))		temp = LEFT(temp);
				else								temp = RIGHT(temp);
			}
			/** insert node into parent node according to its key **/
			if(DATA(node) <= DATA(parent))			LEFT(parent) = node;
			else									RIGHT(parent)= node;
			PARENT(node) = parent;
		}
	}
}


Node_t *searchBST(Node_t *root, int key){
	if(root == NULL)	{
		showBSTError("Cannot search. The tree is empty.\n");
		return NULL;
	}

		Node_t *temp = root;
		while(temp != NULL ){
			if (key == DATA(temp))			break;
			if(key <= DATA(temp))			temp = LEFT(temp);
			else							temp = RIGHT(temp);
		}

	return temp;
}


Node_t *minimumBST(Node_t *root){
	if(root == NULL){
		showBSTError("Cannot find minimum. The tree is empty.\n");
		return NULL;
	}

/** minimum is at the left most node of the tree **/
	Node_t *temp = root;
	while(LEFT(temp) != NULL)	temp = LEFT(temp);

	return temp;
}


Node_t *maximumBST(Node_t *root){
	if(root == NULL){
		showBSTError("Cannot find maximum. The tree is empty.\n");
		return NULL;
	}

/** maximum is the right most node of the tree **/
	Node_t *temp = root;
	while(RIGHT(temp) != NULL)	temp = RIGHT(temp);

	return temp;
}


void preorderTraversalBST(Node_t *root){
	if(root != NULL){
		printf("%d,", DATA(root));
		preorderTraversalBST(LEFT(root));
		preorderTraversalBST(RIGHT(root));
	}
}


void inorderTraversalBST(Node_t *root){
	if(root != NULL){
		inorderTraversalBST(LEFT(root));
		printf("%d,", DATA(root));
		inorderTraversalBST(RIGHT(root));
	}
}


void postorderTraversalBST(Node_t *root){
	if(root != NULL){
		postorderTraversalBST(LEFT(root));
		postorderTraversalBST(RIGHT(root));
		printf("%d,", DATA(root));
	}
}
