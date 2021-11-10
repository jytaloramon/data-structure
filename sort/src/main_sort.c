/**
 * @author Ytalo Ramon
 * @date   10/11/2021
 */

#include "../include/bubble_sort.h"
#include "../include/quick_sort.h"
#include "stdio.h"
#include "stdlib.h"

int comp(void *const a, void *const b) {
    int v = *((int *)a), u = *((int *)b);
    return v - u;
}

int main(int argc, char const *argv[]) {

    int arr[] = {3, 2, 1};
    //bubble_sort(arr, 3, sizeof(int), comp);
    quick_sort(arr, 3, sizeof(int), comp);
    for (size_t i = 0; i < 3; i++) {
        printf("%d\n", arr[i]);
    }

    return 0;
}
