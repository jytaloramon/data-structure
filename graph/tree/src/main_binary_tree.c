/**
 * @author Ytalo Ramon
 * @date   21/08/2021
 */

#include "stdio.h"
#include "stdlib.h"
#include "../include/binary_tree.h"

#define MAX 16
#define INPUTSIZE 20 // Input size for test.

enum option {
    INSERT,
    DELETE,
    SEARCHNODE,
    PREDECESSOR,
    SUCCESSOR,
    MINIMUMMAXIMUM
};

int compare_number(void *const a, void *const b);

void inorder(Node *node);

void preorder(Node *node);

void postorder(Node *node);

int main(int argc, char const *argv[]) {

    int arr[MAX] = {25, 15, 50, 10, 22, 35, 70, 4,
                    12, 18, 24, 31, 44, 66, 90, 13};

    int test_cases[INPUTSIZE][2] = {
        {DELETE, 0},         {DELETE, 4},         {INSERT, 13},
        {SEARCHNODE, 8},     {MINIMUMMAXIMUM, 0}, {SUCCESSOR, 11},
        {SEARCHNODE, 4},     {PREDECESSOR, 11},   {SUCCESSOR, 11},
        {MINIMUMMAXIMUM, 0}, {INSERT, 14},        {MINIMUMMAXIMUM, 0},
        {SUCCESSOR, 14},     {DELETE, 6},         {SEARCHNODE, 7},
        {DELETE, 7},         {DELETE, 3},         {SEARCHNODE, 8},
        {INSERT, 15},        {SEARCHNODE, 8}};

    printf("+++++ Binary Tree +++++\n\n");

    int op, idx, *data = NULL;
    Node *node = NULL;
    Tree *tree = tree_new();

    if (!tree) {
        printf("Memory allocation error!\n");
        exit(0);
    }

    // Initializing tree
    for (size_t i = 0; i < MAX - 3; i++)
        tree_insert(tree, &arr[i], compare_number);

    printf("INORDER: ");
    inorder(tree->root);
    printf("\n\n");

    for (int i = 0; i < INPUTSIZE; i++) {
        op = test_cases[i][0];
        idx = test_cases[i][1];

        switch (op) {
        case INSERT:
            printf("  * INSERT: %d | ", arr[idx]);
            node = tree_insert(tree, &arr[idx], compare_number);
            node ? printf("@ Success!\n") : printf("# Fail!\n");

            inorder(tree->root);
            printf(" -> %d\n", tree->length);
            printf("\n");
            break;
        case DELETE:
            printf("  * DELETE: %d | ", arr[idx]);
            data = tree_delete(tree, &arr[idx], compare_number);
            data ? printf("@ Success!\n") : printf("# Fail!\n");

            inorder(tree->root);
            printf(" -> %d\n", tree->length);
            printf("\n");
            break;
        case SEARCHNODE:
            printf("  * SEARCHNODE: %d | ", arr[idx]);
            node = tree_search_node(tree, &arr[idx], compare_number);
            if (!node) {
                printf("# Not Found!\n");
            } else {
                printf("@ Found! ->");
                if (node->father)
                    printf(" FATHER (%d)", *((int *)node->father->data));
                if (node->left)
                    printf(" LEFT (%d)", *((int *)node->left->data));
                if (node->right)
                    printf(" RIGHT (%d)", *((int *)node->right->data));
                printf("\n");
            }
            break;
        case PREDECESSOR:
            printf("  * PREDECESSOR: %d | ", arr[idx]);
            data = tree_predecessor(
                tree_search_node(tree, &arr[idx], compare_number));
            data ? printf("%d\n", *((int *)data)) : printf("Not found!\n");
            break;
        case SUCCESSOR:
            printf("  * SUCCESSOR: %d | ", arr[idx]);
            data = tree_successor(
                tree_search_node(tree, &arr[idx], compare_number));
            data ? printf("%d\n", *((int *)data)) : printf("Not found!\n");
            break;
        case MINIMUMMAXIMUM:
            printf("  * MINIMUM-MAXIMUM: ");
            if (tree_is_empty(tree->root)) {
                printf("Tree is empty!\n");
            } else {
                data = tree_minimum(tree->root);
                printf("(%d) ", *((int *)data));
                data = tree_maximum(tree->root);
                printf("(%d)\n", *((int *)data));
            }
            break;
        default:
            printf(" * Option ERROR!\n");
            break;
        }
        printf("\n");
    }

    printf("-- Final --\n\n");

    printf("INORDER: ");
    inorder(tree->root);
    printf("\n\n");

    printf("PREORDER: ");
    preorder(tree->root);
    printf("\n\n");

    printf("POSTORDER: ");
    postorder(tree->root);
    printf("\n");

    return 0;
}

int compare_number(void *const a, void *const b) {

    return *((int *)a) - *((int *)b);
}

void inorder(Node *node) {

    if (tree_is_empty(node))
        return;

    inorder(node->left);
    printf("%d, ", *((int *)node->data));
    inorder(node->right);
}

void preorder(Node *node) {

    if (tree_is_empty(node))
        return;

    printf("%d, ", *((int *)node->data));
    preorder(node->left);
    preorder(node->right);
}

void postorder(Node *node) {

    if (tree_is_empty(node))
        return;

    postorder(node->left);
    postorder(node->right);
    printf("%d, ", *((int *)node->data));
}
