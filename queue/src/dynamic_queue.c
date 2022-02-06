/**
 * @author Ytalo Ramon
 * @date   12/06/2021
 */

#include "../include/dynamic_queue.h"
#include "stdlib.h"

LList *dq_new() { return ll_new(); }

int dq_is_empty(LList *queue) { return ll_is_empty(queue); }

int dq_enqueue(LList *queue, LlItem *new_item) {

    return ll_append(queue, new_item);
}

LlItem *dq_dequeue(LList *queue) { return ll_remove(queue); }

LlItem *dq_peek(LList *queue) {

    return !dq_is_empty(queue) ? queue->head.next : NULL;
}

int dq_offset(LList *queue, void *elmnt, ICOMPARATOR) {

    return ll_index_of(queue, elmnt, comparator);
}
