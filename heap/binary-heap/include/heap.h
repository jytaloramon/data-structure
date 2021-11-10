/**
 * @author Ytalo Ramon
 * @date   09/08/2021
 */

#include "../../../includes/icomparator.h"
#include "../../../includes/itree_array.h"

typedef struct _Heap Heap;

typedef struct _ItemHeap ItemHeap;

struct _ItemHeap {
    void *key;
};

struct _Heap {
    struct _ItemHeap **arr;
    int lenght, size;
};

/**
 * Create a new Heap structure.
 * @param arr heap, array of pointers to items.
 * @param length number of items in array.
 * @param size maximum array capacity.
 * @return A Heap instance or Null in case of error.
 */
Heap *heap_new(ItemHeap **arr, int length, int size);

/**
 * Build a heap.
 * @param heap Heap instance.
 * @param comparator Function comparator.
 * @return Or 1 on success, or 0 on failure.
 */
int heap_build(Heap *heap, ICOMPARATOR);

/**
 * Checks if the heap is empty.
 * @param heap Heap instance.
 * @return Or 1 if empty or 0 if not empty.
 */
int heap_is_empty(Heap *heap);

/**
 * Checks if the heap is full.
 * @param heap Heap instance.
 * @return Or 1 if full or 0 if not full.
 */
int heap_is_full(Heap *heap);

/**
 * Heapify bottom-up
 * @param posi Position of the reference element in the array, start of heapify.
 * @param arr heap, array of pointers to items.
 * @param comparator Function comparator.
 * @return Final position of the process.
 */
int heapify_up(int posi, ItemHeap **arr, ICOMPARATOR);

/**
 * Heapify top-down.
 * @param posi Position of the reference element in the array, start of heapify.
 * @param arr heap, array of pointers to items.
 * @param length Length of array.
 * @param comparator Function comparator.
 * @return Final position of the process.
 */
int heapify_down(int posi, ItemHeap **arr, int length, ICOMPARATOR);

/**
 * Insert a new element.
 * @param heap Heap instance.
 * @param item Element Heap for insertion.
 * @param comparator Function comparator.
 * @return Or 1 on success, or 0 on failure.
 */
int heap_insert(Heap *heap, ItemHeap *item, ICOMPARATOR);

/**
 * Remove the top heap element.
 * @param heap Heap instance.
 * @param comparator Function comparator.
 * @return Or the instance removed, or NULL on failure.
 */
ItemHeap *heap_remove(Heap *heap, ICOMPARATOR);

/**
 * Return the top heap element
 * @param heap Heap instance.
 * @return Or the instance of the first element, or NULL on failure.
 */
ItemHeap *heap_peek(Heap *heap);
