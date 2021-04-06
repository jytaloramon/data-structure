/**
 * @author Ytalo Ramon
 * @date   31/03/2021
*/

#include "../../includes/icomparator.h"

typedef struct _Tree Tree;

typedef struct _Node Node;

/**
 * Create a new tree.
 * @return A tree instance, or Null on failure..
*/
Tree *tree_new();

/**
 * Create a new Node.
 * @param elmnt - New element. 
 * @param father - Node father of the new node.
 * @return A Node instance, or Null on failure.
*/
Node *tree_new_node(void *elmnt, Node *father);

/**
 * Insert a new element in tree.
 * @param tree Tree pointer.
 * @param elmnt Element for insertion.
 * @param comparator Function comparator.
 * @return The inserted Node instance, or Null on failure.
*/
Node *tree_insert(Tree *tree, void *elmnt, ICOMPARATOR);

/**
 * Delete a Node of the tree.
 * @param tree Tree pointer.
 * @param elmnt Element for deletion.
 * @return The deleted element data, or Null on failure.
*/
void *tree_delete(Tree *tree, void *elmnt, ICOMPARATOR);

/**
 * Find the element node in the tree.
 * @param tree Tree pointer.
 * @param elmnt Element searched.
 * @return The element Node found, or Null on failure.
*/
Node *tree_search_node(Tree *tree, void *elmnt, ICOMPARATOR);

/**
 * Search a element in the tree.
 * @param tree Tree pointer.
 * @param elmnt Element searched.
 * @return The data of the element found, or Null on failure.
*/
void *tree_search(Tree *tree, void *elmnt, ICOMPARATOR);

/**
 * Returns the minimum element of the tree
 * @param tree Tree pointer
 * @return The data of the element if exists, or Null on failure.
*/
void *tree_minimum(Tree *tree);

/**
 * Returns the maximum element of the tree
 * @param tree Tree pointer
 * @return The data of the element if exists, or Null on failure.
*/
void *tree_maximum(Tree *tree);
