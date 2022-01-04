/**
 * @author Ytalo Ramon
 * @date   03/01/2021
 */

#include "../../includes/icomparator.h"
#include "doubly_linked_list_base.h"
#include "stdlib.h"

/**
 * Define the prototype of the struct.
 * struct _CdlList CdlList.
 */
typedef struct _CdlList CdlList;

/**
 * struct _CdlList.
 * attr: length - Number of elements currently present in the lists.
 * attr: head - Head CdlList.
 */
struct _CdlList {
    size_t length;
    struct _DllItem head;
};

/**
 * Create a new CdlList.
 * @return A CdlList instance or Null in case of error.
 */
CdlList *cdll_new();

/**
 * Checks if the CdlList is empty.
 * @param cdll CdlList pointer.
 * @return Or 1 if empty or 0 if not empty.
 */
int cdll_is_empty(CdlList *cdll);

/**
 * Add an element before the list first item.
 * @param cdll CdlList pointer.
 * @param new_item Item for insertion.
 * @return Or 1 if added or 0 if not added.
 */
int cdll_append(CdlList *cdll, DllItem *new_item);

/**
 * Remove the first element.
 * @param cdll CdlList pointer.
 * @return The item removed, or NULL if list is empty.
 */
DllItem *cdll_remove(CdlList *cdll);

/**
 * Returns the first DllItem with the specified value.
 * @param cdll CdlList pointer.
 * @param elmnt Element sought.
 * @param comparator Comparison function.
 *      Input in comparator(elmnt, DllItem_curr).
 * @return The item if found, or NULL if not.
 */
DllItem *cdll_find(CdlList *cdll, void *elmnt, ICOMPARATOR);

/**
 * Returns the number of DllItem with the specified value.
 * @param cdll CdlList pointer.
 * @param elmnt Element sought.
 * @param comparator Comparison function.
 *      Input in comparator(elmnt, DllItem_curr).
 * @return Number of itens that satisfy the conditions.
 */
size_t cdll_count(CdlList *cdll, void *elmnt, ICOMPARATOR);

/**
 * Returns the offset between the first DllItem with the specified value
 *  and the beginning of the list.
 * @param cdll CdlList pointer.
 * @param elmnt Element sought.
 * @param comparator Comparison function.
 *      Input in comparator(elmnt, DllItem_curr).
 * @return The offset if found, or -1 if not found.
 */
int cdll_offset(CdlList *cdll, void *elmnt, ICOMPARATOR);

/**
 * Links an item to its previous and next.
 * @param item Reference item.
 * @param prev Previous item.
 * @param next Next item.
 */
void cdll_item_link(DllItem *item, DllItem *prev, DllItem *next);

/**
 * Add an element after a base item.
 * @param new_item Item for insertion.
 * @param prev_item Base/Previous item.
 * @return Or 1 if added or 0 if not added.
 */
int cdll_item_append(DllItem *new_item, DllItem *prev_item);

/**
 * Remove the item and link your current previous and next.
 * @param list List pointer.
 * @param item Item to be removed.
 * @return Or 1 on success or NULL on failure.
 */
int cdll_item_remove(DllItem *rm_item);

/**
 * Returns the first DllItem with the specified value within the range.
 * @param item_s The starting item.
 * @param item_e The final item.
 * @param elmnt Element sought.
 * @param comparator Comparison function.
 *      Input in comparator(elmnt, DllItem_curr).
 * @return The item if found, or NULL if not.
 */
DllItem *cdll_item_find(DllItem *item_s, DllItem *item_e, void *elmnt,
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
size_t cdll_item_count(DllItem *item_s, DllItem *item_e, void *elmnt,
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
int cdll_item_offset(DllItem *item_s, DllItem *item_e, void *elmnt,
                     ICOMPARATOR);

/**
 * Join two sequences ofDllItem.
 * @param item_s1 An item from the first sequence.
 * @param item_s2 An item from the second sequence.
 * @return Or 1 if successful or 0 if not successful.
 */
int cdll_item_join(DllItem *item_s1, DllItem *item_s2);
