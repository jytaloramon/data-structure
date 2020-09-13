/**
 * QuickSort, é um método de ordenação muito rápido e eficiente que seguindo a ideia separação (= partition subproblem).
 * A estratégia desse algoritmo consiste em rearranjar as chaves de modo que as chaves "menores" precedam as chaves "maiores". 
 *      Em seguida o quicksort ordena as duas sublistas de chaves menores e maiores recursivamente até que a lista completa se encontre ordenada.
 * Seu método consiste em escolher um pivô(pivot), a partir dele posicionar todos os valores menores que ele à esqueda e maiores à direita.
 * Complexidade: pior - O(n^2), melhor - O(n log n).
 * */

#include "stdio.h"
#include "stdlib.h"
#define MAX 10

void swap(int *v1, int *v2);

void quick(int *vector, int startInterv, int endInterv);

int partition(int *vector, int startInterv, int endInterv);

void printArray(int *vector);

int main(int argc, char const *argv[]){

    int vector[] = {5, 1, 3, 2, 10, 5, 0, 8, 9, -65};

    printf("########## QUICK SORT ##########\n\n");

    printf("Antes de ordenar: ");
    printArray(vector);

    quick(vector, 0, MAX);

    printf("Apos ordenar: ");
    printArray(vector);

    return 0;
}

void swap(int *v1, int *v2){
    int vAux = *v1;
    *v1 = *v2;
    *v2 = vAux;
}

void quick(int *vector, int startInterv, int endInterv){
    if (startInterv >= endInterv - 1)
        return;

    int posiFinaPivot = partition(vector, startInterv, endInterv);    

    quick(vector, startInterv, posiFinaPivot);
    quick(vector, posiFinaPivot + 1, endInterv);
}

int partition(int *vector, int startInterv, int endInterv){
    int down = startInterv,
        up = endInterv - 1,
        valuePivot = vector[startInterv];

    while (down < up){
        while (vector[down] <= valuePivot && down < up)
            down++;
        
        while (vector[up] > valuePivot && up > startInterv)
            up--;

        if(down < up)
            swap(&vector[down++], &vector[up--]);
    }

    swap(&vector[startInterv], &vector[up]);

    return up;
}

void printArray(int *vector){
    for(int i = 0; i < MAX; i++)
        printf("%d ", vector[i]);

    printf("\n");
}