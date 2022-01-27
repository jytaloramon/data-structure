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
    new_item->mark = new_item->degree = 0;

    if (!heapf_is_empty(heap)) {
        cdll_item_append(&new_item->cdll_item,
                         heap->min_item->cdll_item.previous);
    } else {
        cdll_item_link(&new_item->cdll_item, &new_item->cdll_item,
                       &new_item->cdll_item);
    }

    if (!heap->min_item || comparator(heap->min_item, new_item) > 0)
        heap->min_item = new_item;

    ++heap->length;

    return 1;
}

HeapFibItem *heapf_extract_min(HeapFib *heap, ICOMPARATOR) {

    if (heapf_is_empty(heap))
        return NULL;

    HeapFibItem *min_item_rm = heap->min_item;

    if (min_item_rm->child) {
        cdll_item_join(&min_item_rm->cdll_item, &min_item_rm->child->cdll_item);

        min_item_rm->child->father = NULL;
        for (HeapFibItem *hpf_item = (HeapFibItem *)GETSTRUCTFROM(
                 min_item_rm->child->cdll_item.next, HeapFibItem, cdll_item);
             hpf_item != min_item_rm->child;
             hpf_item = (HeapFibItem *)GETSTRUCTFROM(hpf_item->cdll_item.next,
                                                     HeapFibItem, cdll_item)) {
            hpf_item->father = NULL;
        }
    }

    heap->min_item =
        cdll_item_is_alone(&min_item_rm->cdll_item)
            ? NULL
            : (HeapFibItem *)GETSTRUCTFROM(min_item_rm->cdll_item.next,
                                           HeapFibItem, cdll_item);

    min_item_rm->mark = min_item_rm->degree = 0;
    min_item_rm->child = NULL;
    cdll_item_remove(&min_item_rm->cdll_item);

    if (!heapf_is_empty(heap))
        heapf_consolidate(heap, comparator);

    --heap->length;

    return min_item_rm;
}

int *heapf_remove(HeapFib *heap, HeapFibItem *rm_item, ICOMPARATOR);

void heapf_consolidate(HeapFib *heap, ICOMPARATOR) {

    if (heapf_is_empty(heap))
        return;

    HeapFibItem **hpf_list = calloc(heap->length, sizeof(HeapFibItem *));
    hpf_list[heap->min_item->degree] = heap->min_item;

    HeapFibItem *hpf_item = (HeapFibItem *)GETSTRUCTFROM(
        heap->min_item->cdll_item.next, HeapFibItem, cdll_item);

    while (hpf_item != heap->min_item) {
        HeapFibItem *hpfi_a = hpf_item, *hpfi_b = hpf_list[hpfi_a->degree];

        while (hpfi_b) {

            hpf_list[hpfi_a->degree] = NULL;

            if (comparator(hpfi_a, hpfi_b) > 0) {
                HeapFibItem *hpfi_aux = hpfi_a;
                hpfi_a = hpfi_b;
                hpfi_b = hpfi_aux;
            }

            cdll_item_remove(&hpfi_b->cdll_item);

            if (hpfi_a->child) {
                cdll_item_append(&hpfi_b->cdll_item,
                                 hpfi_a->child->cdll_item.previous);
            } else {
                cdll_item_link(&hpfi_b->cdll_item, &hpfi_b->cdll_item,
                               &hpfi_b->cdll_item);
                hpfi_a->child = hpfi_b;
            }

            hpfi_b->father = hpfi_a;
            ++hpfi_a->degree;
            hpfi_b = hpf_list[hpfi_a->degree];
        }

        hpf_list[hpfi_a->degree] = hpfi_a;

        if (comparator(heap->min_item, hpfi_a) > 0)
            heap->min_item = hpfi_a;

        hpf_item = (HeapFibItem *)GETSTRUCTFROM(hpfi_a->cdll_item.next,
                                                HeapFibItem, cdll_item);
    }

    free(hpf_list);
}

HeapFibItem *heapf_peek(HeapFib *heap) {

    return heapf_is_empty(heap) ? NULL : heap->min_item;
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
