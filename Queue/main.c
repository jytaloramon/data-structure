/**
 * Uma Fila é uma estrutura linear que segue uma ordem específica na qual as operações são executadas. 
 * A ordem é First In First Out (FIFO): o primeiro elemento a ser colocado na estrutura é o primeiro a ser retirado.
 */

#include "stdio.h"
#include "stdlib.h"

#define TRUE 1
#define FALSE 0

typedef struct _node {
    int value;
    struct _node *next;
} Node;

typedef struct _queue {
    struct _node *root;
} Queue;

Node *createNode(int value);

int empty(Queue *queue);

void enqueue(Queue *queue, Node *node);

Node* desqueue(Queue *queue);

Node* getFront(Queue *queue);

int main(int argc, char const *argv[]){
    
    Queue queue = { NULL };
    Node *nodeAux;
    int opt, value;

    do {
        printf("[1] Enqueue\n[2] Dequeue\n[3] fistElQueue\n[Q] Exit\n");
        scanf("%d", &opt);

        switch (opt){
            case 1:
                printf("Enqueue value: ");
                scanf("%d", &value);

                nodeAux = createNode(value);
                enqueue(&queue, nodeAux);
                break;
        
            case 2:
                if (empty(&queue) == TRUE)
                    printf("    Pilha Vazia\n");
                else {
                    nodeAux = desqueue(&queue);
                    printf("    Elemento removido: %d\n", nodeAux->value);
                }
                break;
            
            case 3:
                if (empty(&queue) == TRUE)
                    printf("    Pilha Vazia\n");
                else {
                    nodeAux = getFront(&queue);
                    printf("    Primeiro elemento: %d\n", nodeAux->value);
                }
                break;
                
            default:
                exit(0);
        }

        printf("\n"); 
    } while (TRUE);

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
    Node *ptr = queue->root;

    if (ptr == NULL){
        queue->root = node;
        return;
    }

    while (ptr->next != NULL)
        ptr = ptr->next;
    
    ptr->next = node;
}

Node* desqueue(Queue *queue){
    Node *ptr = queue->root;
    queue->root = ptr->next;
    
    return ptr;
}

Node* getFront(Queue *queue){
    return queue->root;
}
