/**
 * @author Ytalo Ramon
 * @date   31/03/2021
 */

#include "../../../includes/icomparator.h"

/**
 * Define the prototype of the struct.
 * struct _Node Node.
 */
typedef struct _Node Node;

/**
 * Check if the tree is empty.
 * @param tree Node instance.
 * @return Or 1 if empty, or 0 if not empty.
 */
int tree_is_empty(Node *tree);

/**
 * Insert a new node in the tree.
 * @param tree_root A root node.
 * @param new_node Node for insertion.
 * @param comparator Function comparator.
 *      Input in comparator(new_node, actual_node).
 * @return Or 1 for success, or 0 for failure.
 */
int tree_insert(Node **tree_root, Node *new_node, ICOMPARATOR);

/**
 * Remove a element of the tree.
 * @param tree_root A root node.
 * @param elmnt Element key for removal.
 *      Input in comparator(elmnt, actual_node).
 * @return Removed Node, or Null on failure/not found.
 */
Node *tree_remove(Node **tree_root, void *elmnt, ICOMPARATOR);

/**
 * Find the node in the tree.
 * @param tree Node instance.
 * @param elmnt Element key searched.
 *      Input in comparator(elmnt, actual_node).
 * @return Node instance if found, or Null.
 */
Node *tree_search(Node *tree, void *elmnt, ICOMPARATOR);

/**
 * Find the node immediately before the node.
 * @param Node instance.
 * @return Node instance if any, or Null.
 */
Node *tree_predecessor(Node *node);

/**
 * Find the node immediately after the node.
 * @param Node instance.
 * @return Node instance if any, or Null.
 */
Node *tree_successor(Node *node);

/**
 * Returns the minimum node of the tree.
 * @param Node instance.
 * @return Node instance if any, or Null.
 */
Node *tree_minimum(Node *node);

/**
 * Returns the maximum node of the tree.
 * @param Node instance.
 * @return Node instance if any, or Null.
 */
Node *tree_maximum(Node *node);
