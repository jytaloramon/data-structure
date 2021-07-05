/**
 * @author Ytalo Ramon
 * @date   04/07/2021
*/

#include "stdio.h"
#include "stdlib.h"
#include "string.h"
#include "../include/segment_tree_2d.h"

#define LEN 4      // Length array.
#define SEGMULTI 4 // Multiplication factor between length array by length segtree array.

#define INPUTSIZE 13 // Input size for test.

enum option {
    UPDATE,
    SUMBETWEEN
};

void segtree_show(SegTree2d *seg_tree);

int main(int argc, char const *argv[]){

    int test_cases[INPUTSIZE][6] = {
        {SUMBETWEEN, 0, 0, LEN, LEN, 0},
        {SUMBETWEEN, 0, 1, 4, 3, 0},
        {UPDATE, 2, 2, 25, 0, 0},
        {SUMBETWEEN, 3, 3, LEN, LEN, 0},
        {SUMBETWEEN, 2, 3, 3, 4, 0},
        {SUMBETWEEN, 1, 1, 3, 4, 0},
        {SUMBETWEEN, 0, 3, 4, 4, 0},
        {UPDATE, 3, 3, 31, 0, 0},
        {UPDATE, 0, 0, 0, 0, 0},
        {SUMBETWEEN, 0, 0, 3, 3, 0},
        {UPDATE, 2, 3, 11, 0, 0},
        {UPDATE, 1, 3, 4, 0, 0},
        {SUMBETWEEN, 0, 1, 4, 3, 0},
    };

    printf("+++++ SEGMENT TREE 2D +++++\n\n");

    int op, *v, rs;
    int arr[LEN][LEN] = {{1, 2, 3, 4},
                         {5, 6, 7, 8},
                         {1, 7, 5, 9},
                         {3, 0, 6, 2}};
    int arr_segt[LEN * SEGMULTI][LEN * SEGMULTI];

    // Setting all array positions to 0
    for (int i = 0; i < LEN * SEGMULTI; ++i)
        memset(arr_segt[i], 0, sizeof(int) * LEN * SEGMULTI);

    SegTree2d *seg_tree2d = segtree2d_new(&arr[0][0], &arr_segt[0][0], (CoordCartesian2D){LEN, LEN});

    if (!seg_tree2d){
        printf("Memory allocation error!\n");
        exit(0);
    }

    segtree2d_build(seg_tree2d);
    segtree_show(seg_tree2d);

    // Test
    for (int i = 0; i < INPUTSIZE; ++i){
        op = test_cases[i][0]; v = &test_cases[i][1];

        switch (op){
        case SUMBETWEEN:
            rs = segtree2d_sum_between(seg_tree2d, (CoordCartesian2D){v[0], v[1]}, (CoordCartesian2D){v[2], v[3]});
            printf(" * SUMBETWEEN [(%d, %d) - (%d, %d)]: %d\n\n", v[0], v[1], v[2] - 1, v[3] - 1, rs);
            break;
        case UPDATE:
            printf(" * UPDATE [%d, %d](%d) to (%d)\n\n", v[0], v[1], ((int (*)[LEN]) seg_tree2d->arr)[v[0]][v[1]], v[2]);
            segtree2d_update(seg_tree2d, v[2], (CoordCartesian2D){v[0], v[1]});
            segtree_show(seg_tree2d);
        }
    }

    printf("Final:\n");
    segtree_show(seg_tree2d);

    return 0;
}

void segtree_show(SegTree2d *seg_tree){

    int len = seg_tree->shape.col,
        (*arr_link)[len] = (int(*)[])seg_tree->arr,
        (*arr_segt_link)[len * SEGMULTI] = (int(*)[])seg_tree->arr_segt;

    printf("Matrix:\n");
    for (int i = 0; i < seg_tree->shape.row; ++i){
        for (int j = 0; j < seg_tree->shape.col; ++j){
            printf("%d, ", arr_link[i][j]);
        }
        printf("\n");
    }

    printf("\nSegtree_matrix:\n");
    for (int i = 0; i < seg_tree->shape.row * SEGMULTI; ++i){
        for (int j = 0; j < len * SEGMULTI; ++j){
            printf("%d, ", arr_segt_link[i][j]);
        }
        printf("\n");
    }

    for (int i = 0; i < len * SEGMULTI; ++i)
        printf("---");

    printf("\n\n");
}
