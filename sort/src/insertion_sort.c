/**
 * @author Ytalo Ramon
 * @date   11/11/2021
 */

#include "../include/insertion_sort.h"
#include "stdlib.h"
#include "string.h"

void insertion_sort(void *arr, size_t n_member, size_t size_m, ICOMPARATOR) {

    char *arr_c = (char *)arr, *temp = malloc(size_m);

    for (size_t i = 1, j = 0; i < n_member; ++i) {
        memcpy(temp, arr_c + SHIFTBYTEIDXSIZEM(i, size_m), size_m);
        
        j = i;
        while (j > 0 &&
               comparator(arr_c + SHIFTBYTEIDXSIZEM(j - 1, size_m), temp) > 0) {
            memcpy(arr_c + SHIFTBYTEIDXSIZEM(j, size_m),
                   arr_c + SHIFTBYTEIDXSIZEM(j - 1, size_m), size_m);
            j--;
        }

        memcpy(arr_c + SHIFTBYTEIDXSIZEM(j, size_m), temp, size_m);
    }

    free(temp);
}
