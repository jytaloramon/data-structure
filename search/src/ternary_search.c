/**
 * @author: Ytalo Ramon
 * @date:   24/07/2021
 */

#include "stdlib.h"
#include "../include/nsearch.h"

#define CALSEGMENT(v) ((v) / 3)


void *nsearch(void *v_key, void *arr, int size_m, int s_i, int e_i,
              ICOMPARATOR) {

    int seg, rs_1 = 0, rs_2;
    char *arr_t = arr;

    while (s_i != e_i) {
        seg = CALSEGMENT(e_i - s_i - 1);

        rs_1 = comparator(v_key, arr_t + size_m * (s_i + seg));
        if (rs_1 == 0)
            return arr_t + size_m * (s_i + seg);

        rs_2 = comparator(v_key, arr_t + size_m * (s_i + seg * 2));
        if (rs_2 == 0)
            return arr_t + size_m * (s_i + seg * 2);

        if (rs_1 < 0)
            e_i = s_i + seg;
        else if (rs_2 > 0)
            s_i = s_i + seg * 2 + 1;
        else {
            s_i = s_i + seg + 1;
            e_i = s_i + seg * 2 - 1;
        }
    }

    return NULL;
}

// 0 1 2 3 4 5 6 7
// 2
//
//