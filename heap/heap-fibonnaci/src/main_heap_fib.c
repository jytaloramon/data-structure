/**
 * @author Ytalo Ramon
 * @date   22/01/2022
 */

#include "../../../includes/istructure_utils.h"
#include "../include/heap_fib.h"
#include "stdio.h"
#include "stdlib.h"

int comp(void *const a, void *const b);

void heapf_show(HeapFib *heap);

int main(int argc, char const *argv[]) {

    HeapFib *heapf = heapf_new();

    HeapFibItem heapf_items[10] = {{.value = 10},  {.value = 20}, {.value = 40},
                                   {.value = 35},  {.value = 50}, {.value = 15},
                                   {.value = 100}, {.value = 95}, {.value = 2},
                                   {.value = 41}};

    heapf_insert(heapf, &heapf_items[0], comp);
    heapf_insert(heapf, &heapf_items[1], comp);
    heapf_insert(heapf, &heapf_items[2], comp);
    heapf_insert(heapf, &heapf_items[3], comp);
    heapf_insert(heapf, &heapf_items[4], comp);
    heapf_insert(heapf, &heapf_items[5], comp);
    heapf_show(heapf);

    heapf_extract_min(heapf, comp);
    heapf_show(heapf);

    heapf_insert(heapf, &heapf_items[6], comp);
    heapf_insert(heapf, &heapf_items[7], comp);
    heapf_insert(heapf, &heapf_items[8], comp);
    heapf_insert(heapf, &heapf_items[9], comp);
    heapf_show(heapf);

    heapf_extract_min(heapf, comp);
    heapf_show(heapf);

    return 0;
}

int comp(void *const a, void *const b) {

    HeapFibItem *h_a = (HeapFibItem *)a, *h_b = (HeapFibItem *)b;

    return h_a->value - h_b->value;
}

void heapf_show(HeapFib *heap) {

    printf("+++++ Heap Fibonacci +++++\n");

    if (heapf_is_empty(heap)) {
        printf("Empty\n\n");
        return;
    }

    int ls = 0, le = 0;
    HeapFibItem *heapf_temp = NULL;
    DllItem *lists[heap->length];
    lists[le++] = &heap->min_item->cdll_item;

    printf("HEAP_min=%d\n\n", heap->min_item->value);

    while (ls < le) {

        heapf_temp =
            (HeapFibItem *)GETSTRUCTFROM(lists[ls++], HeapFibItem, cdll_item);

        heapf_temp->father ? printf("Father: %d\n", heapf_temp->father->value)
                           : printf("Father: root\n");
        printf("(%d | %lu | %d), ", heapf_temp->value, heapf_temp->degree,
               heapf_temp->is_marked);

        if (heapf_temp->child)
            lists[le++] = &heapf_temp->child->cdll_item;

        for (HeapFibItem *hpf_r = (HeapFibItem *)GETSTRUCTFROM(
                 heapf_temp->cdll_item.next, HeapFibItem, cdll_item);
             hpf_r != heapf_temp;
             hpf_r = (HeapFibItem *)GETSTRUCTFROM(hpf_r->cdll_item.next,
                                                  HeapFibItem, cdll_item)) {

            printf("(%d | %lu | %d), ", hpf_r->value, hpf_r->degree,
                   hpf_r->is_marked);

            if (hpf_r->child)
                lists[le++] = &hpf_r->child->cdll_item;
        }

        printf("\n\n");
    }

    printf("\n\n");
}