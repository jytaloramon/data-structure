/**
 * @author Ytalo Ramon
 * @date   15/06/2021
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
 * struct _ItemList.
 * attr: data - Payload.
 */
struct _ItemList {
    char *padding;
};

/**
 * struct _List.
 * attr: p_front - Index of the first element of the list.
 * attr: p_rear - Index of the last element of the list.
 * attr: size - List size.
 * attr: length - Number of elements currently present in the lists.
 * attr: items - array of elements.
 */
struct _List {
    int p_front, p_rear, size, length;
    struct _ItemList **items;
};

/**
 * Create a new list.
 * @param size List size.
 * @return A list instance or Null in case of error.
 */
List *list_new(int size);

/**
 * Checks if the list is empty.
 * @param list List pointer.
 * @return Or 1 if empty, or 0 if not empty.
 */
int list_is_empty(List *list);

/**
 * Checks if the queue is full.
 * @param queue Queue pointer.
 * @return Or 1 if full, or 0 if not full.
 */
int list_is_full(List *list);

/**
 * Adds an element at the end of the list.
 * @param list List pointer.
 * @param new_item Item for insertion.
 * @return Or 1 if added, or 0 if not added.
 */
int list_append(List *list, ItemList *new_item);

/**
 * Adds an element at the specified position.
 * @param list List pointer.
 * @param new_item Item for insertion.
 * @param index Insertion position.
 * @return Or 1 if added or 0 if not added.
 */
int list_insert_at(List *list, ItemList *new_item, int index);

/**
 * Remove the fist element.
 * @param list List pointer.
 * @return The item removed, or NULL if list is empty.
 */
ItemList *list_remove(List *list);

/**
 * Remove the element at the specified position.
 * @param list List pointer.
 * @param index Position of the removed element.
 *      Value -1 to remove the last element.
 * @return The item removed, or NULL if list is empty.
 */
ItemList *list_remove_at(List *list, int index);

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
 * Returns the first element with the specified value.
 * @param list List pointer.
 * @param elmnt Element sought.
 * @param comparator Comparison function.
 *      Input in comparator(elmnt, itemList_current).
 * @return The object if found, or NULL if not.
 */
ItemList *list_find(List *list, void *elmnt, ICOMPARATOR);

/**
 * Returns the index of the first element with the specified value.
 * @param list List pointer.
 * @param elmnt Element sought.
 * @param comparator Comparison function.
 *      Input in comparator(elmnt, itemList_current).
 * @return Object index if found, or -1 if not.
 */
int list_index_of(List *list, void *elmnt, ICOMPARATOR);
