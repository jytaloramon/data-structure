/**
 * Binary search, ou busca binária, é um algoritmo de busca em vetores que segue o paradigma de divisão e conquista. 
 * Ela parte do pressuposto de que o vetor está ordenado e realiza sucessivas divisões do espaço de busca comparando o elemento buscado (chave) com o elemento no meio do vetor.
 * Se o elemento do meio do vetor for a chave, a busca termina com sucesso. 
 * Caso contrário, se o elemento do meio vier antes do elemento buscado, então a busca continua na metade posterior do vetor. 
 * E finalmente, se o elemento do meio vier depois da chave, a busca continua na metade anterior do vetor.
 * Se o elemento do meio não for igual a chave e o index do início for igual a do fim, isso significa que o elemento não existe na lista.
 * Complexidade: pior - O(log n), médio - O(log n), melhor - O(1)
 * Ref.: Wikipédia
 * */

#include "stdio.h"
#include "stdlib.h"

#define MAX 15
#define MIDDLECAL(a, b)((a + b) / 2)

int *search(int value, int *vector, int startInterv, int endInterv);

int main(int argc, char const *argv[]){

    int vector[MAX] = {-1, 0, 1, 2, 4, 7, 10, 15, 20, 50, 74, 98, 100, 200, 300};

    int value, *resp;

    do {
        printf("Valor: ");
        scanf("%d", &value);

        resp = search(value, vector, 0, MAX);

        resp != NULL ? printf("ok %d\n\n", *resp) : printf("nao ok\n\n");
    } while(1);

    return 0;
}

int* search(int value, int *vector, int startInterv, int endInterv){
    int middle = MIDDLECAL(startInterv, endInterv);

    if (vector[middle] == value)
        return &vector[middle];

    if(endInterv - startInterv == 1)
        return NULL;

    return value < vector[middle] ? search(value, vector, startInterv, middle) : search(value, vector, middle, endInterv);
}