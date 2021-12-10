/**
 * @author: Ytalo Ramon
 * @date: 16/06/2021
 * 
*/

#include "./stack.h"

/**
 * struct _ItemStack.
 * attr: data - Payload.
*/
struct _ItemStack{
    char padding;
};

/**
 * struct Stack.
 * attr: p_top - Index of the top element of the stack.
 * attr: length - Number of elements currently present in the Stack.
 * attr: size - Stack size.
 * attr: items - array of elements.
*/
struct _Stack{
    int p_top, length, size;
    struct _ItemStack **items; 
};


/**
 * Create a new Stack.
 * @param size Stack size.
 * @return A stack instance or Null in case of error.
*/
Stack *stack_new(int size);

/**
 * Checks if the stack is full.
 * @param stack Stack pointer.
 * @return int, or 1 if full or 0 if not full.
 */
int stack_is_full(Stack *stack);
