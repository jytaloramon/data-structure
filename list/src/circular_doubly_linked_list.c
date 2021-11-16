/**
 * @author Ytalo Ramon
 * @date   16/11/2021
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

    if (!list_is_empty(list)) {
        list->length++;
        return list_insert_after_item(list->front.next->previous, elmnt);
    }

    ItemList *new_item = list_new_item(elmnt);
    if (!new_item)
        return 0;

    new_item->previous = new_item->next = new_item;
    list->front.next = new_item;
    list->length++;

    return 1;
}

int list_insert_after_item(ItemList *item, void *elmnt) {

    if (!item)
        return 0;

    ItemList *new_item = list_new_item(elmnt);

    if (!new_item)
        return 0;

    new_item->previous = item;
    new_item->next = item->next;
    item->next->previous = new_item;
    item->next = new_item;

    return 1;
}

void *list_remove(List *list) {

    if (list_is_empty(list))
        return NULL;

    if (list->length > 1) {
    }
    return list_remove_item(list->front.next);

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

void *list_remove_item(ItemList *item) {

    if (!item || item->previous == item)
        return NULL;

    void *data = item->data;

    item->previous->next = item->next;
    item->next->previous = item->previous;

    free(item);

    return data;
}

void list_clear(List *list);

ItemList *list_find(List *list, void *value, ICOMPARATOR);

int list_count(List *list, void *value, ICOMPARATOR);