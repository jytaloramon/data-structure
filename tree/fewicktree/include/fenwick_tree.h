/**
 * @author Ytalo Ramon
 * @date   18/06/2021
*/

/**
 * Bitwise operation of the value and its complement.
 * @param val value 
*/
#define OPBITANDBITCOMP(val) ((val) & (-val))

/**
 * Define the prototype of the struct.
 * struct _CoordCartesian CoordCartesian.
*/
typedef struct _CoordCartesian CoordCartesian;

/**
 * Define the prototype of the struct.
 * struct _FenwickStructure FenwickStructure.
*/
typedef struct _FenwickStructure FenwickStructure;


/**
 * Create a new Fenwick Tree.
 * @param shape Fenwick Tree shape.
 * @return A Fenwick instance or Null in case of error.
*/
FenwickStructure *bitree_new(CoordCartesian shape);

/**
 * Build a fenwick Tree.
 * @param fwks Fenwick Structure
*/
void bitree_build(FenwickStructure *fwks);

/**
 * Update value in Fenwick Tree.
 * @param @param fwks Fenwick Structure
 * @param value value added in position, arr[i] = arr[i] + value.
 * @param coord update coordinate.
*/
void bitree_update(FenwickStructure *fwks, int value, CoordCartesian coord);

/**
 * Sum of interval, of array start to given value.
 * @param fwks Fenwick Structure
 * @param e_cord end break, coordinate.
 * @return sum of interval.
*/
int bitree_sum(FenwickStructure *fwks, CoordCartesian e_coord);

/**
 * Sum of interval between two values. [start - end[.
 * @param fwks Fenwick Structure
 * @param s_coord start of break, coordinate.
 * @param e_coord end break, coordinate.
*/
int bitree_sum_between(FenwickStructure *fwks, CoordCartesian s_coord, CoordCartesian e_coord);