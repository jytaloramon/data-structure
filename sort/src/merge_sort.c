/**
 * @author Ytalo Ramon
 * @date   11/11/2021
 */

#include "../include/merge_sort.h"
#include "stdlib.h"
#include "string.h"

void merge_sort(void *arr, size_t n_member, size_t size_m, ICOMPARATOR) {

    if (n_member <= 1)
        return;

    size_t middle = CALMIDDLE(n_member);

    merge_sort(arr, middle, size_m, comparator);
    merge_sort(((char *)arr) + SHIFTBYTEIDXSIZEM(middle, size_m),
               n_member - middle, size_m, comparator);

    merge_partition(arr, n_member, size_m, comparator);
}

void merge_partition(void *arr, size_t n_member, size_t size_m, ICOMPARATOR) {

    char *arr_c = (char *)arr, *arr_a = malloc(n_member * size_m), *temp;
    size_t middle = CALMIDDLE(n_member), i = 0, j = middle, t = 0;

    while (i < middle && j < n_member) {

        temp = (comparator(arr_c + SHIFTBYTEIDXSIZEM(i, size_m),
                           arr_c + SHIFTBYTEIDXSIZEM(j, size_m)) <= 0
                    ? arr_c + SHIFTBYTEIDXSIZEM(i++, size_m)
                    : arr_c + SHIFTBYTEIDXSIZEM(j++, size_m));

        memcpy(arr_a + SHIFTBYTEIDXSIZEM(t++, size_m), temp, size_m);
    }

    while (i < middle) {
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
