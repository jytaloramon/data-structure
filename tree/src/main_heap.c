#include "stdio.h"
#include "stdlib.h"
#include "string.h"
#include "../include/heap.h"

#define SIZE 15

int comp(void *const a, void *const b);

void show_arr(int *const arr, size_t length);

int main(int argc, char const *argv[]){

    int array[SIZE] = {27, 17, 3, 16, 13, 10, 1, 5, 7, 12, 4, 8, 9, 0},
        value, *ps;

    size_t length = 14;
   
    show_arr(array, length);
    build_heap(array, length, sizeof(int), comp);
    show_arr(array, length);

    ps = (int *) peek(array, length);
    printf("Top: %d\n\n", *ps);

    ps = (int *) remove_heap(array, length, sizeof(int), comp);
    printf("Removed: %d\n\n", *ps);
    free(ps); ps = NULL;
    length--;
    show_arr(array, length);

    value = 39;
    printf("Insertion: %d\n\n", value);
    insert_heap(&value, array, length, sizeof(int), comp);
    length++;
    show_arr(array, length);

    ps = (int *) peek(array, length);
    printf("Top: %d\n\n", *ps);

    value = 24;
    printf("Insertion: %d\n\n", value);
    insert_heap(&value, array, length, sizeof(int), comp);
    length++;
    show_arr(array, length);

    return 0;
}

int comp(void *const a, void *const b){
    return *((int *) a) - *((int *) b);
}

void show_arr(int *const arr, size_t length){
    printf("Status (HEAP):\n    ");
    
    for (size_t i = 0; i < length; i++)
        printf(" %d |", arr[i]);
    printf("\n\n");
}
