/**
 * @author: Ytalo Ramon
 * @date:   16/06/2021
 */

#include "../include/static_stack.h"
#include "../../math/include/arithmetic.h"
#include "stdlib.h"

SList *sst_new(size_t size) { return sl_new(size); }

int sst_is_empty(SList *stack) { return sl_is_empty(stack); }

int sst_is_full(SList *stack) { return sl_is_full(stack); }

int sst_push(SList *stack, SlItem *new_item) {

    return sl_insert_at(stack, new_item, 0);
}

SlItem *sst_pop(SList *stack) { return sl_remove(stack); }

SlItem *sst_peek(SList *stack) {

    return !sst_is_empty(stack) ? stack->items[stack->p_front] : NULL;
}

int sst_offset(SList *stack, void *elmnt, ICOMPARATOR) {

    return sl_index_of(stack, elmnt, comparator);
}
