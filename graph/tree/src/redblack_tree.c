/**
 * @author Ytalo Ramon
 * @date   01/03/2022
 */

#include "../include/redblack_tree.h"

/**
 * change the parent of a node
 */
#define FATHERCHG(child, newfather)                                            \
    do {                                                                       \
        if (!rbtree_node_is_empty(child))                                      \
            child->father = newfather;                                         \
    } while (0);

RbTree *rbtree_new() {

    RbTree *rb_tree = malloc(sizeof(RbTree));

    if (rb_tree) {
        rb_tree->root = NULL;
        rb_tree->length = 0;
    }

    return rb_tree;
}

void *rbtree_node_setdefault(Noderb *node, Noderb *father) {

    node->father = father;
    node->left = node->right = NULL;
    node->is_red = 1;
}

int rbtree_is_empty(RbTree *rb_tree) {

    return rbtree_node_is_empty(rb_tree->root);
}

int rbtree_insert(RbTree *rb_tree, Noderb *new_node, ICOMPARATOR) {

    return rbtree_node_insert(&rb_tree->root, new_node, comparator) &&
           ++rb_tree->length;
}

Noderb *rbtree_remove(RbTree *rb_tree, void *elmnt, ICOMPARATOR) {

    Noderb *rm_node = rbtree_node_remove(&rb_tree->root, elmnt, comparator);

    if (rm_node)
        --rb_tree->length;

    return rm_node;
}

Noderb *rbtree_search(RbTree *rb_tree, void *elmnt, ICOMPARATOR) {

    return rbtree_node_search(rb_tree->root, elmnt, comparator);
}

Noderb *rbtree_minimum(RbTree *rb_tree) {

    return rbtree_node_minimum(rb_tree->root);
}

Noderb *rbtree_maximum(RbTree *rb_tree) {

    return rbtree_node_maximum(rb_tree->root);
}

int rbtree_node_is_empty(Noderb *node_root) { return node_root == NULL; }

int rbtree_node_insert(Noderb **node_root, Noderb *new_node, ICOMPARATOR) {

    if (!new_node)
        return 0;

    int rs = 1;
    Noderb **node_r = node_root, *node_f = NULL;

    while (*node_r && (rs = comparator(new_node, *node_r))) {
        node_f = *node_r;
        node_r = (rs < 0 ? &(*node_r)->left : &(*node_r)->right);
    }

    // Check duplicate Key
    if (rs == 0)
        return 0;

    rbtree_node_setdefault(new_node, node_f);
    *node_r = new_node;
    rbtree_node_insert_fixup(node_root, new_node);

    return 1;
}

Noderb *rbtree_node_remove(Noderb **node_root, void *elmnt, ICOMPARATOR) {

    if (rbtree_node_is_empty(*node_root) || !elmnt)
        return NULL;

    int rs = 1;
    Noderb **p_node = node_root;

    while (*p_node && (rs = comparator(elmnt, *p_node)))
        p_node = (rs < 0 ? &(*p_node)->left : &(*p_node)->right);

    // Key not found.
    if (rs != 0)
        return NULL;

    Noderb *node_aux = *p_node;
    *p_node = rbtree_node_cut_paste(node_aux);
    rbtree_node_setdefault(node_aux, NULL);

    return node_aux;
}

Noderb *rbtree_node_cut_paste(Noderb *rm_node) {

    // If there are no children
    if (rbtree_node_is_empty(rm_node->left) &&
        rbtree_node_is_empty(rm_node->right))
        return NULL;

    Noderb *child_node = NULL;

    //  If there is only child left
    if (rbtree_node_is_empty(rm_node->right)) {
        child_node = rm_node->left;
        child_node->father = rm_node->father;
    } else {
        // If there is a child on the right
        child_node = rm_node->right;

        // If the child on the right has no child on the left.
        if (rbtree_node_is_empty(child_node->left)) {
            child_node->father = rm_node->father;
        } else {
            // if have a left child
            while (!rbtree_node_is_empty(child_node->left))
                child_node = child_node->left;

            child_node->father->left = child_node->right;
            FATHERCHG(child_node->right, child_node->father);
            child_node->right = rm_node->right;
            child_node->right->father = child_node;
        }

        child_node->left = rm_node->left;
        FATHERCHG(child_node->left, child_node);
    }

    return child_node;
}

