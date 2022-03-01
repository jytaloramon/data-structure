/**
 * @author Ytalo Ramon
 * @date   01/03/2022
 */

#include "../../../includes/icomparator.h"
#include "stdlib.h"

typedef struct _RbTree RbTree;

/**
 * Define the prototype of the struct.
 * struct _Noderb Noderb.
 */
typedef struct _Noderb Noderb;

struct _RbTree {
    struct _Noderb *root;
    size_t length;
};

/**
 * struct _Noderb.
 * attr: father - node father.
 * attr: left - child left.
 * attr: right - child right.
 */
struct _Noderb {
    struct _Noderb *father, *left, *right;
    char is_red;
};

/**
 * Create a new RbTree.
 * @return A RbTree instance or Null in case of error.
 */
RbTree *rbtree_new();

void *rbtree_node_setdefault(Noderb *node, Noderb *father);

int rbtree_is_empty(RbTree *rb_tree);

int rbtree_insert(RbTree *rb_tree, Noderb *new_node, ICOMPARATOR);

Noderb *rbtree_remove(RbTree *rb_tree, void *elmnt, ICOMPARATOR);

/**
 * Find the node in the tree.
 * @param tree Node instance.
 * @param elmnt Element key searched.
 *      Input in comparator(elmnt, actual_node).
 * @return Node instance if found, or Null.
 */
Noderb *rbtree_search(RbTree *rb_tree, void *elmnt, ICOMPARATOR);

/**
 * Returns the minimum node of the tree.
 * @param Node instance.
 * @return Node instance if any, or Null.
 */
Noderb *rbtree_minimum(RbTree *rb_tree);

/**
 * Returns the maximum node of the tree.
 * @param Node instance.
 * @return Node instance if any, or Null.
 */
Noderb *rbtree_maximum(RbTree *rb_tree);

/**
 * Check if the subtree is empty.
 * @param node_root Node instance.
 * @return Or 1 if empty, or 0 if not empty.
 */
int rbtree_node_is_empty(Noderb *node_root);

/**
 * Insert a new node in the tree.
 * @param node_root A root node.
 * @param new_node Node for insertion.
 * @param comparator Function comparator.
 *      Input in comparator(Noderb, Noderb).
 * @return Or 1 for success, or 0 for failure.
 */
int rbtree_node_insert(Noderb **node_root, Noderb *new_node, ICOMPARATOR);

/**
 * Remove a element of the tree.
 * @param node_root A root node.
 * @param elmnt Element key for removal.
 *      Input in comparator(elmnt, actual_node).
 * @return Removed Node, or Null on failure/not found.
 */
Noderb *rbtree_node_remove(Noderb **node_root, void *elmnt, ICOMPARATOR);

Noderb *rbtree_node_cut_paste(Noderb *rm_node);

/**
 * Find the node in the tree.
 * @param tree Node instance.
 * @param elmnt Element key searched.
 *      Input in comparator(elmnt, actual_node).
 * @return Node instance if found, or Null.
 */
Noderb *rbtree_node_search(Noderb *node_root, void *elmnt, ICOMPARATOR);

/**
 * Find the node immediately before the node.
 * @param Node instance.
 * @return Node instance if any, or Null.
 */
Noderb *rbtree_node_predecessor(Noderb *node_root);

/**
 * Find the node immediately after the node.
 * @param Node instance.
 * @return Node instance if any, or Null.
 */
Noderb *rbtree_node_successor(Noderb *node_root);

/**
 * Returns the minimum node of the tree.
 * @param Node instance.
 * @return Node instance if any, or Null.
 */
Noderb *rbtree_node_minimum(Noderb *node_root);

/**
 * Returns the maximum node of the tree.
 * @param Node instance.
 * @return Node instance if any, or Null.
 */
Noderb *rbtree_node_maximum(Noderb *node_root);

void rbtree_node_left_rotate(Noderb *node); 

void rbtree_node_right_rotate(Noderb *node);

int rbtree_node_is_red(Noderb *node);

void rbtree_node_insert_fixup(Noderb **node_root, Noderb *node);