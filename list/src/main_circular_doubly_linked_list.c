/**
 * @author Ytalo Ramon
 * @date   15/06/2021
 */

#include "../../includes/istructure_utils.h"
#include "../include/circular_doubly_linked_list.h"
#include "stdio.h"
#include "stdlib.h"
#include "string.h"

#define INPUTSIZE 35 // Input size for test.

enum options { ADD, INSERTAFTER, REMOVE, REMOVEITEM, FIND, COUNT };

typedef struct _List {
    ItemDLList *head;
    size_t length;
} List;

typedef struct _Cel {
    char data;
    struct _ItemDLList item_list;
} Cel;

int comparator(void *const a, void *const b);

void list_show(List *list);

int main(int argc, char const *argv[]) {

    int op, rs;
    size_t c;
    char *value1;
    Cel *cel_aux = NULL;
    ItemDLList *item_list_aux = NULL;

    List list = {NULL, 0};

    char test_cases[INPUTSIZE][4] = {
        {REMOVE, '_', '_'},      {ADD, 'A', '_'},        {ADD, 'B', '_'},
        {REMOVE, '_', '_'},      {REMOVE, '_', '_'},     {REMOVE, '_', '_'},
        {ADD, 'C', '_'},         {ADD, 'D', '_'},        {FIND, 'D', '_'},
        {INSERTAFTER, 'G', '_'}, {ADD, 'E', '_'},        {FIND, 'C', '_'},
        {INSERTAFTER, 'F', '_'}, {ADD, 'F', '_'},        {REMOVE, '_', '_'},
        {FIND, 'C', '_'},        {FIND, 'F', '_'},       {REMOVEITEM, '_', '_'},
        {ADD, 'G', '_'},         {ADD, 'P', '_'},        {ADD, 'H', '_'},
        {REMOVE, '_', '_'},      {ADD, 'H', '_'},        {ADD, 'K', 'K'},
        {COUNT, 'F', '_'},       {FIND, 'H', '_'},       {REMOVEITEM, '_', '_'},
        {COUNT, 'G', '_'},       {COUNT, 'H', '_'},      {COUNT, 'K', '_'},
        {FIND, 'T', '_'},        {ADD, 'T', '_'},        {FIND, 'T', '_'},
        {FIND, 'F', '_'},        {REMOVEITEM, '_', '_'},
    };

    printf("+++++ CIRCULAR DOUBLY LINKED LIST +++++\n\n");
    list_show(&list);

    for (int i = 0; i < INPUTSIZE; ++i) {
        op = test_cases[i][0];
        value1 = &test_cases[i][1];

        printf("* ");
        switch (op) {
        case ADD:
            printf("ADD: %c: ", *value1);

            cel_aux = malloc(sizeof(Cel));
            cel_aux->data = *value1;

            rs = cdll_add(&cel_aux->item_list,
                          (list.head ? &list.head->previous : &list.head));
            list.length += rs;
            rs == 1 ? printf("Success\n") : printf("Fail!\n");
            list_show(&list);
            break;
        case INSERTAFTER:
            printf("INSERTAFTER (%c) %c: ",
                   ((Cel *)GETSTRUCTFROM(item_list_aux, Cel, item_list))->data,
                   *value1);

            cel_aux = malloc(sizeof(Cel));
            cel_aux->data = *value1;

            rs = cdll_add(&cel_aux->item_list, &item_list_aux);
            list.length += rs;
            rs ? printf("Success\n") : printf("Fail!\n");
            list_show(&list);
            break;
        case REMOVE:
            printf("REMOVE: ");

            item_list_aux = list.head;
            rs = cdll_remove(list.head, &list.head);

            if (rs) {
                printf("%c\n",
                       ((Cel *)GETSTRUCTFROM(item_list_aux, Cel, item_list))
                           ->data);

                list.length--;
            } else {
                printf("Fail!\n");
            }
            list_show(&list);
            break;
        case REMOVEITEM:
            printf("REMOVEITEM (%c): ",
                   ((Cel *)GETSTRUCTFROM(item_list_aux, Cel, item_list))->data);

            rs = cdll_remove(item_list_aux, &list.head);
            list.length -= rs;
            rs ? printf("Success\n") : printf("Fail!\n");
            list_show(&list);
            break;
        case FIND:
            printf("FIND (%c): ", *value1);
            item_list_aux = cdll_find(list.head, value1, comparator);
            item_list_aux
                ? printf("%c\n",
                         ((Cel *)GETSTRUCTFROM(item_list_aux, Cel, item_list))
                             ->data)
                : printf("Not Found!\n");
            break;
        case COUNT:
            c = cdll_count(list.head, value1, comparator);
            printf("COUNT (%c): %ld\n", *value1, c);
            break;
        default:
            printf("OPTION NOT FOUND\n");
            break;
        }
    }

    printf("\n");

    return 0;
}

int comparator(void *const a, void *const b) {

    char elmnt = *((char *)a);
    Cel *cel = GETSTRUCTFROM(b, Cel, item_list);

    return elmnt - cel->data;
}

void list_show(List *list) {

    printf("\n @ List SHOW: ");

    if (!cdll_is_empty(list->head)) {

        printf("%c, ",
               ((Cel *)GETSTRUCTFROM(list->head, Cel, item_list))->data);

        for (ItemDLList *item = list->head->next; item != list->head;
             item = item->next) {
            printf("%c, ", ((Cel *)GETSTRUCTFROM(item, Cel, item_list))->data);
        }
        printf("[%ld]\n--------------", list->length);

        for (int i = 0; i < list->length; ++i)
            printf("---");
    } else {
        printf("Empty!\n");
        printf("---------------------");
    }

    printf("\n\n");
}
