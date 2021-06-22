/**
 * @author Ytalo Ramon
 * @date   11/03/2021
*/

#include "../../includes/icomparator.h"
#include "../../includes/itree_array.h"

/**
 * Heapify bottom-up
 * @param elmnt Reference element of the comparison.
 * @param posi Position of the reference element in the array, start of heapify.
 * @param arr Array values.
 * @param length Length of array. 
 * @param size_m Element size.
 * @param comparator Function comparator.
 * @return Final position of the element.
*/
size_t heapify_up(void *elmnt, size_t posi, void *arr, size_t length, size_t size_m, ICOMPARATOR);

/**
 * Heapify top-down.
 * @param elmnt Reference element of the comparison.
 * @param posi Position of the reference element in the array, start of heapify.
 * @param arr Array values.
 * @param length Length of array. 
 * @param size_m Element size.
 * @param comparator Function comparator.
 * @return Final position of the element.
*/
size_t heapify_down(void *elmnt, size_t posi, void *arr, size_t length, size_t size_m, ICOMPARATOR);

/**
 * Build a heap.
 * @param arr Array values.
 * @param length Length of array.
 * @param size_m Element size.
 * @param comparator Function comparator.
 * @return Or 1 on success, or 0 on failure.
*/
int heap_build(void *arr, size_t length, size_t size_m, ICOMPARATOR);

/**
 * Insert a new element.
 * @param elmnt Element for insertion.
 * @param arr Array values.
 * @param length Length of array.
 * @param size_m Element size.
 * @param comparator Function comparator.
 * @return Or 1 on success, or 0 on failure.
*/
int heap_insert(void *elmnt, void *arr, size_t length, size_t size_m, ICOMPARATOR);

/**
 * Remove the top heap element.
 * @param arr Array values.
 * @param length Length of array.
 * @param size_m Element size.
 * @param comparator Function comparator.
 * @return Or the instance removed, or NULL on failure.
*/
void *heap_remove(void *arr,  size_t length, size_t size_m, ICOMPARATOR);

/**
 * Return the top heap element
 * @param arr Array values.
 * @param length Length of array.
 * @return Or the instance element, or NULL on failure.
 */
void *heap_peek(void *arr,  size_t length);