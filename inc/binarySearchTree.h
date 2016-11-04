/*
 * binarySearchTree.h
 *
 *  Created on: 04-Nov-2016
 *      Author: Aniket
 */

#ifndef BINARYSEARCHTREE_H_
#define BINARYSEARCHTREE_H_

#include <stdio.h>
#include <stdlib.h>

#define LEFT(p)			((p)->left)
#define RIGHT(p)		((p)->right)
#define PARENT(p)		((p)->parent)
#define DATA(p)			((p)->data)


typedef struct bstNode {
	int data;
	struct bstNode *left;
	struct bstNode *right;
	struct bstNode *parent;
}Node_t;

Node_t *createBSTNode(int data);
void deleteBSTNode(Node_t **node);
void insertNodeBST(Node_t *root, Node_t *node);

Node_t *searchBST(Node_t *root, int key);
Node_t *minimumBST(Node_t *root);
Node_t *maximumBST(Node_t *root);

void preorderTraversalBST(Node_t *root);
void inorderTraversalBST(Node_t *root);
void postorderTraversalBST(Node_t *root);

#endif /* BINARYSEARCHTREE_H_ */
