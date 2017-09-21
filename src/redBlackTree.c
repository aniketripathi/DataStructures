/** Implementation of Red Black Trees. Header file is redBlackTree.h **/

#include "../inc/redBlackTree.h"

RBT_t *createRBT(){
    RBT_t *tree = malloc(sizeof(RBT_t));
    Node_t *nil = malloc(sizeof(Node_t));
    LEFT(nil) = NULL;
    RIGHT(nil) = NULL;
    PARENT(nil) = NULL;
    DATA(nil) = 0;
    COLOR(nil) = BLACK;

    ROOT(tree) = nil;
    LEAF(tree) = nil;

    return tree;
}


Node_t* createNodeRBT(int data){
    Node_t *node = malloc(sizeof(Node_t));
    LEFT(node) = NULL;
    RIGHT(node) = NULL;
    PARENT(node) = NULL;
    COLOR(node) = BLACK;
    DATA(node) = data;
    return node;
}
void destroyNodeRBT(Node_t **node){
    free(*node);
    *node = NULL;
    node = NULL;

}

void deleteRBT(RBT_t **tree){

   if(ROOT(*tree) != LEAF(*tree))
    fputs("Cannot delete non-empty RBT. Delete its children first.\n", stderr);

 else {
        free(ROOT(*tree));
        free(LEAF(*tree));
        *tree = NULL;
        tree = NULL;
    }
}



int blackHeightRBT(Node_t *node){
    int bh = 0;

    if(node != NULL){
        int left_bh = 0, right_bh = 0;
        if(LEFT(node) != NULL)
            left_bh = blackHeightRBT(LEFT(node)) + COLOR(LEFT(node));
        if(RIGHT(node) != NULL)
            right_bh = blackHeightRBT(RIGHT(node)) + COLOR(RIGHT(node));

        bh = (left_bh > right_bh)?left_bh:right_bh;
    }
    return bh;
}



Node_t *minimumRBT(RBT_t *tree, Node_t *node){

    if(node == LEAF(tree)){
        fputs("Cannot find minimum in empty tree. Returning 0.\n", stderr);
        return 0;
    }

    while(LEFT(node) != LEAF(tree))
        node = LEFT(node);

    return (node);

}

        
Node_t *maximumRBT(RBT_t *tree, Node_t *node){

    if(node == LEAF(tree)){
        fputs("Cannot find minimum in empty tree. Returning 0.\n", stderr);
        return 0;
    }

    while(RIGHT(node) != LEAF(tree))
        node = RIGHT(node);

    return (node);

}


Node_t *searchNodeRBT(RBT_t *tree, int key){
    Node_t *x = ROOT(tree);
    while(x != LEAF(tree) && key != DATA(x)){
        if(key < DATA(x))
            x = LEFT(x);
        else
            x = RIGHT(x);
    }
    
    return x; 
}


void inorderTraversalRBT(RBT_t *tree, Node_t *node){
    if(node != LEAF(tree)){
        inorderTraversalRBT(tree, LEFT(node));
        printf("%d, ", DATA(node));
        inorderTraversalRBT(tree, RIGHT(node));
    }
}



void leftRotateRBT(RBT_t *tree, Node_t *x){ 
    Node_t *y = RIGHT(x);
    RIGHT(x) = LEFT(y);
    if(LEFT(y) != LEAF(tree))
        PARENT(LEFT(y)) = x;

    PARENT(y) = PARENT(x);
    if(PARENT(x) == LEAF(tree))
        ROOT(tree) = y;

    else if(x == LEFT(PARENT(x)))
            LEFT(PARENT(x)) = y;
    else RIGHT(PARENT(x)) = y; 
    LEFT(y) = x;
    PARENT(x) = y;
}


void rightRotateRBT(RBT_t *tree, Node_t *y){
    Node_t *x = LEFT(y);
    LEFT(y) = RIGHT(x);
    if(RIGHT(x) != LEAF(tree))
        PARENT(RIGHT(x)) = y;

    PARENT(x) = PARENT(y);
    if(PARENT(y) == LEAF(tree))
        ROOT(tree) = x;

    else if(y == RIGHT(PARENT(y)))
            RIGHT(PARENT(y)) = x;
    else LEFT(PARENT(y)) = x;
    RIGHT(x) = y;
    PARENT(y) = x;
}


static void insertFixupRBT(RBT_t *tree, Node_t *z){ 
  while(COLOR(PARENT(z)) == RED){
        if(PARENT(z) == LEFT(PARENT(PARENT(z)))){
           Node_t *y = RIGHT(PARENT(PARENT(z)));
            if(COLOR(y) == RED){
                COLOR(PARENT(z)) = BLACK;
                COLOR(y) = BLACK;
                COLOR(PARENT(PARENT(z))) = RED;
                z = PARENT(PARENT(z));
                }
            else { 
                 if(z == RIGHT(PARENT(z))){
                    z = PARENT(z);
                     leftRotateRBT(tree, z);
                 }
                COLOR(PARENT(z)) = BLACK;
                COLOR(PARENT(PARENT(z))) = RED;
                rightRotateRBT(tree, PARENT(PARENT(z)));
             }
            }
        else {
           Node_t *y = LEFT(PARENT(PARENT(z)));
            if(COLOR(y) == RED) {
                 COLOR(PARENT(z)) = BLACK;
                 COLOR(y) = BLACK;
                 COLOR(PARENT(PARENT(z))) = RED;
                 z = PARENT(PARENT(z));
                }
            else { 
                if(z == LEFT(PARENT(z))){
                     z = PARENT(z);
                     rightRotateRBT(tree, z);
                 }
                 COLOR(PARENT(z)) = BLACK;
                 COLOR(PARENT(PARENT(z))) = RED;
                 leftRotateRBT(tree, PARENT(PARENT(z)));
             }
            }
        }
    COLOR(ROOT(tree)) = BLACK;
}


