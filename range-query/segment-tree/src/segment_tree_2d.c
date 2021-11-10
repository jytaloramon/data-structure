/**
 * @author Ytalo Ramon
 * @date   03/07/2021
 */

#include "stdlib.h"
#include "../include/segment_tree_2d.h"
#include "../include/segment_tree_1d.h"

#define MULTI 4


SegTree2d *segtree2d_new(int *arr, int *arr_segt, CoordCartesian2D shape) {

    SegTree2d *seg_tree = malloc(sizeof(SegTree2d));

    if (!seg_tree)
        return NULL;

    seg_tree->arr = arr;
    seg_tree->arr_segt = arr_segt;
    seg_tree->shape.row = shape.row;
    seg_tree->shape.col = shape.col;

    return seg_tree;
}

void segtree2d_build(SegTree2d *seg_tree) {

    segtree2d_build_curr(
        seg_tree->arr, seg_tree->arr_segt,
        (CoordCartesian2D){0, seg_tree->shape.col - 1},
        (CoordCartesian2D){seg_tree->shape.row - 1, seg_tree->shape.col - 1},
        0);
}

void segtree2d_build_curr(int *arr, int *arr_segt,
                          CoordCartesian2D s_curr_coord,
                          CoordCartesian2D e_curr_coord, int posi) {

    int len = s_curr_coord.col + 1, (*arr_lk)[len] = (int(*)[])arr,
        (*arr_lk_segt)[len * MULTI] = (int(*)[])arr_segt;

    if (s_curr_coord.row == e_curr_coord.row) {
        segtree_build_curr(arr_lk[s_curr_coord.row], arr_lk_segt[posi],
                           (CoordCartesian1D){0},
                           (CoordCartesian1D){e_curr_coord.col}, 0);
        return;
    }

    int middle = (s_curr_coord.row + e_curr_coord.row) / 2,
        left = CHILDLEFT(posi), right = CHILDRIGHT(posi);

    segtree2d_build_curr(arr, arr_segt, s_curr_coord,
                         (CoordCartesian2D){middle, e_curr_coord.col}, left);
    segtree2d_build_curr(arr, arr_segt,
                         (CoordCartesian2D){middle + 1, s_curr_coord.col},
                         e_curr_coord, right);

    for (int i = 0; i < len * MULTI; ++i)
        arr_lk_segt[posi][i] = arr_lk_segt[left][i] + arr_lk_segt[right][i];
}

void segtree2d_update(SegTree2d *seg_tree, int value, CoordCartesian2D coord) {

    int(*arr_lk)[seg_tree->shape.col] = (int(*)[])seg_tree->arr,
        diff = value - arr_lk[coord.row][coord.col];

    segtree2d_update_curr(
        seg_tree->arr_segt, diff, coord, (CoordCartesian2D){0, 0},
        (CoordCartesian2D){seg_tree->shape.row - 1, seg_tree->shape.col - 1}, 0);

    // Update origem array. For viewing purposes only.
    arr_lk[coord.row][coord.col] = value; 
}

void segtree2d_update_curr(int *arr_segt, int value, CoordCartesian2D coord,
                           CoordCartesian2D s_curr_coord,
                           CoordCartesian2D e_curr_coord, int posi) {

    if (s_curr_coord.row > coord.row || e_curr_coord.row < coord.row)
        return;

    int len = (e_curr_coord.col + 1) * MULTI,
        (*arr_lk_segt)[len] = (int(*)[])arr_segt;

    if (s_curr_coord.row == e_curr_coord.row) {
        segtree_update_curr(
            arr_lk_segt[posi], value, (CoordCartesian1D){coord.col},
            (CoordCartesian1D){0}, (CoordCartesian1D){e_curr_coord.col}, 0);

        return;
    }

    int middle = (s_curr_coord.row + e_curr_coord.row) / 2,
        left = CHILDLEFT(posi), right = CHILDRIGHT(posi);

    segtree2d_update_curr(arr_segt, value, coord, s_curr_coord,
                          (CoordCartesian2D){middle, e_curr_coord.col}, left);

    segtree2d_update_curr(arr_segt, value, coord,
                          (CoordCartesian2D){middle + 1, s_curr_coord.col},
                          e_curr_coord, right);

    for (int i = 0; i < len; ++i)
        arr_lk_segt[posi][i] = arr_lk_segt[left][i] + arr_lk_segt[right][i];
}

int segtree2d_sum_between(SegTree2d *seg_tree, CoordCartesian2D s_coord,
                          CoordCartesian2D e_coord) {

    e_coord.row--;
    e_coord.col--;

    return segtree2d_sum_between_curr(
        seg_tree->arr_segt, s_coord, e_coord, (CoordCartesian2D){0, 0},
        (CoordCartesian2D){seg_tree->shape.row - 1, seg_tree->shape.col - 1},
        0);
}

int segtree2d_sum_between_curr(int *arr_segt, CoordCartesian2D s_coord,
                               CoordCartesian2D e_coord,
                               CoordCartesian2D s_curr_coord,
                               CoordCartesian2D e_curr_coord, int posi) {

    if (s_curr_coord.row > e_coord.row || e_curr_coord.row < s_coord.row)
        return 0;

    if (s_coord.row <= s_curr_coord.row && e_coord.row >= e_curr_coord.row) {
        int len = (e_curr_coord.col + 1) * MULTI,
            (*arr_lk_segt)[len] = (int(*)[])arr_segt;

        return segtree_sum_between_curr(
            arr_lk_segt[posi], (CoordCartesian1D){s_coord.col},
            (CoordCartesian1D){e_coord.col}, (CoordCartesian1D){0},
            (CoordCartesian1D){e_curr_coord.col}, 0);
    }

    int middle = (s_curr_coord.row + e_curr_coord.row) / 2,
        left = CHILDLEFT(posi), right = CHILDRIGHT(posi);

    return (segtree2d_sum_between_curr(
                arr_segt, s_coord, e_coord, s_curr_coord,
                (CoordCartesian2D){middle, e_curr_coord.col}, left) +
            segtree2d_sum_between_curr(
                arr_segt, s_coord, e_coord,
                (CoordCartesian2D){middle + 1, s_curr_coord.col}, e_curr_coord,
                right));
}
