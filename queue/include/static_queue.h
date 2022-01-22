/**
 * @author Ytalo Ramon
 * @date   13/02/2021
 */

#include "../../includes/icomparator.h"
#include "../../list/include/static_list.h"
#include "stdlib.h"

/**
 * Create a new Static Queue.
 *  The Static Queue works over Static List.
 *
 * @param size Queue SIZE.
 * @return A list instance or Null in case of error.
 */
SList *sq_new(size_t size);

/**
 * Checks if the queue is empty.
 *
 * @param queue SList pointer.
 * @return Or 1 if empty or 0 if not empty.
 */
int sq_is_empty(SList *queue);

/**
 * Checks if the queue is full.
 *
 * @param queue SList pointer.
 * @return Or 1 if full or 0 if not full.
 */
int sq_is_full(SList *queue);

/**
 * Enqueue a new item.
 *
 * @param queue SList pointer.
 * @param new_item SlItem for insertion..
 * @return Or 1 if added or 0 if not added.
 */
int sq_enqueue(SList *queue, SlItem *new_item);

/**
 * Dequeue item.
 *
 * @param queue SList pointer.
 * @return The SlItem dequeued or NULL.
 */
SlItem *sq_dequeue(SList *queue);

/**
 * Return the item on the front of the queue.
 *
 * @param queue SList pointer.
 * @return The intance of the front item.
 */
SlItem *sq_peek(SList *queue);

/**
 * Returns the offset between the first item
 *  with the specified value and the first item in the queue.
 *
 * @param queue SList pointer.
 * @param elmnt Searched element.
 * @param Comparator Function comparator.
 *  Input in comparator(elmnt, SlItem_curr).
 * @return The item offset, or -1 if not found.
 */
int sq_offset(SList *queue, void *elmnt, ICOMPARATOR);