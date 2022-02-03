/**
 * @author Ytalo Ramon
 * @date   24/12/2021
 */

/**
 * Define the prototype of the struct.
 * struct _DllItem DllItem.
 */
typedef struct _DllItem DllItem;

/**
 * struct _DllItem.
 * attr: previous - Pointer to the previous element in the chain.
 * attr: next - Pointer to the next element in the chain.
 */
struct _DllItem {
    struct _DllItem *previous, *next;
};
