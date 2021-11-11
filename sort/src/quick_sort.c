/**
 * @author Ytalo Ramon
 * @date   10/11/2021
 */

#include "../include/quick_sort.h"
#include "stdlib.h"
#include "string.h"

void quick_sort(void *arr, size_t n_member, size_t size_m, ICOMPARATOR) {

    if (n_member <= 1)
        return;

    size_t pivot_f = quick_partition(arr, n_member, size_m, comparator);

    quick_sort(arr, pivot_f, size_m, comparator);
    quick_sort(((char *)arr) + SHIFTBYTEIDXSIZEM(pivot_f + 1, size_m),
               n_member - pivot_f - 1, size_m, comparator);
}

size_t quick_partition(void *arr, size_t e, size_t size_m, ICOMPARATOR) {

    char *arr_c = (char *)arr;
    size_t i = 1, j = e - 1;

    while (i < j) {

        while (i < j && comparator(&arr_c[SHIFTBYTEIDXSIZEM(i, size_m)],
                                   &arr_c[0]) <= 0) {
            i++;
        }

        while (comparator(&arr_c[SHIFTBYTEIDXSIZEM(j, size_m)], &arr_c[0]) >
               0) {
            j--;
        }

        if (i < j) {
            SWAPVARIABLE(&arr_c[SHIFTBYTEIDXSIZEM(i, size_m)],
                         &arr_c[SHIFTBYTEIDXSIZEM(j, size_m)], size_m);
        }
    }

    if (comparator(&arr_c[SHIFTBYTEIDXSIZEM(j, size_m)], &arr_c[0]) < 0)
        SWAPVARIABLE(&arr_c[0], &arr_c[SHIFTBYTEIDXSIZEM(j, size_m)], size_m);

    return j;
}
