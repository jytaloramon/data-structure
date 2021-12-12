/**
 * @author Ytalo Ramon
 * @date   15/06/2021
 */

#include "linked_list_base.h"

/**
 * struct _ItemList.
 * attr: data - Payload.
 * attr: last - Pointer to the previous element in the chain.
 * attr: next - Pointer to the next element in the chain.
 */
struct _ItemList {
    struct _ItemList *previous, *next;
};

/**
 * Remove the item from the list.
 * @param list List pointer.
 * @param item Item to be removed.
 * @return Or 1 on success, or NULL on failure.
 */
int list_remove_item(List *list, ItemList *item);
