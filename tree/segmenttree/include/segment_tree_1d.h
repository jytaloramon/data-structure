/**
 * @author Ytalo Ramon
 * @date   19/06/2021
*/

#include "segment_tree.h"


/**
 * struct _CoordCartesian 1D.
 * attr: col - collumn, coordinate.
*/
struct _CoordCartesian {
    int col;
};

/**
 * struct SegTree.
 * attr: arr - Pointer to array one-dimension.
 * attr: bitree_arr - Pointer to array BITREE one-dimension.
 * attr: shape - Array dimension.
*/
struct _SegTree {
    int *arr, *segt_arr;
    struct _CoordCartesian shape;
};


SegTree *segtree_new(int *arr, int *seg_arr, CoordCartesian shape);