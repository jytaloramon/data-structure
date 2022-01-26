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

    HeapFibItem a = {.value = 5}, b = {.value = 10}, c = {.value = 1},
                d = {.value = 100}, e = {.value = 0}, f = {.value = 8};

    heapf_insert(heapf, &a, comp);
    printf("a inserido\n");
    heapf_show(heapf);

    heapf_insert(heapf, &b, comp);
    printf("b inserido\n");
    heapf_show(heapf);

    heapf_insert(heapf, &c, comp);
    printf("c inserido\n");
    heapf_show(heapf);

    heapf_insert(heapf, &d, comp);
    printf("d inserido\n");
    heapf_show(heapf);

    heapf_insert(heapf, &e, comp);
    printf("e inserido\n");
    heapf_show(heapf);

    heapf_insert(heapf, &f, comp);
    printf("f inserido\n");
    heapf_show(heapf);

    heapf_extract_min(heapf, comp);
    printf("MIN REMOVE\n");
    heapf_show(heapf);

    heapf_extract_min(heapf, comp);
    printf("MIN REMOVE\n");
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
        printf("%d, ", heapf_temp->value);

        if (heapf_temp->child)
            lists[le++] = &heapf_temp->child->cdll_item;

        for (HeapFibItem *hpf_r = (HeapFibItem *)GETSTRUCTFROM(
                 heapf_temp->cdll_item.next, HeapFibItem, cdll_item);
             hpf_r != heapf_temp;
             hpf_r = (HeapFibItem *)GETSTRUCTFROM(hpf_r->cdll_item.next,
                                                  HeapFibItem, cdll_item)) {

            printf("%d, ", hpf_r->value);

            if (hpf_r->child)
                lists[le++] = &hpf_r->child->cdll_item;
        }

        printf("\n\n");
    }

    printf("\n\n");
}