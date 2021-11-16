/**
 * @author Ytalo Ramon
 * @date   16/11/2021
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
 * struct _List.
 * attr: length - Number of elements currently present in the lists.
 * attr: front - Pointer to the first element in the list..
 * attr: rear - Pointer to the last element in the list.
 */
struct _List {
    int length;
    struct _ItemList front, *rear;
};

/**
 * Create a new list.
 * @return A list instance or Null in case of error.
 */
List *list_new();

/**
 * Create a new ItemList.
 * @param data Void pointer.
 * @return The instance of a new ItemList.
 */
ItemList *list_new_item(void *data);


