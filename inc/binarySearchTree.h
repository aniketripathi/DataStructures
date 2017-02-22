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

/**
 * @brief Macro defined to get the left node of node p.
 */
#define LEFT(p)			((p)->left)

/**
 * @brief Macro defined to get the right node of node p.
 */
#define RIGHT(p)		((p)->right)

/**
 * @brief Macro defined to get the parent node of node p.
 */
#define PARENT(p)		((p)->parent)

/**
 * @brief Macro defined to get the data of node p.
 */
#define DATA(p)			((p)->data)


/**
 * @brief Structure defining the node of a Binary Search Tree.
 */
typedef struct bstNode {

	/**
	 * @brief Stores the integer value.
	 */
	int data;

	/**
	 * @brief Stores the address of left node.
	 */
	struct bstNode *left;

	/**
	 * @brief Stores the address of the right node.
	 */
	struct bstNode *right;

	/**
	 * @brief Stores the address of the parent node.
	 */
	struct bstNode *parent;
}Node_t;



/**
 * @brief Creates a BST node.
 *
 * Creates a Binary Search Tree node with the given key and returns the address of the node. If
 * memory cannot be allocated then error message is displayed.
 *
 * @param data Data value to be stored in the node.
 * @return Node_t* Address of the node created. NULL if node cannot be created.
 */
Node_t *createBSTNode(int data);


/**
 * @brief Deletes a BST node.
 *
 * Deletes a Binary Search Tree node and frees up the memory. The pointer is set to NULL.
 *
 * @param node Address of the pointer to be freed.
 * @return void. Returns nothing.
 */
void deleteBSTNode(Node_t **node);


/**
 * @brief Inserts a BST node into the tree.
 *
 * Inserts a BST node into the tree into its appropriate position. If the node is NULL then error message
 * is displayed. The node will be inserted even if the tree is empty.
 *
 * @param root Address of the pointer of the root node.
 * @param node Address of the node to be inserted.
 * @return void. Returns nothing.
 */
void insertNodeBST(Node_t **root, Node_t *node);


/**
 * @brief Deletes a BST node into the tree.
 *
 * Deletes a BST node into the tree without disturbing the binary search tree property. If the node or tree is NULL then error message
 * is displayed. The memory to the deleted node is also freed.
 *
 * @param root Address of the pointer of the root node.
 * @param node Address of the node to be deleted.
 * @return void. Returns nothing.
 */
void deleteNodeBST(Node_t **root, Node_t *node);


/**
 * @brief Returns the successor node of the given node.
 *
 * Successor is the smallest element greater than the data of the given node. It is the next element that will appear in
 * inorder traversal. This function will return the successor of the given node. If node or root is empty then error message
 * is displayed.
 *
 * @param root Address of the pointer of the root node.
 * @param node Address of the node whose successor is to be searched.
 * @return Node_t* Address of the successor of the node. If not found then NULL is returned.
 */
Node_t *successorBST(Node_t **root, Node_t *node);


/**
 * @brief Returns the predecessor node of the given node.
 *
 * Predecessor is the greatest element smaller than the data of the given node. It is the previous element that will appear in
 * inorder traversal. This function will return the predecessor of the given node. If node or root is empty then error message
 * is displayed.
 *
 * @param root Address of the pointer of the root node.
 * @param node Address of the node whose successor is to be searched.
 * @return Node_t* Address of the predecessor of the node. If not found then NULl is returned.S
 */

Node_t *predecessorBST(Node_t **root, Node_t *node);

/**
 * @brief Replaces a given node of a tree with another node.
 *
 * This function replaces a given node of the tree with another node. Remember that this function doesn't check
 * for the binary search property of the tree and hence must be used very carefully. Using this function incorrectly
 * might destroy the binary search property of the tree.
 *
 * @param root Address of the pointer of the root node.
 * @param initial Address of the node to be replaced.
 * @param final Address of the node to replace the initial node.
 * @return void. Returns nothing.
 */
void replaceNodeBST(Node_t **root, Node_t *initial, Node_t *final);

/**
 * @brief Searches the tree with the given key.
 *
 * Searches for the node with the given key and returns the address of the node. Returns NULL if no
 * such node is found.
 *
 * @param root Address of the pointer of the root node.
 * @param key Key to be searched for.
 *
 * @return Node_t* Address of the node containing the key. NULl is returned if no such node is found.
 */
Node_t *searchBST(Node_t **root, int key);

/**
 * @brief Searches the tree for minimum value .
 *
 * Searches for the node with the minimum value and returns the address of the node.
 *
 * @param root Address of the pointer of the root node.
 * @return Node_t* Address of the node containing the minimum value.
 */
Node_t *minimumBST(Node_t **root);

/**
 * @brief Searches the tree for maximum value .
 *
 * Searches for the node with the maximum value and returns the address of the node.
 *
 * @param root Address of the pointer of the root node.
 * @return Node_t* Address of the node containing the maximum value.
 */
Node_t *maximumBST(Node_t **root);


/**
 * @brief Displays the tree elements in preorder sequence.
 *
 * Displays the elements of the tree in preorder sequence. The preorder sequence follows displaying of
 * root, left subtree and then right subtree. Recursive method is used.
 *
 * @param root Address of the pointer of the root node.
 * @return void. Returns nothing.
 */
void preorderTraversalBST(Node_t **root);

/**
 * @brief Displays the tree elements in pinorder sequence.
 *
 * Displays the elements of the tree in inorder sequence. The inorder sequence follows displaying of
 * left subtree, root and then right subtree. Recursive method is used.
 *
 * @param root Address of the pointer of the root node.
 * @return void. Returns nothing.
 */
void inorderTraversalBST(Node_t **root);

/**
 * @brief Displays the tree elements in postorder sequence.
 *
 * Displays the elements of the tree in postorder sequence. The postorder sequence follows displaying of
 * left subtree, right subtree and then root. Recursive method is used.
 *
 * @param root Address of the pointer of the root node.
 * @return void. Returns nothing.
 */void postorderTraversalBST(Node_t **root);

#endif /* BINARYSEARCHTREE_H_ */
