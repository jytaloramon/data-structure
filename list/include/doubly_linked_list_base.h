/**
 * @author Ytalo Ramon
 * @date   24/12/2021
 */

#include "../../includes/icomparator.h"
#include "stdlib.h"

/**
 * Define the prototype of the struct.
 * struct _ItemList ItemList.
 */
typedef struct _ItemDLList ItemDLList;

/**
 * struct _ItemList.
 * attr: data - Payload.
 * attr: last - Pointer to the previous element in the chain.
 * attr: next - Pointer to the next element in the chain.
 */
struct _ItemDLList {
    struct _ItemDLList *previous, *next;
};
