/**
 * @author Ytalo Ramon
 * @date   12/06/2021
 */

#include "stdlib.h"

/**
 * Returns the item with the lowest value.
 *
 */
#define min(a, b) (((a) <= (b) ? (a) : (b)))

/**
 * Returns the item with the highest value.
 *
 */
#define max(a, b) (((a) >= (b) ? (a) : (b)))

/**
 * Calculate modular arithmetic.
 *
 * @param a value
 * @param b div_value
 * @return remainder
 */
size_t divmodular(int a, int b);
