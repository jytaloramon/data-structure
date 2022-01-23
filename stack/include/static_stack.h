/**
 * @author: Ytalo Ramon
 * @date: 16/06/2021
 */

#include "../../includes/icomparator.h"
#include "../../list/include/static_list.h"
#include "stdlib.h"

/**
 * Create a new Static Stack.
 *  The Static Stack works over Static List.
 *
 * @param size Stack size.
 * @return A list instance or Null in case of error.
 */
SList *sst_new(size_t size);

/**
 * Checks if the stack is empty.
 *
 * @param stack SList pointer.
 * @return Or 1 if empty or 0 if not empty.
 */
int sst_is_empty(SList *stack);

/**
 * Checks if the stack is full.
 *
 * @param stack SList pointer.
 * @return Or 1 if full or 0 if not full.
 */
int sst_is_full(SList *stack);

/**
 * Push a new item onto the stack.
 *
 * @param stack SList pointer.
 * @param new_item SlItem for insertion.
 * @return Or 1 if added or 0 if not added.
 */
int sst_push(SList *stack, SlItem *new_item);

/**
 * Remove the item at the top of the stack.
 *
 * @param stack SList pointer.
 * @return The item removed or NULL.
 */
SlItem *sst_pop(SList *stack);

/**
 * Return the item on the top of the stack.
 *
 * @param stack SList pointer.
 * @return The SlItem top or NULL.
 */
SlItem *sst_peek(SList *stack);

/**
 * Returns the offset between the first item
 *  with the specified value and the top item in the stack.
 *
 * @param stack SList pointer.
 * @param elmnt Searched element.
 * @param Comparator Function comparator.
 *  Input in comparator(elmnt, SlItem_curr).
 * @return The item offset, or -1 if not found.
 */
int sst_offset(SList *stack, void *elmnt, ICOMPARATOR);
