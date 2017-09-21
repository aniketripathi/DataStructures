/** Header file for redBlackTree.c **/

#ifdef _RBT_H
#define _RBT_H

#include <stdio.h>
#include <stdlib.h>


typedef struct _Node_t {

struct _Node_t *left;
struct _Node_t *right;
struct  _Node_t *parent;
 int data;
 unsigned int color : 1;
}Node_t;


typedef struct {
 Node_t *root;
 Node_t *nil;
}RBT_t;

#define ROOT(t)     ((t)->root)
#define LEAF(t)     ((t)->nil)

#define LEFT(x)     ((x)->left)
#define RIGHT(x)    ((x)->right)
#define PARENT(x)   ((x)->parent)
#define COLOR(x)    ((x)->color)
#define DATA(x)     ((x)->data)

#define RED 0
#define BLACK 1

/** functions **/

/** Creates an empty RBT tree with LEAF node. Note that LEAF node is not NULL. It is a dummy node with COLOR=BLACK, DATA=0 and both
    LEFT and RIGHT pointing to NULL.
    **/
RBT_t *createRBT();

Node_t *createNodeRBT(int data);

void destroyNodeRBT(Node_t **node);

void destroyRBT(RBT_t **tree);

int blackHeightRBT(Node_t *node);

Node_t *minimumRBT(RBT_t *tree, Node_t *node);

Node_t *maximumRBT(RBT_t *tree, Node_t *node);

Node_t *searchNodeRBT(RBT_t *tree, Node_t *node);

void inorderTraversalRBT(RBT_t *tree, Node_t *node);

void leftRotateRBT(RBT_t *tree, Node_t *x);

void rightRotateRBT(RBT_t *tree, Node_t *y);

void insertNodeRBT(RBT_t *tree, Node_t *z);

void deleteNodeRBT(RBT_t *tree, Node_t *z);




#endif    
