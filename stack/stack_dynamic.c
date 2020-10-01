/**
 * @author: Ytalo Ramon
*/

#include "stdio.h"
#include "stdlib.h"
#include "string.h"
#include "./headers/stack.h"

/* Maximum string size.  Real capacity is STRINGSIZE - 1. */
#define STRINGSIZE 13
/* Input size for test. */
#define INPUTSIZE 29

/**
 * struct _ItemStack.
 * _ItemStack information.
 * attr: char* value - string value.
 * attr: struct _ItemStack *next - pointer next item.
*/
struct _ItemStack{
    char value[STRINGSIZE];
    struct _ItemStack *next;
};

/**
 * struct _Stack.
 * _Stack information.
 * attr: struct _ItemStack *top_item - pointer to the top item instance.
*/
struct _Stack{
    struct _ItemStack *top_item;
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
    stack->top_item = NULL;
}

int is_empty(Stack *stack){
    return !stack->top_item;
}

void clear(Stack *stack){
    if (!is_empty(stack)){
        ItemStack *item_actual = stack->top_item, *item_next;
        while (item_actual){
            item_next = item_actual->next;
            free(item_actual);
            item_actual = item_next;
        }
    }
    
    initialize_stack(stack);
}

ItemStack *new_item(char *value){
    ItemStack *item_stack = malloc(sizeof(ItemStack));
    if(!item_stack) return NULL;

    strncpy(item_stack->value, value, STRINGSIZE);
    item_stack->next = NULL;
    return item_stack;
}

char *pop(Stack *stack){
    if(is_empty(stack)) return NULL;

    ItemStack *top_item = stack->top_item;
    stack->top_item = top_item->next;
    char *value = malloc(sizeof(char) * STRINGSIZE);
    strncpy(value, top_item->value, STRINGSIZE);
    free(top_item);
    return value;
}

char *push(Stack *stack, char *value){
    ItemStack *item_new = new_item(value);
    if(!item_new) return NULL;

    item_new->next = stack->top_item;
    stack->top_item = item_new;
    return stack->top_item->value;
}

char *peek(Stack *stack){
    if(is_empty(stack)) return NULL;

    return stack->top_item->value;
}

int search(Stack *stack, char *value){
    ItemStack *item_actual = stack->top_item;
    int idx = 0;
    while (item_actual){
        if (!strncmp(item_actual->value, value, STRINGSIZE)) return idx;
        item_actual = item_actual->next;
        idx++;
    }
    
    return -1;
}

void show(Stack *stack){
    printf("\n\n");
    if(is_empty(stack)) printf("EMPTY!\n");
    else {
        ItemStack *item_actual = stack->top_item;
        int idx = 0;
        while (item_actual){
            printf("| %d - %s\n", idx, item_actual->value);
            item_actual = item_actual->next;
            idx++;
        }
    }
    
    for(int i = 0; i < STRINGSIZE + 4; i++) printf("-");
    printf("\n\n");
}