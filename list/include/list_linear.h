/**
 * @author Ytalo Ramon
 * @date   14/02/2021
 */

#include "list.h"

/**
 * Adds an element at the specified position.
 * @param list List pointer.
 * @param index Insertion position.
 * @param elmnt Element.
 * @return Or 1 if added or 0 if not added.
 */
int list_insert_at(List *list, int index, void *elmnt);

/**
 * Remove the element at the specified position.
 * @param list List pointer.
 * @param index Position of the removed element. Value -1 to remove the last
 * element.
 * @return The instance removed or NULL if list is empty.
 */
void *list_remove_at(List *list, int index);

/**
 * Returns the index of the first element with the specified value.
 * @param list List pointer.
 * @param value Value sought.
 * @param comparator Comparison function.
 * @return Object index if found, or -1 if not.
 */
int list_index_of(List *list, void *value, ICOMPARATOR);
