/**
 * @author Ytalo Ramon
 * @date   10/06/2021
*/

#include "stdlib.h"
#include "../include/fenwick_tree_1d.h"

FenwickStructure *bitree_new(CoordCartesian shape){

    FenwickStructure *fkws = malloc(sizeof(FenwickStructure));
    if (!fkws)
        return NULL;

    fkws->shape.col = shape.col;
    fkws->arr = malloc(sizeof(int) * fkws->shape.col);
    fkws->bitree_arr = malloc(sizeof(int) * fkws->shape.col);

    if (!fkws->arr || !fkws->bitree_arr){
        !fkws->arr ? free(fkws->arr) : free(fkws->bitree_arr);
        free(fkws);
        return NULL;
    }

    // Set default values in the array  
    for (int i = 0; i < fkws->shape.col; ++i)
        fkws->arr[i] = fkws->bitree_arr[i] = 0;

    return fkws;
}

void bitree_build(FenwickStructure *fwks){
    
    for (int i = 0; i < fwks->shape.col; ++i){
        for (int j = i + 1; j <= fwks->shape.col; j += OPBITANDBITCOMP(j))
            fwks->bitree_arr[j - 1] += fwks->arr[i];
    }
}

void bitree_update(FenwickStructure *fwks, int value, CoordCartesian coord){
    
    for (int i = coord.col + 1; i <= fwks->shape.col; i += OPBITANDBITCOMP(i))
        fwks->bitree_arr[i - 1] += value;
}

int bitree_sum(FenwickStructure *fwks, CoordCartesian e_coord){
    
    int sum = 0;

    for (int i = e_coord.col; i > 0; i -= OPBITANDBITCOMP(i))
        sum += fwks->bitree_arr[i - 1];

    return sum;
}

int bitree_sum_between(FenwickStructure *fwks, CoordCartesian s_coord, CoordCartesian e_coord){

    return bitree_sum(fwks, e_coord) - bitree_sum(fwks, s_coord);
}
