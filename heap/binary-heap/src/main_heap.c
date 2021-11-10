/**
 * @author Ytalo Ramon
 * @date   09/08/2021
 */

#include "stdio.h"
#include "stdlib.h"
#include "../include/heap.h"

#define SIZE 15

#define LENINIT 9

#define INPUTSIZE 23 // Input size for test.

enum options {
    INSERT,
    REMOVE,
    PEEK,
};

int comp(void *const a, void *const b);

void show_arr(ItemHeap **const arr, size_t length);

int main(int argc, char const *argv[]) {

    int test_cases[INPUTSIZE][2] = {
        {PEEK, 0},     {REMOVE, 0},  {INSERT, -1}, {INSERT, 100}, {PEEK, 0},
        {REMOVE, 200}, {INSERT, 20}, {REMOVE, 0},  {REMOVE, 0},   {REMOVE, 0},
        {REMOVE, 0},   {REMOVE, 0},  {REMOVE, 0},  {REMOVE, 0},   {REMOVE, 0},
        {REMOVE, 0},   {REMOVE, 0},  {REMOVE, 0},  {INSERT, 1},   {INSERT, 8},
        {PEEK, 0},     {INSERT, 10}, {REMOVE, 0}};

    int op, rs, array_init[LENINIT] = {27, 17, 3, 16, 13, 10, 1, 8, 9};

    ItemHeap *item_heap = NULL, *heap_array[SIZE];

    // heap_array initialization
    for (int i = 0; i < LENINIT; i++) {
        ItemHeap *item = malloc(sizeof(ItemHeap));
        item->key = &array_init[i];
        heap_array[i] = item;
    }

    printf("+++++ HEAP +++++\n\n");

    Heap *heap = heap_new(heap_array, LENINIT, SIZE);

    if (!heap) {
        printf("Memory allocation error!\n");
        exit(0);
    }

    heap_build(heap, comp);
    show_arr(heap->arr, heap->lenght);

    for (int i = 0; i < INPUTSIZE; i++) {
        op = test_cases[i][0];
        switch (op) {
        case INSERT:
            printf(" * INSERT: %d", test_cases[i][1]);

            item_heap = malloc(sizeof(ItemHeap));
            item_heap->key = &test_cases[i][1];

            rs = heap_insert(heap, item_heap, comp);
            rs != -1 ? printf("  -> Ok!\n") : printf("  -> Fail!\n");
            show_arr(heap->arr, heap->lenght);
            break;
        case REMOVE:
            printf(" * REMOVE: ");
            item_heap = heap_remove(heap, comp);
            item_heap ? printf("%d\n", *((int *)item_heap->key))
                      : printf("Fail!\n");
            show_arr(heap->arr, heap->lenght);
            break;
        case PEEK:
            printf(" * PEEK: ");
            item_heap = heap_peek(heap);
            item_heap ? printf("%d\n", *((int *)item_heap->key))
                      : printf("Empty!\n");
            break;
        default:
            printf(" * Option ERROR:\n");
        }

        item_heap = NULL;
    }

    return 0;
}

int comp(void *const a, void *const b) { return *((int *)a) - *((int *)b); }

void show_arr(ItemHeap **const arr, size_t length) {

    printf("\nStatus (HEAP):\n    ");
    for (size_t i = 0; i < length; i++)
        printf(" %d |", *((int *)arr[i]->key));
    printf("\n\n");
}
