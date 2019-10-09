/**
 * O bubble sort, ou ordenação por flutuação (literalmente "por bolha"), é um algoritmo de ordenação dos mais simples. 
 * A ideia é percorrer o vector diversas vezes, e a cada passagem fazer flutuar para o topo o maior elemento da sequência. 
 * Essa movimentação lembra a forma como as bolhas em um tanque de água procuram seu próprio nível, e disso vem o nome do algoritmo.
 * Complexidade O(N^2)
 */ 

#include "stdio.h"
#include "stdlib.h"

#define MAX 15

int vector[MAX] = {5, 10, 3, -10, 11, -1,  0, 1, 2, 112, 122, 112, 0, 5, -1000};

void printArray();

int main(int argc, char const *argv[]){
    
    int aux;

    printf("Antes de ordenar: ");
    printArray();

    // Percorrendo vetor
    for (int i = 0; i < MAX; i++){
        
        // Movimentando o maior valor para a última posicão do intervalor(n - quantidade de elementos já ordenados) 
        for (int j = 0; j < MAX - (i + 1); j++)
            if(vector[j + 1] < vector[j]){
                aux = vector[j + 1];
                vector[j + 1] = vector[j];
                vector[j] = aux;
            }
    }
    
    printf("Apos ordenar: ");
    printArray();

    return 0;
}

void printArray(){
    for(int i = 0; i < MAX; i++)
        printf("%d ", vector[i]);

    printf("\n");
}