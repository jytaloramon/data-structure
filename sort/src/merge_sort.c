/**
 * @author Ytalo Ramon
 * @date   11/11/2021
 */

#include "../include/merge_sort.h"
#include "../../math/include/arithmetic.h"
#include "stdlib.h"
#include "string.h"

void merge_sort(void *arr, size_t n_member, size_t size_m, ICOMPARATOR) {

    if (n_member <= 1)
        return;

    char *arr_aux = malloc(n_member * size_m);

    if (!arr_aux)
        return;

    char *arr_c = arr;

    for (size_t pass_len = 1; pass_len < n_member; pass_len <<= 1) {
        for (size_t i = 0, r_s = 0, r_e = 0; i < n_member; i += r_e) {

            r_s = min(pass_len, n_member - i);
            r_e = min(pass_len * 2, n_member - i);
            if (r_s < r_e) {
                merge_partition(arr_c + SHIFTBYTEIDXSIZEM(i, size_m), r_s, r_e,
                                size_m, arr_aux, comparator);
            }
        }
    }

    free(arr_aux);
}

void merge_partition(void *arr, size_t right_s, size_t n_member, size_t size_m,
                     void *arr_aux, ICOMPARATOR) {

    char *arr_c = arr, *arr_a = arr_aux, *temp = NULL;
    size_t i = 0, j = right_s, t = 0;

    while (i < right_s && j < n_member) {

        temp = (comparator(arr_c + SHIFTBYTEIDXSIZEM(i, size_m),
                           arr_c + SHIFTBYTEIDXSIZEM(j, size_m)) <= 0
                    ? arr_c + SHIFTBYTEIDXSIZEM(i++, size_m)
                    : arr_c + SHIFTBYTEIDXSIZEM(j++, size_m));

        memcpy(arr_a + SHIFTBYTEIDXSIZEM(t++, size_m), temp, size_m);
    }

    while (i < right_s) {
        memcpy(arr_a + SHIFTBYTEIDXSIZEM(t++, size_m),
               arr_c + SHIFTBYTEIDXSIZEM(i++, size_m), size_m);
    }

    while (j < n_member) {
        memcpy(arr_a + SHIFTBYTEIDXSIZEM(t++, size_m),
               arr_c + SHIFTBYTEIDXSIZEM(j++, size_m), size_m);
    }

    for (size_t k = 0; k < t; k++) {
        memcpy(arr_c + SHIFTBYTEIDXSIZEM(k, size_m),
               arr_a + SHIFTBYTEIDXSIZEM(k, size_m), size_m);
    }
}
