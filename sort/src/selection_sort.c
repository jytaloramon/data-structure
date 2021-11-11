/**
 * @author Ytalo Ramon
 * @date   11/11/2021
 */

#include "../include/selection_sort.h"

void selection_sort(void *arr, size_t n_member, size_t size_m, ICOMPARATOR) {

    char *arr_c = (char *)arr;

    for (size_t i = 0, idx_min = 0; i < n_member; ++i) {
        idx_min = i;

        for (size_t j = i + 1; j < n_member; ++j) {
            if (comparator(arr_c + SHIFTBYTEIDXSIZEM(j, size_m),
                           arr_c + SHIFTBYTEIDXSIZEM(idx_min, size_m)) < 0) {
                idx_min = j;
            }
        }

        SWAPVARIABLE(arr_c + SHIFTBYTEIDXSIZEM(i, size_m),
                     arr_c + SHIFTBYTEIDXSIZEM(idx_min, size_m), size_m);
    }
}
