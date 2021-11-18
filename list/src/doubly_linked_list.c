/**
 * @author Ytalo Ramon
 * @date   15/06/2021
 */

#include "../include/doubly_linked_list.h"
#include "stdio.h"
#include "string.h"

List *list_new() {
    
    List *list = malloc(sizeof(List));

    if (!list)
        return NULL;

    list->front.previous = list->front.next = NULL;
    list->rear = &list->front;
    list->length = 0;

    return list;
}

ItemList *list_new_item(void *data) {

    ItemList *item = malloc(sizeof(ItemList));

    if (!item)
        return NULL;

    item->data = data;
    item->previous = item->next = NULL;

    return item;
}

int list_is_empty(List *list) { return list->front.next == NULL; }

int list_append(List *list, void *elmnt) {

    ItemList *item = list_new_item(elmnt);

    if (!item)
        return 0;

    if (!list_is_empty(list))
        item->previous = list->rear;

    list->rear->next = item;
    list->rear = list->rear->next;
    list->length++;

    return 1;
}

int list_insert_at(List *list, int posi, void *elmnt) {

    if (posi < 0 || posi > list->length)
        return 0;

    if (posi == list->length)
        return list_append(list, elmnt);

    ItemList *item = list_new_item(elmnt);

    if (!item)
        return 0;

    int middle = list->length / 2;
    ItemList *item_r = NULL;

    if (posi <= middle) {
        item_r = &list->front;
        for (int i = 0; i < posi; ++i, item_r = item_r->next)
            ;
    } else {
        item_r = list->rear;
        for (int i = 0; i < list->length - posi; ++i, item_r = item_r->previous)
            ;
    }

    item->previous = item_r->next->previous;
    item_r->next->previous = item;
    item->next = item_r->next;
    item_r->next = item;
    list->length++;

    return 1;
}

void *list_remove_first(List *list) {

    if (list_is_empty(list))
        return NULL;

    ItemList *item = list->front.next;
    void *data = item->data;

    list->front.next = item->next;
    list->length--;
    free(item);

    if (!list_is_empty(list))
        list->front.next->previous = NULL;
    else
        list->rear = &list->front;

    return data;
}

void *list_remove_at(List *list, int posi) {

    if (list_is_empty(list) || (posi < 0 && posi != -1) || posi >= list->length)
        return NULL;

    if (posi == 0)
        return list_remove_first(list);

    if (posi == -1)
        posi = list->length - 1;

    int middle = list->length / 2;
    ItemList *item_r = NULL;

    if (posi <= middle) {
        item_r = &list->front;
        for (int i = 0; i < posi; ++i, item_r = item_r->next)
            ;
    } else {
        item_r = list->rear;
        for (int i = 0; i < list->length - posi; ++i, item_r = item_r->previous)
            ;
    }

    ItemList *item = item_r->next;
    void *data = item->data;
    item_r->next = item->next;
    list->length--;

    if (list_is_empty(list))
        list->rear = &list->front;
    else if (item->next)
        item->next->previous = item->previous;
    else
        list->rear = item->previous;

    free(item);

    return data;
}

void list_clear(List *list) {

    for (ItemList *item_r = &list->front, *item_n = NULL; !list_is_empty(list);
         item_r->next = item_n) {

        item_n = item_r->next->next;
        free(item_r->next->data);
        free(item_r->next);
    }

    list->rear = &list->front;
}

int list_index_of(List *list, void *value, ICOMPARATOR) {

    int i = 0;
    ItemList *item_r = list->front.next;

    while (item_r && comparator(value, item_r->data)) {
        item_r = item_r->next;
        i++;
    }

    return item_r ? i : -1;
}

void *list_find(List *list, void *value, ICOMPARATOR) {

    ItemList *item_r = list->front.next;

    while (item_r && comparator(value, item_r->data))
        item_r = item_r->next;

    return item_r ? item_r->data : NULL;
}

int list_count(List *list, void *value, ICOMPARATOR) {

    int count = 0;
    ItemList *item_r = list->front.next;

    while (item_r) {
        if (!comparator(value, item_r->data))
            count++;
        item_r = item_r->next;
    }

    return count;
}
