/**
 * @author Ytalo Ramon
 * @date   26/06/2021
 */

#include "stdlib.h"
#include "stdio.h"
#include "../include/segment_tree_1d_lazy.h"

SegTree *segtree_new(int *arr, int *arr_segt, int *arr_lazy,
                     CoordCartesian1D shape) {

    SegTree *seg_tree = malloc(sizeof(SegTree));

    if (!seg_tree)
        return NULL;

    seg_tree->arr = arr;
    seg_tree->arr_segt = arr_segt;
    seg_tree->arr_lazy = arr_lazy;
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

void segtree_update_between(SegTree *seg_tree, int value,
                            CoordCartesian1D s_coord,
                            CoordCartesian1D e_coord) {

    e_coord.col--;
    segtree_update_between_curr(seg_tree->arr_segt, seg_tree->arr_lazy, value,
                                s_coord, e_coord, (CoordCartesian1D){0},
                                (CoordCartesian1D){seg_tree->shape.col - 1}, 0);

    // Update origem array. For viewing purposes only.
    for (int i = s_coord.col; i <= e_coord.col; ++i)
        seg_tree->arr[i] += value;
}

void segtree_update_between_curr(int *arr_segt, int *arr_lazy, int value,
                                 CoordCartesian1D s_coord,
                                 CoordCartesian1D e_coord,
                                 CoordCartesian1D s_curr_coord,
                                 CoordCartesian1D e_curr_coord, int posi) {

    if (s_coord.col > e_curr_coord.col || e_coord.col < s_curr_coord.col)
        return;

    int middle = (s_curr_coord.col + e_curr_coord.col) / 2,
        left = CHILDLEFT(posi), right = CHILDRIGHT(posi);

    if (s_coord.col <= s_curr_coord.col && e_coord.col >= e_curr_coord.col) {
        arr_segt[posi] += (e_curr_coord.col - s_curr_coord.col + 1) * value;
       
        if (s_curr_coord.col != e_curr_coord.col)
            arr_lazy[posi] += value;

        return;
    }

    if (arr_lazy[posi]) {

        arr_segt[left] += (middle - s_curr_coord.col + 1) * arr_lazy[posi];
        arr_segt[right] += (e_curr_coord.col - middle) * arr_lazy[posi];

        if (left != middle) {
            arr_lazy[left] += arr_lazy[posi];
            arr_lazy[right] += arr_lazy[posi];
        }

        arr_lazy[posi] = 0;
    }

    segtree_update_between_curr(arr_segt, arr_lazy, value, s_coord, e_coord,
                                s_curr_coord, (CoordCartesian1D){middle}, left);
    segtree_update_between_curr(arr_segt, arr_lazy, value, s_coord, e_coord,
                                (CoordCartesian1D){middle + 1}, e_curr_coord,
                                right);

    arr_segt[posi] = arr_segt[left] + arr_segt[right];
}

int segtree_sum_between(SegTree *seg_tree, CoordCartesian1D s_coord,
                        CoordCartesian1D e_coord) {

    e_coord.col--;

    return segtree_sum_between_curr(
        seg_tree->arr_segt, seg_tree->arr_lazy, s_coord, e_coord,
        (CoordCartesian1D){0}, (CoordCartesian1D){seg_tree->shape.col - 1}, 0);
}

int segtree_sum_between_curr(int *arr_segt, int *arr_lazy,
                             CoordCartesian1D s_coord, CoordCartesian1D e_coord,
                             CoordCartesian1D s_curr_coord,
                             CoordCartesian1D e_curr_coord, int posi) {

    if (s_coord.col > e_curr_coord.col || e_coord.col < s_curr_coord.col)
        return 0;

    int middle = (s_curr_coord.col + e_curr_coord.col) / 2,
        left = CHILDLEFT(posi), right = CHILDRIGHT(posi);

    if (s_coord.col <= s_curr_coord.col && e_coord.col >= e_curr_coord.col)
        return arr_segt[posi];

    if (arr_lazy[posi]) {
        arr_segt[left] += (middle - s_curr_coord.col + 1) * arr_lazy[posi];
        arr_segt[right] += (e_curr_coord.col - middle) * arr_lazy[posi];

        if (left != middle) {
            arr_lazy[left] += arr_lazy[posi];
            arr_lazy[right] += arr_lazy[posi];
        }

        arr_lazy[posi] = 0;
    }

    return (segtree_sum_between_curr(arr_segt, arr_lazy, s_coord, e_coord,
                                     s_curr_coord, (CoordCartesian1D){middle},
                                     left) +
            segtree_sum_between_curr(arr_segt, arr_lazy, s_coord, e_coord,
                                     (CoordCartesian1D){middle + 1},
                                     e_curr_coord, right));
}
