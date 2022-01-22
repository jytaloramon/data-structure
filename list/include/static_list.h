/**
 * @author Ytalo Ramon
 * @date   15/06/2021
 */

#include "../../includes/icomparator.h"
#include "stdlib.h"

/**
 * Define the prototype of the struct.
 * struct _SList SList.
 */
typedef struct _SList SList;

/**
 * Define the prototype of the struct.
 * struct _SlItem SlItem.
 */
typedef struct _SlItem SlItem;

/**
 * struct _SlItem.
 * attr: padding - Padding (blank space).
 */
struct _SlItem {
    char padding;
};

/**
 * struct _SList.
 * attr: p_front - Index of the first item of the list.
 * attr: p_rear - Index of the last item of the list + 1.
 * attr: size - List size.
 * attr: length - Number of item currently present in the lists.
 * attr: items - array of items.
 */
struct _SList {
    size_t p_front, p_rear, size, length;
    struct _SlItem **items;
};

/**
 * Create a new Static List(SList).
 *
 * @param size List size.
 * @return A list instance or Null in case of error.
 */
SList *sl_new(size_t size);

/**
 * Checks if the list is empty.
 *
 * @param list SList pointer.
 * @return Or 1 if empty or 0 if not empty.
 */
int sl_is_empty(SList *list);

/**
 * Checks if the list is full.
 *
 * @param list SList pointer.
 * @return Or 1 if full or 0 if not full.
 */
int sl_is_full(SList *list);

/**
 * Adds an item at the end of the list.
 *
 * @param list SList pointer.
 * @param new_item SlItem for insertion.
 * @return Or 1 if added, or 0 if not added.
 */
int sl_append(SList *list, SlItem *new_item);

/**
 * Adds an item at the specified position.
 *
 * @param list SList pointer.
 * @param new_item SlItem for insertion.
 * @param index Insertion position.
 * @return Or 1 if added or 0 if not added.
 */
int sl_insert_at(SList *list, SlItem *new_item, size_t index);

/**
 * Remove the fist item.
 *
 * @param list SList pointer.
 * @return The SlItem removed or NULL.
 */
SlItem *sl_remove(SList *list);

/**
 * Remove the item at the specified position.
 *
 * @param list SList pointer.
 * @param index Item index.
 * @return The item removed, or NULL if list is empty.
 */
SlItem *sl_remove_at(SList *list, size_t index);

/**
 * Returns the number of items with the specified value.
 *
 * @param list SList pointer.
 * @param elmnt Element sought.
 * @param comparator Comparison function.
 *      Input in comparator(elmnt, SlItem_curr).
 * @return Number of items that satisfy the conditions.
 */
size_t sl_count(SList *list, void *elmnt, ICOMPARATOR);

/**
 * Returns the first item with the specified value.
 *
 * @param list SList pointer.
 * @param elmnt Element sought.
 * @param comparator Comparison function.
 *      Input in comparator(elmnt, SlItem_curr).
 * @return The item if found, or NULL if not.
 */
SlItem *sl_find(SList *list, void *elmnt, ICOMPARATOR);

/**
 * Returns the index of the first item with the specified value.
 *
 * @param list SList pointer.
 * @param elmnt Element sought.
 * @param comparator Comparison function.
 *      Input in comparator(elmnt, SlItem_curr).
 * @return Item index if found, or -1 if not.
 */
int sl_index_of(SList *list, void *elmnt, ICOMPARATOR);
