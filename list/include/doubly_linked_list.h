/**
 * @author Ytalo Ramon
 * @date   24/12/2021
 */

#include "doubly_linked_list_base.h"

/**
 * Adds an element in the root location.
 * @param root Two-pointer root.
 * @param new_item Item for insertion.
 * @return Or 1 if added or 0 if not added.
 */
int dll_insert_at(ItemDLList **root, ItemDLList *new_item);

/**
 * Remove the element after a base item.
 * @param item_base Reference item.
 * @param new_item Item for insertion.
 */
void dll_insert_after_item(ItemDLList *item_base, ItemDLList *new_item);

/**
 * Remove the element at the specified position.
 * @param root Two-pointer root.
 * @return The item removed, or NULL if list is empty.
 */
ItemDLList *dll_remove_at(ItemDLList **root);

/**
 * Remove the element after a base item.
 * @param item_base Reference item.
 */
void dll_remove_after_item(ItemDLList *item_base);

/**
 * Returns the number of items with the specified value.
 * @param item_start Pointer to start element.
 * @param elmnt Element sought.
 * @param comparator Comparison function.
 *      Input in comparator(elmnt, itemList_current).
 * @return Number of elements that satisfy the conditions.
 */
size_t dll_count(ItemDLList *item_start, void *elmnt, ICOMPARATOR);

/**
 * Returns the first ItemList with the specified value.
 * @param item_start Pointer to start element.
 * @param elmnt Element sought.
 * @param comparator Comparison function.
 *      Input in comparator(elmnt, itemList_current).
 * @return The object if found, or NULL if not.
 */
ItemDLList *dll_find(ItemDLList *item_start, void *elmnt, ICOMPARATOR);

/**
 * Returns the offset bettween the item_start
 *  and the element with the specified value.
 * @param item_start Pointer to start element.
 * @param elmnt Element sought.
 * @param comparator Comparison function.
 *      Input in comparator(elmnt, itemList_current).
 * @return Offset object if found, or -1 if not.
 */
int dll_offset(ItemDLList *item_start, void *elmnt, ICOMPARATOR);
