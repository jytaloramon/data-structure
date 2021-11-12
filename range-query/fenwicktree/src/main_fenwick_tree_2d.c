/**
 * @author Ytalo Ramon
 * @date   18/06/2021
 */

#include "stdio.h"
#include "stdlib.h"
#include "../include/fenwick_tree_2d.h"

#define LEN 4 // Length array

#define INPUTSIZE 10 // Input size for test.

enum options {
    SUM,
    SUMBETWEEN,
    UPDATE,
};

void bitree_show(FenwickStructure *fwks);

int main(int argc, char const *argv[]) {

    int test_cases[INPUTSIZE][5] = {
        {SUMBETWEEN, 0, 0, 1, 2}, {SUMBETWEEN, 0, 0, LEN, LEN},
        {UPDATE, 0, 0, 10, 0},    {SUMBETWEEN, 0, 0, 1, 2},
        {UPDATE, 3, 3, 8, 0},     {SUMBETWEEN, 0, 0, LEN, LEN},
        {SUM, 3, 3, 0, 0},        {SUMBETWEEN, 2, 2, LEN, LEN},
        {UPDATE, 2, 3, 9, 0},     {SUMBETWEEN, 1, 3, LEN, LEN},
    };

    int op, rs, v[4];
    int array[LEN][LEN] = {
        {1, 2, 3, 4}, {8, 7, 6, 5}, {9, 10, 11, 12}, {13, 14, 15, 16}};

    int array_bit[LEN][LEN] = {
        {0, 0, 0, 0}, {0, 0, 0, 0}, {0, 0, 0, 0}, {0, 0, 0, 0}};

    printf("+++++ FENWICK TREE (BIT) 2D +++++\n\n");

    FenwickStructure *fwks =
        bitree_new((int *)array, (int *)array_bit, (CoordCartesian){LEN, LEN});

    if (!fwks) {
        printf("Memory allocation error!\n");
        exit(0);
    }

    bitree_build(fwks);
    bitree_show(fwks);

    // Tests
    for (int i = 0; i < INPUTSIZE; ++i) {
        op = test_cases[i][0];
        v[0] = test_cases[i][1];
        v[1] = test_cases[i][2];
        v[2] = test_cases[i][3];
        v[3] = test_cases[i][4];

        switch (op) {
        case SUM:
            rs = bitree_sum(fwks, (CoordCartesian){v[0], v[1]});
            printf(" * SUM [(0, 0) - (%d, %d)]: %d\n\n", v[0] - 1, v[1] - 1,
                   rs);
            break;
        case SUMBETWEEN:
            rs = bitree_sum_between(fwks, (CoordCartesian){v[0], v[1]},
                                    (CoordCartesian){v[2], v[3]});
            printf(" * SUMBETWEEN [(%d, %d) - (%d, %d)]: %d\n\n", v[0], v[1],
                   v[2] - 1, v[3] - 1, rs);
            break;
        case UPDATE:
            printf(" * UPDATE [%d, %d](%d) to (%d)\n\n", v[0], v[1],
                   ((int(*)[LEN])fwks->arr)[v[0]][v[1]], v[2]);
            bitree_update(fwks, v[2], (CoordCartesian){v[0], v[1]});
            bitree_show(fwks);
            break;
        }
    }

    return 0;
}

void bitree_show(FenwickStructure *fwks) {

    int(*arr)[fwks->shape.col] = (int(*)[fwks->shape.col])fwks->arr,
    (*bitree_arr)[fwks->shape.col] = (int(*)[fwks->shape.col])fwks->bitree_arr;

    printf("Arr:\n");
    for (int i = 0; i < fwks->shape.row; ++i) {
        for (int j = 0; j < fwks->shape.col; ++j) {
            printf("%d ", arr[i][j]);
        }
        printf("\n");
    }

    printf("\nBitree_arr:\n");
    for (int i = 0; i < fwks->shape.row; ++i) {
        for (int j = 0; j < fwks->shape.col; ++j) {
            printf("%d ", bitree_arr[i][j]);
        }
        printf("\n");
    }

    for (int i = 0; i < fwks->shape.col; ++i)
        printf("----");

    printf("\n\n");
}
