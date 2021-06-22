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
 * attr: shape - Arrays dimensions.
*/
struct _FenwickStructure {
    int **arr, **bitree_arr;
    struct _CoordCartesian shape;
};


/**
 * Create a new Fenwick Tree.
 * @param arr array two-dimension.
 * @param bitree_arr array two-dimension BIT.
 * @param shape arrays dimensions.
 * @return A Fenwick instance or Null in case of error.
*/
FenwickStructure *bitree_new(int **arr, int **bitree_arr, CoordCartesian shape);
