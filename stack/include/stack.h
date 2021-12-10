/**
 * @author: Ytalo Ramon
 * @date: 16/06/2021
 *
 */

#include "../../includes/icomparator.h"

/**
 * Define the prototype of the struct.
 * typedef struct _Stack Stack.
 *
 */
typedef struct _Stack Stack;

/**
 * Define the prototype of the struct.
 * typedef struct _ItemStack ItemStack.
 */
typedef struct _ItemStack ItemStack;

/**
 * Checks if the stack is empty.
 * @param stack Stack pointer.
 * @return int, or 1 if empty or 0 if not empty.
 */
int stack_is_empty(Stack *stack);

/**
 * Push a new item onto the stack.
 * @param stack Stack pointer.
 * @param new_item Item for insertion.
 * @return Or 1 if added or 0 if not added.
 */
int stack_push(Stack *stack, ItemStack *new_item);

/**
 * Remove the item at the top of the stack.
 * @param stack Stack pointer.
 * @return The item removed, or NULL if stack is empty.
 */
ItemStack *stack_pop(Stack *stack);

/**
 * Return the item on the top of the stack.
 * @param stack Stack pointer.
 * @return Or top item object, or NULL if stack is empty.
 */
ItemStack *stack_peek(Stack *stack);

/**
 * Search for value in the stack.
 * @param stack Stack pointer.
 * @param elmnt void pointer.
 * @param comparator Comparison function.
 *      Input in comparator(elmnt, itemStack_current).
 * @return if found, its offset from the top of the stack is returned.
 * Or -1 if not found.
 */
int stack_search(Stack *stack, void *elmnt, ICOMPARATOR);
