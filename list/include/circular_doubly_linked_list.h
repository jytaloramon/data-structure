/**
 * @author Ytalo Ramon
 * @date   16/11/2021
 */

#include "doubly_linked_list_base.h"

/**
 * struct _ItemList.
 * attr: data - Payload.
 * attr: last - Pointer to the previous element in the chain.
 * attr: next - Pointer to the next element in the chain.
 */
struct _ItemList {
    void *data;
    struct _ItemList *previous, *next;
};

/**
 * struct _List.
 * attr: length - Number of elements currently present in the lists.
 * attr: front - Pointer to the first element in the list.
 */
struct _List {
    int length;
    struct _ItemList head;
};

/**
 * Returns the offset bettween itemBase and Item with the specified value.
 * @param item_base Reference item.
 * @param value Value sought.
 * @param comparator Comparison function.
 * @return Object offset if found, or -1 if not.
 */
int list_index_of_item_base(ItemList *item_base, void *value, ICOMPARATOR);
