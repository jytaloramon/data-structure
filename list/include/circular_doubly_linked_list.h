/**
 * @author Ytalo Ramon
 * @date   16/11/2021
 */

#include "doubly_linked_list_base.h"
#include "../../includes/icomparator.h"
#include "stdlib.h"

/**
 * Define the prototype of the struct.
 * struct _List List.
 */
typedef struct _List List;

/**
 * struct _List.
 * attr: length - Number of elements currently present in the lists.
 * attr: head - Head List.
 */
struct _CdllList {
    size_t length;
    struct _DllItem head;
};

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

/**
 * Remove the item from the list.
 * @param list List pointer.
 * @param item Item to be removed.
 * @return Or 1 on success, or NULL on failure.
 */
int list_remove_item(List *list, ItemList *item);


