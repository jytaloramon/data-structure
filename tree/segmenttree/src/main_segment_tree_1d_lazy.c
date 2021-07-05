/**
 * @author Ytalo Ramon
 * @date   11/06/2021
*/

#include "stdio.h"
#include "stdlib.h"
#include "string.h"
#include "../include/segment_tree_1d_lazy.h"

#define LEN 10       // Length array.
#define SEGMULTI 4   // Multiplication factor between length array by length segtree array.

#define INPUTSIZE 15 // Input size for test.

enum option {
    UPDATEBETWEEN,
    SUMBETWEEN
};

void segtree_show(SegTree *seg_tree);

int main(int argc, char const *argv[]){

    int test_cases[INPUTSIZE][4] = {
        {SUMBETWEEN, 0, 5, 0,},
        {SUMBETWEEN, 3, 8, 0},
        {UPDATEBETWEEN, 0, LEN, 7},
        {SUMBETWEEN, 3, 4, 0},
        {SUMBETWEEN, 3, 8, 0},
        {SUMBETWEEN, 0, LEN, 0},
        {SUMBETWEEN, 5, LEN, 0},
        {SUMBETWEEN, 6, 8, 0},
        {UPDATEBETWEEN, 7, LEN, 10},
        {UPDATEBETWEEN, 2, 3, 25},
        {SUMBETWEEN, 1, 9, 0},
        {SUMBETWEEN, 0, 3, 0},
        {SUMBETWEEN, 0, 1, 0},
        {SUMBETWEEN, LEN - 1, LEN, 0},
        {SUMBETWEEN, 0, LEN, 0},
    };
    
    printf("+++++ SEGMENT TREE 1D LAZY +++++\n\n");

    int op, v1, v2, v3, rs,
        arr[LEN] = {1, 8, 9, 0, 5, 3, 2, 4, 6, 7},
        arr_segt[LEN * SEGMULTI],
        arr_lazy[LEN * SEGMULTI];

    // Setting all arrayS positions to 0
    memset(arr_segt, 0, sizeof(int) * LEN * SEGMULTI);
    memset(arr_lazy, 0, sizeof(int) * LEN * SEGMULTI);

    SegTree *seg_tree = segtree_new(arr, arr_segt, arr_lazy, (CoordCartesian1D){LEN});

    if (!seg_tree){
        printf("Memory allocation error!\n");
        exit(0);
    }

    segtree_build(seg_tree);
    segtree_show(seg_tree);

    // Test
    for (int i = 0; i < INPUTSIZE; ++i){
        op = test_cases[i][0]; v1 = test_cases[i][1];
        v2 = test_cases[i][2]; v3 = test_cases[i][3];

        switch (op){
        case SUMBETWEEN:
            rs = segtree_sum_between(seg_tree, (CoordCartesian1D){v1}, (CoordCartesian1D){v2});
            printf(" * SUMBETWEEN [%d - %d]: %d\n\n", v1, v2 - 1, rs);
            break;
        case UPDATEBETWEEN:
            printf(" * UPDATEBETWEEN [%d - %d] => %d\n\n", v1, v2 - 1, v3);
            segtree_update_between(seg_tree, v3, (CoordCartesian1D){v1}, (CoordCartesian1D){v2});
            segtree_show(seg_tree);
        }
    }

    printf("Final:\n");
    segtree_show(seg_tree);

    return 0;
}

void segtree_show(SegTree *seg_tree){

    int i = 0, j = 0;

    printf("Arr: ");
    for (i = 0; i < seg_tree->shape.col; ++i)
        printf("%d, ", seg_tree->arr[i]);
    
    for (j = seg_tree->shape.col * SEGMULTI - 1; j >= 0 && seg_tree->arr_segt[j] == 0; --j);

    printf("\nArr_lazy: ");
    for (i = 0; i < j + 1; ++i)
        printf("%d, ", seg_tree->arr_lazy[i]);

    printf("\nArr_Segtree: ");
    for (i = 0; i < j + 1; ++i)
        printf("%d, ", seg_tree->arr_segt[i]);

    printf("\n");
    for (i = 0; i < j; ++i)
        printf("----");

    printf("\n\n");
}
