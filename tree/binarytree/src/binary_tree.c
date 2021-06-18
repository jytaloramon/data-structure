/**
 * @author Ytalo Ramon
 * @date   18/03/2021
*/

#include "stdio.h"
#include "stdlib.h"
#include "string.h"
#include "../include/binary_tree.h"

Tree *tree_new(){
    Tree *tree = malloc(sizeof(Tree));

    if (!tree)
        return NULL;
    
    tree->root = NULL;

    return tree;
}

Node *tree_new_node(void *elmnt, Node *father){
    Node *node = malloc(sizeof(Node));

    if (!node)
        return NULL;

    node->data = elmnt;
    node->father = father;
    node->left = node->right = NULL;

    return node;
}

Node *tree_insert(Tree *tree, void *elmnt, ICOMPARATOR){
    int rs = 1;
    Node **node = &tree->root,
        *node_last = NULL;
    
    while (*node && (rs = comparator(elmnt, (*node)->data)) != 0){
        node_last = *node;
        node = rs > 0 ? &(*node)->right : &(*node)->left;
    }

    if (rs == 0) // If the element already exists
        return NULL;
    
    Node *new_node = tree_new_node(elmnt, node_last);
    if (!new_node)
        return NULL;
    *node = new_node;

    return *node;
}

void *tree_delete(Tree *tree, void *elmnt, ICOMPARATOR){
    int rs = 1;
    Node **node = &tree->root;
    
    while (*node && (rs = comparator(elmnt, (*node)->data)) != 0)
        node = rs > 0 ? &(*node)->right : &(*node)->left;
    
    if (rs != 0) // If the element not found
        return NULL;

    Node *node_aux = NULL;

    // Rearranging the tree
    if (!(*node)->left || !(*node)->right){ 
        // If exists just a son 
        node_aux = ((*node)->right ? (*node)->right : (*node)->left);
    } else { 
        // More than one child  
        node_aux = (*node)->right; rs = 0;
        while (node_aux->left){
            node_aux = node_aux->left;
            rs = 1;
        }

        if (rs){
            node_aux->father->left = node_aux->right;
            node_aux->right = (*node)->right;
        }
        node_aux->left = (*node)->left;
    }
    
    void *data_aux = (*node)->data;
    free((*node));
    *node = node_aux;

    return data_aux;
}

Node *tree_search_node(Tree *tree, void *elmnt, ICOMPARATOR){
    int rs = 1;
    Node *node = tree->root;
    
    while (node && (rs = comparator(elmnt, node->data)) != 0)
        node = rs > 0 ? node->right : node->left;
    
    return node;    
}

void *tree_search(Tree *tree, void *elmnt, ICOMPARATOR){
    Node *node = tree_search_node(tree, elmnt, comparator);

    if (!node)
        return NULL;

    return node->data;
}

Node *tree_search_node(Tree *tree, void *elmnt, ICOMPARATOR){
    int rs = 1;
    Node *node = tree->root;
    
    while (node && (rs = comparator(elmnt, node->data)) != 0)
        node = rs > 0 ? node->right : node->left;
    
    return node;    
}

void *tree_minimum(Tree *tree){
    if (!tree->root)
        return NULL;

    Node *node = tree->root;

    while (node->left)
        node = node->left;
    
    return node;
}

void *tree_maximum(Tree *tree){
    if (!tree->root)
        return NULL;

    Node *node = tree->root;
    
    while (node->right)
        node = node->right;
    
    return node;
}