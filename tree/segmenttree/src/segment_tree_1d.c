/**
 * @author Ytalo Ramon
 * @date   11/06/2021
*/

#include "stdlib.h"
#include "stdio.h"
#include "../include/segment_tree_1d.h"


SegTree *segtree_new(int *arr, int *seg_arr, CoordCartesian shape){

    SegTree *seg_tree = malloc(sizeof(SegTree));

    if (!seg_tree)
        return NULL;

    seg_tree->arr = arr;
    seg_tree->segt_arr = seg_arr;
    seg_tree->shape.col = shape.col;
    
    return seg_tree;
}

void segtree_build(SegTree *seg_tree){

    segtree_mount(seg_tree, (CoordCartesian){0}, (CoordCartesian){seg_tree->shape.col - 1}, 0);  
}

void segtree_mount(SegTree *seg_tree, CoordCartesian s, CoordCartesian e, int posi){

    if (s.col == e.col){
        seg_tree->segt_arr[posi] = seg_tree->arr[s.col];
        return;
    }

    int middle = (s.col + e.col) / 2,
        left = LEFT(posi), right = RIGTH(posi);

    segtree_mount(seg_tree, s, (CoordCartesian){middle}, left);
    segtree_mount(seg_tree, (CoordCartesian){middle + 1}, e, right);
    
    seg_tree->segt_arr[posi] = seg_tree->segt_arr[left] + seg_tree->segt_arr[right];
}

void segtree_update(SegTree *seg_tree, int value, CoordCartesian coord){
    
    int s = 0, e = seg_tree->shape.col - 1,
        posi = 0, middle = 0, dif = value - seg_tree->arr[coord.col];
    
    while (s != e){
        middle = (s + e) / 2;
        seg_tree->segt_arr[posi] += dif;

        if (coord.col <= middle){
            e = middle;
            posi = LEFT(posi);
        } else {
            s = middle + 1;
            posi = RIGTH(posi);
        }
    }
    
    seg_tree->segt_arr[posi] = seg_tree->arr[coord.col] = value;
}

int segtree_sum(SegTree *seg_tree, CoordCartesian s_coord, CoordCartesian e_coord, CoordCartesian s_act_coord, CoordCartesian e_act_coord, int posi){
    
    if (s_coord.col > e_act_coord.col || e_coord.col < s_act_coord.col)
        return 0;

    if (s_coord.col <= s_act_coord.col && e_coord.col >= e_act_coord.col)
        return seg_tree->segt_arr[posi];

    int middle = (s_act_coord.col + e_act_coord.col) / 2;

    return segtree_sum(seg_tree, s_coord, e_coord, s_act_coord, (CoordCartesian){middle}, LEFT(posi))
            + segtree_sum(seg_tree, s_coord, e_coord, (CoordCartesian){middle + 1}, e_act_coord, RIGTH(posi));
}

int segtree_sum_between(SegTree *seg_tree, CoordCartesian s_coord, CoordCartesian e_coord){
    
    e_coord.col -= 1;
    return segtree_sum(seg_tree, s_coord, e_coord, (CoordCartesian){0}, (CoordCartesian){seg_tree->shape.col - 1}, 0);
}