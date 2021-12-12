/**
 * @author Ytalo Ramon
 * @date   14/02/2021
 */

#include "list.h"

/**
 * Adds an element at the specified position.
 * @param list List pointer.
 * @param new_item Item for insertion.
 * @param index Insertion position.
 * @return Or 1 if added or 0 if not added.
 */
int list_insert_at(List *list, ItemList *new_item, int index);

/**
 * Remove the element at the specified position.
 * @param list List pointer.
 * @param index Position of the removed element.
 *      Value -1 to remove the last element.
 * @return The item removed, or NULL if list is empty.
 */
ItemList *list_remove_at(List *list, int index);

/**
 * Returns the index of the first element with the specified value.
 * @param list List pointer.
 * @param elmnt Element sought.
 * @param comparator Comparison function.
 *      Input in comparator(elmnt, itemList_current).
 * @return Object index if found, or -1 if not.
 */
int list_index_of(List *list, void *elmnt, ICOMPARATOR);
