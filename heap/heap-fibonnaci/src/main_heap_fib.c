/**
 * @author Ytalo Ramon
 * @date   22/01/2022
 */

#include "../../../includes/istructure_utils.h"
#include "../include/heap_fib.h"
#include "stdio.h"
#include "stdlib.h"

#define INPUTSIZE 24 // Input size for test.

enum options { INSERT, EXTRACTMIN, REMOVE, DECREASEKEY, PEEK, FIND };

typedef struct _CelFib {
    int value;
    struct _HeapFibItem f_item;
} CelFib;

#define SHOWCEL(heap_f_item)                                                   \
    do {                                                                       \
        CelFib *cel_aux = GETSTRUCTFROM(heap_f_item, CelFib, f_item);          \
        printf("(%d | %lu | %d)", cel_aux->value, cel_aux->f_item.degree,      \
               cel_aux->f_item.is_marked);                                     \
    } while (0);

int comp_fitem_fitem(void *const a, void *const b);

int comp_elmnt_fitem(void *const a, void *const b);

void heapf_show(HeapFib *heap);

int main(int argc, char const *argv[]) {

    char test_cases[INPUTSIZE][2] = {
        {INSERT, 10},      {INSERT, 20},      {INSERT, 40},
        {INSERT, 35},      {INSERT, 50},      {INSERT, 15},
        {EXTRACTMIN, '_'}, {INSERT, 100},     {INSERT, 95},
        {INSERT, 2},       {INSERT, 41},      {EXTRACTMIN, '_'},
        {FIND, 40},        {DECREASEKEY, 17}, {FIND, 35},
        {DECREASEKEY, 21}, {FIND, 15},        {REMOVE, '_'},
        {INSERT, 110},     {EXTRACTMIN, '_'}, {EXTRACTMIN, '_'},
        {FIND, 95},        {DECREASEKEY, 8},  {EXTRACTMIN, '_'},
    };

    char v_a = 0, op = 0;
    int rs = 0;
    CelFib *cel_f_aux = NULL;
    HeapFibItem *heapf_i_aux = NULL;

    HeapFib *heapf = heapf_new();

    printf("+++++ HEAP FIBONNACI +++++\n\n");
    heapf_show(heapf);

    for (size_t i = 0; i < INPUTSIZE; ++i) {
        op = test_cases[i][0];
        v_a = test_cases[i][1];

        switch (op) {
        case INSERT:
            printf("* INSERT %d: ", v_a);

            cel_f_aux = malloc(sizeof(CelFib));
            cel_f_aux->value = v_a;

            rs = heapf_insert(heapf, &cel_f_aux->f_item, comp_fitem_fitem);
            printf("%s!\n\n", rs ? "Success" : "Fail");

            heapf_show(heapf);
            break;
        case EXTRACTMIN:
            printf("* EXTRACTMIN:");
            heapf_i_aux = heapf_extract_min(heapf, comp_fitem_fitem);

            if (!heapf_i_aux) {
                printf("Fail!\n\n");
            } else {
                cel_f_aux = GETSTRUCTFROM(heapf_i_aux, CelFib, f_item);
                printf("%d\n\n", cel_f_aux->value);
            }

            heapf_show(heapf);
            break;
        case REMOVE:
            printf("* REMOVE ");
            SHOWCEL(heapf_i_aux);

            rs = heapf_remove(heapf, heapf_i_aux, comp_fitem_fitem);
            printf(": %s!\n\n", rs ? "Success" : "Fail");

            heapf_show(heapf);
            break;
        case DECREASEKEY:
            printf("* DECREASEKEY ");
            SHOWCEL(heapf_i_aux);
            printf(" TO (%d): ", v_a);

            // Update valeu
            ((CelFib *)GETSTRUCTFROM(heapf_i_aux, CelFib, f_item))->value = v_a;

            rs = heapf_decrease_key(heapf, heapf_i_aux, comp_fitem_fitem);
            printf("%s!\n\n", rs ? "Success" : "Fail");

            heapf_show(heapf);
            break;
        case PEEK:
            printf("* PEEK: ");
            heapf_i_aux = heapf_peek(heapf);

            if (!heapf_i_aux) {
                printf("Empty!");
            } else {
                SHOWCEL(heapf_i_aux);
                printf("\n");
            }
            break;
        case FIND:
            printf("* FIND (%d): ", v_a);
            heapf_i_aux = heapf_find(heapf, &v_a, comp_elmnt_fitem);

            if (!heapf_i_aux) {
                printf("Not Found!");
            } else {
                SHOWCEL(heapf_i_aux);
            }
            break;

        default:
            printf("NOT AN OPTION!");
        }

        printf("\n\n");
    }

    return 0;
}

int comp_fitem_fitem(void *const a, void *const b) {

    CelFib *c_a = GETSTRUCTFROM(a, CelFib, f_item),
           *c_b = GETSTRUCTFROM(b, CelFib, f_item);

    return c_a->value - c_b->value;
}

int comp_elmnt_fitem(void *const a, void *const b) {

    int v_a = *(char *)a;
    CelFib *c_b = GETSTRUCTFROM(b, CelFib, f_item);

    return v_a - c_b->value;
}

void heapf_show(HeapFib *heap) {

    printf("---- Status ----\n");

    if (heapf_is_empty(heap)) {
        printf("Empty\n");
    } else {

        size_t ls = 0, le = 0;
        HeapFibItem *item_s = NULL;
        DllItem *lists[heap->length];

        lists[le++] = &heap->min_item->cdll_item;

        printf("HEAP_min=%d | LEN=%lu\n",
               ((CelFib *)GETSTRUCTFROM(heap->min_item, CelFib, f_item))->value,
               heap->length);

        while (ls < le) {

            item_s = (HeapFibItem *)GETSTRUCTFROM(lists[ls++], HeapFibItem,
                                                  cdll_item);

            item_s->father ? printf("\n> Father: %d\n",
                                    ((CelFib *)GETSTRUCTFROM(item_s->father,
                                                             CelFib, f_item))
                                        ->value)
                           : printf("\n> Father: root\n");

            SHOWCEL(item_s);
            printf(", ");

            if (item_s->child)
                lists[le++] = &item_s->child->cdll_item;

            for (HeapFibItem *item_r = (HeapFibItem *)GETSTRUCTFROM(
                     item_s->cdll_item.next, HeapFibItem, cdll_item);
                 item_r != item_s;
                 item_r = (HeapFibItem *)GETSTRUCTFROM(
                     item_r->cdll_item.next, HeapFibItem, cdll_item)) {

                SHOWCEL(item_r);
                printf(", ");

                if (item_r->child)
                    lists[le++] = &item_r->child->cdll_item;
            }
        }

        printf("\n");
    }
    printf("----------------\n\n");
}
