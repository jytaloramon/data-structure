/**
 * @author Ytalo Ramon
 * @date   15/06/2021
*/

#include "stdio.h"
#include "stdlib.h"
#include "string.h"
#include "../include/doubly_linked_list.h"

#define INPUTSIZE 30 // Input size for test.

enum options {
    APPEND,
    INSERTAT,
    REMOVEFIRST,
    REMOVEAT,
    CLEAR,
    INDEXOF,
    FIND,
    COUNT
};

int comparator(void *const a, void *const b);

void list_show(List *list);

int main(int argc, char const *argv[]){

    int op, rs;
    char *value1, *value2;
    char test_cases[INPUTSIZE][4] = {
        {REMOVEFIRST, '_'},
        {APPEND, 'A', '_'},
        {APPEND, 'B', '_'},
        {REMOVEFIRST, '_'},
        {REMOVEFIRST, '_'},
        {REMOVEFIRST, '_'},
        {APPEND, 'C', '_'},
        {APPEND, 'D', '_'},
        {REMOVEAT, 1, '_'},
        {APPEND, 'E', '_'},
        {REMOVEAT, -1, '_'},
        {APPEND, 'F', '_'},
        {REMOVEAT, 0, '_'},
        {INSERTAT, 0, 'G'},
        {INSERTAT, 1, 'H'},
        {APPEND, 'G', '_'},
        {REMOVEAT, 2, '_'},
        {APPEND, 'H', '_'},
        {APPEND, 'H', '_'},
        {INSERTAT, 0, 'K' },
        {INSERTAT, 5, 'G'},
        {INDEXOF, 'H', '_'},
        {REMOVEAT, -1, '_'},
        {COUNT, 'G', '_'},
        {COUNT, 'H', '_'},
        {COUNT, 'K', '_'},
        {FIND, 'T', '_'},
        {APPEND, 'T', '_'},
        {FIND, 'T', '_'},
        {REMOVEFIRST, '_', '_'},
    };

    List *list = list_new();
    list_show(list);
    
    for (int i = 0; i < INPUTSIZE; ++i){
        op = test_cases[i][0];
        value1 = &test_cases[i][1];
        value2 = &test_cases[i][2];

        printf("* ");
        switch (op){
        case APPEND:    
            printf("APPEND: %c: ", *value1);
            rs = list_append(list, value1);
            rs == 1 ? printf("Success\n") : printf("Fail!\n");
            list_show(list);
            break;
        case INSERTAT:
            rs = ((int) *value1);
            printf("INSERTAT (%d) %c: ", rs, *value2);
            rs = list_insert_at(list, rs, value2);
            rs ? printf("Success\n") : printf("Fail!\n");
            list_show(list);
            break;
        case REMOVEFIRST:
            printf("REMOVEFIST: ");
            value1 = list_remove_first(list);
            value1 ? printf("%c\n", *value1) : printf("Fail!\n");
            list_show(list);
            break;
        case REMOVEAT:
            rs = ((int) *value1);
            printf("REMOVEAT (%d): ", rs);
            value1 = list_remove_at(list, rs);
            value1 ? printf("%c\n", *value1) : printf("Fail!\n");
            list_show(list);
            break;
        case INDEXOF:
            printf("INDEXOF (%c): ", *value1);
            rs = list_index_of(list, value1, comparator);
            rs != -1 ? printf("%d\n", rs) : printf("Not Found!\n");
            break;
        case FIND:
            printf("FIND (%c): ", *value1);
            value2 = (char *) list_find(list, value1, comparator);
            value2 ? printf("%c\n", *value2) : printf("Not Found!\n");
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

int comparator(void *const a, void *const b){
    
    return *((char *) a) - *((char *) b);
}

void list_show(List *list){
    
    printf("\n @ List SHOW: ");

    if (!list_is_empty(list)){
        for (ItemList *item = list->front.next; item; item = item->next)
            printf("%c, ", *((char *) item->data));
        printf("[%d]\n--------------", list->length);

        for (int i = 0; i < list->length; ++i)
            printf("---");
    } else {
        printf("Empty!\n");
        printf("---------------------");
    }

    printf("\n\n");
}
