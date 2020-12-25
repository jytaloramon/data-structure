/**
 * @author: Ytalo Ramon 
 * @date: 04/12/2020
 * 
 */

#include "./sort.h"

/**
 * Bubble sort.
 * @param data void pointer const.
 * @param length int.
 * @param size_type int.
 * @param FUNC_COMPARATOR_SORT function: (int)(*)(void *const, void *const).
 */
void b_sort(void *const data, int length, int size_type, FUNC_COMPARATOR_SORT){
    if (length <= 0)
        return;

    char *data_aux = (char *) data, *value1, *value2;

    for (int i = 0; i < length; i++){
        for (int j = 0; j < length - (i + 1); j++){
            value1 = &data_aux[j * size_type];
            value2 = &data_aux[(j + 1) * size_type];

            if (func_comparator_sort(value1, value2) >= 0){
                SWAP(value1, value2, size_type);
            }
        }
    }
}