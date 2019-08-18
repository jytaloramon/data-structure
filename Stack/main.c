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

void push(Stack *stack, Element *newElement);

int empty(Stack *stack);

Element* pop(Stack *stack);

Element* stackTop(Stack *stack);

Element* createElement(int value);

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

void push(Stack *stack, Element *newElement){
    newElement->next = stack->top;
    stack->top = newElement;
}

int empty(Stack *stack){
    return stack->top == NULL;
}

Element* pop(Stack *stack){
    Element *elPush = stack->top;
    stack->top = elPush->next;

    return elPush;
}

Element* stackTop(Stack *stack){
    return stack->top;
}

Element* createElement(int value){
    Element *el = malloc(sizeof(Element));
    el->value = value;
    el->next = NULL;

    return el;
}