/**
 * @author: Ytalo Ramon
 * @date:   16/06/2021
*/

#include "stdio.h"
#include "stdlib.h"
#include "../include/static_stack.h"

#define INPUTSIZE 30 // Input size for test.

enum options {
    PUSH,
    POP,
    PEEK,
    SEARCH,
    CLEAR
};

int comparator(void *const a, void *const b);

void stack_show(Stack *stack);

int main(int argc, char const *argv[]){

    int op, rs;
    char *value1, *value2;
    char test_cases[INPUTSIZE][2] = {
        {POP, '_'},
        {PUSH, 'A'},
        {PUSH, 'B'},
        {POP, '_'},
        {POP, '_'},
        {POP, '_'},
        {PUSH, 'C'},
        {PUSH, 'D'},
        {POP, '_'},
        {PUSH, 'E'},
        {POP, '_'},
        {PUSH, 'F'},
        {POP, '_'},
        {PUSH, 'G'},
        {PUSH, 'H'},
        {PUSH, 'G'},
        {POP, '_'},
        {PUSH, 'H'},
        {PUSH, 'H'},
        {PUSH, 'K'},
        {PUSH, 'G'},
        {PEEK, '_'},
        {POP, '_'},
        {SEARCH, 'G'},
        {SEARCH, 'H'},
        {SEARCH, 'K'},
        {SEARCH, 'T'},
        {PUSH, 'T'},
        {SEARCH, 'T'},
        {POP, '_'},
    };

    Stack *stack = stack_new(7);
    
    printf("+++++ STATIC STACK +++++\n\n");
    stack_show(stack);
    
    for (int i = 0; i < INPUTSIZE; ++i){
        op = test_cases[i][0];
        value1 = &test_cases[i][1];

        printf("* ");
        switch (op){
        case PUSH:    
            printf("PUSH: %c: ", *value1);
            rs = stack_push(stack, value1);
            rs == 1 ? printf("Success\n") : printf("Fail!\n");
            stack_show(stack);
            break;
        case POP:
            printf("POP: ");
            value2 = stack_pop(stack);
            value2 ? printf("%c\n", *value2) : printf("Fail!\n");
            stack_show(stack);
            break;
        case PEEK:
            printf("PEEK: ");
            value2 = stack_peek(stack);
            value2 ? printf("%c\n", *value2) : printf("Empty!\n");
            break;
        case SEARCH:
            printf("SEARCH (%c): ", *value1);
            rs = stack_search(stack, value1, comparator);
            rs != -1 ? printf("%d\n", rs) : printf("Not Found!\n");
            break;
        default:
            printf("CLEAR\n");
            stack_clear(stack);
            stack_show(stack);
            break;
        }
    }
    
    printf("\n");

    return 0;
}

int comparator(void *const a, void *const b){
    
    return *((char *) a) - *((char *) b);
}

void stack_show(Stack *stack){
    
    printf("\n @ Stack SHOW\n");

    if (!stack_is_empty(stack)){

        for (int i = stack->p_top; i >= 0; --i)
            printf("| -> %c\n", *((char *) stack->items[i].data));
        printf("----------\n   [%d/%d]", stack->length, stack->size);
    } else {
        printf("| Empty!\n");
        printf("----------");
    }

    printf("\n\n");
}
