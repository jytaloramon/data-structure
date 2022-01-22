/**
 * @author Ytalo Ramon
 * @date   13/02/2021
 */

#include "../include/static_queue.h"
#include "stdlib.h"

SList *sq_new(size_t size) { return sl_new(size); }

int sq_is_empty(SList *queue) { return sl_is_empty(queue); }

int sq_is_full(SList *queue) { return sl_is_full(queue); }

int sq_enqueue(SList *queue, SlItem *new_item) {

    return sl_append(queue, new_item);
}

SlItem *sq_dequeue(SList *queue) { return sl_remove(queue); }

SlItem *sq_peek(SList *queue) {

    return !sq_is_empty(queue) ? queue->items[queue->p_front] : NULL;
}

int sq_offset(SList *queue, void *elmnt, ICOMPARATOR) {

    return sl_index_of(queue, elmnt, comparator);
}
