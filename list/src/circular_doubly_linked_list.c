/**
 * @author Ytalo Ramon
 * @date   16/11/2021
 */

#include "../include/circular_doubly_linked_list.h"
#include "stdio.h"
#include "string.h"

// Temp. Prototypes

int cdll_item_is_null(DllItem *item);
int cdll_item_append(DllItem *new_item, DllItem *prev_item);
int cdll_item_remove(DllItem *rm_item);

List *list_new() {

    List *list = malloc(sizeof(List));

    if (!list)
        return NULL;

    list->head.previous = list->head.next = NULL;
    list->length = 0;

    return list;
}

int list_append(List *list, ItemList *new_item) {

    if (!new_item)
        return 0;

    if (!list_is_empty(list))
        return list_insert_after_item(list, list->head.next->previous,
                                      new_item);

    new_item->previous = new_item->next = new_item;
    list->head.next = new_item;
    list->length++;

    return 1;
}

ItemList *list_remove(List *list) {

    if (list_is_empty(list))
        return NULL;

    ItemList *item_list = list->head.next;

    return list_remove_item(list, item_list) ? item_list : 0;
}

int list_remove_item(List *list, ItemList *item) {

    if (!item)
        return 0;

    if (item == item->previous) {
        list->head.next = NULL;
    } else {
        item->previous->next = item->next;
        item->next->previous = item->previous;

        if (list->head.next == item)
            list->head.next = item->next;
    }

    list->length--;

    return 1;
}

ItemList *list_find(List *list, void *elmnt, ICOMPARATOR) {

    if (list_is_empty(list))
        return NULL;

    ItemList *item = list->head.next;

    if (!comparator(elmnt, item))
        return item;

    int rs = 1;
    item = item->next;

    while (item != list->head.next && (rs = comparator(elmnt, item))) {
        item = item->next;
    }

    return !rs ? item : NULL;
}

size_t list_count(List *list, void *elmnt, ICOMPARATOR) {

    if (list_is_empty(list))
        return 0;

    ItemList *item = list->head.next->next;
    int count = !comparator(elmnt, list->head.next);

    while (item != list->head.next) {
        count += !comparator(elmnt, item);
        item = item->next;
    }

    return count;
}

int cdll_item_is_null(DllItem *item) { return item = NULL; }

int cdll_item_append(DllItem *new_item, DllItem *prev_item) {

    if (cdll_item_is_null(new_item) || cdll_item_is_null(prev_item))
        return 0;

    new_item->previous = prev_item;
    new_item->next = prev_item->next;
    prev_item->next->previous = new_item;
    prev_item->next = new_item;

    return 1;
}

int cdll_item_remove(DllItem *rm_item) {

    if (cdll_item_is_null(rm_item))
        return 0;

    rm_item->previous = rm_item->next;
    rm_item->next->previous = rm_item->previous;

    return 1;
}