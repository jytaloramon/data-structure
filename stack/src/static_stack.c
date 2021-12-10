/**
 * @author: Ytalo Ramon
 * @date:   16/06/2021
 */

#include "../include/static_stack.h"
#include "stdlib.h"

Stack *stack_new(int size) {

    Stack *stack = malloc(sizeof(Stack));

    if (!stack)
        return NULL;

    stack->p_top = -1;
    stack->length = 0;
    stack->size = size;
    stack->items = malloc(sizeof(ItemStack *) * stack->size);

    if (!stack->items) {
        free(stack);
        return NULL;
    }

    return stack;
}

int stack_is_empty(Stack *stack) { return stack->p_top == -1; }

int stack_is_full(Stack *stack) { return stack->p_top == stack->size - 1; }

int stack_push(Stack *stack, ItemStack *new_item) {

    if (stack_is_full(stack))
        return 0;

    stack->items[++stack->p_top] = new_item;
    stack->length++;

    return 1;
}

ItemStack *stack_pop(Stack *stack) {

    if (stack_is_empty(stack))
        return NULL;

    ItemStack *item_stack = stack->items[stack->p_top];
    stack->items[stack->p_top--] = NULL;
    stack->length--;

    return item_stack;
}

ItemStack *stack_peek(Stack *stack) {

    if (stack_is_empty(stack))
        return NULL;

    return stack->items[stack->p_top];
}

int stack_search(Stack *stack, void *elmnt, ICOMPARATOR) {

    if (stack_is_empty(stack))
        return -1;

    for (int i = stack->p_top; i >= 0; --i) {
        if (!comparator(elmnt, stack->items[i]))
            return stack->p_top - i;
    }

    return -1;
}
