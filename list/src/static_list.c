/**
 * @author Ytalo Ramon
 * @date   15/06/2021
 */

#include "../include/static_list.h"
#include "../../math/include/arithmetic.h"
#include "stdlib.h"

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

int list_insert_at(List *list, int index, void *elmnt) {

    if (list_is_full(list) || index < 0 || index > list->length)
        return 0;

    if (index == list->length)
        return list_append(list, elmnt);

    int posi_insert = 0;

    if (index == 0) {
        posi_insert = divmodular(list->p_front - 1, list->size);
        list->p_front = posi_insert;
    } else {
        posi_insert = divmodular(list->p_front + index, list->size);

        for (int idx = list->p_rear; idx != posi_insert;
             idx = divmodular(idx - 1, list->size))
            list->items[idx].data = list->items[idx - 1].data;

        list->p_rear = divmodular(list->p_rear + 1, list->size);
    }

    list->items[posi_insert].data = elmnt;
    list->length++;

    return 1;
}

void *list_remove(List *list) {

    if (list_is_empty(list))
        return NULL;

    void *data = list->items[list->p_front].data;
    list->items[list->p_front].data = NULL;
    list->p_front = divmodular(list->p_front + 1, list->size);
    list->length--;

    return data;
}

void *list_remove_at(List *list, int index) {

    if (list_is_empty(list) || (index < 0 && index != -1) ||
        index >= list->length)
        return NULL;

    if (index == 0)
        return list_remove(list);

    int posi_remove = divmodular(
        list->p_front + (index != -1 ? index : list->length - 1), list->size);
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

    for (size_t i = list->p_front; i != list->p_rear;
         i = divmodular(i + 1, list->size)) {

        free(list->items[i].data);
        list->items[i].data = NULL;
    }

    list->p_front = list->p_rear = list->length = 0;
}

int list_index_of(List *list, void *value, ICOMPARATOR) {

    int i = list->p_front;

    while (i != list->p_rear && comparator(list->items[i].data, value))
        i = divmodular(i + 1, list->size);

    if (i == list->p_rear)
        return -1;

    return i >= list->p_front ? i - list->p_front
                              : list->size - list->p_front + i;
}

void *list_find(List *list, void *value, ICOMPARATOR) {

    int posi = list_index_of(list, value, comparator);

    if (posi == -1)
        return NULL;

    return list->items[divmodular(list->p_front + posi, list->size)].data;
}

size_t list_count(List *list, void *value, ICOMPARATOR) {

    size_t count = 0;

    for (int i = list->p_front; i != list->p_rear;
         i = divmodular(i + 1, list->size)) {

        if (!comparator(list->items[i].data, value))
            count++;
    }

    return count;
}
