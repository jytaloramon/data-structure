/**
 * @author Ytalo Ramon
 * @date   15/01/2022
 */

#include "../include/heap_fib.h"
#include "../../../includes/istructure_utils.h"
#include "stdlib.h"

HeapFib *heapf_new() {

    HeapFib *heap = malloc(sizeof(HeapFib));

    if (heap) {
        heap->length = 0;
        heap->min_item = NULL;
    }

    return heap;
}

int heapf_is_empty(HeapFib *heap) { return heap->min_item == NULL; }

int heapf_insert(HeapFib *heap, HeapFibItem *new_item, ICOMPARATOR) {

    if (!new_item)
        return 0;

    new_item->father = new_item->child = NULL;
    new_item->is_marked = new_item->degree = 0;

    if (heapf_is_empty(heap)) {
        cdll_item_link(&new_item->cdll_item, &new_item->cdll_item,
                       &new_item->cdll_item);
    } else {
        cdll_item_append(&new_item->cdll_item,
                         heap->min_item->cdll_item.previous);
    }

    if (!heap->min_item || comparator(heap->min_item, new_item) > 0)
        heap->min_item = new_item;

    ++heap->length;

    return 1;
}

HeapFibItem *heapf_extract_min(HeapFib *heap, ICOMPARATOR) {

    HeapFibItem *min_item_rm = heap->min_item;
    heapf_item_remove(heap, min_item_rm, comparator);

    return min_item_rm;
}

int heapf_remove(HeapFib *heap, HeapFibItem *rm_item, ICOMPARATOR) {

    if (heapf_is_empty(heap) || !rm_item)
        return 0;

    if (rm_item->father)
        heapf_cut(heap, rm_item);

    return heapf_item_remove(heap, rm_item, comparator);
}

int heapf_decrease_key(HeapFib *heap, HeapFibItem *up_item, ICOMPARATOR) {

    if (!up_item)
        return 0;

    if (up_item->father && comparator(up_item->father, up_item) > 0)
        heapf_cut(heap, up_item);

    if (comparator(heap->min_item, up_item) > 0)
        heap->min_item = up_item;

    return 1;
}

void heapf_consolidate(HeapFib *heap, ICOMPARATOR) {

    if (heapf_is_empty(heap))
        return;

    HeapFibItem *item_s = heap->min_item,
                **items_dg = calloc(heap->length, sizeof(HeapFibItem *)),
                *item_r = GETSTRUCTFROM(item_s->cdll_item.next, HeapFibItem,
                                        cdll_item),
                *item_a = NULL, *item_b = NULL, *item_n = NULL;

    items_dg[item_s->degree] = item_s;

    while (item_r != item_s) {
        item_a = item_r;
        item_b = items_dg[item_a->degree];
        item_n = GETSTRUCTFROM(item_r->cdll_item.next, HeapFibItem, cdll_item);

        while (item_b) {
            items_dg[item_a->degree] = NULL;

            if (comparator(item_a, item_b) > 0) {
                HeapFibItem *item_aux = item_a;
                item_a = item_b;
                item_b = item_aux;
            }

            if (item_b == item_s) {
                item_s = GETSTRUCTFROM(item_b->cdll_item.next, HeapFibItem,
                                       cdll_item);
            }

            cdll_item_remove(&item_b->cdll_item);

            if (item_a->child) {
                cdll_item_append(&item_b->cdll_item,
                                 item_a->child->cdll_item.previous);
            } else {
                cdll_item_link(&item_b->cdll_item, &item_b->cdll_item,
                               &item_b->cdll_item);
                item_a->child = item_b;
            }

            item_b->father = item_a;
            ++item_a->degree;
            item_b = items_dg[item_a->degree];
        }

        items_dg[item_a->degree] = item_a;

        if (comparator(heap->min_item, item_a) > 0)
            heap->min_item = item_a;

        item_r = item_n;
    }

    free(items_dg);
}

