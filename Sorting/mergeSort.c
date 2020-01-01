/**
 * Merge Sort, é um algoritmo de divisão e conquista(Divide and Conquer).
 * Ele divide a matriz em duas metades recursivamente, ordena, e após faz a mesclagem dessas partes.
 * Como o algoritmo Merge Sort usa a recursividade, há um alto consumo de memória.
 * Complexidade: O(n log n) - constante em todos os casos.
 * */

#include "stdio.h"
#include "stdlib.h"
#define MAX 10
#define MIDDLE(a,b)((a + b) / 2)

void merge(int *vector, int startInterv, int endInterv);

void sort(int *vector, int startInterv, int middle, int endInterv);

void printArray(int *vector);

int main(int argc, char const *argv[]){
    int vector[] = {5, 1, 3, 2, 10, 5, 0, 8, 9, -65};

    printf("########## MERGER SORT ##########\n\n");
    
    printf("Antes de ordenar: ");
    printArray(vector);
    
    merge(vector, 0, MAX);

    printf("Apos ordenar: ");
    printArray(vector);

    return 0;
}

void merge(int *vector, int startInterv, int endInterv){
    // Caso base - quando houver apenas um elemento
    if(startInterv >= endInterv - 1)
        return;
    
    // Calculando posição no meio do intervalo
    int middle = MIDDLE(startInterv, endInterv);
    
    // Dividindo as partes
    merge(vector, startInterv, middle);
    merge(vector, middle, endInterv);

    // Ordenar
    sort(vector, startInterv, middle, endInterv);
}

void sort(int *vector, int startInterv, int middle, int endInterv){
    
    int i = startInterv, j = middle, t = 0;
    int *listAux = malloc(sizeof(int) * (endInterv - startInterv));

    // Ordenando as metades e guardando os valores no array auxiliar
    while (i < middle && j < endInterv){
        if(vector[i] <= vector[j])
            listAux[t++] = vector[i++];
        else
            listAux[t++] = vector[j++];
    }

    // Passando os valores que sobraram na parte para o array aux.
    while (i < middle)
        listAux[t++] = vector[i++];
    
    while (j < endInterv)
        listAux[t++] = vector[j++];

    t = 0;

    // passando os valores do array auxiliar para o de origem - ordenado
    for (i = startInterv; i < endInterv; i++)
        vector[i] = listAux[t++];
}

void printArray(int *vector){
    for(int i = 0; i < MAX; i++)
        printf("%d ", vector[i]);
   
    printf("\n");
}