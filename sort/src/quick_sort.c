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

    char v;
    scanf("%c", &v);
    size_t pivot_f = quick_partition(arr, n_member, size_m, comparator);
    printf("%lu - %lu\n", pivot_f, n_member);
    quick_sort(arr, pivot_f, size_m, comparator);
    quick_sort(((char *)arr) + SHIFTBYTEIDXSIZEM(pivot_f + 1, size_m),
               n_member - pivot_f, size_m, comparator);
}

size_t quick_partition(void *arr, size_t e, size_t size_m, ICOMPARATOR) {

    char *arr_c = (char *)arr;
    size_t i = 1, j = e - 1;
}
