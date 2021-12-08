/**
 * @author Ytalo Ramon
 * @date   18/03/2021
 */

#include "tree.h"

/**
 * struct _Node.
 * attr: father - node father.
 * attr: left - child left.
 * attr: right - child right.
 */
struct _Node {
    struct _Node *father, *left, *right;
};
