/**
 * ShellSort, é o mais eficiente algoritmo de ordenação dentre os de complexidade quadrática.
 * O tipo de inserção, move os elementos apenas uma posição à frente. 
 * A idéia do shellSort é permitir a troca de itens em um passo maior,  fazemndo a matriz classificada h para um grande valor de h. 
 * Continuamos reduzindo o valor de h até que se torne 1. Uma matriz é classificada como 
 *      h-classificada se todas as sublistas de cada h-ésimo elemento são classificadas.
 * Complexidade: pior - O(n^2), melhor - O(n log n).
 * */

#include "stdio.h"
#include "stdlib.h"
#define MAX 10

void swap(int *v1, int *v2);

int calPass(int length);

void sort(int *vector, int length, int pass);

void printArray(int *vector);

int main(int argc, char const *argv[]){
    
    int vector[] = {5, 1, 3, 2, 10, 5, 0, 8, 9, -65};

    printf("########## SHELL SORT ##########\n\n");

    printf("Antes de ordenar: ");
    printArray(vector);

    sort(vector, MAX, calPass(MAX));

    printf("Apos ordenar: ");
    printArray(vector);

    return 0;
}

void swap(int *v1, int *v2){
    int vAux = *v1;
    *v1 = *v2;
    *v2 = vAux;
}

int calPass(int length){
    int i;
    for (i = 1; i <= length / 3; i *= 3 + 1);
    
    return i;
}

void sort(int *vector, int length, int pass){
    if(pass == 0)
        return;

    int i = length - 1;

    while (i - pass >= 0){
        if(vector[i] < vector[i - pass])
            swap(&vector[i], &vector[i - pass]);
        
        i--;
    }
    
    sort(vector, length, pass / 2);
}

void printArray(int *vector){
    for(int i = 0; i < MAX; i++)
        printf("%d ", vector[i]);

    printf("\n");
}