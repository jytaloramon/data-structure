/**
 * @author Ytalo Ramon
 * @date   18/06/2021
*/

#include "fenwick_tree.h"

/**
 * struct _CoordCartesian 1D.
 * attr: col - collumn, coordinate.
*/
struct _CoordCartesian {
    int col;
};

/**
 * struct _FenwickStructure.
 * attr: arr - Pointer to array one-dimension.
 * attr: bitree_arr - Pointer to array BITREE one-dimension.
 * attr: shape - Arrays dimension.
*/
struct _FenwickStructure {
    int *arr, *bitree_arr;
    struct _CoordCartesian shape;
};


/**
 * Create a new Fenwick Tree.
 * @param arr array.
 * @param bitree_arr array BIT.
 * @param shape arrays dimension.
 * @return A Fenwick instance or Null in case of error.
*/
FenwickStructure *bitree_new(int *arr, int *bitree_arr, CoordCartesian shape);
