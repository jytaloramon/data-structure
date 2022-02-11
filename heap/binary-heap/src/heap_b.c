/**
 * @author Ytalo Ramon
 * @date   09/08/2021
 */

#include "stdlib.h"
#include "../include/heap_b.h"

#define SWAPPOINTER(s, t)                                                      \
    do {                                                                       \
        void *aux = s;                                                         \
        s = t;                                                                 \
        t = aux;                                                               \
    } while (0);

Heap *heapb_new(ItemHeap **arr, int length, int size) {

    Heap *heap = malloc(sizeof(Heap));

    if (!heap)
        return NULL;

    heap->arr = arr;
    heap->lenght = length;
    heap->size = size;

    return heap;
}

int heapb_build(Heap *heap, ICOMPARATOR) {

    if (heap->lenght < 2)
        return 1;

    for (int i = FATHER(heap->lenght - 1); i >= 0; i--)
        heapb_heapify_down(i, heap->arr, heap->lenght, comparator);

    return 1;
}

int heapb_is_empty(Heap *heap) { return heap->lenght == 0; }

int heapb_is_full(Heap *heap) { return heap->lenght == heap->size; }

int heapb_heapify_up(int posi, ItemHeap **arr, ICOMPARATOR) {

    int i = posi, f = FATHER(i);

    while (i > 0 && comparator(arr[i]->key, arr[f]->key) > 0) {
        SWAPPOINTER(arr[f], arr[i]);
        i = f;
        f = FATHER(i);
    }

    return i;
}

int heapb_heapify_down(int posi, ItemHeap **arr, int length, ICOMPARATOR) {

    int i = posi, idx_min_child = 0;

    while ((idx_min_child = CHILDLEFT(i)) < length) {

        if (CHILDRIGHT(i) < length) {
            idx_min_child =
                comparator(arr[CHILDLEFT(i)]->key, arr[CHILDRIGHT(i)]->key) >= 0
                    ? CHILDLEFT(i)
                    : CHILDRIGHT(i);
        }

        if (comparator(arr[idx_min_child]->key, arr[i]->key) <= 0)
            return i;

        SWAPPOINTER(arr[idx_min_child], arr[i]);
        i = idx_min_child;
    }

    return FATHER(i);
}

int heapb_insert(Heap *heap, ItemHeap *item, ICOMPARATOR) {

    if (heapb_is_full(heap) || !item)
        return -1;

    heap->arr[heap->lenght++] = item;

    return heapb_heapify_up(heap->lenght - 1, heap->arr, comparator);
}

ItemHeap *heapb_remove(Heap *heap, ICOMPARATOR) {

    if (heapb_is_empty(heap))
        return NULL;

    void *elmnt = heap->arr[0];
    heap->arr[0] = heap->arr[--heap->lenght];
    heapb_heapify_down(0, heap->arr, heap->lenght, comparator);

    return elmnt;
}

ItemHeap *heapb_peek(Heap *heap) {

    if (heapb_is_empty(heap))
        return NULL;

    return heap->arr[0];
}
