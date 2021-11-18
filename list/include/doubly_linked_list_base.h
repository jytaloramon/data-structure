/**
 * @author Ytalo Ramon
 * @date   15/06/2021
 */

#include "list.h"

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
 * Create a new list.
 * @return A list instance or Null in case of error.
 */
List *list_new();

/**
 * Create a new ItemList.
 * @param data Void pointer.
 * @return The instance of a new ItemList or Null in case of error.
 */
ItemList *list_new_item(void *data);

/**
 * Adds an element after ItemBase
 * @param list List pointer.
 * @param item_base Reference item.
 * @param elmnt Element.
 * @return Or 1 if added or 0 if not added.
 */
int list_insert_after_item(List *list, ItemList *item_base, void *elmnt);

/**
 * Remove the item from the list.
 * @param list List pointer.
 * @param item Item to be removed.
 * @return The instance removed or NULL if list is empty.
 */
void *list_remove_item(List *list, ItemList *item);