void insertNodeRBT(RBT_t *tree, Node_t *z){
  if(z == NULL || z == LEAF(tree))
     fputs("The node is either NULL or LEAF of tree.\n", stderr);

else {
    Node_t *y = LEAF(tree), *x = ROOT(tree);
    while(x != LEAF(tree)){
        y = x;
        if(DATA(z) < DATA(x))
            x = LEFT(x);
        else x = RIGHT(x);
    }        

    PARENT(z) = y;
    if(y == LEAF(tree))
        ROOT(tree) = z;
    else if(DATA(z) < DATA(y))
        LEFT(y) = z;
    else RIGHT(y) = z;
    LEFT(z) = LEAF(tree);
    RIGHT(z) = LEAF(tree);
    COLOR(z) = RED;
    insertFixupRBT(tree, z);
   } 
}



static void transplantNodeRBT(RBT_t *tree, Node_t *initial,  Node_t *final){
    if(PARENT(initial) == LEAF(tree))
        ROOT(tree) == final;

    else if(initial == LEFT(PARENT(initial)))
                LEFT(PARENT(initial)) = final;
    else    RIGHT(PARENT(initial)) = final;
    
    if(final != LEAF(tree))
        PARENT(final) = PARENT(initial);
}




static void deleteFixupRBT(RBT_t *tree,Node_t *x){
    while(x != ROOT(tree) && COLOR(x) == BLACK){
        if(x == LEFT(PARENT(x))){
            Node_t *w = RIGHT(PARENT(x));
            if(COLOR(w) == RED){
                COLOR(w) = BLACK;
                COLOR(PARENT(x)) = BLACK;
                leftRotateRBT(tree, PARENT(x));
                w = RIGHT(PARENT(x));
            }
            if(COLOR(LEFT(w)) == BLACK && COLOR(RIGHT(w)) == BLACK){
                COLOR(w) = RED; 
                x = PARENT(x); }

            else if(COLOR(RIGHT(w)) == BLACK){
                COLOR(LEFT(w)) = BLACK;
                COLOR(w) = RED;
                rightRotateRBT(tree, w);
                w = RIGHT(PARENT(x));
            }

            COLOR(w) = COLOR(PARENT(x));
            COLOR(PARENT(x)) = BLACK;
            COLOR(RIGHT(w)) = BLACK;
            leftRotateRBT(tree, PARENT(x));
            x = ROOT(tree);
        } 
       else {
             Node_t *w = LEFT(PARENT(x));
            if(COLOR(w) == RED){
                COLOR(w) = BLACK;
                COLOR(PARENT(x)) = BLACK;
                rightRotateRBT(tree, PARENT(x));
                w = LEFT(PARENT(x));
                }
            if(COLOR(RIGHT(w)) == BLACK && COLOR(LEFT(w)) == BLACK){
                COLOR(w) = RED; 
                x = PARENT(x); }

            else if(COLOR(LEFT(w)) == BLACK){
                COLOR(RIGHT(w)) = BLACK;
                COLOR(w) = RED;
                leftRotateRBT(tree, w);
                w = LEFT(PARENT(x));
            }

            COLOR(w) = COLOR(PARENT(x));
            COLOR(PARENT(x)) = BLACK;
            COLOR(LEFT(w)) = BLACK;
            rightRotateRBT(tree, PARENT(x));


            x = ROOT(tree);
        }
    }
        COLOR(x) = BLACK;
}


void deleteNodeRBT(RBT_t *tree, Node_t *z){

if(z != LEAF(tree) && z != NULL) {
   Node_t *y = z, *x = NULL; 
    unsigned int original_color = COLOR(y);
    if(LEFT(z) == LEAF(tree)){
         x = RIGHT(z);
         transplantNodeRBT(tree, z, RIGHT(z));
        }
    else if(RIGHT(z) == LEAF(tree)){
         x = LEFT(z);
         transplantNodeRBT(tree, z, LEFT(z));
        }
    else {
            y = minimumRBT(tree, RIGHT(z));
            original_color = COLOR(y);
            x = RIGHT(y);
            if(PARENT(y) == z)
                PARENT(x) = y;

            else { 
                transplantNodeRBT(tree, y, RIGHT(y)); 
                RIGHT(y) = RIGHT(z);
                PARENT(RIGHT(y)) = y;
                }
            transplantNodeRBT(tree, z, y);
            LEFT(y) = LEFT(z);
            PARENT(LEFT(y)) = y;
            COLOR(y) = COLOR(z);
        }
    if(z == ROOT(tree)){
        ROOT(tree) = LEAF(tree);
        x = LEAF(tree);
       }
     destroyNodeRBT(&z);
    if(original_color == BLACK && x != LEAF(tree))
        deleteFixupRBT(tree, x);
  }
  else fputs("The node is either NULL or LEAF of the tree.\n", stderr);
}



