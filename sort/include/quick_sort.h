/**
 * @author Ytalo Ramon
 * @date   10/11/2021
 */

#include "sort.h"

/**
 * Sort array with classification Bubble Sort.
 * @param arr source array.
 * @param n_member member number.
 * @param size_m size of each member.
 * @param comparator Function comparator.
 */
void quick_sort(void *arr, size_t n_member, size_t size_m, ICOMPARATOR);

size_t quick_partition(void *arr, size_t e, size_t size_m, ICOMPARATOR);
