/**
 * Selection sort, ou ordenação por seleção. E um algoritmo de ordenação baseado em se passar sempre o menor valor do vetor para a primeira posição (ou o maior dependendo da ordem requerida), depois o de segundo menor valor para a segunda posição, sucessivament. 
 * Composto por dois laços: um externo e outro interno; constitui em fazer um pesquisa em um intervalo(i + 1 - n) e para encontrar o menor valor, adicionando-o posteriormente em sua posição correta.
 * Complexidade O(N^2)
 */ 

#include "stdio.h"
#include "stdlib.h"

#define MAX 10

int vector[MAX] = {5, 10, 3, 11, 0, 1, 2, 112, 122, 112};

void printArray();

int main(int argc, char const *argv[]){
    
    int index_min, aux;

    printf("Antes de ordenar: ");
    printArray();

    // Percorrendo vetor
    for (int i = 0; i - 1 < MAX; i++){
        index_min = i;
        
        // Buscando menor valor no intervalor entre o index atual e o fim da lista
        for (int j = i + 1; j < MAX; j++)
            if(vector[j] < vector[index_min])
                index_min = j;
        
        // Trocando os valores de posição
        aux = vector[index_min];
        vector[index_min] = vector[i];
        vector[i] = aux;
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