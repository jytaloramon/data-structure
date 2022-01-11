/**
 * @author Ytalo Ramon
 * @date   10/01/2022
 */

#include "../../includes/icomparator.h"
#include "doubly_linked_list_base.h"
#include "stdlib.h"

/**
 * Define the prototype of the struct.
 * struct _DlList DlList.
 */
typedef struct _DlList DlList;

/**
 * struct _DlList.
 * attr: length - Number of elements currently present in the lists.
 * attr: head - Head List.
 * attr: rear - Pointer to the last element in the list.
 */
struct _DlList {
    size_t length;
    struct _DllItem head, *rear;
};

/**
 * Create a new DlList.
 * @return A DlList instance or Null in case of error.
 */
DlList *dll_new();

/**
 * Checks if the DlList is empty.
 * @param dll DlList pointer.
 * @return Or 1 if empty or 0 if not empty.
 */
int dll_is_empty(DlList *dll);

/**
 * Add an element before the list first item.
 * @param dll DlList pointer.
 * @param new_item Item for insertion.
 * @return Or 1 if added or 0 if not added.
 */
int dll_append(DlList *dll, DllItem *new_item);

/**
 * Adds an element at the specified position.
 * @param dll DlList pointer.
 * @param new_item Item for insertion.
 * @param index Insertion position.
 * @return Or 1 if added or 0 if not added.
 */
int dll_insert_at(DlList *dll, DllItem *new_item, size_t index);

/**
 * Remove the first element.
 * @param dll DlList pointer.
 * @return The item removed, or NULL if list is empty.
 */
DllItem *dll_remove(DlList *dll);

/**
 * Remove the element at the specified position.
 * @param dll DlList pointer.
 * @param index Position of the removed element.
 *      Value -1 to remove the last element.
 * @return The item removed, or NULL if list is empty.
 */
DllItem *dll_remove_at(DlList *dll, size_t index);

/**
 * Remove the last element.
 * @param dll DlList pointer.
 * @return The item removed, or NULL if list is empty.
 */
DllItem *dll_pop(DlList *dll);

/**
 * Returns the first DllItem with the specified value.
 * @param dll CdlList pointer.
 * @param elmnt Element sought.
 * @param comparator Comparison function.
 *      Input in comparator(elmnt, DllItem_curr).
 * @return The item if found, or NULL if not.
 */
DllItem *dll_find(DlList *dll, void *elmnt, ICOMPARATOR);

/**
 * Returns the number of DllItem with the specified value.
 * @param dll DlList pointer.
 * @param elmnt Element sought.
 * @param comparator Comparison function.
 *      Input in comparator(elmnt, DllItem_curr).
 * @return Number of itens that satisfy the conditions.
 */
size_t dll_count(DlList *dll, void *elmnt, ICOMPARATOR);

/**
 * Returns the index of the first element with the specified value.
 * @param dll DlList pointer.
 * @param elmnt Element sought.
 * @param comparator Comparison function.
 *      Input in comparator(elmnt, itemList_current).
 * @return Object index if found, or -1 if not found.
 */
int dll_index_of(DlList *dll, void *elmnt, ICOMPARATOR);

/**
 * Links an item to its previous and next.
 * @param item Reference item.
 * @param prev Previous item.
 * @param next Next item.
 */
void dll_item_link(DllItem *item, DllItem *prev, DllItem *next);

/**
 * Add an element after a base item.
 * @param new_item Item for insertion.
 * @param prev_item Base/Previous item.
 * @return Or 1 if added or 0 if not added.
 */
int dll_item_append(DllItem *new_item, DllItem *prev_item);

/**
 * Remove the item and link your current previous and next.
 * @param rm_item Item to be removed.
 * @return Or 1 on success or NULL on failure.
 */
int dll_item_remove(DllItem *rm_item);

/**
 * Returns the first DllItem with the specified value within the range.
 * @param item_s The starting item.
 * @param item_e The final item.
 * @param elmnt Element sought.
 * @param comparator Comparison function.
 *      Input in comparator(elmnt, DllItem_curr).
 * @return The item if found, or NULL if not.
 */
DllItem *dll_item_find(DllItem *item_s, DllItem *item_e, void *elmnt,
                       ICOMPARATOR);

/**
 * Returns the number of DllItem with the specified value within the range.
 * @param item_s The starting item.
 * @param item_e The final item.
 * @param elmnt Element sought.
 * @param comparator Comparison function.
 *      Input in comparator(elmnt, DllItem_curr).
 * @return Number of itens that satisfy the conditions.
 */
size_t dll_item_count(DllItem *item_s, DllItem *item_e, void *elmnt,
                      ICOMPARATOR);

/**
 * Returns the offset between the first DllItem with the specified value
 *  and the starting item of the range.
 * @param item_s The starting item.
 * @param item_e The final item.
 * @param elmnt Element sought.
 * @param comparator Comparison function.
 *      Input in comparator(elmnt, DllItem_curr).
 * @return The offset if found, or -1 if not found.
 */
int dll_item_offset(DllItem *item_s, DllItem *item_e, void *elmnt, ICOMPARATOR);

/**
 * Join two sequences of DllItem.
 * @param item_ls1 The last item seq_1.
 * @param item_fs2 The first item seq_2.
 * @return Or 1 if successful or 0 if not successful.
 */
int dll_item_join(DllItem *item_ls1, DllItem *item_fs2);
