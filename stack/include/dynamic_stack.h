/**
 * @author: Ytalo Ramon
 * @date: 16/06/2021
 *
 */

#include "./stack.h"

/**
 * struct _ItemStack.
 * attr: next - Pointer to the next element in the chain.
 */
struct _ItemStack {
    struct _ItemStack *next;
};

/**
 * struct _Stack.
 * attr: head - Head element in the stack.
 * attr: length - Number of elements currently present in the stack.
 */
struct _Stack {
    struct _ItemStack head;
    int length;
};

/**
 * Create a new stack.
 * @return A stack instance or Null in case of error.
 */
Stack *stack_new();
