/**
 * @author Ytalo Ramon
 * @date   11/06/2021
 */

#include "stdio.h"
#include "stdlib.h"
#include "string.h"
#include "../include/segment_tree_1d.h"

#define LEN 10 // Length array.
#define SEGMULTI                                                               \
    4 // Multiplication factor between length array by length segtree array.

#define INPUTSIZE 13 // Input size for test.

enum option { UPDATE, SUMBETWEEN };

void segtree_show(SegTree *seg_tree);

int main(int argc, char const *argv[]) {

    int test_cases[INPUTSIZE][3] = {
        {SUMBETWEEN, 0, 5},   {SUMBETWEEN, 3, 8},   {UPDATE, 6, 7},
        {SUMBETWEEN, 3, 8},   {SUMBETWEEN, 0, LEN}, {SUMBETWEEN, 5, LEN},
        {SUMBETWEEN, 6, 8},   {UPDATE, 7, 1},       {UPDATE, 3, 15},
        {SUMBETWEEN, 1, 9},   {SUMBETWEEN, 0, 3},   {SUMBETWEEN, 0, 1},
        {SUMBETWEEN, 0, LEN},
    };

    printf("+++++ SEGMENT TREE 1D +++++\n\n");

    int op, v1, v2, rs, arr[LEN] = {1, 8, 9, 0, 5, 3, 2, 4, 6, 7},
                        arr_segt[LEN * SEGMULTI];

    // Setting all array positions to 0
    memset(arr_segt, 0, sizeof(int) * LEN * SEGMULTI);

    SegTree *seg_tree = segtree_new(arr, arr_segt, (CoordCartesian1D){LEN});

    if (!seg_tree) {
        printf("Memory allocation error!\n");
        exit(0);
    }

    segtree_build(seg_tree);
    segtree_show(seg_tree);

    // Tests
    for (int i = 0; i < INPUTSIZE; ++i) {
        op = test_cases[i][0];
        v1 = test_cases[i][1];
        v2 = test_cases[i][2];

        switch (op) {
        case SUMBETWEEN:
            rs = segtree_sum_between(seg_tree, (CoordCartesian1D){v1},
                                     (CoordCartesian1D){v2});
            printf(" * SUMBETWEEN [%d - %d]:%d\n\n", v1, v2 - 1, rs);
            break;
        case UPDATE:
            printf(" * UPDATE [%d](%d) to (%d)\n\n", v1, seg_tree->arr[v1], v2);
            segtree_update(seg_tree, v2, (CoordCartesian1D){v1});
            segtree_show(seg_tree);
        }
    }

    printf("Final:\n");
    segtree_show(seg_tree);

    return 0;
}

void segtree_show(SegTree *seg_tree) {

    int i = 0, j = 0;

    printf("Arr: ");
    for (i = 0; i < seg_tree->shape.col; ++i)
        printf("%d, ", seg_tree->arr[i]);

    for (j = seg_tree->shape.col * SEGMULTI - 1;
         j >= 0 && seg_tree->arr_segt[j] == 0; --j)
        ;

    printf("\nSegtree_arr: ");
    for (i = 0; i < j + 1; ++i)
        printf("%d, ", seg_tree->arr_segt[i]);

    printf("\n");
    for (i = 0; i < j; ++i)
        printf("----");

    printf("\n\n");
}
