/**
 * @author Ytalo Ramon
 * @date   11/03/2021
*/

#include "stdio.h"
#include "stdlib.h"
#include "string.h"
#include "../include/heap.h"

size_t heapify_up(void *elmnt, size_t posi, void *arr, size_t length, size_t size_m, ICOMPARATOR){
    
    size_t i = posi, parent = PARENT(i);

    while (i > 0 && comparator(elmnt, arr + parent * size_m) > 0){
        memcpy(arr + i * size_m, arr + parent * size_m, size_m);
        i = parent;
        parent = PARENT(i);
    }
    
    return i;
}

size_t heapify_down(void *elmnt, size_t posi, void *arr, size_t length, size_t size_m, ICOMPARATOR){
    size_t i = posi,
        child_rigth,
        child_obj;

    while (i < length){
        child_obj = LEFT(i),
        child_rigth = RIGTH(i);

        if (child_obj >= length)
            return i;
        
        if (child_rigth < length 
            && !(comparator(arr + child_obj * size_m, arr + child_rigth * size_m) > 0))
            child_obj = child_rigth;

        if (comparator(elmnt, arr + child_obj * size_m) > 0)
            return PARENT(child_obj);
        
        memcpy(arr + i * size_m, arr + child_obj * size_m, size_m);
        i = child_obj;
    }
    
    return PARENT(i);
}

int heap_build(void *arr, size_t length, size_t size_m, ICOMPARATOR){
    if (length < 1 || size_m < 1)
        return 0;

    char *obj_aux = malloc(size_m);

    if (!obj_aux)
        return 0;

    for (int i = length - 1, idx_swap; i >= 0; i--){
        memcpy(obj_aux, arr + i * size_m, size_m);
        //idx_swap = heapify_up(obj_aux, i, arr, length, size_m, comparator);
        idx_swap = heapify_down(obj_aux, i, arr, length, size_m, comparator);

        if (idx_swap != i)
            memcpy(arr + idx_swap * size_m, obj_aux, size_m);
    }

    free(obj_aux);

    return 1;
}

int heap_insert(void *elmnt, void *arr, size_t length, size_t size_m, ICOMPARATOR){

    if (length < 0 || size_m < 1)
        return 0;

    size_t n_length = length + 1,
            idx_add = heapify_up(elmnt, length, arr, n_length, size_m, comparator);
    
    memcpy(arr + idx_add * size_m, elmnt, size_m);
    
    return 1;
}

void *heap_remove(void *arr,  size_t length, size_t size_m, ICOMPARATOR){
    if (length < 1 || size_m < 1)
        return 0;

    char *obj_aux = malloc(size_m);

    if (!obj_aux)
        return 0;

    memcpy(obj_aux, arr, size_m);
    size_t n_length = length - 1,
        idx_add = heapify_down(arr + n_length * size_m, 0, arr, n_length, size_m, comparator);

    memcpy(arr + idx_add * size_m, arr + n_length * size_m, size_m);
    memset(arr + n_length * size_m, 0, size_m);

    return obj_aux;
}

void *heap_peek(void *arr,  size_t length){
    if (length == 0)
        return 0;

    return arr;
}