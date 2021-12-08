/**
 * @author Ytalo Ramon
 * @date   21/08/2021
 */

#include "../../../includes/istructure_utils.h"
#include "../include/binary_tree.h"
#include "stdio.h"
#include "stdlib.h"

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

typedef struct _Tree {
    struct _Node *root;
    size_t length;
} Tree;

typedef struct _Number {
    int data;
    struct _Node node;
} Number;

int compare_number_node_node(void *const a, void *const b);

int compare_number_elmnt_node(void *const a, void *const b);

void inorder(Node *node);

void preorder(Node *node);

void postorder(Node *node);

Tree *tree_new();

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

    int op, idx, r;
    Number *number_aux = NULL;
    Node *node = NULL;
    Tree *tree = tree_new();

    if (!tree) {
        printf("Memory allocation error!\n");
        exit(0);
    }

    // Initializing tree
    for (size_t i = 0; i < MAX - 3; i++) {
        number_aux = malloc(sizeof(Number));
        number_aux->data = arr[i];

        tree_insert(&tree->root, &number_aux->node, compare_number_node_node);
        tree->length++;
    }
    number_aux = NULL;

    printf("INORDER: ");
    inorder(tree->root);
    printf("\n\n");

    for (int i = 0; i < INPUTSIZE; i++) {
        op = test_cases[i][0];
        idx = test_cases[i][1];

        switch (op) {
        case INSERT:
            printf("  * INSERT: %d | ", arr[idx]);

            number_aux = malloc(sizeof(Number));
            number_aux->data = arr[idx];

            tree->length += (r = tree_insert(&tree->root, &number_aux->node,
                                             compare_number_node_node));
            r ? printf("@ Success!\n") : printf("# Fail!\n");

            inorder(tree->root);
            printf(" -> %lu\n", tree->length);
            printf("\n");
            break;
        case DELETE:
            printf("  * DELETE: %d | ", arr[idx]);
            node = tree_remove(&tree->root, &arr[idx], compare_number_elmnt_node);
            node ? printf("@ Success!\n") : printf("# Fail!\n");
            tree->length -= node ? 1 : 0;

            inorder(tree->root);
            printf(" -> %lu\n", tree->length);
            printf("\n");
            break;
        case SEARCHNODE:
            printf("  * SEARCHNODE: %d | ", arr[idx]);
            node = tree_search(tree->root, &arr[idx], compare_number_elmnt_node);
            if (!node) {
                printf("# Not Found!\n");
            } else {
                printf("@ Found! ->");
                if (node->father) {
                    number_aux = GETSTRUCTFROM(node->father, Number, node);
                    printf(" FATHER (%d)", number_aux->data);
                }
                if (node->left) {
                    number_aux = GETSTRUCTFROM(node->left, Number, node);
                    printf(" LEFT (%d)", number_aux->data);
                }
                if (node->right) {
                    number_aux = GETSTRUCTFROM(node->right, Number, node);
                    printf(" RIGHT (%d)", number_aux->data);
                }
                printf("\n");
            }
            break;
        case PREDECESSOR:
            printf("  * PREDECESSOR: %d | ", arr[idx]);
            node = tree_predecessor(
                tree_search(tree->root, &arr[idx], compare_number_elmnt_node));

            node ? printf("%d\n",
                          ((Number *)GETSTRUCTFROM(node, Number, node))->data)
                 : printf("Not found!\n");
            break;
        case SUCCESSOR:
            printf("  * SUCCESSOR: %d | ", arr[idx]);
            node = tree_successor(
                tree_search(tree->root, &arr[idx], compare_number_elmnt_node));

            node ? printf("%d\n",
                          ((Number *)GETSTRUCTFROM(node, Number, node))->data)
                 : printf("Not found!\n");
            break;
        case MINIMUMMAXIMUM:
            printf("  * MINIMUM-MAXIMUM: ");
            if (tree_is_empty(tree->root)) {
                printf("Tree is empty!\n");
            } else {
                node = tree_minimum(tree->root);
                printf("(%d) ",
                       ((Number *)GETSTRUCTFROM(node, Number, node))->data);

                node = tree_maximum(tree->root);
                printf("(%d)\n",
                       ((Number *)GETSTRUCTFROM(node, Number, node))->data);
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

int compare_number_node_node(void *const a, void *const b) {

    Number const *n_a = GETSTRUCTFROM(a, Number, node);
    Number const *n_b = GETSTRUCTFROM(b, Number, node);

    return n_a->data - n_b->data;
}

int compare_number_elmnt_node(void *const a, void *const b) {

    int elmnt = *((int *)a);
    Number const *n_b = GETSTRUCTFROM(b, Number, node);

    return elmnt - n_b->data;
}

void inorder(Node *node) {

    if (tree_is_empty(node))
        return;

    inorder(node->left);
    Number *n = GETSTRUCTFROM(node, Number, node);
    printf("%d, ", n->data);

    inorder(node->right);
}

void preorder(Node *node) {

    if (tree_is_empty(node))
        return;

    Number *n = GETSTRUCTFROM(node, Number, node);
    printf("%d, ", n->data);

    preorder(node->left);
    preorder(node->right);
}

void postorder(Node *node) {

    if (tree_is_empty(node))
        return;

    postorder(node->left);
    postorder(node->right);

    Number *n = GETSTRUCTFROM(node, Number, node);
    printf("%d, ", n->data);
}

Tree *tree_new() {

    Tree *tree = malloc(sizeof(Tree));

    if (!tree)
        return NULL;

    tree->root = NULL;
    tree->length = 0;

    return tree;
}
