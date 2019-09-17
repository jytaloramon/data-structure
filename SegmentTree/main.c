#include "stdio.h"
#include "stdlib.h"
#define TRUE 1
#define FALSE 0
#define MAX 10000
#define MIDDLECAL(a, b)((a + b) / 2)

int array[MAX];
int tree[MAX * 3];

int buildTree(int level, int startInterv, int endInterv);

int updateTree(int level, int startInterv, int endInterv, int posiAlter, int newValue);

int getSum(int level, int startInterv, int endInterv, int queryS, int queryE);

void printArray(int length);

int main(int argc, char const *argv[]){
    
    int i, lengthArray, opt, a, b; 
    
    printf("Numero total de elementos: ");
    scanf("%d", &lengthArray);
    
    for(i = 0; i < lengthArray; i++){
        printf("Valor %d: ", i + 1);
        scanf("%d", &array[i]);
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

                array[b - 1] = a;
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

int buildTree(int level, int startInterv, int endInterv){
    if(startInterv == endInterv)
       return tree[level] = array[startInterv];

    int middle = MIDDLECAL(startInterv, endInterv),
        vLeft = buildTree(level * 2 + 1, startInterv, middle),
        vRigth = buildTree(level * 2 + 2, middle + 1, endInterv);

    
    return tree[level] = vLeft + vRigth;
}

int updateTree(int level, int startInterv, int endInterv, int posiAlter, int newValue){
    if(startInterv == endInterv)
        return tree[level] = newValue;

    int middle = MIDDLECAL(startInterv, endInterv);
    if(posiAlter <= middle)
        return tree[level] = updateTree(level * 2 + 1, startInterv, middle, posiAlter, newValue) + tree[level * 2 + 2];

    return tree[level] = updateTree(level * 2 + 2, middle + 1, endInterv, posiAlter, newValue) + tree[level * 2 + 1];
}   

int getSum(int level, int startInterv, int endInterv, int queryS, int queryE){
    if(queryS <= startInterv && queryE >= endInterv)
        return tree[level];
    
    if(queryS > endInterv || queryE < startInterv)
        return 0;

    int middle = MIDDLECAL(startInterv, endInterv);
    
    return getSum(level * 2 + 1, startInterv, middle, queryS, queryE) +
           getSum(level * 2 + 2, middle + 1, endInterv, queryS, queryE);
}

void printArray(int length){
    printf("\nArray:");
    for (int i = 0; i < length; i++)
        printf(" %d", array[i]);
    
    printf("\n");
}