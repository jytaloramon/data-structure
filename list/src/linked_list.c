/**
 * @author Ytalo Ramon
 * @date   31/01/2022
 */

#include "../include/linked_list.h"
#include "stdlib.h"

LList *ll_new() {

    LList *ll = malloc(sizeof(LList));

    if (ll) {
        ll->head.next = NULL;
        ll->rear = &ll->head;
        ll->length = 0;
    }

    return ll;
}

int ll_is_empty(LList *ll) { return ll->head.next == NULL; }

int ll_append(LList *ll, LlItem *new_item) {

    if (!new_item)
        return 0;

    ll_item_append(new_item, ll->rear);
    ll->rear = new_item;
    ++ll->length;

    return 1;
}

int ll_insert_at(LList *ll, LlItem *new_item, size_t index) {

    if (!new_item)
        return 0;

    if (ll->length == index)
        return ll_append(ll, new_item);

    if (index == 0) {
        new_item->next = ll->head.next;
        ll->head.next = new_item;
    } else {
        LlItem *item_r = ll->head.next;
        for (size_t i = 1; i < index; ++i, item_r = item_r->next);
        
        ll_item_append(new_item, item_r);
    }

    ++ll->length;

    return 1;
}

LlItem *ll_remove(LList *ll) {

    if (ll_is_empty(ll))
        return NULL;

    LlItem *rm_item = ll->head.next;
    ll_item_remove_next(&ll->head);

    if (ll_is_empty(ll))
        ll->rear = &ll->head;

    --ll->length;

    return rm_item;
}

LlItem *ll_remove_at(LList *ll, size_t index) {

    if (ll_is_empty(ll) || index >= ll->length)
        return NULL;

    if (index == 0)
        return ll_remove(ll);

    LlItem *item_r = ll->head.next;
    for (size_t i = 1; i < index; ++i, item_r = item_r->next);

    LlItem *rm_item = item_r->next;
    ll_item_remove_next(item_r);

    if (!item_r->next)
        ll->rear = item_r;

    --ll->length;

    return rm_item;
}

LlItem *ll_find(LList *ll, void *elmnt, ICOMPARATOR) {

    return ll_item_find(ll->head.next, NULL, elmnt, comparator);
}

size_t ll_count(LList *ll, void *elmnt, ICOMPARATOR) {

    return ll_item_count(ll->head.next, NULL, elmnt, comparator);
}

int ll_index_of(LList *ll, void *elmnt, ICOMPARATOR) {

    return ll_item_offset(ll->head.next, NULL, elmnt, comparator);
}

int ll_merge(LList *ll1, LList *ll2) {

    if (!ll1 || !ll2)
        return 0;

    if (ll_is_empty(ll2))
        return 1;

    if (ll_is_empty(ll1))
        ll1->head.next = ll2->head.next;
    else
        ll_item_merge(ll1->rear, ll2->head.next);

    ll1->length += ll2->length;
    ll1->rear = ll2->rear;

    return 1;
}

int ll_item_append(LlItem *new_item, LlItem *prev_item) {

    if (!new_item || !prev_item)
        return 0;

    new_item->next = prev_item->next;
    prev_item->next = new_item;

    return 1;
}

int ll_item_remove_next(LlItem *prev_item) {

    if (!prev_item || !prev_item->next)
        return 0;

    LlItem *rm_item = prev_item->next;
    prev_item->next = rm_item->next;
    rm_item->next = NULL;

    return 1;
}

LlItem *ll_item_find(LlItem *item_s, LlItem *item_e, void *elmnt, ICOMPARATOR) {

    if (!item_s)
        return NULL;

    for (LlItem *item_r = item_s; item_r != item_e; item_r = item_r->next) {
        if (comparator(elmnt, item_r) == 0)
            return item_r;
    }

    return NULL;
}

size_t ll_item_count(LlItem *item_s, LlItem *item_e, void *elmnt, ICOMPARATOR) {

    if (!item_s)
        return 0;

    size_t count = 0;

    for (LlItem *item_r = item_s; item_r != item_e; item_r = item_r->next)
        count += comparator(elmnt, item_r) == 0 ? 1 : 0;

    return count;
}

int ll_item_offset(LlItem *item_s, LlItem *item_e, void *elmnt, ICOMPARATOR) {

    if (!item_s)
        return 0;

    size_t offset = 0;

    for (LlItem *item_r = item_s; item_r != item_e; item_r = item_r->next) {
        if (comparator(elmnt, item_r) == 0)
            return offset;

        offset++;
    }

    return -1;
}

int ll_item_merge(LlItem *item_ls1, LlItem *item_fs2) {

    if (!item_ls1 || !item_fs2)
        return 0;

    item_ls1->next = item_fs2;

    return 1;
}
