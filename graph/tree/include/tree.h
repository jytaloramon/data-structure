/**
 * @author Ytalo Ramon
 * @date   31/03/2021
 */

#include "../../../includes/icomparator.h"

/**
 * Define the prototype of the struct.
 * struct _Tree Tree.
*/
typedef struct _Tree Tree;

/**
 * Define the prototype of the struct.
 * struct _Node Node.
*/
typedef struct _Node Node;


/**
 * Create a new tree.
 *
 * @return A tree instance, or Null on failure.
 */
Tree *tree_new();

/**
 * Create a new Node.
 *
 * @param elmnt New element.
 * @param father Node father of the new node.
 *
 * @return A Node instance, or Null on failure.
 */
Node *tree_new_node(void *elmnt, Node *father);

/**
 * Check if the tree is empty.
 *
 * @param tree Node instance.
 *
 * @return Or 1 if empty or 0 if not empty.
 */
int tree_is_empty(Node *tree);

/**
 * Insert a new element in tree.
 *
 * @param tree Tree instance.
 * @param elmnt Element for insertion.
 * @param comparator Function comparator.
 *
 * @return The Node instance inserted, or Null on failure.
 */
Node *tree_insert(Tree *tree, void *elmnt, ICOMPARATOR);

/**
 * Delete a Node of the tree.
 *
 * @param tree Tree instance.
 * @param elmnt Element key deleted.
 *
 * @return Deleted element data, or Null on failure.
 */
void *tree_delete(Tree *tree, void *elmnt, ICOMPARATOR);

/**
 * Find the node in the tree.
 *
 * @param tree Tree instance.
 * @param elmnt Element key searched.
 *
 * @return The Node instance, or Null on failure.
 */
Node *tree_search_node(Tree *tree, void *elmnt, ICOMPARATOR);

/**
 * Find the node in the tree and return only the data.
 *
 * @param tree Tree instance.
 * @param elmnt Element key searched.
 *
 * @return The data, or Null on failure.
 */
void *tree_search(Tree *tree, void *elmnt, ICOMPARATOR);

/**
 * Find the element immediately before the node.
 *
 * @param Node instance.
 *
 * @return The data, or Null on failure.
 */
void *tree_predecessor(Node *node);

/**
 * Find the element immediately after the node.
 *
 * @param Node instance.
 *
 * @return The data, or Null on failure.
 */
void *tree_successor(Node *node);

/**
 * Returns the minimum element of the tree.
 *
 * @param Node instance.
 *
 * @return The data, or Null on failure.
 */
void *tree_minimum(Node *node);

/**
 * Returns the maximum element of the tree.
 *
 * @param Node instance.
 *
 * @return The data, or Null on failure.
 */
void *tree_maximum(Node *node);
