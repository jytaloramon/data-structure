/**
 * @author Ytalo Ramon
 * @date   15/06/2021
 */

#include "../include/static_list.h"
#include "../../math/include/arithmetic.h"
#include "stdlib.h"

SList *sl_new(size_t size) {

    SList *list = malloc(sizeof(SList));

    if (!list)
        return NULL;

    list->size = size + 1;
    list->p_front = list->p_rear = list->length = 0;
    list->items = malloc(sizeof(SlItem *) * list->size);

    if (!list->items) {
        free(list);
        return NULL;
    }

    return list;
}

int sl_is_empty(SList *list) { return list->p_front == list->p_rear; }

int sl_is_full(SList *list) {

    return divmodular(list->p_rear + 1, list->size) == list->p_front;
}

int sl_append(SList *list, SlItem *new_item) {

    if (sl_is_full(list) || !new_item)
        return 0;

    list->items[list->p_rear] = new_item;
    list->p_rear = divmodular(list->p_rear + 1, list->size);
    ++list->length;

    return 1;
}

int sl_insert_at(SList *list, SlItem *new_item, size_t index) {

    if (sl_is_full(list) || !new_item || index > list->length)
        return 0;

    if (index == list->length)
        return sl_append(list, new_item);

    size_t posi_insert = 0;

    if (index == 0) {
        posi_insert = divmodular(list->p_front - 1, list->size);
        list->p_front = posi_insert;
    } else {
        posi_insert = divmodular(list->p_front + index, list->size);

        for (size_t idx = list->p_rear, k; idx != posi_insert; idx = k) {
            k = divmodular(idx - 1, list->size);
            list->items[idx] = list->items[k];
        }

        list->p_rear = divmodular(list->p_rear + 1, list->size);
    }

    list->items[posi_insert] = new_item;
    ++list->length;

    return 1;
}

SlItem *sl_remove(SList *list) {

    if (sl_is_empty(list))
        return NULL;

    SlItem *rm_item = list->items[list->p_front];

    list->items[list->p_front] = NULL;
    list->p_front = divmodular(list->p_front + 1, list->size);
    --list->length;

    return rm_item;
}

SlItem *sl_remove_at(SList *list, size_t index) {

    if (sl_is_empty(list) || index >= list->length)
        return NULL;

    if (index == 0)
        return sl_remove(list);

    size_t posi_remove = divmodular(list->p_front + index, list->size),
           end_loop = divmodular(list->p_rear - 1, list->size);
    SlItem *rm_item = list->items[posi_remove];

    for (size_t idx = posi_remove, k; idx != end_loop; idx = k) {
        k = divmodular(idx + 1, list->size);
        list->items[idx] = list->items[k];
    }

    list->p_rear = divmodular(list->p_rear - 1, list->size);
    list->items[list->p_rear] = NULL;
    --list->length;

    return rm_item;
}

size_t sl_count(SList *list, void *elmnt, ICOMPARATOR) {

    size_t count = 0;

    for (size_t i = list->p_front; i != list->p_rear;
         i = divmodular(i + 1, list->size)) {

        count += (comparator(elmnt, list->items[i]) == 0 ? 1 : 0);
    }

    return count;
}

SlItem *sl_find(SList *list, void *elmnt, ICOMPARATOR) {

    int posi = sl_index_of(list, elmnt, comparator);

    if (posi == -1)
        return NULL;

    return list->items[divmodular(list->p_front + posi, list->size)];
}

int sl_index_of(SList *list, void *elmnt, ICOMPARATOR) {

    size_t i = list->p_front;

    while (i != list->p_rear && comparator(elmnt, list->items[i]))
        i = divmodular(i + 1, list->size);

    if (i == list->p_rear)
        return -1;

    return i >= list->p_front ? i - list->p_front
                              : list->size - list->p_front + i;
}
