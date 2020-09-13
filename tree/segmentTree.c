/**
 * Segment Tree, ou Árvore de Segmentos, é uma das estruturas de dados mais utilizadas na programação competitiva 
 *      por conta da sua eficiência e versatilidade em operações de consulta em intervalos e atualização de elementos no array.
 * Consiste em quebrar o array em vários intervalos(segmentos).
 * Então, com base nesses intervalos, construimos uma árvore onde cada nó guarda a soma dos elementos do intervalo.
 * Complexidade: construção - O(n); consulta&atualização - O(log n).
 */

#include "stdio.h"
#include "stdlib.h"
#include "string.h"

#define MAX 10
#define CALMIDDLE(a, b)((a + b) / 2)

int build(int *listV, int *listSegment, int startInterv, int endInterv, int posi);

int update(int newValue, int indexUpdate, int *listSegment, int startInterv, int endInterv, int posi);

int getSum(int *listSegment, int findStartIndex, int findEndIndex, int startInterv, int endInterv, int posi);

void print(int *l, int length);

int main(int argc, char const *argv[]){
    
    int a, b, option, status = 1, lengthArray,
        listValues[MAX], listSegmTree[MAX * 3];

    memset(listSegmTree, 0, sizeof(int) * MAX * 3);

    printf("Tamanho do array (<= %d): ", MAX);
    scanf("%d", &lengthArray);
    
    printf("Digite os valoes: ");
    for (int i = 0; i < lengthArray; i++)    
        scanf("%d", &listValues[i]);

    // Construção da árvore de segmentos
    build(listValues, listSegmTree, 0, lengthArray, 0);

    do {
        printf("[1] Ver Array\n[2] Update\n[3] Soma\n[Q] Sair\nDigite: ");
        scanf("%d", &option);

        switch (option){
        case 1:
            printf("Array: ");
            print(listValues, lengthArray);

            printf("Array SegTree: ");
            print(listSegmTree, lengthArray * 3 - 1);
            break;
        
        case 2:
            printf("Posicao: ");
            scanf("%d", &a);
            printf("Novo valor: ");
            scanf("%d", &b);

            if (a < 0 && a > lengthArray)
                printf("Index invalido!\n");
            else {
                listValues[a - 1] = b;
                update(b, a - 1, listSegmTree, 0, lengthArray, 0);
            }
            break;

        case 3:
            printf("Inicio intervalo: ");
            scanf("%d", &a);
            printf("Fim intervalo: ");
            scanf("%d", &b);

            if (a > b || a < 0 || a > lengthArray || b < 0 || b > lengthArray)
                printf("Intervalo invalidos!\n");
            else {
                printf("Soma de %d - %d: %d\n", a, b, getSum(listSegmTree, a - 1, b - 1, 0, lengthArray, 0));
            }
            break;

        default:
            status = 0;
        }
        
        printf("\n\n");
    } while(status);

    return 0;
}

int build(int *listV, int *listSegment, int startInterv, int endInterv, int posi){
    if (startInterv == endInterv - 1)
        return listSegment[posi] = listV[startInterv];

    const int middle = CALMIDDLE(startInterv, endInterv),
        sumInterv = build(listV, listSegment, startInterv, middle, posi * 2 + 1) +
                    build(listV, listSegment, middle, endInterv, posi * 2 + 2);

    return listSegment[posi] = sumInterv; 
}

int update(int newValue, int indexUpdate, int *listSegment, int startInterv, int endInterv, int posi){
    if (startInterv == endInterv - 1)
        return listSegment[posi] = newValue;

    const int middle = CALMIDDLE(startInterv, endInterv),
            sumInterv = indexUpdate < middle ? 
                            update(newValue, indexUpdate, listSegment, startInterv, middle, posi * 2 + 1) + listSegment[posi * 2 + 2]:
                            update(newValue, indexUpdate, listSegment, middle, endInterv, posi * 2 + 2) + listSegment[posi * 2 + 1];
                                                
    return listSegment[posi] = sumInterv;
}

int getSum(int *listSegment, int findStartIndex, int findEndIndex, int startInterv, int endInterv, int posi){
    if (findStartIndex >= endInterv || findEndIndex < startInterv)
        return 0;

    if (findStartIndex <= startInterv && endInterv <= findEndIndex + 1)
        return listSegment[posi];

    const int middle = CALMIDDLE(startInterv, endInterv);

    return getSum(listSegment, findStartIndex, findEndIndex, startInterv, middle, posi * 2 + 1) +
            getSum(listSegment, findStartIndex, findEndIndex, middle, endInterv, posi * 2 + 2);
}

void print(int *l, int length){
    for (int i = 0; i < length; i++)
        printf("%d ", l[i]);

    printf("\n");
}