void heapf_cut(HeapFib *heap, HeapFibItem *up_item) {

    if (!up_item)
        return;

    HeapFibItem *item_r = up_item, *father = NULL;

    do {
        father = item_r->father;
        item_r->father = NULL;
        item_r->is_marked = 0;

        if (father) {
            if (cdll_item_is_alone(&item_r->cdll_item)) {
                father->child = NULL;
            } else {
                if (&father->child->cdll_item == &item_r->cdll_item) {
                    father->child = GETSTRUCTFROM(item_r->cdll_item.next,
                                                  HeapFibItem, cdll_item);
                }

                cdll_item_remove(&item_r->cdll_item);
            }

            cdll_item_append(&item_r->cdll_item,
                             heap->min_item->cdll_item.previous);
            --father->degree;

            if (!father->is_marked) {
                father->is_marked = 1;
                father = NULL;
            }
        }

        item_r = father;
    } while (item_r);
}

HeapFibItem *heapf_peek(HeapFib *heap) {

    return heapf_is_empty(heap) ? NULL : heap->min_item;
}

HeapFibItem *heapf_find(HeapFib *heap, void *elmnt, ICOMPARATOR) {

    if (heapf_is_empty(heap))
        return NULL;

    int rs = 0;
    size_t ls = 0, le = 0;
    DllItem *lists[heap->length];
    HeapFibItem *item_s = NULL;

    lists[le++] = &heap->min_item->cdll_item;

    while (ls < le) {

        item_s = GETSTRUCTFROM(lists[ls++], HeapFibItem, cdll_item);

        rs = comparator(elmnt, item_s);
        if (rs == 0)
            return item_s;

        if (rs > 0 && item_s->child)
            lists[le++] = &item_s->child->cdll_item;

        for (HeapFibItem *item_r =
                 GETSTRUCTFROM(item_s->cdll_item.next, HeapFibItem, cdll_item);
             item_r != item_s; item_r = GETSTRUCTFROM(item_r->cdll_item.next,
                                                      HeapFibItem, cdll_item)) {

            rs = comparator(elmnt, item_r);
            if (rs == 0)
                return item_r;

            if (rs > 0 && item_r->child)
                lists[le++] = &item_r->child->cdll_item;
        }
    }

    return NULL;
}

int heapf_union(HeapFib *heap, HeapFib *heap_from, ICOMPARATOR) {

    if (!heap || !heap_from)
        return 0;

    if (heapf_is_empty(heap_from))
        return 1;

    HeapFibItem *min_global = heap_from->min_item;

    if (!heapf_is_empty(heap)) {
        cdll_item_join(&heap->min_item->cdll_item,
                       &heap_from->min_item->cdll_item);

        if (comparator(heap->min_item, min_global) > 0)
            min_global = heap->min_item;
    }

    heap->min_item = min_global;
    heap->length += heap_from->length;

    return 1;
}

int heapf_item_remove(HeapFib *heap, HeapFibItem *rm_item, ICOMPARATOR) {

    if (heapf_is_empty(heap) || !rm_item)
        return 0;

    if (rm_item->child) {
        rm_item->child->father = NULL;
        for (HeapFibItem *item_r = GETSTRUCTFROM(rm_item->child->cdll_item.next,
                                                 HeapFibItem, cdll_item);
             item_r != rm_item->child;
             item_r = GETSTRUCTFROM(item_r->cdll_item.next, HeapFibItem,
                                    cdll_item)) {
            item_r->father = NULL;
        }

        cdll_item_join(&heap->min_item->cdll_item, &rm_item->child->cdll_item);
    }

    heap->min_item =
        cdll_item_is_alone(&rm_item->cdll_item)
            ? NULL
            : GETSTRUCTFROM(rm_item->cdll_item.next, HeapFibItem, cdll_item);

    rm_item->is_marked = rm_item->degree = 0;
    rm_item->child = NULL;
    cdll_item_remove(&rm_item->cdll_item);

    if (!heapf_is_empty(heap))
        heapf_consolidate(heap, comparator);

    --heap->length;

    return 1;
}
