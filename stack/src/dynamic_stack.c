/**
 * @author: Ytalo Ramon
 * @date:   16/06/2021
 */

#include "../include/dynamic_stack.h"
#include "stdlib.h"

LList *dst_new() { return ll_new(); }

int dst_is_empty(LList *stack) { return ll_is_empty(stack); }

int dst_push(LList *stack, LlItem *new_item) {

    return ll_insert_at(stack, new_item, 0);
}

LlItem *dst_pop(LList *stack) { return ll_remove(stack); }

LlItem *dst_peek(LList *stack) {

    return !dst_is_empty(stack) ? stack->head.next : NULL;
}

int dst_offset(LList *stack, void *elmnt, ICOMPARATOR) {

    return ll_index_of(stack, elmnt, comparator);
}
