/**
 * @author Ytalo Ramon
 * @date   15/06/2021
 */

#include "../include/circular_doubly_linked_list.h"
#include "stdio.h"
#include "stdlib.h"
#include "string.h"

#define INPUTSIZE 35 // Input size for test.

enum options { APPEND, INSERTAFTER, REMOVE, REMOVEITEM, CLEAR, FIND, COUNT };

int comparator(void *const a, void *const b);

void list_show(List *list);

int main(int argc, char const *argv[]) {

    int op, rs;
    char *value1;
    ItemList *item_aux = NULL;
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
    list_show(list);

    for (int i = 0; i < INPUTSIZE; ++i) {
        op = test_cases[i][0];
        value1 = &test_cases[i][1];

        printf("* ");
        switch (op) {
        case APPEND:
            printf("APPEND: %c: ", *value1);
            rs = list_append(list, value1);
            rs == 1 ? printf("Success\n") : printf("Fail!\n");
            list_show(list);
            break;
        case INSERTAFTER:
            printf("INSERTAFTER (%c) %c: ", *((char *)item_aux->data), *value1);
            rs = list_insert_after_item(list, item_aux, value1);
            rs ? printf("Success\n") : printf("Fail!\n");
            list_show(list);
            break;
        case REMOVE:
            printf("REMOVE: ");
            value1 = list_remove(list);
            value1 ? printf("%c\n", *value1) : printf("Fail!\n");
            list_show(list);
            break;
        case REMOVEITEM:
            printf("REMOVEITEM (%c): ", *((char *)item_aux->data));
            value1 = list_remove_item(list, item_aux);
            value1 ? printf("Success\n") : printf("Fail!\n");
            list_show(list);
            break;
        case FIND:
            printf("FIND (%c): ", *value1);
            item_aux = list_find(list, value1, comparator);
            item_aux ? printf("%c\n", *((char *)item_aux->data))
                     : printf("Not Found!\n");
            break;
        case COUNT:
            rs = list_count(list, value1, comparator);
            printf("COUNT (%c): %d\n", *value1, rs);
            break;
        default:
            printf("CLEAR\n");
            list_clear(list);
            list_show(list);
            break;
        }
    }

    printf("\n");

    return 0;
}

int comparator(void *const a, void *const b) {

    return *((char *)a) - *((char *)b);
}

void list_show(List *list) {

    printf("\n @ List SHOW: ");

    if (!list_is_empty(list)) {

        printf("%c, ", *((char *)list->head.next->data));

        for (ItemList *item = list->head.next->next; item != list->head.next;
             item = item->next)
            printf("%c, ", *((char *)item->data));
        printf("[%d]\n--------------", list->length);

        for (int i = 0; i < list->length; ++i)
            printf("---");
    } else {
        printf("Empty!\n");
        printf("---------------------");
    }

    printf("\n\n");
}
