/**
 * @author Ytalo Ramon
 * @date   15/02/2021
*/

#include "stdio.h"
#include "stdlib.h"
#include "string.h"
#include "../include/list_static.h"

#define STRINGSIZE 21 // Maximum string size. Real capacity is (STRINGSIZE - 1).
#define INPUTSIZE 29  // Input size for test.

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

char *to_string(void *const data);

int comparator_txt(void *const v1, void *const v2);

int main(int argc, char const *argv[]){

    List *list = new_list(5);

    // Here is EMPTY
    printf("%s\n", list_to_string(list, to_string));

    append(list, "Ramon");
    printf("%s\n", list_to_string(list, to_string));

    append(list, "Ytalo");
    printf("%s\n", list_to_string(list, to_string));
    
    remove_fist(list);
    printf("%s\n", list_to_string(list, to_string));

    remove_fist(list);
    printf("%s\n", list_to_string(list, to_string));

    // Here is EMPTY
    remove_fist(list);
    printf("%s\n", list_to_string(list, to_string));

    append(list, "Gabriel");
    printf("%s\n", list_to_string(list, to_string));

    printf("\nINDEXOF: %d - %s\n", index_of(list, "Jack", &comparator_txt), "Jack");
    
    append(list, "Maria");
    printf("%s\n", list_to_string(list, to_string));

    printf("\nINDEXOF: %d - %s\n", index_of(list, "Maria", &comparator_txt), "Maria");

    append(list, "Ana");
    printf("%s\n", list_to_string(list, to_string));

    printf("\nINDEXOF: %d - %s\n", index_of(list, "Ana", &comparator_txt), "Ana");
    printf("\nINDEXOF: %d - %s\n", index_of(list, "Ramon", &comparator_txt), "Ramon");

    append(list, "Isadora");
    printf("%s\n", list_to_string(list, to_string));

    printf("\nCOUNT:%d - %s\n", count(list, "Ramon", &comparator_txt), "Ramon");
    printf("\nCOUNT: %d - %s\n", count(list, "Isadora", &comparator_txt), "Isadora");

    append(list, "Ana");
    printf("%s\n", list_to_string(list, to_string));

    append(list, "Vitoria");
    printf("%s\n", list_to_string(list, to_string));

    printf("\nCOUNT:%d - %s\n", count(list, "Vitoria", &comparator_txt), "Vitoria");
    printf("\nCOUNT: %d - %s\n", count(list, "ana", &comparator_txt), "ana");

    remove_at(list, 1);
    printf("%s\n", list_to_string(list, to_string));

    remove_at(list, 3);
    printf("%s\n", list_to_string(list, to_string));
    
    remove_at(list, -1);
    printf("%s\n", list_to_string(list, to_string));

    insert_at(list, 0, "Vitoria");
    printf("%s\n", list_to_string(list, to_string));

    insert_at(list, 2, "Bruno");
    printf("%s\n", list_to_string(list, to_string));
    
    return 0;
}

char *to_string(void *const data){
    char *txt = malloc(sizeof(char) * BUFFER / 32);
    strcpy(txt, data);
    return txt;
}

int comparator_txt(void *const v1, void *const v2){
    return strcmp((char *) v1, (char *) v2);
}
