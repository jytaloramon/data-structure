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

    list->head.previous = list->head.next = NULL;
    list->rear = &list->head;
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

int list_insert_at(List *list, int index, void *elmnt) {

    if (index < 0 || index > list->length)
        return 0;

    if (index == list->length)
        return list_append(list, elmnt);

    ItemList *item_r = &list->head;
    for (size_t i = 0; i < index; ++i, item_r = item_r->next)
        ;

    int rs = list_insert_after_item(list, item_r, elmnt);

    if (rs && index == 0)
        list->head.next->previous = NULL;

    return rs;
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

void *list_remove_at(List *list, int index) {

    if (list_is_empty(list) || (index < 0 && index != -1) ||
        index >= list->length)
        return NULL;

    if (index == 0)
        return list_remove(list);

    if (index == -1)
        index = list->length - 1;

    ItemList *item_r = list->head.next->next;
    for (size_t i = 1; i < index; ++i, item_r = item_r->next)
        ;

    return list_remove_item(list, item_r);
}

void *list_remove_item(List *list, ItemList *item) {

    if (!item)
        return NULL;

    void *data = item->data;
    ItemList *previous_final = NULL;

    if (!item->previous) {
        // if the item is the first element.
        list->head.next = item->next;
    } else {
        item->previous->next = item->next;
        previous_final = item->previous;
    }

    if (item->next) // if the item is not the last element.
        item->next->previous = previous_final;
    else
        list->rear = previous_final ? previous_final : &list->head;

    free(item);
    list->length--;

    return data;
}

void list_clear(List *list) {

    for (ItemList *item_r = &list->head, *item_n = NULL; !list_is_empty(list);
         item_r->next = item_n) {

        item_n = item_r->next->next;
        free(item_r->next->data);
        free(item_r->next);
    }

    list->rear = &list->head;
}

int list_index_of(List *list, void *value, ICOMPARATOR) {

    int i = 0;
    ItemList *item_r = list->head.next;

    while (item_r && comparator(item_r->data, value)) {
        item_r = item_r->next;
        i++;
    }

    return item_r ? i : -1;
}

ItemList *list_find(List *list, void *value, ICOMPARATOR) {

    ItemList *item_r = list->head.next;

    while (item_r && comparator(item_r->data, value))
        item_r = item_r->next;

    return item_r ? item_r : NULL;
}

size_t list_count(List *list, void *value, ICOMPARATOR) {

    size_t count = 0;
    ItemList *item_r = list->head.next;

    while (item_r) {
        if (!comparator(value, item_r->data))
            count++;

        item_r = item_r->next;
    }

    return count;
}

int list_extend(List *list, List *list_src) {

    if (!list || !list_src || list_is_empty(list) || list_is_empty(list_src))
        return 0;

    ItemList *item_rollback = list->rear;
    int erro_create = 0;

    for (ItemList *item_r = list_src->head.next; !erro_create && item_r;
         item_r = item_r->next) {

        erro_create = !list_append(list, item_r->data);
    }

    if (erro_create) {
        for (ItemList *item_r = list->rear, *item_p = NULL;
             item_r != item_rollback; item_r = item_p) {

            item_p = item_r->previous;
            list_remove_item(list, item_r);
        }
    }

    return erro_create;
}