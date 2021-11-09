/**
 * @author Ytalo Ramon
 * @date   03/07/2021
 */

#include "../../../includes/itree_array.h"


/**
 * Define the prototype of the struct.
 * struct _CoordCartesian CoordCartesian 1D.
 */
typedef struct _CoordCartesian1D CoordCartesian1D;

/**
 * Define the prototype of the struct.
 * struct _SegTree SegTree.
 */
typedef struct _SegTree SegTree;


/**
 * Build the Segment Tree.
 * @param seg_tree an instance of the SegTree.
 */
void segtree_build(SegTree *seg_tree);

/**
 * Build a segment (current) between two values of the Tree.
 * @param arr array.
 * @param arr_segt array segtree.
 * @param s_curr_coord start of break (current), coordinate.
 * @param e_curr_coord end break (current), coordinate.
 * @param posi position in segment array.
 */
void segtree_build_curr(int *arr, int *arr_segt, CoordCartesian1D s_curr_coord,
                        CoordCartesian1D e_curr_coord, int posi);

/**
 * Get the sum of the segment between two values. [start - end[
 * @param seg_tree an instance of the SegTree.
 * @param s_coord start of break, coordinate.
 * @param e_coord end break, coordinate.
 * @return The sum of the segment.
 */
int segtree_sum_between(SegTree *seg_tree, CoordCartesian1D s_coord,
                        CoordCartesian1D e_coord);
