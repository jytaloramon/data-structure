/**
 * @author Ytalo Ramon
 * @date   14/02/2021
 */

#include "../../includes/icomparator.h"
#include "stdlib.h"

/**
 * Define the prototype of the struct.
 * struct _List List.
 */
typedef struct _List List;

/**
 * Define the prototype of the struct.
 * struct _ItemList ItemList.
 */
typedef struct _ItemList ItemList;

/**
 * Checks if the list is empty.
 * @param list List pointer.
 * @return Or 1 if empty, or 0 if not empty.
 */
int list_is_empty(List *list);

/**
 * Adds an element at the end of the list.
 * @param list List pointer.
 * @param new_item Item for insertion.
 * @return Or 1 if added, or 0 if not added.
 */
int list_append(List *list, ItemList *new_item);

/**
 * Remove the fist element.
 * @param list List pointer.
 * @return The item removed, or NULL if list is empty.
 */
ItemList *list_remove(List *list);

/**
 * Returns the number of ItemList with the specified value.
 * @param list List pointer.
 * @param elmnt Element sought.
 * @param comparator Comparison function.
 *      Input in comparator(elmnt, itemList_current).
 * @return Number of elements that satisfy the conditions.
 */
size_t list_count(List *list, void *elmnt, ICOMPARATOR);
