/**
 * @author Ytalo Ramon
 * @date   03/01/2022
 */

#include "../include/circular_doubly_linked_list.h"
#include "stdlib.h"

CdlList *cdll_new() {

    CdlList *cdll = malloc(sizeof(CdlList));

    if (!cdll)
        return NULL;

    cdll->head.previous = cdll->head.next = NULL;
    cdll->length = 0;

    return cdll;
}

int cdll_is_empty(CdlList *cdll) { return cdll->head.next == NULL; }

int cdll_append(CdlList *cdll, DllItem *new_item) {

    if (!cdll_is_empty(cdll)) {
        int rs = cdll_item_append(new_item, cdll->head.next->previous);
        cdll->length += rs;

        return rs;
    }

    if (!new_item)
        return 0;

    cdll_item_link(new_item, new_item, new_item);
    cdll->head.next = new_item;
    cdll->length++;

    return 1;
}

DllItem *cdll_remove(CdlList *cdll) {

    if (cdll_is_empty(cdll))
        return NULL;

    DllItem *rm_item = cdll->head.next;

    if (rm_item == rm_item->previous) {
        cdll->head.next = NULL;
        rm_item->previous = rm_item->next = NULL;
    } else {
        cdll->head.next = rm_item->next;
        cdll_item_remove(rm_item);
    }

    cdll->length--;

    return rm_item;
}

DllItem *cdll_find(CdlList *cdll, void *elmnt, ICOMPARATOR) {

    if (cdll_is_empty(cdll))
        return NULL;

    return cdll_item_find(cdll->head.next, cdll->head.next->previous, elmnt,
                          comparator);
}

size_t cdll_count(CdlList *cdll, void *elmnt, ICOMPARATOR) {

    if (cdll_is_empty(cdll))
        return 0;

    return cdll_item_count(cdll->head.next, cdll->head.next->previous, elmnt,
                           comparator);
}

int cdll_offset(CdlList *cdll, void *elmnt, ICOMPARATOR) {

    if (cdll_is_empty(cdll))
        return -1;

    return cdll_item_offset(cdll->head.next, cdll->head.next->previous, elmnt,
                            comparator);
}

void cdll_item_link(DllItem *item, DllItem *prev, DllItem *next) {

    item->previous = prev;
    item->next = next;
    prev->next = next->previous = item;
}

int cdll_item_append(DllItem *new_item, DllItem *prev_item) {

    if (!new_item || !prev_item)
        return 0;

    cdll_item_link(new_item, prev_item, prev_item->next);

    return 1;
}

int cdll_item_remove(DllItem *rm_item) {

    if (!rm_item)
        return 0;

    rm_item->previous->next = rm_item->next;
    rm_item->next->previous = rm_item->previous;
    rm_item->previous = rm_item->next = NULL;

    return 1;
}

DllItem *cdll_item_find(DllItem *item_s, DllItem *item_e, void *elmnt,
                        ICOMPARATOR) {

    if (!item_s || !item_e)
        return NULL;

    for (DllItem *item_r = item_s; item_r != item_e; item_r = item_r->next) {

        if (comparator(elmnt, item_r) == 0)
            return item_r;
    }

    return comparator(elmnt, item_e) == 0 ? item_e : NULL;
}

size_t cdll_item_count(DllItem *item_s, DllItem *item_e, void *elmnt,
                       ICOMPARATOR) {

    if (!item_s || !item_e)
        return 0;

    size_t count = 0;

    for (DllItem *item_r = item_s; item_r != item_e; item_r = item_r->next)
        count += (comparator(elmnt, item_r) == 0 ? 1 : 0);

    return count + (comparator(elmnt, item_e) == 0 ? 1 : 0);
}

int cdll_item_offset(DllItem *item_s, DllItem *item_e, void *elmnt,
                     ICOMPARATOR) {

    if (!item_s || !item_e)
        return -1;

    size_t offset = 0;

    for (DllItem *item_r = item_s; item_r != item_e; item_r = item_r->next) {

        if (comparator(elmnt, item_r) == 0)
            return offset;

        offset++;
    }

    return comparator(elmnt, item_e) == 0 ? offset : -1;
}

int cdll_item_join(DllItem *item_s1, DllItem *item_s2) {

    if (!item_s1 || !item_s2)
        return 0;

    DllItem *prev_s2 = item_s2->previous;

    item_s1->previous->next = item_s2;
    item_s2->previous = item_s1->previous;
    prev_s2->next = item_s1;
    item_s1->previous = prev_s2;

    return 1;
}
