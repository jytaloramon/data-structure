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

enum options { APPEND, INSERTAFTER, REMOVE, REMOVEITEM, FIND, COUNT };

typedef struct _Cel {
    char data;
    ItemList item_list;
} Cel;

int comparator(void *const a, void *const b);

void list_show(List *list);

int main(int argc, char const *argv[]) {

    int op, rs;
    char *value1;
    Cel *cel_aux = NULL;
    ItemList *item_list_aux = NULL;

    char test_cases[INPUTSIZE][4] = {
        {REMOVE, '_', '_'},      {APPEND, 'A', '_'},     {APPEND, 'B', '_'},
        {REMOVE, '_', '_'},      {REMOVE, '_', '_'},     {REMOVE, '_', '_'},
        {APPEND, 'C', '_'},      {APPEND, 'D', '_'},     {FIND, 'D', '_'},
        {INSERTAFTER, 'G', '_'}, {APPEND, 'E', '_'},     {FIND, 'C', '_'},
        {INSERTAFTER, 'F', '_'}, {APPEND, 'F', '_'},     {REMOVE, '_', '_'},
        {FIND, 'C', '_'},        {FIND, 'F', '_'},       {REMOVEITEM, '_', '_'},
        {APPEND, 'G', '_'},      {APPEND, 'P', '_'},     {APPEND, 'H', '_'},
        {REMOVE, '_', '_'},      {APPEND, 'H', '_'},     {APPEND, 'K', 'K'},
        {COUNT, 'F', '_'},       {FIND, 'H', '_'},       {REMOVEITEM, '_', '_'},
        {COUNT, 'G', '_'},       {COUNT, 'H', '_'},      {COUNT, 'K', '_'},
        {FIND, 'T', '_'},        {APPEND, 'T', '_'},     {FIND, 'T', '_'},
        {FIND, 'F', '_'},        {REMOVEITEM, '_', '_'},
    };

    List *list = list_new();

    printf("+++++ CIRCULAR DOUBLY LINKED LIST +++++\n\n");
    list_show(list);

    for (int i = 0; i < INPUTSIZE; ++i) {
        op = test_cases[i][0];
        value1 = &test_cases[i][1];

        printf("* ");
        switch (op) {
        case APPEND:
            printf("APPEND: %c: ", *value1);

            cel_aux = malloc(sizeof(Cel));
            cel_aux->data = *value1;

            rs = list_append(list, &cel_aux->item_list);
            rs == 1 ? printf("Success\n") : printf("Fail!\n");
            list_show(list);
            break;
        case INSERTAFTER:
            printf("INSERTAFTER (%c) %c: ",
                   ((Cel *)GETSTRUCTFROM(item_list_aux, Cel, item_list))->data,
                   *value1);

            cel_aux = malloc(sizeof(Cel));
            cel_aux->data = *value1;

            rs = list_insert_after_item(list, item_list_aux,
                                        &cel_aux->item_list);
            rs ? printf("Success\n") : printf("Fail!\n");
            list_show(list);
            break;
        case REMOVE:
            printf("REMOVE: ");

            item_list_aux = list_remove(list);
            item_list_aux
                ? printf("%c\n",
                         ((Cel *)GETSTRUCTFROM(item_list_aux, Cel, item_list))
                             ->data)
                : printf("Fail!\n");
            list_show(list);
            break;
        case REMOVEITEM:
            printf("REMOVEITEM (%c): ",
                   ((Cel *)GETSTRUCTFROM(item_list_aux, Cel, item_list))->data);

            rs = list_remove_item(list, item_list_aux);
            rs ? printf("Success\n") : printf("Fail!\n");
            list_show(list);
            break;
        case FIND:
            printf("FIND (%c): ", *value1);
            item_list_aux = list_find(list, value1, comparator);
            item_list_aux
                ? printf("%c\n",
                         ((Cel *)GETSTRUCTFROM(item_list_aux, Cel, item_list))
                             ->data)
                : printf("Not Found!\n");
            break;
        case COUNT:
            rs = list_count(list, value1, comparator);
            printf("COUNT (%c): %d\n", *value1, rs);
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

    if (!list_is_empty(list)) {

        printf("%c, ",
               ((Cel *)GETSTRUCTFROM(list->head.next, Cel, item_list))->data);

        for (ItemList *item = list->head.next->next; item != list->head.next;
             item = item->next) {
            printf("%c, ", ((Cel *)GETSTRUCTFROM(item, Cel, item_list))->data);
        }
        printf("[%d]\n--------------", list->length);

        for (int i = 0; i < list->length; ++i)
            printf("---");
    } else {
        printf("Empty!\n");
        printf("---------------------");
    }

    printf("\n\n");
}
