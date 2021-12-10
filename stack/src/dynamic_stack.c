/**
 * @author: Ytalo Ramon
 * @date:   16/06/2021
 */

#include "../include/dynamic_stack.h"
#include "stdio.h"
#include "stdlib.h"

Stack *stack_new() {

    Stack *stack = malloc(sizeof(Stack));

    if (!stack)
        return NULL;

    stack->head.next = NULL;
    stack->length = 0;

    return stack;
}

int stack_is_empty(Stack *stack) { return stack->head.next == NULL; }

int stack_push(Stack *stack, ItemStack *new_item) {

    if (!new_item)
        return 0;

    new_item->next = stack->head.next;
    stack->head.next = new_item;
    stack->length++;

    return 1;
}

ItemStack *stack_pop(Stack *stack) {

    if (stack_is_empty(stack))
        return NULL;

    ItemStack *item = stack->head.next;
    stack->head.next = item->next;
    stack->length--;

    return item;
}

ItemStack *stack_peek(Stack *stack) {

    if (stack_is_empty(stack))
        return NULL;

    return stack->head.next;
}

int stack_search(Stack *stack, void *elmnt, ICOMPARATOR) {

    if (stack_is_empty(stack))
        return -1;

    int i = 0;
    ItemStack *item_r = stack->head.next;

    while (item_r && comparator(elmnt, item_r)) {
        item_r = item_r->next;
        i++;
    }

    return item_r ? i : -1;
}
