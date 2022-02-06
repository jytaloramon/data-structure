/**
 * @author Ytalo Ramon
 * @date   13/02/2021
 */

#include "../../list/include/linked_list.h"

/**
 * Create a new Dynamic Queue.
 *  The Dynamic Queue works over Linked List.
 *
 * @return A LList instance or Null in case of error.
 */
LList *dq_new();

/**
 * Checks if the queue is empty.
 *
 * @param queue LList pointer.
 * @return Or 1 if empty or 0 if not empty.
 */
int dq_is_empty(LList *queue);

/**
 * Enqueue a new item.
 *
 * @param queue LList pointer.
 * @param new_item LlItem for insertion.
 * @return Or 1 if added or 0 if not added.
 */
int dq_enqueue(LList *queue, LlItem *new_item);

/**
 * Dequeue a item.
 *
 * @param queue LList pointer.
 * @return The LlItem dequeued or NULL if queue is empty.
 */
LlItem *dq_dequeue(LList *queue);

/**
 * Return the item on the front of the queue.
 *
 * @param queue LList pointer.
 * @return The LlItem of the front.
 */
LlItem *dq_peek(LList *queue);

/**
 * Returns the offset between the first item in the queue
 *  and the first item with the specified value.
 *
 * @param queue LList pointer.
 * @param elmnt Searched value.
 * @param Comparator Function comparator.
 *  Input in comparator(elmnt, LlItem_curr).
 * @return The item offset, or -1 if not found.
 */
int dq_offset(LList *queue, void *elmnt, ICOMPARATOR);
