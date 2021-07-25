/**
 * @author: Ytalo Ramon
 * @date:   24/07/2021
 */

#include "stdlib.h"
#include "../include/nsearch.h"

#define CALMIDDLE(v) ((v) / 2)


void *nsearch(void *v_key, void *arr, int size_m, int s_i, int e_i,
              ICOMPARATOR) {

    int middle = 0, rs = 0;
    char *arr_t = arr;

    while (s_i != e_i) {
        middle = CALMIDDLE(s_i + e_i - 1);
        rs = comparator(v_key, arr_t + (size_m * middle));

        if (rs == 0)
            return arr_t + (size_m * middle);
        
        if (rs < 0)
            e_i = middle;
        else
            s_i = middle + 1;
    }

    return NULL;
}