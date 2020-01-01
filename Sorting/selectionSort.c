/**
 * Selection sort, ou ordenação por seleção. E um algoritmo de ordenação baseado em se passar sempre o menor valor do vetor para a primeira posição (ou o maior dependendo da ordem requerida), depois o de segundo menor valor para a segunda posição, sucessivament. 
 * Composto por dois laços: um externo e outro interno; constitui em fazer um pesquisa em um intervalo(i + 1 - n) para encontrar o menor valor, adicionando-o posteriormente em sua posição correta - começo do intervalo da busca.
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

    printf("########## SELECTION SORT ##########\n\n");

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
    int index_min;

    // Percorrendo vetor
    for (int i = 0; i < length - 1; i++){
        index_min = i;
        
        // Buscando menor valor no intervalor entre o index atual e o fim da lista
        for (int j = i + 1; j < length; j++)
            if(vector[j] < vector[index_min])
                index_min = j;
        
        // Trocando os valores de posição
        swap(&vector[i], &vector[index_min]);
    }  
}

void printArray(int *vector){
    for(int i = 0; i < MAX; i++)
        printf("%d ", vector[i]);

    printf("\n");
}