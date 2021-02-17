/**
 * @author Ytalo Ramon
 * @date   16/02/2021
*/

#include "list.h"

/**
 * struct _ItemList.
 * attr: data - Payload.
 * attr: Ponteiro para o próximo elemento na cadeia.
*/
struct _ItemList{
    void *data;
    struct _ItemList *next;
};

/**
 * struct _List.
 * attr: length - Number of elements currently present in the lists.
 * attr: front - Pointer to the first element in the list..
 * attr: rear - Pointer to the last element in the list..
*/
struct _List{
    size_t length;
    struct _ItemList front, *rear; 
};



/**
 * Create a new list.
 * @return A list instance or Null in case of error.
*/
List *new_list();

/** 
 * Create a new ItemList.
 * @param data Void pointer.
 * @return The instance of a new ItemList.
*/
ItemList *new_item_list(void *data);
