#include "stdio.h"
#include "stdlib.h"
#include "../include/binary_tree.h"

#define MAX 15

int compare_number(void *const a, void *const b);

void inorder(Node *node);

void preorder(Node *node);

void postorder(Node *node);

int main(int argc, char const *argv[]){

    int arr[] = {25, 15, 50, 10, 22, 35, 70, 4, 12, 18, 24, 31, 44, 66, 90};
    Tree *tree = tree_new();
    
    for (size_t i = 0; i < MAX; i++)
        tree_insert(tree, &arr[i], compare_number);

    //inorder(tree->root);
    //tree_delete(tree, &arr[1], compare_number);
    
    preorder(tree->root);
    printf("\n");
    inorder(tree->root);
    printf("\n");
    postorder(tree->root);
    printf("\n");

    return 0;
}

int compare_number(void *const a, void *const b){
    return *((int *) a) - *((int *) b);
}

void inorder(Node *node){
    if (!node)
        return;
    
    inorder(node->left);
    printf("%d, ", *((int *) node->data));
    inorder(node->right);
}

void preorder(Node *node){
    if (!node)
        return;
    
    printf("%d, ", *((int *) node->data));
    preorder(node->left);
    preorder(node->right);
}

void postorder(Node *node){
    if (!node)
        return;
    
    postorder(node->left);
    postorder(node->right);
    printf("%d, ", *((int *) node->data));
}