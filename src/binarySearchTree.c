/*
 * binarySearchTree.c
 *
 *  Created on: 04-Nov-2016
 *      Author: Aniket
 */

#include "../inc/binarySearchTree.h"


/*
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

/* set default attributes */
	DATA(newNode) = data;
	LEFT(newNode) = NULL;
	RIGHT(newNode) = NULL;
	PARENT(newNode) = NULL;

	return newNode;
}

/* delete a BST node */
void deleteBSTNode(Node_t **node){
	free(*node);
	*node = NULL;
}



void insertNodeBST(Node_t **root, Node_t *node){
	if(node == NULL)	showBSTError("Cannot insert an empty node.\n");

	/* valid node */
	else {

		if(*root == NULL)		*root = node;
		else {

			/* search for parent node where node is to be inserted */
			Node_t *temp = *root, *parent;
			while(temp != NULL){
				parent = temp;
				if(DATA(node) <= DATA(temp))		temp = LEFT(temp);
				else								temp = RIGHT(temp);
			}
			/* insert node into parent node according to its key */
			if(DATA(node) <= DATA(parent))			LEFT(parent) = node;
			else									RIGHT(parent)= node;
			PARENT(node) = parent;
		}
	}
}




void deleteNodeBST(Node_t **root, Node_t *node){
	if(*root == NULL || node == NULL)	showBSTError("Cannot delete node. Tree or node is NULL.\n");
	else {
				if(LEFT(node) == NULL && RIGHT(node) == NULL)	replaceNodeBST(root, node, NULL);
		else 	if(LEFT(node) == NULL)		replaceNodeBST(root, node, RIGHT(node));
		else    if(RIGHT(node) == NULL)		replaceNodeBST(root, node, LEFT(node));
		else {
			Node_t *successor = successorBST(root, node);
			/* successor will take place of the node when deleted */
			if( PARENT(successor) != node){
		/* replace right subtree of successor to with the successor */
			replaceNodeBST(root, successor, RIGHT(successor));

		/* associate right, left , parent of node and successor */
			RIGHT(successor) = RIGHT(node);
			PARENT(RIGHT(node)) = successor;

		/* finally replace node with successor */
			replaceNodeBST(root, node, successor);
			LEFT(successor) = LEFT(node);
			PARENT(LEFT(node)) = successor;
			}
			else {
			/* replace node with successor and associate their left only */
				replaceNodeBST(root, node, successor);
				LEFT(successor) = LEFT(node);
			}
		}


			deleteBSTNode(&node);
	}
}


Node_t *searchBST(Node_t **root, int key){
	if(*root == NULL)	{
		showBSTError("Cannot search. The tree is empty.\n");
		return NULL;
	}
	/* search node */
		Node_t *temp = *root;
		while(temp != NULL ){
			if (key == DATA(temp))			break;
			if(key <= DATA(temp))			temp = LEFT(temp);
			else							temp = RIGHT(temp);
		}

	return temp;
}


Node_t *minimumBST(Node_t **root){
	if(*root == NULL){
		showBSTError("Cannot find minimum. The tree is empty.\n");
		return NULL;
	}

/* minimum is at the left most node of the tree */
	Node_t *temp = *root;
	while(LEFT(temp) != NULL)	temp = LEFT(temp);

	return temp;
}


Node_t *maximumBST(Node_t **root){
	if(*root == NULL){
		showBSTError("Cannot find maximum. The tree is empty.\n");
		return NULL;
	}

/* maximum is the right most node of the tree */
	Node_t *temp = *root;
	while(RIGHT(temp) != NULL)	temp = RIGHT(temp);

	return temp;
}


void preorderTraversalBST(Node_t **root){
	if(*root != NULL){
		printf("%d,", DATA(*root));
		preorderTraversalBST(&LEFT(*root));
		preorderTraversalBST(&RIGHT(*root));
	}
}



void inorderTraversalBST(Node_t **root){
	if(*root != NULL){
		inorderTraversalBST(&LEFT(*root));
		printf("%d,", DATA(*root));
		inorderTraversalBST(&RIGHT(*root));
	}
}


void postorderTraversalBST(Node_t **root){
	if(*root != NULL){
		postorderTraversalBST(&LEFT(*root));
		postorderTraversalBST(&RIGHT(*root));
		printf("%d,", DATA(*root));
	}
}


/* Successor is the smallest element greater than current node */
Node_t *successorBST(Node_t **root, Node_t *node){
	if(*root == NULL || node ==  NULL){
		showBSTError("Tree or node is NULL. Returning -1/n");
		return NULL;
	}
/* search for minimum in right subtree */
	if(RIGHT(node) != NULL )	return minimumBST(&RIGHT(node));
	Node_t *temp = node;
	Node_t *tempParent = PARENT(temp);
	/* search in ancestors */
	while(tempParent != NULL  && temp != (tempParent) )  {
		temp = tempParent;
		tempParent = PARENT(tempParent);
	}
return tempParent;
}



/* Predecessor is the smallest element greater than current node */
Node_t *predecessorBST(Node_t **root, Node_t *node){

	if(*root == NULL || node ==  NULL){
			showBSTError("Tree or node is NULL. Returning -1/n");
			return NULL;
	}
/* search for maximum in left subtree */
	if(LEFT(node) != NULL )	return maximumBST(&LEFT(node));
	Node_t *temp = node;
	Node_t *tempParent = PARENT(temp);
	/* search in ancestors */
	while(tempParent != NULL  && temp != RIGHT(tempParent) )  {
		temp = tempParent;
		tempParent = PARENT(tempParent);
	}
return tempParent;
}


/* It replaces a node in a tree with another node. Note that the initial node is not deleted */
void replaceNodeBST(Node_t **root, Node_t *initial, Node_t *final){
	if(PARENT(initial) == NULL)		*root = final;
	else if(initial == LEFT(PARENT(initial)) ) 		LEFT(PARENT(initial)) = final;
	else if(initial == RIGHT(PARENT(initial)) ) 	RIGHT(PARENT(initial)) = final;

	if( final != NULL)		PARENT(final) = PARENT(initial);
}



