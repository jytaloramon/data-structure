/**
 * Árvore Fenwick ou árvore indexada binária(BIT) é uma estrutura de dados que pode atualizar com eficiência elementos 
 *      e calcular somas de intervalos em uma lista de números; funcionamento semelhante as SegmentTree. 
 * Complexidade: consulta&atualização - O(log n).
 */

#include "stdio.h"
#include "stdlib.h"
#include "string.h"

#define MAX 15

void update(int value, int startIndex, int *listBit, int length);

int getSum(int *listBit, int endInterv);

void print(int *list, int lenght);

int main(int argc, char const *argv[]){
    
    int status = 1, a, b, option, lengthArray,
        listValues[MAX], listBit[MAX];

    memset(listBit, 0, sizeof(int) * MAX);

    printf("Tamanho do array (<= %d): ", MAX);
    scanf("%d", &lengthArray);
    
    printf("Digite os valoes: ");
    for (int i = 0; i < lengthArray; i++)    
        scanf("%d", &listValues[i]);

    // Contrução do array BIT
    for (int i = 0; i < MAX; i++)
        update(listValues[i], i, listBit, lengthArray);

    do {
        printf("[1] Ver Array\n[2] Update\n[3] Soma\n[Q] Sair\nDigite: ");
        scanf("%d", &option);

        switch (option){
        case 1:
            printf("Array: ");
            print(listValues, lengthArray);

            printf("Array BIT: ");
            print(listBit, lengthArray);
            break;
        
        case 2:
            printf("Index: ");
            scanf("%d", &a);
            printf("Novo valor: ");
            scanf("%d", &b);

            if (a < 0 && a > lengthArray)
                printf("Index invalido!\n");
            else 
                update(b - listValues[a], a, listBit, lengthArray);
            break;
       
        case 3:
            printf("Inicio intervalo: ");
            scanf("%d", &a);
            printf("Fim intervalo: ");
            scanf("%d", &b);

            if (a > b || a < 0 || a > lengthArray || b < 0 || b > lengthArray)
                printf("Intervalo invalidos!\n");
            else 
                printf("Soma de %d - %d: %d\n", a, b, getSum(listBit, b) - getSum(listBit, a));
            
            break;

        default:
            status = 0;
        }
        
        printf("\n\n");
    } while(status);


    return 0;
}

void update(int value, int startIndex, int *listBit, int length){
    int i = startIndex + 1;

    while (i <= length){
        listBit[i - 1] += value;
        i += (i & -i);
    }
}

int getSum(int *listBit, int endInterv){
    int i = endInterv, sum = 0;

    while (i > 0){
        sum += listBit[i - 1];
        i -= (i & -i); 
    }
    
    return sum;
}

void print(int *list, int lenght){
    for (int i = 0; i < lenght; i++)
        printf("%d ", list[i]);

    printf("\n\n");
}
