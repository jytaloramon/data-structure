/**
 * @author Ytalo Ramon
 * @date   10/01/2022
 */

#include "../include/doubly_linked_list.h"
#include "stdlib.h"

DlList *dll_new() {

    DlList *dll = malloc(sizeof(DlList));

    if (!dll)
        return NULL;

    dll_item_link(&dll->head, NULL, NULL);
    dll->rear = &dll->head;
    dll->length = 0;

    return dll;
}

int dll_is_empty(DlList *dll) { return dll->head.next == NULL; }

int dll_append(DlList *dll, DllItem *new_item) {

    if (!new_item)
        return 0;

    if (!dll_is_empty(dll)) {
        dll_item_append(new_item, dll->rear);
    } else {
        dll_item_link(new_item, NULL, NULL);
        dll->rear->next = new_item;
    }

    dll->rear = new_item;
    ++dll->length;

    return 1;
}

int dll_insert_at(DlList *dll, DllItem *new_item, size_t index) {

    if (!new_item || index > dll->length)
        return 0;

    if (index == dll->length)
        return dll_append(dll, new_item);

    if (index == 0) {
        dll_item_link(new_item, NULL, dll->head.next);
        dll->head.next = new_item;
    } else {
        DllItem *item_r = dll->head.next;
        for (size_t i = 1; i < index; ++i, item_r = item_r->next);
        dll_item_append(new_item, item_r);
    }

    ++dll->length;

    return 1;
}

DllItem *dll_remove(DlList *dll) {

    if (dll_is_empty(dll))
        return NULL;

    DllItem *rm_item = dll->head.next;
    dll->head.next = rm_item->next;
    dll_item_remove(rm_item);

    if (dll_is_empty(dll))
        dll->rear = &dll->head;

    --dll->length;

    return rm_item;
}

DllItem *dll_remove_at(DlList *dll, size_t index) {

    if (dll_is_empty(dll) || index >= dll->length)
        return NULL;

    if (index == 0)
        return dll_remove(dll);

    if (index == dll->length - 1)
        return dll_pop(dll);

    DllItem *item_r = dll->head.next->next;
    for (size_t i = 1; i < index; i++, item_r = item_r->next);
    dll_item_remove(item_r);

    --dll->length;

    return item_r;
}

DllItem *dll_pop(DlList *dll) {

    if (dll_is_empty(dll))
        return NULL;

    DllItem *rm_item = dll->rear;
    dll->rear = rm_item->previous ? rm_item->previous : &dll->head;
    dll_item_remove(rm_item);

    --dll->length;

    return rm_item;
}

DllItem *dll_find(DlList *dll, void *elmnt, ICOMPARATOR) {

    if (dll_is_empty(dll))
        return NULL;

    return dll_item_find(dll->head.next, dll->rear, elmnt, comparator);
}

size_t dll_count(DlList *dll, void *elmnt, ICOMPARATOR) {

    if (dll_is_empty(dll))
        return 0;

    return dll_item_count(dll->head.next, dll->rear, elmnt, comparator);
}

int dll_index_of(DlList *dll, void *elmnt, ICOMPARATOR) {

    if (dll_is_empty(dll))
        return -1;

    return dll_item_offset(dll->head.next, dll->rear, elmnt, comparator);
}

void dll_item_link(DllItem *item, DllItem *prev, DllItem *next) {

    item->previous = prev;
    item->next = next;

    if (prev)
        prev->next = item;

    if (next)
        next->previous = item;
}

int dll_item_append(DllItem *new_item, DllItem *prev_item) {

    if (!new_item || !prev_item)
        return 0;

    dll_item_link(new_item, prev_item, prev_item->next);

    return 1;
}

int dll_item_remove(DllItem *rm_item) {

    if (!rm_item)
        return 0;

    if (rm_item->previous) {
        dll_item_link(rm_item->previous, rm_item->previous->previous,
                      rm_item->next);
    } else if (rm_item->next) {
        dll_item_link(rm_item->next, NULL, rm_item->next->next);
    }

    rm_item->previous = rm_item->next = NULL;

    return 1;
}

DllItem *dll_item_find(DllItem *item_s, DllItem *item_e, void *elmnt,
                       ICOMPARATOR) {

    if (!item_s || !item_e)
        return NULL;

    for (DllItem *item_r = item_s; item_r != item_e; item_r = item_r->next) {

        if (comparator(elmnt, item_r) == 0)
            return item_r;
    }

    return comparator(elmnt, item_e) == 0 ? item_e : NULL;
}

size_t dll_item_count(DllItem *item_s, DllItem *item_e, void *elmnt,
                      ICOMPARATOR) {

    if (!item_s || !item_e)
        return 0;

    size_t count = 0;

    for (DllItem *item_r = item_s; item_r != item_e; item_r = item_r->next)
        count += (comparator(elmnt, item_r) == 0 ? 1 : 0);

    return count + (comparator(elmnt, item_e) == 0 ? 1 : 0);
}

int dll_item_offset(DllItem *item_s, DllItem *item_e, void *elmnt,
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

int dll_item_join(DllItem *item_ls1, DllItem *item_fs2) {

    if (!item_ls1 || !item_fs2)
        return 0;

    item_ls1->next = item_fs2;
    item_fs2->previous = item_ls1;

    return 1;
}
