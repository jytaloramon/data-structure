/**
 * @author Ytalo Ramon
 * @date   18/03/2021
*/

#include "tree.h"

/**
 * struct _Node.
 * ---------------
 * attr: data - payload of data.
 * attr: father - node father.
 * attr: left - child left.
 * attr: right - child right.
*/
struct _Node {
    void *data;
    struct _Node *father, *left, *right;
};

/**
 * struct _Tree
 * ---------------
 * attr: root - root element. 
*/
struct _Tree {
    struct _Node *root;
};
