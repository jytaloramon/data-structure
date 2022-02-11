/**
 * @author Ytalo Ramon
 * @date   09/08/2021
 */

#include "../../../includes/icomparator.h"
#include "stdlib.h"

typedef struct _HeapB HeapB;

typedef struct _HeapBItem HeapBItem;

struct _HeapBItem {
    char padding;
};

struct _HeapB {
    struct _HeapBItem **arr;
    size_t lenght, size;
};

/**
 * Create a new Binary Heap (HeapB) Structure.
 *
 * @param arr heap array, array of pointers HeapBItem.
 * @param length number of items in array.
 * @param size maximum array capacity.
 * @return A Heap instance or Null in case of error.
 */
HeapB *heapb_new(HeapBItem **arr, size_t length, size_t size);

/**
 * Build a heap.
 *
 * @param heap HeapB instance.
 * @param comparator Comparison function.
 *  Input in comparator(HeapBItem, HeapBItem).
 * @return Or 1 on success or 0 on failure.
 */
int heapb_build(HeapB *heap, ICOMPARATOR);

/**
 * Checks if the heap is empty.
 *
 * @param heap HeapB instance.
 * @return Or 1 if empty or 0 if not empty.
 */
int heapb_is_empty(HeapB *heap);

/**
 * Checks if the heap is full.
 *
 * @param heap HeapB instance.
 * @return Or 1 if full or 0 if not full.
 */
int heapb_is_full(HeapB *heap);

/**
 * Heapify bottom-up.
 *
 * @param arr heap array, array of pointers HeapBItem.
 * @param posi Position of the reference element in the array, start of heapify.
 * @param comparator Comparison function.
 *  Input in comparator(HeapBItem, HeapBItem).
 * @return Final item position.
 */
size_t heapb_heapify_up(HeapBItem **arr, size_t posi, ICOMPARATOR);

/**
 * Heapify top-down.
 *
 * @param arr heap array, array of pointers HeapBItem.
 * @param posi Position of the reference element in the array, start of heapify.
 * @param length Length of array.
 * @param comparator Comparison function.
 *  Input in comparator(HeapBItem, HeapBItem).
 * @return Final item position.
 */
size_t heapb_heapify_down(HeapBItem **arr, size_t posi, size_t length,
                       ICOMPARATOR);

/**
 * Insert a new item in the heap.
 *
 * @param heap HeapB instance.
 * @param new_item HeapBItem for insertion.
 * @param comparator Comparison function.
 *  Input in comparator(HeapBItem, HeapBItem).
 * @return Or 1 on success or 0 on failure.
 */
int heapb_insert(HeapB *heap, HeapBItem *new_item, ICOMPARATOR);

/**
 * Remove the top item of the heap.
 * 
 * @param heap HeapB instance.
 * @param comparator Comparison function.
 *  Input in comparator(HeapBItem, HeapBItem).
 * @return Or the instance removed, or NULL on failure.
 */
HeapBItem *heapb_remove(HeapB *heap, ICOMPARATOR);

/**
 * Return the top item heap.
 * 
 * @param HeapB Heap instance.
 * @return or the top item or NULL on failure.
 */
HeapBItem *heapb_peek(HeapB *heap);
