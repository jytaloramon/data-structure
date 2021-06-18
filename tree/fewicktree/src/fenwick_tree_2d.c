/**
 * @author Ytalo Ramon
 * @date   10/06/2021
*/

#include "stdlib.h"
#include "stdio.h"
#include "../include/fenwick_tree_2d.h"

FenwickStructure *bitree_new(CoordCartesian shape){
    
    
    FenwickStructure *fkws = malloc(sizeof(FenwickStructure));
    if (!fkws)
        return NULL;

    fkws->shape.row = shape.row;
    fkws->shape.col = shape.col;

    fkws->arr = malloc(sizeof(int) * fkws->shape.row);
    fkws->bitree_arr = malloc(sizeof(int) * fkws->shape.row);
    
    if (!fkws->arr || !fkws->bitree_arr){
        !fkws->arr ? free(fkws->arr) : free(fkws->bitree_arr);
        free(fkws);
        return NULL;
    }

    int i = 0, err_malloc = 0;

    // Allocate matrix 
    while (i < fkws->shape.row && !err_malloc){
        fkws->arr[i] = malloc(sizeof(int) * fkws->shape.col);
        fkws->bitree_arr[i] = malloc(sizeof(int) * fkws->shape.col);

        if (!fkws->arr[i] || !fkws->bitree_arr[i]){
            !fkws->arr[i] ? free(fkws->arr[i]) : free(fkws->bitree_arr[i]);
            err_malloc = 0;
        }
        i++;
    }

    if (err_malloc){
        for (int j = 0; j < i - 1; ++j){ // Free: matrix in case of error.
            free(fkws->arr[j]);
            free(fkws->bitree_arr[j]);
        }

        free(fkws);

        return NULL;
    }

    // Set default values in the array  
    for (i = 0; i < fkws->shape.row; ++i)
        for (int j = 0; j < fkws->shape.col; ++j)        
            fkws->arr[i][j] = fkws->bitree_arr[i][j] = 0;

    return fkws;
}

void bitree_build(FenwickStructure *fwks){

    for (int i = 0; i < fwks->shape.row; ++i){
        for (int j = 0; j < fwks->shape.col; ++j){
            
            for (int k = i + 1; k <= fwks->shape.row; k += OPBITANDBITCOMP(k)){
                for (int t =  j + 1; t <= fwks->shape.col; t += OPBITANDBITCOMP(t)){
                    fwks->bitree_arr[k - 1][t - 1] += fwks->arr[i][j];
                }
            }

        }
    }
}

void bitree_update(FenwickStructure *fwks, int value, CoordCartesian coord){

    for (int i = coord.row; i > 0; i -= OPBITANDBITCOMP(i)){
        for (int j = coord.col; j > 0; j -= OPBITANDBITCOMP(j)){
            fwks->bitree_arr[i - 1][j - 1] += value;
        }
    }
}

int bitree_sum(FenwickStructure *fwks, CoordCartesian e_coord){

    int sumt = 0;

    for (int i = e_coord.row; i > 0; i -= OPBITANDBITCOMP(i)){
        for (int j = e_coord.col; j > 0; j -= OPBITANDBITCOMP(j)){
            sumt += fwks->bitree_arr[i - 1][j - 1];
        }
    }

    return sumt;
}

int bitree_sum_between(FenwickStructure *fwks, CoordCartesian s_coord, CoordCartesian e_coord){
   
    return bitree_sum(fwks, e_coord) 
            - bitree_sum(fwks, (CoordCartesian){s_coord.row, e_coord.col})
            - bitree_sum(fwks, (CoordCartesian){e_coord.row, s_coord.col})
            + bitree_sum(fwks, (CoordCartesian){s_coord.row, s_coord.col});
}
