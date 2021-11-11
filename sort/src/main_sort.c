/**
 * @author Ytalo Ramon
 * @date   10/11/2021
 */

#include "../include/bubble_sort.h"
#include "../include/quick_sort.h"
#include "stdio.h"
#include "stdlib.h"

#define SIZE 9

int comp(void *const a, void *const b);

void arr_int_show(int *arr, size_t lenght);

int main(int argc, char const *argv[]) {

    int arr[SIZE] = {9, -3, 5, 2, 6, 8, -6, 1, 3};

    printf("+++++ SORT +++++\n\n");

    printf("Source: ");
    arr_int_show(arr, SIZE);

    // printf("@@ BUBBLE SORT\n");
    // bubble_sort(arr, 9, sizeof(int), comp);

    printf("@@ QUICK SORT\n");
    quick_sort(arr, SIZE, sizeof(int), comp);

    printf("Final: ");
    arr_int_show(arr, SIZE);

    return 0;
}

int comp(void *const a, void *const b) {
    int v = *((int *)a), u = *((int *)b);
    return v - u;
}

void arr_int_show(int *arr, size_t lenght) {

    for (size_t i = 0; i < lenght; ++i)
        printf("%d, ", arr[i]);

    printf("\n\n");
}