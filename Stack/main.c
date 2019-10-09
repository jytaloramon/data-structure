/**
 * Stack: Trata-se de uma estrutura de dados que usa o esquema FILO: First In, Last Out.
 * Ou seja, o primeiro elemento a ser colocado na estrutura é o último a ser retirado.
 */

#include "stdio.h"
#include "stdlib.h"

#define TRUE 1
#define FALSE 0

typedef struct _element {
    int value;
    struct _element *next;
} Element;

typedef struct {
    struct _element *top;
} Stack;

Element* createElement(int value);

int empty(Stack *stack);

void push(Stack *stack, Element *newElement);

Element* pop(Stack *stack);

Element* stackTop(Stack *stack);

int main(int argc, char const *argv[]){
    
    Stack stack = { NULL };

    Element *elAux;
    int opt, value;

    do {
        printf("[1] Push\n[2] Pop\n[3] StackTop\n[Q] Exit\n");
        scanf("%d", &opt);

        switch (opt){
            case 1:
                printf("Push value: ");
                scanf("%d", &value);

                elAux = createElement(value);
                push(&stack, elAux);
                break;
        
            case 2:
                if (empty(&stack) == TRUE)
                    printf("    Pilha Vazia\n");
                else {
                    elAux = pop(&stack);
                    printf("    Elemento removido: %d\n", elAux->value);
                }
                break;
            
            case 3:
                if (empty(&stack) == TRUE)
                    printf("    Pilha Vazia\n");
                else {
                    elAux = stackTop(&stack);
                    printf("    Elemento no topo: %d\n", elAux->value);
                }
                break;
                
            default:
                exit(0);
        }

        printf("\n"); 
    } while (TRUE);
    
    return EXIT_SUCCESS;
}

Element* createElement(int value){
    Element *el = malloc(sizeof(Element));
    el->value = value;
    el->next = NULL;

    return el;
}

int empty(Stack *stack){
    return stack->top == NULL;
}

void push(Stack *stack, Element *newElement){
    newElement->next = stack->top;
    stack->top = newElement;
}

Element* pop(Stack *stack){
    Element *elPush = stack->top;
    stack->top = elPush->next;

    return elPush;
}

Element* stackTop(Stack *stack){
    return stack->top;
}
