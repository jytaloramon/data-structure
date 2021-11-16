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
 * @return Or 1 if empty or 0 if not empty.
 */
int list_is_empty(List *list);

/**
 * Adds an element at the end of the list.
 * @param list List pointer.
 * @param elmnt Element.
 * @return Or 1 if added or 0 if not added.
 */
int list_append(List *list, void *elmnt);

/**
 * Remove the fist element.
 * @param list List pointer.
 * @return The instance removed or NULL if list is empty.
 */
void *list_remove(List *list);

/**
 * Removes all items from the list.
 * @param list List pointer.
 */
void list_clear(List *list);

/**
 * Returns the first element with the specified value.
 * @param list List pointer.
 * @param value Value sought.
 * @param comparator Comparison function.
 * @return The object if found, or NULL if not.
 */
ItemList *list_find(List *list, void *value, ICOMPARATOR);

/**
 * Returns the number of elements with the specified value.
 * @param list List pointer.
 * @param value Value sought.
 * @param comparator Comparison function.
 * @return Number of elements that satisfy the conditions.
 */
int list_count(List *list, void *value, ICOMPARATOR);