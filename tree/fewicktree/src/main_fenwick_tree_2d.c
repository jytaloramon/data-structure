#include "stdio.h"
#include "stdlib.h"
#include "../include/fenwick_tree_2d.h"

// Length array
#define LEN 4

#define INPUTSIZE 1 // Input size for test.

enum options {
    UPDATE,
    SUM,
    SUMBETWEEN,
};

void bitree_show(FenwickStructure *fwks);

int main(int argc, char const *argv[]){

    int test_cases[INPUTSIZE][6] = {
        {SUMBETWEEN, 0, 0, 1, 2, 0},
    };

    printf("----- FENWICK TREE (BIT) 2D -----\n\n");
    
    FenwickStructure *fwks = bitree_new((CoordCartesian){LEN, LEN});
    
    if (!fwks){
        printf("Memory allocation error!\n");
        exit(0);
    }
    
    int op, rs, v[5];
    int array[LEN][LEN] = {{1, 2, 3, 4},
                            {8, 7, 6, 5},
                            {9, 10, 11, 12},
                            {13, 14, 15, 16}};

    // Copy values from FenwickStructure array;
    for (int i = 0; i < LEN; ++i){
        for (int j = 0; j < LEN; ++j){
            fwks->arr[i][j] = array[i][j];
        }
    }

    bitree_build(fwks);
    bitree_show(fwks);

    
    // Tests
    for (int i = 0; i < INPUTSIZE; ++i){
        op = test_cases[i][0]; v[1] = test_cases[i][1];
        v[2] = test_cases[i][2]; v[3] = test_cases[i][3];
        v[4] = test_cases[i][4]; v[5] = test_cases[i][5];

        switch (op){
        case SUMBETWEEN:
            rs = bitree_sum_between(fwks, (CoordCartesian){v[1], v[2]}, (CoordCartesian){v[3], v[4]});
            printf("SUMBETWEEN [(%d, %d) - (%d, %d)]: %d\n\n", v[1], v[2], v[3], v[4], rs);
            break;
        /*case UPDATE:
            printf("UPDATE [%d](%d) to (%d)\n\n", v1, fwks->arr[v1], v2);
            rs = v2 - fwks->arr[v1];
            fwks->arr[v1] = v2;
            bitree_update(fwks, rs, (CoordCartesian){v1});
            bitree_show(fwks);
        */
        }
    }
    

    return 0;
}

void bitree_show(FenwickStructure *fwks){
    
    printf("Arr:\n");
    for (int i = 0; i < fwks->shape.row; ++i){
        for (int j = 0; j < fwks->shape.col; ++j){
            printf("%d ", fwks->arr[i][j]);
        }
        printf("\n");
    }

    printf("\n\nnBitree_arr:\n");
    for (int i = 0; i < fwks->shape.row; ++i){
        for (int j = 0; j < fwks->shape.col; ++j){
            printf("%d ", fwks->bitree_arr[i][j]);
        }
        printf("\n");
    } 

    for (int i = 0; i < fwks->shape.col; ++i)
        printf("----");
    
    printf("\n\n");
}
