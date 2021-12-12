/**
 * @author Ytalo Ramon
 * @date   16/11/2021
 */

#include "doubly_linked_list_base.h"
#include "list_linear.h"

/**
 * struct _List.
 * attr: length - Number of elements currently present in the lists.
 * attr: head - Head List.
 * attr: rear - Pointer to the last element in the list.
 */
struct _List {
    int length;
    struct _ItemList head, *rear;
};
