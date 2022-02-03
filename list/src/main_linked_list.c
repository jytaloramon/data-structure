/**
 * @author Ytalo Ramon
 * @date   02/02/2022
 */

#include "../../includes/istructure_utils.h"
#include "../include/linked_list.h"
#include "stdio.h"
#include "stdlib.h"

#define INPUTSIZE 30 // Input size for test.

enum options { APPEND, INSERTAT, REMOVE, REMOVEAT, POP, INDEXOF, FIND, COUNT };

typedef struct _Cel {
    char data;
    LlItem item_list;
} Cel;

int comparator(void *const a, void *const b);

void list_show(LList *list);

int main(int argc, char const *argv[]) {

    char test_cases[INPUTSIZE][4] = {
        {REMOVE, '_'},       {APPEND, 'A', '_'}, {APPEND, 'B', '_'},
        {REMOVE, '_'},       {REMOVE, '_'},      {REMOVE, '_'},
        {APPEND, 'C', '_'},  {APPEND, 'D', '_'}, {REMOVEAT, 1, '_'},
        {APPEND, 'E', '_'},  {POP, '_', '_'},    {APPEND, 'F', '_'},
        {REMOVEAT, 0, '_'},  {INSERTAT, 0, 'G'}, {INSERTAT, 1, 'H'},
        {APPEND, 'G', '_'},  {REMOVEAT, 2, '_'}, {APPEND, 'H', '_'},
        {APPEND, 'H', '_'},  {INSERTAT, 0, 'K'}, {INSERTAT, 5, 'G'},
        {INDEXOF, 'H', '_'}, {POP, '_', '_'},    {COUNT, 'G', '_'},
        {COUNT, 'H', '_'},   {COUNT, 'K', '_'},  {FIND, 'T', '_'},
        {APPEND, 'T', '_'},  {FIND, 'T', '_'},   {REMOVE, '_', '_'},
    };

    printf("+++++ LINKED LIST +++++\n\n");

    int op, rs;
    char *value1, *value2;
    Cel *cel_aux = NULL;
    LlItem *item_list_aux = NULL;
    LList *list = ll_new();

    list_show(list);

    for (int i = 0; i < INPUTSIZE; ++i) {
        op = test_cases[i][0];
        value1 = &test_cases[i][1];
        value2 = &test_cases[i][2];

        printf("* ");
        switch (op) {
        case APPEND:
            printf("APPEND: %c: ", *value1);

            cel_aux = malloc(sizeof(Cel));
            cel_aux->data = *value1;

            rs = ll_append(list, &cel_aux->item_list);
            rs == 1 ? printf("Success\n") : printf("Fail!\n");
            list_show(list);
            break;
        case INSERTAT:
            printf("INSERTAT (%d) %c: ", *value1, *value2);

            cel_aux = malloc(sizeof(Cel));
            cel_aux->data = *value2;

            rs = ll_insert_at(list, &cel_aux->item_list, (int)*value1);
            rs ? printf("Success\n") : printf("Fail!\n");
            list_show(list);
            break;
        case REMOVE:
            printf("REMOVE: ");

            item_list_aux = ll_remove(list);
            item_list_aux
                ? printf("%c\n",
                         ((Cel *)GETSTRUCTFROM(item_list_aux, Cel, item_list))
                             ->data)
                : printf("Fail!\n");
            list_show(list);
            break;
        case REMOVEAT:
            printf("REMOVEAT (%d): ", *value1);

            item_list_aux = ll_remove_at(list, (int)*value1);
            item_list_aux
                ? printf("%c\n",
                         ((Cel *)GETSTRUCTFROM(item_list_aux, Cel, item_list))
                             ->data)
                : printf("Fail!\n");
            list_show(list);
            break;
        case POP:
            printf("POP: ");

            item_list_aux = ll_remove_at(list, list->length - 1);
            item_list_aux
                ? printf("%c\n",
                         ((Cel *)GETSTRUCTFROM(item_list_aux, Cel, item_list))
                             ->data)
                : printf("Fail!\n");
            list_show(list);
            break;
        case INDEXOF:
            printf("INDEXOF (%c): ", *value1);

            rs = ll_index_of(list, value1, comparator);
            rs != -1 ? printf("%d\n", rs) : printf("Not Found!\n");
            break;
        case FIND:
            printf("FIND (%c): ", *value1);

            item_list_aux = ll_find(list, value1, comparator);
            item_list_aux
                ? printf("%c\n",
                         ((Cel *)GETSTRUCTFROM(item_list_aux, Cel, item_list))
                             ->data)
                : printf("Not Found!\n");
            break;
        case COUNT:
            rs = ll_count(list, value1, comparator);
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

void list_show(LList *list) {

    printf("\n @ List SHOW: ");

    if (!ll_is_empty(list)) {
        for (LlItem *item_r = list->head.next; item_r; item_r = item_r->next) {
            printf("%c, ",
                   ((Cel *)GETSTRUCTFROM(item_r, Cel, item_list))->data);
        }
        printf("[%lu]\n--------------", list->length);

        for (int i = 0; i < list->length; ++i)
            printf("---");
    } else {
        printf("Empty!\n");
        printf("---------------------");
    }

    printf("\n\n");
}
