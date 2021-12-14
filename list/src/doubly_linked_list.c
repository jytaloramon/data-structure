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

int list_is_empty(List *list) { return list->head.next == NULL; }

int list_append(List *list, ItemList *new_item) {

    if (!new_item)
        return 0;

    if (!list_is_empty(list))
        new_item->previous = list->rear;
    
    new_item->next = NULL;
    list->rear->next = new_item;
    list->rear = list->rear->next;
    list->length++;

    return 1;
}

int list_insert_at(List *list, ItemList *new_item, int index) {

    if (!new_item || index < 0 || index > list->length)
        return 0;

    if (index == list->length)
        return list_append(list, new_item);

    ItemList *item_r = &list->head;
    for (size_t i = 0; i < index; ++i, item_r = item_r->next)
        ;

    int rs = list_insert_after_item(list, item_r, new_item);

    if (rs && index == 0)
        list->head.next->previous = NULL;

    return rs;
}

int list_insert_after_item(List *list, ItemList *item_base,
                           ItemList *new_item) {

    if (!new_item)
        return 0;

    new_item->previous = item_base;
    new_item->next = item_base->next;
    item_base->next->previous = new_item;
    item_base->next = new_item;
    list->length++;

    return 1;
}

ItemList *list_remove(List *list) {

    if (list_is_empty(list))
        return NULL;

    ItemList *item_aux = list->head.next;
    return list_remove_item(list, item_aux) ? item_aux : NULL;
}

ItemList *list_remove_at(List *list, int index) {

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

    return list_remove_item(list, item_r) ? item_r : NULL;
}

int list_remove_item(List *list, ItemList *item) {

    if (!item)
        return 0;

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

    list->length--;

    return 1;
}

int list_index_of(List *list, void *elmnt, ICOMPARATOR) {

    int i = 0;
    ItemList *item_r = list->head.next;

    while (item_r && comparator(elmnt, item_r)) {
        item_r = item_r->next;
        i++;
    }

    return item_r ? i : -1;
}

ItemList *list_find(List *list, void *elmnt, ICOMPARATOR) {

    ItemList *item_r = list->head.next;

    while (item_r && comparator(elmnt, item_r))
        item_r = item_r->next;

    return item_r ? item_r : NULL;
}

size_t list_count(List *list, void *elmnt, ICOMPARATOR) {

    size_t count = 0;
    ItemList *item_r = list->head.next;

    while (item_r) {
        if (!comparator(elmnt, item_r))
            count++;

        item_r = item_r->next;
    }

    return count;
}
