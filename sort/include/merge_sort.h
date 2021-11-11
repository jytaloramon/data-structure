/**
 * @author Ytalo Ramon
 * @date   11/11/2021
 */

#include "sort.h"

#define CALMIDDLE(v) ((v) / 2)

/**
 * Sort array with classification Bubble Sort.
 * @param arr source array.
 * @param n_member member number.
 * @param size_m size of each member.
 * @param comparator Function comparator.
 */
void merge_sort(void *arr, size_t n_member, size_t size_m, ICOMPARATOR);

/**
 * Sort partition.
 * @param arr source array.
 * @param n_member member number.
 * @param size_m size of each member.
 * @param comparator Function comparator.
 */
void merge_partition(void *arr, size_t n_member, size_t size_m, ICOMPARATOR);
