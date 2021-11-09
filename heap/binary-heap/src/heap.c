/**
 * @author Ytalo Ramon
 * @date   09/08/2021
 */

#include "../include/heap.h"
#include "stdlib.h"

#define SWAPPOINTER(s, t)                                                      \
    do {                                                                       \
        void *aux = s;                                                         \
        s = t;                                                                 \
        t = aux;                                                               \
    } while (0);

Heap *heap_new(void **arr, int length, int size) {

    Heap *heap = malloc(sizeof(Heap));

    if (!heap)
        return NULL;

    heap->arr = arr;
    heap->lenght = length;
    heap->size = size;

    return heap;
}

int heap_build(Heap *heap, ICOMPARATOR) {

    if (heap->lenght < 2)
        return 1;

    for (int i = FATHER(heap->lenght - 1); i >= 0; i--)
        heapify_down(i, heap->arr, heap->lenght, comparator);

    return 1;
}

int heap_is_empty(Heap *heap) { return heap->lenght == 0; }

int heap_is_full(Heap *heap) { return heap->lenght == heap->size; }

int heapify_up(int posi, void **arr, ICOMPARATOR) {

    int i = posi, f = FATHER(i);

    while (i > 0 && comparator(arr[i], arr[f]) > 0) {
        SWAPPOINTER(arr[f], arr[i]);
        i = f;
        f = FATHER(i);
    }

    return i;
}

int heapify_down(int posi, void **arr, int length, ICOMPARATOR) {

    int i = posi, idx_min_child = 0;

    while (CHILDLEFT(i) < length) {
        idx_min_child = CHILDLEFT(i);

        if (CHILDRIGHT(i) < length) {
            idx_min_child = comparator(arr[CHILDLEFT(i)], arr[CHILDRIGHT(i)]) >= 0
                            ? CHILDLEFT(i)
                            : CHILDRIGHT(i);
        }

        if (comparator(arr[idx_min_child], arr[i]) <= 0)
            return i;
       
        SWAPPOINTER(arr[idx_min_child], arr[i]);
        i = idx_min_child;
    }

    return FATHER(i);
}

int heap_insert(Heap *heap, void *elmnt, ICOMPARATOR) {

    if (heap_is_full(heap) || !elmnt)
        return -1;

    heap->arr[heap->lenght++] = elmnt;

    return heapify_up(heap->lenght - 1, heap->arr, comparator);
}

void *heap_remove(Heap *heap, ICOMPARATOR) {

    if (heap_is_empty(heap))
        return NULL;

    void *elmnt = heap->arr[0];
    heap->arr[0] = heap->arr[--heap->lenght];
    heapify_down(0, heap->arr, heap->lenght, comparator);

    return elmnt;
}

void *heap_peek(Heap *heap) {

    if (heap_is_empty(heap))
        return NULL;

    return heap->arr[0];
}