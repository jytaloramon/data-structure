/**
 * Insertion Sort, ou ordenação por inserção, é o algoritmo de ordenação que, dado uma estrutura (array, lista) constrói uma matriz final com um elemento de cada vez, uma inserção por vez. 
 * Assim como algoritmos de ordenação quadrática, é bastante eficiente para problemas com pequenas entradas, sendo o mais eficiente entre os algoritmos desta ordem de classificação.
 * Podemos fazer uma comparação do Insertion Sort com o modo de como algumas pessoas organizam um baralho num jogo de cartas. Imagine que você está jogando cartas. 
 * Você está com as cartas na mão e elas estão ordenadas. Você recebe uma nova carta e deve colocá-la na posição correta da sua mão de cartas, de forma que as cartas obedeçam a ordenação.
 * A cada nova carta adicionada à sua mão de cartas, a nova carta pode ser menor que algumas das cartas que você já tem na mão ou maior, e assim, você começa a comparar a nova carta com todas as cartas na sua mão até encontrar sua posição correta. 
 * Complexidade O(N^2)
 */

#include "stdio.h"
#include "stdlib.h"
#define MAX 10

void swap(int *v1, int *v2);

void sort(int *vector, int length);

void printArray(int *vector);

int main(int argc, char const *argv[]){
    int vector[] = {5, 1, 3, 2, 10, 5, 0, 8, 9, -65};

    printf("########## INSERTION SORT ##########\n\n");

    printf("Antes de ordenar: ");
    printArray(vector);

    sort(vector, MAX);

    printf("Apos ordenar: ");
    printArray(vector);

    
    return 0;
}

void swap(int *v1, int *v2){
    int vAux = *v1;
    *v1 = *v2;
    *v2 = vAux;
}

void sort(int *vector, int length){
    int j, valueKey;

    // Percorrendo vetor
    for (int i = 0; i < length; i++){
        valueKey = vector[i];

        // Enquanto tiver elemento e o valor da posicao atual for menor que o anterior eles trocaram de posição
        for (j = i - 1; j >= 0 && valueKey < vector[j]; j--)
            vector[j + 1] = vector[j];
            
        vector[j + 1] = valueKey;
    }
    
}

void printArray(int *vector){
    for(int i = 0; i < MAX; i++)
        printf("%d ", vector[i]);

    printf("\n");
}