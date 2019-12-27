/**
 * Lista, é uma estrutura de dados linear, onde adiciona-se os dados no final e remove-os no começo.
 * Em uma lista estática para menter o funcionamento adequado é necessário fazer operações modulares,
 *      tendo em vista que o index do final pode está antes que o começo.
 * Complexidade de alteração: O(1)
 * Complexidade de busca: O(n)
 * */

#include "stdio.h"
#include "stdlib.h"

#define LIMITE 16

typedef struct _list {
    int start, end;
    int arr[LIMITE];
} List;

int* add(List *list, int value);

int* removeV(List *list);

void printArr(List *list);

int main(int argc, char const *argv[]){

    List list = { start: 1, end: 1 };
    int opt, value, *result;

    do {
        printf("[1] Add\n[2] Remove\n[Q] Exit\nDigite: ");
        scanf("%d", &opt);

        switch (opt){
            case 1:
                printf("Valor: ");
                scanf("%d", &value);

                result = add(&list, value);
                result != NULL ? printArr(&list) : printf("Lista cheia\n");
                break;
        
            case 2:
                result = removeV(&list);
                result != NULL ? printf("Valor removido: %d\n", *result) : printf("Lista vazia\n");
                printArr(&list);
                break;

            default:
                exit(0);

            getchar();
        }

        printf("\n"); 
    } while (1);

    return 0;
}

int* add (List *list, int value){
    int posiLast = (list->end + 1) % LIMITE;

    if (list->start - posiLast == 0)
        return NULL;

    list->arr[list->end] = value;
    list->end = posiLast;

    return &list->arr[list->end];
}

int* removeV(List *list){
    if (list->start == list->end)
        return NULL;

    int posiStar = list->start;
    list->start = (posiStar + 1) % LIMITE;

    return &list->arr[posiStar];
}

void printArr(List *list){
    int i = list->start, j = list->end;

    while (i != j){
        printf("%d ", list->arr[i]);
        i = (i + 1) % LIMITE;
    }
    
    printf("\n");
}