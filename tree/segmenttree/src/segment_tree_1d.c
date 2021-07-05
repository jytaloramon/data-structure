/**
 * @author Ytalo Ramon
 * @date   11/06/2021
 */

#include "stdlib.h"
#include "../include/segment_tree_1d.h"


SegTree *segtree_new(int *arr, int *arr_segt, CoordCartesian1D shape) {

    SegTree *seg_tree = malloc(sizeof(SegTree));

    if (!seg_tree)
        return NULL;

    seg_tree->arr = arr;
    seg_tree->arr_segt = arr_segt;
    seg_tree->shape.col = shape.col;

    return seg_tree;
}

void segtree_build(SegTree *seg_tree) {

    segtree_build_curr(seg_tree->arr, seg_tree->arr_segt, (CoordCartesian1D){0},
                       (CoordCartesian1D){seg_tree->shape.col - 1}, 0);
}

void segtree_build_curr(int *arr, int *arr_segt, CoordCartesian1D s_curr_coord,
                        CoordCartesian1D e_curr_coord, int posi) {

    if (s_curr_coord.col == e_curr_coord.col) {
        arr_segt[posi] = arr[s_curr_coord.col];
        return;
    }

    int middle = (s_curr_coord.col + e_curr_coord.col) / 2,
        left = CHILDLEFT(posi), right = CHILDRIGHT(posi);

    segtree_build_curr(arr, arr_segt, s_curr_coord, (CoordCartesian1D){middle},
                       left);
    segtree_build_curr(arr, arr_segt, (CoordCartesian1D){middle + 1},
                       e_curr_coord, right);

    arr_segt[posi] = arr_segt[left] + arr_segt[right];
}

void segtree_update(SegTree *seg_tree, int value, CoordCartesian1D coord) {

    int diff = value - seg_tree->arr[coord.col];

    segtree_update_curr(seg_tree->arr_segt, diff, coord, (CoordCartesian1D){0},
                        (CoordCartesian1D){seg_tree->shape.col - 1}, 0);

    // Update origem array. For viewing purposes only.
    seg_tree->arr[coord.col] = value;
}

void segtree_update_curr(int *arr_segt, int value, CoordCartesian1D coord,
                         CoordCartesian1D s_curr_coord,
                         CoordCartesian1D e_curr_coord, int posi) {

    int s = 0, e = e_curr_coord.col, middle = 0;

    while (s != e) {
        middle = (s + e) / 2;
        arr_segt[posi] += value;

        if (coord.col <= middle) {
            e = middle;
            posi = CHILDLEFT(posi);
        } else {
            s = middle + 1;
            posi = CHILDRIGHT(posi);
        }
    }

    arr_segt[posi] += value;
}

int segtree_sum_between(SegTree *seg_tree, CoordCartesian1D s_coord,
                        CoordCartesian1D e_coord) {

    e_coord.col--;

    return segtree_sum_between_curr(
        seg_tree->arr_segt, s_coord, e_coord, (CoordCartesian1D){0},
        (CoordCartesian1D){seg_tree->shape.col - 1}, 0);
}

int segtree_sum_between_curr(int *arr_segt, CoordCartesian1D s_coord,
                             CoordCartesian1D e_coord,
                             CoordCartesian1D s_curr_coord,
                             CoordCartesian1D e_curr_coord, int posi) {

    if (s_coord.col > e_curr_coord.col || e_coord.col < s_curr_coord.col)
        return 0;

    if (s_coord.col <= s_curr_coord.col && e_coord.col >= e_curr_coord.col)
        return arr_segt[posi];

    int middle = (s_curr_coord.col + e_curr_coord.col) / 2;

    return (segtree_sum_between_curr(arr_segt, s_coord, e_coord, s_curr_coord,
                                     (CoordCartesian1D){middle},
                                     CHILDLEFT(posi)) +
            segtree_sum_between_curr(arr_segt, s_coord, e_coord,
                                     (CoordCartesian1D){middle + 1},
                                     e_curr_coord, CHILDRIGHT(posi)));
}
