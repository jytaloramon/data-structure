/**
 * @author Ytalo Ramon
 * @date   09/08/2021
 */

#include "../../../includes/istructure_utils.h"
#include "../include/heap_b.h"
#include "stdio.h"
#include "stdlib.h"

#define SIZE 15

#define LENINIT 9

#define INPUTSIZE 23 // Input size for test.

enum options {
    INSERT,
    REMOVE,
    PEEK,
};

typedef struct _Cel {
    int value;
    struct _HeapBItem heap_item;
} Cel;

int comp_item_item(void *const a, void *const b);

void heapb_show(HeapB *heap);

int main(int argc, char const *argv[]) {

    int test_cases[INPUTSIZE][2] = {
        {PEEK, 0},     {REMOVE, 0},  {INSERT, -1}, {INSERT, 100}, {PEEK, 0},
        {REMOVE, 200}, {INSERT, 20}, {REMOVE, 0},  {REMOVE, 0},   {REMOVE, 0},
        {REMOVE, 0},   {REMOVE, 0},  {REMOVE, 0},  {REMOVE, 0},   {REMOVE, 0},
        {REMOVE, 0},   {REMOVE, 0},  {REMOVE, 0},  {INSERT, 1},   {INSERT, 8},
        {PEEK, 0},     {INSERT, 10}, {REMOVE, 0}};

    int op = 0, v_a = 0, rs = 0,
        array_init[LENINIT] = {27, 17, 3, 16, 13, 10, 1, 8, 9};
    HeapBItem *item_heap_aux = NULL, *heap_arr[SIZE];
    Cel *cel_aux = NULL;

    // heap_array initialization
    for (int i = 0; i < LENINIT; i++) {
        cel_aux = malloc(sizeof(Cel));
        cel_aux->value = array_init[i];
        heap_arr[i] = &cel_aux->heap_item;
    }

    printf("+++++ BINARY HEAP +++++\n\n");

    HeapB *heap = heapb_new(heap_arr, LENINIT, SIZE);
    heapb_build(heap, comp_item_item);

    heapb_show(heap);

    for (size_t i = 0; i < INPUTSIZE; ++i) {
        op = test_cases[i][0];
        v_a = test_cases[i][1];

        switch (op) {
        case INSERT:
            printf("@ INSERT (%d): ", v_a);

            cel_aux = malloc(sizeof(Cel));
            cel_aux->value = v_a;

            rs = heapb_insert(heap, &cel_aux->heap_item, comp_item_item);
            rs != -1 ? printf("Success!\n") : printf("Fail!\n");

            heapb_show(heap);
            break;
        case REMOVE:
            printf("@ REMOVE: ");

            item_heap_aux = heapb_remove(heap, comp_item_item);

            if (!item_heap_aux) {
                printf("Fail!\n");
            } else {
                printf("%d\n",
                       ((Cel *)GETSTRUCTFROM(item_heap_aux, Cel, heap_item))
                           ->value);
            }

            heapb_show(heap);
            break;
        case PEEK:
            printf("@ PEEK: ");

            item_heap_aux = heapb_peek(heap);

            if (!item_heap_aux) {
                printf("Empty!\n");
            } else {
                printf("%d\n",
                       ((Cel *)GETSTRUCTFROM(item_heap_aux, Cel, heap_item))
                           ->value);
            }

            break;
        default:
            printf("NOT AN OPTION\n");
        }
        printf("\n\n");
    }

    return 0;
}

int comp_item_item(void *const a, void *const b) {

    Cel *c_a = GETSTRUCTFROM(a, Cel, heap_item),
        *c_b = GETSTRUCTFROM(b, Cel, heap_item);

    return c_a->value - c_b->value;
}

void heapb_show(HeapB *heap) {

    printf("\nStatus\n");

    if (heapb_is_empty(heap)) {
        printf("Empty!\n");
    } else {
        for (size_t i = 0; i < heap->lenght; ++i) {
            printf(" %d |",
                   ((Cel *)GETSTRUCTFROM(heap->arr[i], Cel, heap_item))->value);
        }

        printf("\n");

        for (size_t i = 0; i < heap->lenght; ++i)
            printf("----");
        printf("\n[%lu/%lu]\n", heap->lenght, heap->size);
    }
}
