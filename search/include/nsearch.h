/**
 * @author: Ytalo Ramon
 * @date:   24/07/2021
 */

#include "../../includes/icomparator.h"


/**
 * Search for a value in the array.
 * @param v_key Search key.
 * @param arr Search array.
 * @param size_m Size of each array member.
 * @param s_i Start of search interval.
 * @param e_i end break.
*/
void *nsearch(void *v_key, void *arr, int size_m, int s_i, int e_i,
              ICOMPARATOR);