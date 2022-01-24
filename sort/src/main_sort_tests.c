/**
 * @author Ytalo Ramon
 * @date   10/11/2021
 */

#include "../include/insertion_sort.h"
#include "../include/merge_sort.h"
#include "../include/tim_sort.h"
#include "stdio.h"
#include "stdlib.h"
#include "string.h"
#include "time.h"

// Necessary to configure within the sort functions using external.
unsigned long long int count_comp = 0;

#define BUFFER 31 << 26
#define SIZE 211
#define LEN_DATASET 16

typedef struct _Dataset {
    size_t size;
    long long int *arr;
} Dataset;

char *read_dataset(char *name);

Dataset *text_to_dataset(char *text);

int comp(void *const a, void *const b);

int check_arr_is_sorted(long long int *arr, size_t size);

void arr_int_show(long long int *arr, size_t lenght);

int main(int argc, char const *argv[]) {

    printf("+++++ TIM SORT +++++\n\n");

    char dataset_type[LEN_DATASET][128] = {
        "./dataset/desc_10000.txt",      "./dataset/asc_10000.txt",
        "./dataset/random_10000.txt",    "./dataset/sectioned_10000.txt",
        "./dataset/desc_100000.txt",     "./dataset/asc_100000.txt",
        "./dataset/random_100000.txt",   "./dataset/sectioned_100000.txt",
        "./dataset/desc_1000000.txt",    "./dataset/asc_1000000.txt",
        "./dataset/random_1000000.txt",  "./dataset/sectioned_1000000.txt",
        "./dataset/desc_10000000.txt",   "./dataset/asc_10000000.txt",
        "./dataset/random_10000000.txt", "./dataset/sectioned_10000000.txt"};

    for (size_t i = 0; i < LEN_DATASET; ++i) {

        char *text_file = read_dataset(dataset_type[i]);
        Dataset *dt = text_to_dataset(text_file);
        free(text_file);

        count_comp = 0;
        clock_t t_s = clock();

        tim_sort(dt->arr, dt->size, sizeof(long long int), comp);
        // merge_sort(dt->arr, dt->size, sizeof(long long int), comp);
        // insertion_sort(dt->arr, dt->size, sizeof(long long int), comp);

        clock_t t_e = clock();

        printf("Conf:%s\n  - Check: %s; count: %llu; Time: %lf\n\n",
               dataset_type[i],
               check_arr_is_sorted(dt->arr, dt->size) ? "Ok" : "Invalid",
               count_comp, ((double)t_e - t_s) / CLOCKS_PER_SEC);

        free(dt->arr);
        free(dt);
    }

    return 0;
}

char *read_dataset(char *name) {

    FILE *fl = fopen(name, "r");
    char *text = malloc(BUFFER), c;
    int i = 0;

    while ((c = fgetc(fl)) != EOF)
        text[i++] = c;

    text[i] = '\n';
    fclose(fl);

    return text;
}

Dataset *text_to_dataset(char *text) {

    char *tk = strtok(text, "\n");
    int size = atoi(tk), i = 0;
    long long int *arr = malloc(sizeof(long long int) * size);

    while ((tk = strtok(NULL, " ")))
        arr[i++] = atoll(tk);

    Dataset *dt = malloc(sizeof(Dataset));
    dt->size = size;
    dt->arr = arr;

    return dt;
}

int comp(void *const a, void *const b) {
    int v = *((int *)a), u = *((int *)b);
    return v - u;
}

int check_arr_is_sorted(long long int *arr, size_t size) {

    if (size <= 1)
        return 1;

    for (size_t i = 1; i < size; ++i)
        if (arr[i] < arr[i - 1])
            return 0;

    return 1;
}

void arr_int_show(long long int *arr, size_t lenght) {

    for (size_t i = 0; i < lenght; ++i)
        printf("%lld, ", arr[i]);

    printf("\n\n");
}