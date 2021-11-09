/**
 * @author Ytalo Ramon
 * @date   03/07/2021
 */

#include "../../../includes/itree_array.h"


/**
 * Define the prototype of the struct.
 * struct _CoordCartesian CoordCartesian.
 */
typedef struct _CoordCartesian2D CoordCartesian2D;

/**
 * Define the prototype of the struct.
 * struct _SegTree SegTree.
 */
typedef struct _SegTree2D SegTree2d;


/**
 * struct _CoordCartesian 2D.
 * attr: row - row, coordinate.
 * attr: col - collumn, coordinate.
 */
struct _CoordCartesian2D {
    int row, col;
};

/**
 * struct _SegTree 2D.
 * attr: arr - Pointer to array two-dimension.
 * attr: arr_segt - Pointer to array SegTree two-dimension.
 * attr: shape - Arrays dimensions.
 */
struct _SegTree2D {
    int *arr, *arr_segt;
    struct _CoordCartesian2D shape;
};

/**
 * Create a new Segment Tree.
 * @param arr array.
 * @param arr_segt array segtree.
 * @param shape array dimension.
 * @return A SegTree instance or Null in case of error.
 */
SegTree2d *segtree2d_new(int *arr, int *arr_segt, CoordCartesian2D shape);

/**
 * Build the Segment Tree.
 * @param seg_tree an instance of the SegTree.
 */
void segtree2d_build(SegTree2d *seg_tree);

/**
 * Build a segment (current) between two values of the Tree.
 * @param arr array.
 * @param arr_segt array segtree.
 * @param s_curr_coord start of break (current), coordinate.
 * @param e_curr_coord end break (current), coordinate.
 * @param posi position in segment array.
 */
void segtree2d_build_curr(int *arr, int *arr_segt,
                          CoordCartesian2D s_curr_coord,
                          CoordCartesian2D e_curr_coord, int posi);

/**
 * Update the value in the segment tree.
 * @param seg_tree an instance of the SegTree.
 * @param value new value.
 * @param coord update coordinate.
 */
void segtree2d_update(SegTree2d *seg_tree, int value, CoordCartesian2D coord);

/**
 * Update the value in the segment current.
 * @param arr_segt array segtree.
 * @param value new value.
 * @param coord update coordinate.
 * @param s_curr_coord start of (current), coordinate.
 * @param e_curr_coord end break (current), coordinate.
 * @param posi position in segment array.
 */
void segtree2d_update_curr(int *arr_segt, int value, CoordCartesian2D coord,
                           CoordCartesian2D s_curr_coord,
                           CoordCartesian2D e_curr_coord, int posi);

/**
 * Get the sum of the segment between two values. [start - end[
 * @param seg_tree an instance of the SegTree.
 * @param s_coord start of break, coordinate.
 * @param e_coord end break, coordinate.
 * @return The sum of the segment.
 */
int segtree2d_sum_between(SegTree2d *seg_tree, CoordCartesian2D s_coord,
                          CoordCartesian2D e_coord);

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
int segtree2d_sum_between_curr(int *arr_segt, CoordCartesian2D s_coord,
                               CoordCartesian2D e_coord,
                               CoordCartesian2D s_curr_coord,
                               CoordCartesian2D e_curr_coord, int posi);
