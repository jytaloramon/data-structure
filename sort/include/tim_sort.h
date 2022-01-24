/**
 * @author Ytalo Ramon
 * @date   22/01/2022
 */

#include "sort.h"

/**
 * Sort array with classification tIM Sort.
 * 
 * @param arr Source array.
 * @param n_member Member of numbers.
 * @param size_m Size of each member.
 * @param comparator Function comparator.
 */
void tim_sort(void *arr, size_t n_member, size_t size_m, ICOMPARATOR);

/**
 * Calculates the length of runs.
 * 
 * @param n_member Member of numbers.
 * @param min_merger_param Minrun paramater. Recomendado 32 or 64.
 * @return size_t 
 */
size_t tim_cal_run_length(size_t n_member, size_t min_merger_param);
