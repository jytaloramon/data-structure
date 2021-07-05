/**
 * @author Ytalo Ramon
 * @date   19/06/2021
 */

#include "segment_tree_1d_base.h"


/**
 * struct _CoordCartesian 1D.
 * attr: col - collumn, coordinate.
 */
struct _CoordCartesian1D {
    int col;
};

/**
 * struct _SegTree.
 * attr: arr - Pointer to array one-dimension.
 * attr: arr_segt - Pointer to array SegTree one-dimension.
 * attr: shape - Arrays dimensions.
 */
struct _SegTree {
    int *arr, *arr_segt;
    struct _CoordCartesian1D shape;
};


/**
 * Create a new Segment Tree.
 * @param arr array.
 * @param arr_segt array segtree.
 * @param shape array dimension.
 * @return A SegTree instance or Null in case of error.
 */
SegTree *segtree_new(int *arr, int *arr_segt, CoordCartesian1D shape);

/**
 * Update the value in the segment tree.
 * @param seg_tree an instance of the SegTree.
 * @param value new value.
 * @param coord update coordinate.
 */
void segtree_update(SegTree *seg_tree, int value, CoordCartesian1D coord);

/**
 * Update the value in the current segment.
 * @param arr_segt array segtree.
 * @param value new value.
 * @param coord update coordinate.
 * @param s_curr_coord start of (current), coordinate.
 * @param e_curr_coord end break (current), coordinate.
 * @param posi position in segment array.
 */
void segtree_update_curr(int *arr_segt, int value, CoordCartesian1D coord,
                         CoordCartesian1D s_curr_coord,
                         CoordCartesian1D e_curr_coord, int posi);

/**
 * Get the sum of the a segment (current) between two values. [start - end[
 * @param arr_segt array segtree.
 * @param s_coord start of break, coordinate.
 * @param e_coord end break, coordinate.
 * @param s_curr_coord start of (current), coordinate.
 * @param e_curr_coord end break (current), coordinate.
 * @param posi position in segment array.
 * @return The sum of the segment (current).
 */
int segtree_sum_between_curr(int *arr_segt, CoordCartesian1D s_coord,
                             CoordCartesian1D e_coord,
                             CoordCartesian1D s_curr_coord,
                             CoordCartesian1D e_curr_coord, int posi);
