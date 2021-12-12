/**
 * @author Ytalo Ramon
 * @date   18/11/2021
 */

#include "list.h"

/**
 * Create a new list.
 * @return A list instance or Null in case of error.
 */
List *list_new();

/**
 * Adds an element after ItemBase.
 * @param list List pointer.
 * @param item_base Reference item.
 * @param new_item Item for insertion.
 * @return Or 1 if added or 0 if not added.
 */
int list_insert_after_item(List *list, ItemList *item_base, ItemList *new_item);

/**
 * Returns the first ItemList with the specified value.
 * @param list List pointer.
 * @param elmnt Element sought.
 * @param comparator Comparison function.
 *      Input in comparator(elmnt, itemList_current).
 * @return The object if found, or NULL if not.
 */
ItemList *list_find(List *list, void *elmnt, ICOMPARATOR);
