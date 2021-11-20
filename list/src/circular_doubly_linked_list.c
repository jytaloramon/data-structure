/**
 * @author Ytalo Ramon
 * @date   16/11/2021
 */

#include "../include/circular_doubly_linked_list.h"
#include "stdio.h"
#include "string.h"

List *list_new() {

    List *list = malloc(sizeof(List));

    if (!list)
        return NULL;

    list->head.previous = list->head.next = NULL;
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

int list_is_empty(List *list) { return list->head.next == NULL; }

int list_append(List *list, void *elmnt) {

    if (!list_is_empty(list))
        return list_insert_after_item(list, list->head.next->previous, elmnt);

    ItemList *new_item = list_new_item(elmnt);
    if (!new_item)
        return 0;

    new_item->previous = new_item->next = new_item;
    list->head.next = new_item;
    list->length++;

    return 1;
}

int list_insert_after_item(List *list, ItemList *item, void *elmnt) {

    if (!item)
        return 0;

    ItemList *new_item = list_new_item(elmnt);

    if (!new_item)
        return 0;

    new_item->previous = item;
    new_item->next = item->next;
    item->next->previous = new_item;
    item->next = new_item;
    list->length++;

    return 1;
}

void *list_remove(List *list) {

    if (list_is_empty(list))
        return NULL;

    return list_remove_item(list, list->head.next);
}

void *list_remove_item(List *list, ItemList *item) {

    if (!item)
        return NULL;

    void *data = item->data;

    if (item == item->previous) {
        list->head.next = NULL;
    } else {
        item->previous->next = item->next;
        item->next->previous = item->previous;

        if (list->head.next == item)
            list->head.next = item->next;
    }

    free(item);
    list->length--;

    return data;
}

void list_clear(List *list) {

    if (list_is_empty(list))
        return;

    list->head.next->previous->next = NULL;

    for (ItemList *item_r = &list->head, *item_n = NULL; !list_is_empty(list);
         item_r->next = item_n) {

        item_n = item_r->next->next;
        free(item_r->next->data);
        free(item_r->next);
    }
}

ItemList *list_find(List *list, void *value, ICOMPARATOR) {

    if (list_is_empty(list))
        return NULL;

    ItemList *item = list->head.next;

    if (!comparator(item->data, value))
        return item;

    int rs = 1;
    item = item->next;

    while (item != list->head.next && (rs = comparator(item->data, value))) {
        item = item->next;
    }

    return !rs ? item : NULL;
}

size_t list_count(List *list, void *value, ICOMPARATOR) {

    if (list_is_empty(list))
        return 0;

    ItemList *item = list->head.next->next;
    int count = !comparator(list->head.next->data, value);

    while (item != list->head.next) {
        count += !comparator(item->data, value);
        item = item->next;
    }

    return count;
}
