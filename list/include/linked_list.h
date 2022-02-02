/**
 * @author Ytalo Ramon
 * @date   31/01/2022
 */

#include "../../includes/icomparator.h"
#include "stdlib.h"

/**
 * Define the prototype of the struct.
 * struct _LList LList.
 */
typedef struct _LList LList;

/**
 * Define the prototype of the struct.
 * struct _LlItem LlItem.
 */
typedef struct _LlItem LlItem;

/**
 * struct _LlItem.
 * attr: next - Pointer to the next element in the chain.
 */
struct _LlItem {
    struct _LlItem *next;
};

/**
 * struct _LList.
 * attr: length - Number of elements currently present in the lists.
 * attr: head - Head List.
 * attr: rear - Pointer to the last element in the list.
 */
struct _LList {
    struct _LlItem head, *rear;
    size_t length;
};

/**
 *
 * Create a new LList.
 * @return A LList instance or Null in case of error.
 */
LList *ll_new();

/**
 * Checks if the LList is empty.
 * @param ll LList pointer.
 * @return Or 1 if empty or 0 if not empty.
 */
int ll_is_empty(LList *ll);

/**
 * Add an item to the end of the list.
 * @param ll LList pointer.
 * @param new_item Item for insertion.
 * @return Or 1 if added or 0 if not added.
 */
int ll_append(LList *ll, LlItem *new_item);

/**
 * Adds an item at the specified position.
 * @param ll LList pointer.
 * @param new_item Item for insertion.
 * @param index Insertion position.
 * @return Or 1 if added or 0 if not added.
 */
int ll_insert_at(LList *ll, LlItem *new_item, size_t index);

/**
 * Remove the first item from the list
 * @param ll LList pointer.
 * @return The item removed, or NULL if list is empty.
 */
LlItem *ll_remove(LList *ll);

/**
 * Remove the item at the specified position.
 * @param ll LList pointer.
 * @param index Position of the removed element.
 *      Value -1 to remove the last element.
 * @return The item removed, or NULL if list is empty.
 */
LlItem *ll_remove_at(LList *ll, size_t index);

/**
 * Returns the first LlItem with the specified value.
 * @param ll LList pointer.
 * @param elmnt Element sought.
 * @param comparator Comparison function.
 *      Input in comparator(elmnt, LlItem_curr).
 * @return The item if found, or NULL if not.
 */
LlItem *ll_find(LList *ll, void *elmnt, ICOMPARATOR);

/**
 * Returns the number of LlItem with the specified value.
 * @param ll LList pointer.
 * @param elmnt Element sought.
 * @param comparator Comparison function.
 *      Input in comparator(elmnt, LlItem_curr).
 * @return Number of itens that satisfy the conditions.
 */
size_t ll_count(LList *ll, void *elmnt, ICOMPARATOR);

/**
 * Returns the index of the first item with the specified value.
 * @param ll LList pointer.
 * @param elmnt Element sought.
 * @param comparator Comparison function.
 *      Input in comparator(elmnt, LlItem_curr).
 * @return Object index if found, or -1 if not found.
 */
int ll_index_of(LList *ll, void *elmnt, ICOMPARATOR);

/**
 * Merge two List.
 * @param ll1 LList pointer 1.
 * @param ll2 LList pointer 2.
 * @return Or 1 if successful or 0 if not successful.
 */
int ll_merge(LList *ll1, LList *ll2);

/**
 * Add an item after a base item.
 * @param new_item Item for insertion.
 * @param prev_item Base/Previous item.
 * @return Or 1 if added or 0 if not added.
 */
int ll_item_append(LlItem *new_item, LlItem *prev_item);

/**
 * Removes the next item from a base item.
 * @param prev_item Item to be removed.
 * @return Or 1 on success or NULL on failure.
 */
int ll_item_remove_next(LlItem *prev_item);

/**
 * Returns the first LlItem with the specified value within the range.
 * @param item_s The starting item.
 * @param item_e The final item.
 * @param elmnt Element sought.
 * @param comparator Comparison function.
 *      Input in comparator(elmnt, LlItem_curr).
 * @return The item if found, or NULL if not.
 */
LlItem *ll_item_find(LlItem *item_s, LlItem *item_e, void *elmnt, ICOMPARATOR);

/**
 * Returns the number of LlItem with the specified value within the range.
 * @param item_s The starting item.
 * @param item_e The final item.
 * @param elmnt Element sought.
 * @param comparator Comparison function.
 *      Input in comparator(elmnt, LlItem_curr).
 * @return Number of itens that satisfy the conditions.
 */
size_t ll_item_count(LlItem *item_s, LlItem *item_e, void *elmnt, ICOMPARATOR);

/**
 * Returns the offset between the first LlItem with the specified value
 *  and the starting item of the range.
 * @param item_s The starting item.
 * @param item_e The final item.
 * @param elmnt Element sought.
 * @param comparator Comparison function.
 *      Input in comparator(elmnt, LlItem_curr).
 * @return The offset if found, or -1 if not found.
 */
int ll_item_offset(LlItem *item_s, LlItem *item_e, void *elmnt, ICOMPARATOR);

/**
 * Merge two sequences of DllItem.
 * @param item_ls1 The last item seq_1.
 * @param item_fs2 The first item seq_2.
 * @return Or 1 if successful or 0 if not successful.
 */
int ll_item_merge(LlItem *item_ls1, LlItem *item_fs2);
