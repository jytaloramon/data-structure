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
 * Create a new ItemList.
 * @param data Void pointer.
 * @return The instance of a new ItemList or Null in case of error.
 */
ItemList *list_new_item(void *data);

/**
 * Adds an element after ItemBase.
 * @param list List pointer.
 * @param item_base Reference item.
 * @param elmnt Element.
 * @return Or 1 if added or 0 if not added.
 */
int list_insert_after_item(List *list, ItemList *item_base, void *elmnt);

/**
 * Returns the first ItemList with the specified value.
 * @param list List pointer.
 * @param value Value sought.
 * @param comparator Comparison function.
 * @return The object if found, or NULL if not.
 */
ItemList *list_find(List *list, void *value, ICOMPARATOR);

/**
 * Extend the list by adding list_src to the end.
 * @param list list extended.
 * @param list_src Added list.
 * @return Or 1 if extended, or 0 if not extended.
 */
int list_extend(List *list, List *list_src);