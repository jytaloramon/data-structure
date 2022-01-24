/**
 * @author Ytalo Ramon
 * @date   22/01/2022
 */

#include "../include/tim_sort.h"
#include "../../math/include/arithmetic.h"
#include "../include/insertion_sort.h"
#include "../include/merge_sort.h"
#include "stdlib.h"

#define TIM_MIN_PARAM 32

void tim_sort(void *arr, size_t n_member, size_t size_m, ICOMPARATOR) {

    if (n_member <= 1)
        return;

    char *arr_aux = malloc(n_member * size_m);

    if (!arr_aux)
        return;

    char *arr_c = arr;
    size_t run_length = tim_cal_run_length(n_member, TIM_MIN_PARAM);

    for (size_t i = 0, len_seq = 0; i < n_member; i += run_length) {
        len_seq = min(run_length, n_member - i);
        insertion_sort(arr_c + SHIFTBYTEIDXSIZEM(i, size_m), len_seq, size_m,
                       comparator);
    }

    for (size_t pass_len = run_length; pass_len < n_member; pass_len <<= 1) {

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

size_t tim_cal_run_length(size_t n_member, size_t min_merger_param) {

    size_t n = n_member, r = 0;
    for (; n >= min_merger_param; r |= (n & 1), n >>= 1)
        ;

    return n + r;
}
