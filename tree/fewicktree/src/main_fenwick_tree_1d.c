#include "stdio.h"
#include "stdlib.h"
#include "../include/fenwick_tree_1d.h"

// Length array
#define LEN 12

#define INPUTSIZE 13 // Input size for test.

enum options {
    UPDATE,
    SUM,
    SUMBETWEEN,
};

void bitree_show(FenwickStructure *fwks);

int main(int argc, char const *argv[]){

    int test_cases[INPUTSIZE][3] = {
        {SUMBETWEEN, 0, 5},
        {SUMBETWEEN, 3, 8},
        {UPDATE, 6, 10},
        {SUMBETWEEN, 3, 8},
        {SUMBETWEEN, 0, LEN},
        {SUMBETWEEN, 5, LEN},
        {SUMBETWEEN, 8, 10},
        {UPDATE, 7, 1},
        {UPDATE, 3, 15},
        {SUMBETWEEN, 1, 11},
        {SUMBETWEEN, 0, 0},
        {SUMBETWEEN, 0, 1},
        {SUMBETWEEN, 0, LEN},
    };

    printf("----- FENWICK TREE (BIT) 1D -----\n\n");
    
    FenwickStructure *fwks = bitree_new((CoordCartesian){LEN});
    
    if (!fwks){
        printf("Memory allocation error!\n");
        exit(0);
    }
    
    int op, rs, v1, v2;
    int array[LEN] = {2, 1, 1, 3, 2, 3, 4, 5, 6, 7, 8, 9};

    // Copy values from FenwickStructure array;
    for (int i = 0; i < LEN; ++i)
        fwks->arr[i] = array[i];
    bitree_build(fwks);
    bitree_show(fwks);

    // Tests
    for (int i = 0; i < INPUTSIZE; ++i){
        op = test_cases[i][0]; v1 = test_cases[i][1]; v2 = test_cases[i][2];

        switch (op){
        case SUMBETWEEN:
            rs = bitree_sum_between(fwks, (CoordCartesian){v1}, (CoordCartesian){v2});
            printf("SUMBETWEEN [%d - %d]: %d\n\n", v1, v2, rs);
            break;
        case UPDATE:
            printf("UPDATE [%d](%d) to (%d)\n\n", v1, fwks->arr[v1], v2);
            rs = v2 - fwks->arr[v1];
            fwks->arr[v1] = v2;
            bitree_update(fwks, rs, (CoordCartesian){v1});
            bitree_show(fwks);
        }
    }

    return 0;
}

void bitree_show(FenwickStructure *fwks){
    
    printf("Arr: ");
    for (int i = 0; i < fwks->shape.col; ++i)
        printf("%d, ", fwks->arr[i]);

    printf("\nBitree_arr: ");
    for (int i = 0; i < fwks->shape.col; ++i)
        printf("%d, ", fwks->bitree_arr[i]);
    
    printf("\n");
    for (int i = 0; i < fwks->shape.col; ++i)
        printf("----");
    
    printf("\n\n");
}
