/**
 * @author Ytalo Ramon
 * @date   11/11/2021
 */

#include "sort.h"

/**
 * Sort array with classification Merge Sort.
 *
 * @param arr Source array.
 * @param n_member Member of numbers.
 * @param size_m Size of each member.
 * @param comparator Function comparator.
 */
void merge_sort(void *arr, size_t n_member, size_t size_m, ICOMPARATOR);

/**
 * Sort partition.
 *
 * @param arr Source array.
 * @param right_s Starting index of the right partition.
 * @param n_member Member of numbers.
 * @param size_m Size of each member.
 * @param arr_aux Temporary storage array.
 * @param comparator Function comparator.
 */
void merge_partition(void *arr, size_t right_s, size_t n_member, size_t size_m,
                     void *arr_aux, ICOMPARATOR);
