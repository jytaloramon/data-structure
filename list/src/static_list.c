/**
 * @author Ytalo Ramon
 * @date   15/06/2021
 */

#include "../include/static_list.h"
#include "../../math/include/arithmetic.h"
#include "stdio.h"
#include "string.h"

List *list_new(int size) {

    List *list = malloc(sizeof(List));

    if (!list)
        return NULL;

    list->size = size + 1;
    list->p_front = list->p_rear = list->length = 0;
    list->items = malloc(sizeof(ItemList) * list->size);

    if (!list->items) {
        free(list);
        return NULL;
    }

    return list;
}

int list_is_empty(List *list) { return list->p_front == list->p_rear; }

int list_is_full(List *list) {

    return divmodular(list->p_rear + 1, list->size) == list->p_front;
}

int list_append(List *list, void *elmnt) {

    if (list_is_full(list))
        return 0;

    list->items[list->p_rear].data = elmnt;
    list->p_rear = divmodular(list->p_rear + 1, list->size);
    list->length++;

    return 1;
}

int list_insert_at(List *list, int posi, void *elmnt) {

    if (list_is_full(list) || posi < 0 || posi > list->length)
        return 0;

    if (posi == list->length)
        return list_append(list, elmnt);

    int posi_insert = 0;

    if (posi == 0) {
        posi_insert = divmodular(list->p_front - 1, list->size);
        list->p_front = posi_insert;
    } else {
        posi_insert = divmodular(list->p_front + posi, list->size);

        for (int idx = list->p_rear; idx != posi_insert;
             idx = divmodular(idx - 1, list->size))
            list->items[idx].data = list->items[idx - 1].data;

        list->p_rear = divmodular(list->p_rear + 1, list->size);
    }

    list->items[posi_insert].data = elmnt;
    list->length++;

    return 1;
}

void *list_remove_first(List *list) {

    if (list_is_empty(list))
        return NULL;

    void *data = list->items[list->p_front].data;
    list->items[list->p_front].data = NULL;
    list->p_front = divmodular(list->p_front + 1, list->size);
    list->length--;

    return data;
}

void *list_remove_at(List *list, int posi) {

    if (list_is_empty(list) || (posi < 0 && posi != -1) || posi >= list->length)
        return NULL;

    if (posi == 0)
        return list_remove_first(list);

    int posi_remove = divmodular(
        list->p_front + (posi != -1 ? posi : list->length - 1), list->size);
    void *data = list->items[posi_remove].data;

    int end_loop = divmodular(list->p_rear - 1, list->size);
    for (int idx = posi_remove; idx != end_loop;
         idx = divmodular(idx + 1, list->size))
        list->items[idx].data =
            list->items[divmodular(idx + 1, list->size)].data;

    list->p_rear = divmodular(list->p_rear - 1, list->size);
    list->items[list->p_rear].data = NULL;
    list->length--;

    return data;
}

void list_clear(List *list) {

    for (int i = list->p_front; !list_is_empty(list);
         i = divmodular(i + 1, list->size)) {
        free(list->items[i].data);
        list->items[i].data = NULL;
    }

    list->p_front = list->p_rear = list->length = 0;
}

int list_index_of(List *list, void *value, ICOMPARATOR) {

    int i = list->p_front;

    while (i != list->p_rear && comparator(value, list->items[i].data))
        i = divmodular(i + 1, list->size);

    if (i == list->p_rear)
        return -1;

    return i >= list->p_front ? i - list->p_front
                              : list->size - list->p_front + i;
}

void *list_find(List *list, void *value, ICOMPARATOR) {

    int posi = list_index_of(list, value, comparator);
    return posi != -1
               ? list->items[divmodular(list->p_front + posi, list->size)].data
               : NULL;
}

int list_count(List *list, void *value, ICOMPARATOR) {

    int count = 0;

    for (int i = list->p_front; i != list->p_rear;
         i = divmodular(i + 1, list->size))
        if (!comparator(value, list->items[i].data))
            count++;

    return count;
}
