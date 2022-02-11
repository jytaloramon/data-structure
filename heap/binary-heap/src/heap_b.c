/**
 * @author Ytalo Ramon
 * @date   09/08/2021
 */

#include "../include/heap_b.h"
#include "../../../includes/itree_array.h"
#include "stdlib.h"

#define HPSWAPPOINTER(s, t)                                                      \
    do {                                                                       \
        void *aux = s;                                                         \
        s = t;                                                                 \
        t = aux;                                                               \
    } while (0);

HeapB *heapb_new(HeapBItem **arr, size_t length, size_t size) {

    HeapB *heap = malloc(sizeof(HeapB));

    if (heap) {
        heap->arr = arr;
        heap->lenght = length;
        heap->size = size;
    }

    return heap;
}

int heapb_build(HeapB *heap, ICOMPARATOR) {

    if (heap->lenght < 2)
        return 1;

    for (int i = FATHER(heap->lenght - 1); i >= 0; --i)
        heapb_heapify_down(heap->arr, i, heap->lenght, comparator);

    return 1;
}

int heapb_is_empty(HeapB *heap) { return heap->lenght == 0; }

int heapb_is_full(HeapB *heap) { return heap->lenght == heap->size; }

size_t heapb_heapify_up(HeapBItem **arr, size_t posi, ICOMPARATOR) {

    int i = posi, f = FATHER(i);

    while (i > 0 && comparator(arr[i], arr[f]) > 0) {
        HPSWAPPOINTER(arr[f], arr[i]);
        i = f;
        f = FATHER(f);
    }

    return i;
}

size_t heapb_heapify_down(HeapBItem **arr, size_t posi, size_t length,
                          ICOMPARATOR) {

    int i = posi, idx_min_child = 0;

    while ((idx_min_child = CHILDLEFT(i)) < length) {

        if (CHILDRIGHT(i) < length &&
            comparator(arr[CHILDLEFT(i)], arr[CHILDRIGHT(i)]) < 0) {
            idx_min_child = CHILDRIGHT(i);
        }

        if (comparator(arr[idx_min_child], arr[i]) <= 0)
            return i;

        HPSWAPPOINTER(arr[idx_min_child], arr[i]);
        i = idx_min_child;
    }

    return FATHER(i);
}

int heapb_insert(HeapB *heap, HeapBItem *new_item, ICOMPARATOR) {

    if (heapb_is_full(heap) || !new_item)
        return 0;

    heap->arr[heap->lenght++] = new_item;
    heapb_heapify_up(heap->arr, heap->lenght - 1, comparator);

    return 1;
}

HeapBItem *heapb_remove(HeapB *heap, ICOMPARATOR) {

    if (heapb_is_empty(heap))
        return NULL;

    HeapBItem *item_rm = heap->arr[0];

    heap->arr[0] = heap->arr[--heap->lenght];
    heapb_heapify_down(heap->arr, 0, heap->lenght, comparator);

    return item_rm;
}

HeapBItem *heapb_peek(HeapB *heap) {

    if (heapb_is_empty(heap))
        return NULL;

    return heap->arr[0];
}
