/**
 * @author Ytalo Ramon
 * @date   18/06/2021
*/

#include "fenwick_tree.h"

/**
 * struct _CoordCartesian 2D.
 * attr: row - row, coordinate.
 * attr: col - collumn, coordinate.
*/
struct _CoordCartesian {
    int row, col;
};

/**
 * struct _FenwickStructure.
 * attr: arr - Pointer to array two-dimension.
 * attr: bitree_arr - Pointer to array BITREE two-dimension.
 * attr: shape - Lengths of each dimension.
*/
struct _FenwickStructure {
    int **arr, **bitree_arr;
    CoordCartesian shape;
};
