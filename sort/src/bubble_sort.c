/**
 * @author Ytalo Ramon
 * @date   10/11/2021
 */

#include "../include/bubble_sort.h"

void bubble_sort(void *arr, size_t n_member, size_t size_m, ICOMPARATOR) {

    char *arr_c = (char *)arr;
    size_t a = 0, b = 0;

    for (size_t i = 0; i < n_member - 1; ++i) {
        for (size_t j = 0; j < n_member - (i + 1); ++j) {
            a = SHIFTBYTEIDXSIZEM(j, size_m);
            b = SHIFTBYTEIDXSIZEM(j + 1, size_m);

            if (comparator(&arr_c[a], &arr_c[b]) > 0)
                SWAPVARIABLE(&arr_c[a], &arr_c[b], size_m);
        }
    }
}