Noderb *rbtree_node_search(Noderb *node_root, void *elmnt, ICOMPARATOR) {

    if (rbtree_node_is_empty(node_root) || !elmnt)
        return NULL;

    int rs = 1;
    Noderb *node = node_root;

    while (node && (rs = comparator(elmnt, node)))
        node = (rs < 0 ? node->left : node->right);

    return node;
}

Noderb *rbtree_node_predecessor(Noderb *node_root) {

    if (rbtree_node_is_empty(node_root))
        return NULL;

    if (!rbtree_node_is_empty(node_root->left))
        return tree_maximum(node_root->left);

    for (Noderb *node_f = node_root->father; !rbtree_node_is_empty(node_f);
         node_root = node_f, node_f = node_root->father) {

        if (!rbtree_node_is_empty(node_f->right) && node_root == node_f->right)
            return node_f;
    }

    return NULL;
}

Noderb *rbtree_node_successor(Noderb *node_root) {

    if (rbtree_node_is_empty(node_root))
        return NULL;

    if (!rbtree_node_is_empty(node_root->right))
        return tree_minimum(node_root->right);

    for (Noderb *node_f = node_root->father; !rbtree_node_is_empty(node_f);
         node_root = node_f, node_f = node_root->father) {

        if (!rbtree_node_is_empty(node_f->left) && node_root == node_f->left)
            return node_f;
    }

    return NULL;
}

Noderb *rbtree_node_minimum(Noderb *node_root) {

    if (rbtree_node_is_empty(node_root))
        return NULL;

    Noderb *node_aux = NULL;
    for (node_aux = node_root; node_aux->left; node_aux = node_aux->left)
        ;

    return node_aux;
}

Noderb *rbtree_node_maximum(Noderb *node_root) {

    if (rbtree_node_is_empty(node_root))
        return NULL;

    Noderb *node_aux = NULL;
    for (node_aux = node_root; node_aux->right; node_aux = node_aux->right)
        ;

    return node_aux;
}

void rbtree_node_left_rotate(Noderb *node) {

    if (rbtree_node_is_empty(node->right))
        return;

    Noderb *i_right = node->right;
    i_right->father = node->father;
    node->right = i_right->left;
    node->father = i_right;
    i_right->left = node;

    if (rbtree_node_is_empty(node->right))
        node->right->father = node;

    if (rbtree_node_is_empty(i_right->father)) {
        if (i_right->father->left == node)
            i_right->father->left = i_right;
        else
            i_right->father->right = i_right;
    }
}

void rbtree_node_right_rotate(Noderb *node) {

    if (rbtree_node_is_empty(node->left))
        return;

    Noderb *i_left = node->left;
    i_left->father = node->father;

    node->left = i_left->right;
    node->father = i_left;
    i_left->right = node;

    if (rbtree_node_is_empty(node->left))
        node->left->father = node;

    if (rbtree_node_is_empty(i_left->father)) {
        if (i_left->father->left == node)
            i_left->father->left = i_left;
        else
            i_left->father->right = i_left;
    }
}

int rbtree_node_is_red(Noderb *node) { return node && node->is_red; }

void rbtree_node_insert_fixup(Noderb **node_root, Noderb *node) {

    Noderb *node_r = node, *node_f = node_r->father, *node_u = NULL;

    while (rbtree_node_is_red(node_f)) {

        if (node_f == node_f->father->left) {

            node_u = node_f->father->right;
            if (rbtree_node_is_red(node_u)) {
                node_f->is_red = node_u->is_red = 0;
                node_f->father->is_red = 1;
                node_r = node_f->father;
            } else if (node_r == node_f->right) {
                node_r = node_f;
                rbtree_left_rotate(node_r);
                node_r->father->is_red = 0;
                node_r->father->father->is_red = 1;
                rbtree_right_rotate(node_r->father->father);
            }

        } else {
            node_u = node_f->father->left;
            if (rbtree_node_is_red(node_u)) {
                node_f->is_red = node_u->is_red = 0;
                node_f->father->is_red = 1;
                node_r = node_f->father;
            } else if (node_r == node_f->left) {
                node_r = node_f;
                rbtree_right_rotate(node_r);
                node_r->father->is_red = 0;
                node_r->father->father->is_red = 1;
                rbtree_left_rotate(node_r->father->father);
            }
        }

        node_f = node_r->father;
    }

    (*node_root)->is_red = 0;
}
