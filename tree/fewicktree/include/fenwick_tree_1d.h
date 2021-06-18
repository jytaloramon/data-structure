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
 * attr: shape - Dimension length.
*/
struct _FenwickStructure {
    int *arr, *bitree_arr;
    CoordCartesian shape;
};
