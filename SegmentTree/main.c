/**
 * Segment Tree, ou Árvore de Segmentos, é uma das estruturas de dados mais utilizadas na programação competitiva por conta da sua eficiência e versatilidade. 
 * Uma árvore de segmentos é uma estrutura de dados que pode ser usada para executar consultas e atualizações de intervalos, consiste em cada nó da árvore possui a soma de seus descendente. 
 * É uma árvore binária com altura equilibrada , geralmente construída em cima de uma matriz. 
 * As árvores de segmento podem ser usadas para resolver consultas de intervalo mínimo / máximo e soma e consultas de atualização de intervalo em tempo O (log n).
 */

#include "stdio.h"
#include "stdlib.h"

#define TRUE 1
#define FALSE 0
#define MAX 10000
#define CALMIDDLE(a, b)((a + b) / 2)

int vector[MAX],
    tree[MAX * 3];

int buildTree(int index, int startEspectrum, int endEspectrum);

int updateTree(int index, int startEspectrum, int endEspectrum, int id, int value);

int getSum(int index, int startEspectrum, int endEspectrum, int startInterv, int endInterv);

void printArray(int length);

int main(int argc, char const *argv[]){
    
    int i, lengthArray, opt, a, b; 
    
    printf("Numero total de elementos: ");
    scanf("%d", &lengthArray);
    
    for(i = 0; i < lengthArray; i++){
        printf("Valor %d: ", i + 1);
        scanf("%d", &vector[i]);
    }
    
    buildTree(0, 0, lengthArray - 1);

    do {
        printArray(lengthArray);
        printf("[1] Altera valor\n[2] soma de intervalo\n[Q] Exit\n");
        scanf("%d", &opt);

        switch (opt){
            case 1:
                printf("Novo valor: ");
                scanf("%d", &a);
                printf("Posicao: ");
                scanf("%d", &b);

                vector[b - 1] = a;
                updateTree(0, 0, lengthArray - 1, b - 1, a);
                break;
        
            case 2:
                printf("Limite inferior: ");
                scanf("%d", &a);
                printf("Limite Superior: ");
                scanf("%d", &b);
                printf("Soma: %d\n", getSum(0, 0, lengthArray - 1, a - 1, b - 1));
                break;
            default:
                exit(0);
        }

        printf("\n"); 
    } while (TRUE);
    return 0;
}

int buildTree(int index, int startEspectrum, int endEspectrum){
    if(startEspectrum == endEspectrum)
        return tree[index] = vector[startEspectrum];

    int middle = CALMIDDLE(startEspectrum, endEspectrum);

    return tree[index] = buildTree(index * 2 + 1, startEspectrum, middle) + 
                         buildTree(index * 2 + 2, middle + 1, endEspectrum);
}

int updateTree(int index, int startEspectrum, int endEspectrum, int id, int value){
    if(startEspectrum == endEspectrum)
        return tree[index] = value;
        
    int middle = CALMIDDLE(startEspectrum, endEspectrum);

    if(id <= middle)
        return tree[index] = updateTree(index * 2 + 1, startEspectrum, middle, id, value) + tree[index * 2 + 2];
    
    return tree[index] = updateTree(index * 2 + 2, middle + 1, endEspectrum, id, value) + tree[index * 2 + 1];
}

int getSum(int index, int startEspectrum, int endEspectrum, int startInterv, int endInterv){
    if(startInterv <= startEspectrum && endEspectrum <= endInterv)
        return tree[index];

    if(startInterv > endEspectrum || endInterv < startEspectrum)
        return 0;

    int middle = CALMIDDLE(startEspectrum, endEspectrum);

    return getSum(index * 2 + 1, startEspectrum, middle, startInterv, endInterv) +
           getSum(index * 2 + 2, middle + 1, endEspectrum, startInterv, endInterv);
}

void printArray(int length){
    printf("\nArray:");
    for (int i = 0; i < length; i++)
        printf(" %d", vector[i]);
    
    printf("\n");
}