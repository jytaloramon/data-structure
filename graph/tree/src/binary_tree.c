/**
 * @author Ytalo Ramon
 * @date   21/08/2021
 */

#include "../include/binary_tree.h"
#include "stdlib.h"
#include "stdio.h"

/**
 * change the parent of a node
 */
#define FATHERCHG(child, newfather)                                            \
    do {                                                                       \
        if (!tree_is_empty(child))                                             \
            child->father = newfather;                                         \
    } while (0);

int tree_is_empty(Node *tree) { return tree == NULL; }

int tree_insert(Node **tree_root, Node *new_node, ICOMPARATOR) {

    if (!new_node)
        return 0;

    int rs = 1;
    Node **node_r = tree_root, *node_f = NULL;

    while (*node_r && (rs = comparator(new_node, *node_r))) {
        node_f = *node_r;
        node_r = (rs < 0 ? &(*node_r)->left : &(*node_r)->right);
    }

    // Check duplicate Key
    if (rs == 0)
        return 0;

    new_node->father = node_f;
    new_node->left = new_node->right = NULL;
    *node_r = new_node;

    return 1;
}

Node *tree_remove(Node **tree_root, void *elmnt, ICOMPARATOR) {

    if (tree_is_empty(*tree_root) || !elmnt)
        return NULL;

    int rs = 1;
    Node **p_node = tree_root;

    while (*p_node && (rs = comparator(elmnt, *p_node)))
        p_node = (rs < 0 ? &(*p_node)->left : &(*p_node)->right);

    // Key not found.
    if (rs != 0)
        return NULL;

    Node *node_aux = *p_node;
    *p_node = NULL;

    // If there are no children
    if (tree_is_empty(node_aux->left) && tree_is_empty(node_aux->right))
        return node_aux;

    Node *child_node = NULL;

    //  If there is only child left
    if (tree_is_empty(node_aux->right)) {
        child_node = node_aux->left;
        child_node->father = node_aux->father;
    } else {
        // If there is a child on the right
        child_node = node_aux->right;

        // If the child on the right has no child on the left.
        if (tree_is_empty(child_node->left)) {
            child_node->father = node_aux->father;
        } else {
            // if have a left child
            while (!tree_is_empty(child_node->left))
                child_node = child_node->left;

            child_node->father->left = child_node->right;
            FATHERCHG(child_node->right, child_node->father);
            child_node->right = node_aux->right;
            child_node->right->father = child_node;
        }

        child_node->left = node_aux->left;
        FATHERCHG(child_node->left, child_node);
    }

    *p_node = child_node;

    return node_aux;
}

Node *tree_search(Node *tree, void *elmnt, ICOMPARATOR) {

    if (tree_is_empty(tree) || !elmnt)
        return NULL;

    int rs = 1;
    Node *node = tree;

    while (node && (rs = comparator(elmnt, node)))
        node = (rs < 0 ? node->left : node->right);

    return node;
}

Node *tree_predecessor(Node *node) {

    if (tree_is_empty(node))
        return NULL;

    if (!tree_is_empty(node->left))
        return tree_maximum(node->left);

    for (Node *node_f = node->father; !tree_is_empty(node_f);
         node = node_f, node_f = node->father) {

        if (!tree_is_empty(node_f->right) && node == node_f->right)
            return node_f;
    }

    return NULL;
}

Node *tree_successor(Node *node) {

    if (tree_is_empty(node))
        return NULL;

    if (!tree_is_empty(node->right))
        return tree_minimum(node->right);

    for (Node *node_f = node->father; !tree_is_empty(node_f);
         node = node_f, node_f = node->father) {

        if (!tree_is_empty(node_f->left) && node == node_f->left)
            return node_f;
    }

    return NULL;
}

Node *tree_minimum(Node *node) {

    if (tree_is_empty(node))
        return NULL;

    Node *node_aux = NULL;
    for (node_aux = node; node_aux->left; node_aux = node_aux->left);

    return node_aux;
}

Node *tree_maximum(Node *node) {

    if (tree_is_empty(node))
        return NULL;

    Node *node_aux = NULL;
    for (node_aux = node; node_aux->right; node_aux = node_aux->right);

    return node_aux;
}
