/**
 * @author Ytalo Ramon
 * @date   15/01/2022
 */

#include "../../../list/include/circular_doubly_linked_list.h"
#include "stdlib.h"

typedef struct _HeapFib HeapFib;

typedef struct _HeapFibItem HeapFibItem;

struct _HeapFibItem {
    struct _HeapFibItem *father, *child;
    struct _DllItem cdll_item;
    int mark;
    size_t degree;
    int value;
};

struct _HeapFib {
    struct _HeapFibItem *min_item;
    size_t length;
};

/**
 * Create a new HeapFib structure.
 *
 * @return A HeapFib instance or Null in case of error.
 */
HeapFib *heapf_new();

/**
 * Checks if the heap is empty.
 *
 * @param heap HeapFib instance.
 * @return Or 1 if empty or 0 if not empty.
 */
int heapf_is_empty(HeapFib *heap);

/**
 * Insert a new item into the heap.
 *
 * @param heap HeapFib instance.
 * @param new_item HeapFibItem for insertion.
 * @param comparator Function comparator.
 *  Input in comparator(HeapFibItem, HeapFibItem).
 * @return Or 1 on success or 0 on failure.
 */
int heapf_insert(HeapFib *heap, HeapFibItem *new_item, ICOMPARATOR);

/**
 * Remove the minimum item from the heap.
 *
 * @param heap HeapFib instance.
 * @param comparator Function comparator.
 *  Input in comparator(HeapFibItem, HeapFibItem).
 * @return Or the instance removed or NULL on failure.
 */
HeapFibItem *heapf_extract_min(HeapFib *heap, ICOMPARATOR);

/**
 * Removes the given item from the heap.
 *
 * @param heap HeapFib instance.
 * @param comparator Function comparator.
 *  Input in comparator(HeapFibItem, HeapFibItem).
 * @return int Or 1 on success or 0 on failure.
 */
int *heapf_remove(HeapFib *heap, HeapFibItem *rm_item, ICOMPARATOR);

/**
 * Updates the heap state from an item
 *  that has had its value decremented.
 *
 * @param heap HeapFib instance.
 * @param up_item Updated item.
 * @param comparator Function comparator.
 *  Input in comparator(HeapFibItem, HeapFibItem).
 * @return int Or 1 on success or 0 on failure.
 */
int heapf_decrease_key(HeapFib *heap, HeapFibItem *up_item, ICOMPARATOR);

/**
 * Performs a pruning of the roots list of the heap.
 *
 * @param heap HeapFib instance.
 * @param comparator Function comparator.
 *  Input in comparator(HeapFibItem, HeapFibItem).
 */
void heapf_consolidate(HeapFib *heap, ICOMPARATOR);

/**
 * Remove item from its current position
 *  and insert into root list.
 *
 * @param heap HeapFib instance.
 * @param up_item Updated item.
 */
void heapf_cut(HeapFib *heap, HeapFibItem *up_item);

/**
 * Returns the minimum heap item.
 *
 * @param heap HeapFib instance.
 * @return Or the minimun item instance or NULL.
 */
HeapFibItem *heapf_peek(HeapFib *heap);

/**
 * Returns the HeapFibItem with the specified value.
 *
 * @param heap HeapFib instance.
 * @param elmnt Element sought.
 * @param comparator Function comparator.
 *  Input in comparator(elmnt, HeapFibItem).
 * @return The item if found, or NULL if not.
 */
HeapFibItem *heapf_find(HeapFib *heap, void *elmnt, ICOMPARATOR);

/**
 * Concatenates two heaps. Making Heap receive heap_from.
 *
 * @param heap HeapFib instance.
 * @param heap_from HeapFib instance.
 * @param comparator Function comparator.
 *  Input in comparator(HeapFibItem, HeapFibItem).
 * @return int Or 1 on success or 0 on failure.
 */
int heapf_union(HeapFib *heap, HeapFib *heap_from, ICOMPARATOR);
