/**
 * @author: Ytalo Ramon
 * @date:   24/07/2021
 */

#include "stdio.h"
#include "stdlib.h"
#include "../include/nsearch.h"

#define TITLE "BINARY or TERNARY"

#define LEN 10       // Length array
#define INPUTSIZE 15 // Input size for test.


int compare(void *const a, void *const b) { return *((int *)a) - *((int *)b); }

int main(int argc, char const *argv[]) {

    int test_cases[INPUTSIZE] = {5, 11, 14, 18, 20, -1, 10, 15,
                                 6, 7,  8,  21, 1,  4,  17};

    int value, *rs;
    int arr[LEN] = {-1, 4, 5, 6, 7, 10, 15, 17, 18, 20};

    printf("+++++ %s SEARCH +++++\n\n", TITLE);

    for (int i = 0; i < INPUTSIZE; ++i) {
        value = test_cases[i];
        rs = nsearch(&value, arr, sizeof(int), 0, LEN, &compare);

        printf(" * FIND (%d): %s\n", value, rs ? "FOUND" : "NOT FOUND");
    }

    return 0;
}
