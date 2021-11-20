/**
 * @author Ytalo Ramon
 * @date   16/11/2021
 */

#include "doubly_linked_list_base.h"

/**
 * struct _List.
 * attr: length - Number of elements currently present in the lists.
 * attr: front - Pointer to the first element in the list.
 */
struct _List {
    int length;
    struct _ItemList head;
};
