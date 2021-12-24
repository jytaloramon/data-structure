/**
 * @author Ytalo Ramon
 * @date   24/12/2021
 */

#include "doubly_linked_list_base.h"

/**
 * Checks if the list is empty.
 * @param item Item pointer.
 * @return Or 1 if empty, or 0 if not empty.
 */
int cdll_is_empty(ItemDLList *item);

/**
 * Add a new element after a base item.
 * @param new_item Item for insertion.
 * @param item_b Double-Pointer to base item.
 * @return Or 1 if added, or 0 if not added.
 */
int cdll_add(ItemDLList *item_new, ItemDLList **item_b);

/**
 * Remove the element from the list.
 * @param item_rm Item to be removed.
 * @param head Double pointer to the head element of the list.
 * @return Or 1 if removed, or 0 if not removed.
 */
int cdll_remove(ItemDLList *item_rm, ItemDLList **head);

/**
 * Returns the number of items with the specified value.
 * @param item_start Pointer to start element.
 * @param elmnt Element sought.
 * @param comparator Comparison function.
 *      Input in comparator(elmnt, itemList_current).
 * @return Number of elements that satisfy the conditions.
 */
size_t cdll_count(ItemDLList *item_start, void *elmnt, ICOMPARATOR);

/**
 * Returns the first ItemList with the specified value.
 * @param item_start Pointer to start element.
 * @param elmnt Element sought.
 * @param comparator Comparison function.
 *      Input in comparator(elmnt, itemList_current).
 * @return The object if found, or NULL if not.
 */
ItemDLList *cdll_find(ItemDLList *item_start, void *elmnt, ICOMPARATOR);

/**
 * Returns the offset bettween the item_start
 *  and the element with the specified value.
 * @param item_start Pointer to start element.
 * @param elmnt Element sought.
 * @param comparator Comparison function.
 *      Input in comparator(elmnt, itemList_current).
 * @return Offset object if found, or -1 if not.
 */
int cdll_offset(ItemDLList *item_start, void *elmnt, ICOMPARATOR);

/**
 * Join two item sequences.
 * @param cdll_1 An item from the first list.
 * @param cdll_2 An item from the second list.
 */
int cdll_union(ItemDLList *cdll_1, ItemDLList *cdll_2);