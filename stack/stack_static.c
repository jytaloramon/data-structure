/**
 * @author: Ytalo Ramon
*/

#include "stdio.h"
#include "stdlib.h"
#include "string.h"
#include "./headers/stack.h"

/* Maximum stack size. */
#define STACKSIZE 5
/* Maximum string size.  Real capacity is STRINGSIZE - 1. */
#define STRINGSIZE 13
/* Input size for test. */
#define INPUTSIZE 29

/**
 * struct _ItemStack.
 * _ItemStack information.
 * attr: char* value - string value.
*/
struct _ItemStack{
    char value[STRINGSIZE];
};

/**
 * struct _Stack.
 * _Stack information.
 * attr: int top - top item index.
 * attr: struct _ItemStack *items - pointer array for item instances.
*/
struct _Stack{
    int top;
    struct _ItemStack items[STACKSIZE];
};

/**
 * function main.
*/
int main(int argc, char const *argv[]){
    
    Stack stack;
    initialize_stack(&stack);
    
    char *value_aux;
    int rs;

    char inputs[INPUTSIZE][2][STRINGSIZE] = {
        {"0", ""},
        {"2", ""},
        {"1", "Ramon"},
        {"1", "Jack"},
        {"2", ""},
        {"3", "Jack"},
        {"3", "Caio"},
        {"0", ""},
        {"1", "Maria"},
        {"0", ""},
        {"0", ""},
        {"0", ""},
        {"0", ""},
        {"1", "Fanny"},
        {"1", "Calos"},
        {"0", ""},
        {"1", "Rock"},
        {"1", "Hellen"},
        {"1", "Chris"},
        {"3", "Helen"},
        {"2", ""},
        {"1", "SuperCam"},
        {"3", "Chris"},
        {"1", "Derik"},
        {"3", "Fanny"},
        {"0", ""},
        {"2", ""},
        {"0", ""},
        {"1", "Derik"}};

    for (int i = 0; i < INPUTSIZE; i++){
        switch (inputs[i][0][0]){
        case '0': // POP
            printf("POP: ");
            value_aux = pop(&stack);
            value_aux ? printf("-> %s <-\n", value_aux) : printf("-> Stack Empty! <-\n");
            free(value_aux);
            break;
        case '1': // PUSH
            printf("PUSH: %s\n", inputs[i][1]);
            value_aux = push(&stack, inputs[i][1]);
            value_aux ? printf(" -> OK <-\n") : printf("-> Error! <-\n");
            break;
        case '2': // PEEK
            printf("PEEK: ");
            value_aux = peek(&stack);
            value_aux ? printf("%s\n", value_aux) : printf("-> Stack Empty! <-\n");
            break;
        default: // SEARCH
            printf("SEARCH: %s\n", inputs[i][1]);
            rs = search(&stack, inputs[i][1]);
            rs != -1 ? printf("-> OFFSET: %d <-\n", rs) : printf("-> NOT FOUND! <-\n");
            break;
        }

        show(&stack);
    }

    printf("-> CLEAR STACK <-\n");
    clear(&stack);
    show(&stack);
    
    return 0;
}

void initialize_stack(Stack *stack){
    stack->top = -1;
}

int is_empty(Stack *stack){
    return stack->top == -1; 
}

int is_full(Stack *stack){
    return stack->top == STACKSIZE - 1;
}

void clear(Stack *stack){
    if(!is_empty(stack)) 
        while (stack->top-- >= 0) stack->items[stack->top].value[0] = '\0';
        
    initialize_stack(stack);
}

char *pop(Stack *stack){
    if(is_empty(stack)) return NULL;

    char *value = malloc(sizeof(char) * STRINGSIZE);
    strncpy(value, stack->items[stack->top - 1].value, STRINGSIZE);
    stack->items[--stack->top].value[0] = '\0';
    return value;
}

char *push(Stack *stack, char *value){
    if(is_full(stack)) return NULL;

    strncpy(stack->items[stack->top].value, value, STRINGSIZE);
    return stack->items[stack->top++].value;
}

char *peek(Stack *stack){
    if(is_empty(stack)) return NULL;

    return stack->items[stack->top - 1].value;
}

int search(Stack *stack, char *value){
    for (int idx = stack->top - 1; idx >= 0; idx--)
        if(!strncmp(stack->items[idx].value, value, STRINGSIZE)) return stack->top - idx - 1;        
    
    return -1;
}

void show(Stack *stack){
    printf("\n\n");
    if(is_empty(stack)) printf("EMPTY!\n");
    else {
        for (int idx = stack->top - 1; idx >= 0; idx--)
            printf("| %d - %s\n", stack->top - idx - 1, stack->items[idx].value);
    }
    
    for(int i = 0; i < STRINGSIZE + 4; i++) printf("-");
    printf("\n\n");
}