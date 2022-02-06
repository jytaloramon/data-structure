/**
 * @author: Ytalo Ramon
 * @date: 16/06/2021
 *
 */

#include "../../list/include/linked_list.h"

/**
 * Create a new Dynamic Stack.
 *  The Dynamic Stack works over Linked List.
 *
 * @return A LList instance or Null in case of error.
 */
LList *dst_new();

/**
 * Checks if the stack is empty.
 *
 * @param stack LList pointer.
 * @return Or 1 if empty or 0 if not empty.
 */
int dst_is_empty(LList *stack);

/**
 * Push a new item onto the stack.
 *
 * @param stack LList pointer.
 * @param new_item LlItem for insertion.
 * @return Or 1 if added or 0 if not added.
 */
int dst_push(LList *stack, LlItem *new_item);

/**
 * Remove the item at the top of the stack.
 *
 * @param stack LList pointer.
 * @return The item removed, or NULL if stack is empty.
 */
LlItem *dst_pop(LList *stack);

/**
 * Return the item on the top of the stack.
 *
 * @param stack LList pointer.
 * @return Or top item object or NULL if stack is empty.
 */
LlItem *dst_peek(LList *stack);

/**
 * Returns the offset between the top of the stack
 *  and the LlItem with the specified value.
 *
 * @param stack LList pointer.
 * @param elmnt void pointer.
 * @param comparator Comparison function.
 *      Input in comparator(elmnt, LlItem_curr).
 * @return The offset if found, or -1 if not found.
 */
int dst_offset(LList *stack, void *elmnt, ICOMPARATOR);
