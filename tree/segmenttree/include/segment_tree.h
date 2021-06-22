/**
 * @author Ytalo Ramon
 * @date   19/06/2021
*/

#include "../../../includes/itree_array.h"


/**
 * Define the prototype of the struct.
 * struct _CoordCartesian CoordCartesian.
*/
typedef struct _CoordCartesian CoordCartesian;

/**
 * Define the prototype of the struct.
 * struct _SegTree SegTree.
*/
typedef struct _SegTree SegTree;


void segtree_build(SegTree *seg_tree);

void segtree_mount(SegTree *seg_tree, CoordCartesian s, CoordCartesian e, int posi);

void segtree_update(SegTree *seg_tree, int value, CoordCartesian coord);

int segtree_sum(SegTree *seg_tree, CoordCartesian s_coord, CoordCartesian e_coord, CoordCartesian s_act_coord, CoordCartesian e_act_coord, int posi);

int segtree_sum_between(SegTree *seg_tree, CoordCartesian s_coord, CoordCartesian e_coord);
