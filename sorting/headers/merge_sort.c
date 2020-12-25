/**
 * @author: Ytalo Ramon 
 * @date: 21/12/2020
 * 
 */

#include "stdlib.h"
#include "string.h"
#include "./sort.h"

/**
 * Merge sort.
 * @param data void pointer const.
 * @param length int.
 * @param size_type int.
 * @param FUNC_COMPARATOR_SORT function: (int)(*)(void *const, void *const).
 */
void m_sort(void *const data, int length, int size_type, FUNC_COMPARATOR_SORT){
    char *data_aux = (char *) data, *value2;
    void *value_key = malloc(size_type);

    for (int i = 1, j; i < length; i++){
        memcpy(value_key, &data_aux[i * size_type], size_type);

        value2 = &data_aux[(i - 1) * size_type];
        for(j = i - 1; j >= 0 && func_comparator_sort(value_key, value2) < 0; j--){
            memcpy(&data_aux[(j + 1) * size_type], value2, size_type);
            value2 = &data_aux[(j - 1) * size_type];
        }

        memcpy(&data_aux[(j + 1) * size_type], value_key, size_type);
    }
}