/**
 * Uma Fila é uma estrutura linear que segue uma ordem específica na qual as operações são executadas em ambas extremidades. 
 * Uma extremidade é sempre usada para inserir dados (enfileirar) e a outra é usada para remover dados (enfileirar). 
 *      A fila segue a metodologia First-In-First-Out, ou seja, o item de dados armazenado primeiro será acessado primeiro.
 * Complexidade de alteração: O(1)
 * */

#include "stdio.h"
#include "stdlib.h"

typedef struct _node {
    int value;
    struct _node *next;
} Node;

typedef struct _queue {
    struct _node *root, **last;
} Queue;

Node *createNode(int value);

int empty(Queue *queue);

void enqueue(Queue *queue, Node *node);

Node *desqueue(Queue *queue);

Node *getFront(Queue *queue);

void printArr(Queue *queue);

int main(int argc, char const *argv[]){
    
    int opt, value;
    Queue queue = { NULL, &queue.root };
    Node *nodeAux;
    
    do {
        printf("[1] Enqueue\n[2] Dequeue\n[3] fistElQueue\n[Q] Exit\nDigite: ");
        scanf("%d", &opt);

        switch (opt){
        case 1:
            printf("Enqueue value: ");
            scanf("%d", &value);

            nodeAux = createNode(value);
            enqueue(&queue, nodeAux);
            printArr(&queue);
            break;
        
        case 2:
            if (empty(&queue))
                printf("    Pilha Vazia\n");
            else {
                nodeAux = desqueue(&queue);
                printf("    Elemento removido: %d\n", nodeAux->value);
                printArr(&queue);
            }
            break;
        
        case 3:
            if (empty(&queue))
                printf("    Pilha Vazia\n");
            else {
                nodeAux = getFront(&queue);
                printf("    Primeiro elemento: %d\n", nodeAux->value);
            }
            break;
            
        default: exit(0);

        }

        printf("\n"); 
    } while (1);

    return 0;
}

Node *createNode(int value){
    Node *node = malloc(sizeof(Node));
    node->value = value;
    node->next = NULL;

    return node;
}

int empty(Queue *queue){
    return queue->root == NULL;
}

void enqueue(Queue *queue, Node *node){
    *(queue->last) = node;
    queue->last = &node->next;
}

Node* desqueue(Queue *queue){
    Node *ptr = queue->root;
    queue->root = ptr->next;
    
    if (queue->root == NULL)
        queue->last = &queue->root;

    return ptr;
}

Node* getFront(Queue *queue){
    return queue->root;
}

void printArr(Queue *queue){
    Node *el = queue->root;

    printf("--------------------\n");
    
    while (el != NULL){
        printf("%d ", el->value);
        el = el->next;
    }

    printf("\n--------------------\n\n");
}