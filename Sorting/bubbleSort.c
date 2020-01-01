/**
 * Bubble Sort: ou ordenação por flutuação (literalmente "por bolha"), é um algoritmo de ordenação dos mais simples. 
 * A ideia é percorrer o vector diversas vezes, e a cada passagem fazer flutuar para o topo o maior elemento da sequência. 
 * Essa movimentação lembra a forma como as bolhas em um tanque de água procuram seu próprio nível, e disso vem o nome do algoritmo.
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

    printf("########## BUBBLE SORT ##########\n\n");
    
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

    // Percorrendo vetor
    for (int i = 0; i < length; i++)
        // Movimentando o maior valor para a última posicão do intervalor(n - quantidade de elementos já ordenados) 
        for (int j = 0; j < length - (i + 1); j++)
            if(vector[j] > vector[j + 1])
                swap(&vector[j], &vector[j + 1]);  
    
}

void printArray(int *vector){
    for(int i = 0; i < MAX; i++)
        printf("%d ", vector[i]);

    printf("\n");
}