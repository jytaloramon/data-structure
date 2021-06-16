/**
 * @author: Ytalo Ramon
 * @date:   16/06/2021
*/

#include "stdlib.h"
#include "../include/static_stack.h"

Stack *stack_new(int size){

    Stack *stack = malloc(sizeof(Stack));

    if (!stack)
        return NULL;

    stack->p_top = -1;
    stack->length = 0;
    stack->size = size;
    stack->items = malloc(sizeof(ItemStack) * stack->size);

    if (!stack->items){
        free(stack);
        return NULL;
    }

    return stack;
}

int stack_is_empty(Stack *stack){

    return stack->p_top == -1; 
}

int stack_is_full(Stack *stack){

    return stack->p_top == stack->size - 1;
}

int stack_push(Stack *stack, void *data){
   
    if(stack_is_full(stack)) 
        return 0;

    stack->items[++stack->p_top].data = data;
    stack->length++;

    return 1;
}

void *stack_pop(Stack *stack){
    
    if(stack_is_empty(stack))
        return NULL;

    void *data = stack->items[stack->p_top].data;
    stack->items[stack->p_top--].data = NULL;
    stack->length--;

    return data;
}

void stack_clear(Stack *stack){

    for (int i = stack->p_top; i >= 0; --i)
        free(stack->items[i].data);
    stack->p_top = -1;
    stack->length = 0;
}

void *stack_peek(Stack *stack){

    if(stack_is_empty(stack))
        return NULL;

    return stack->items[stack->p_top].data;
}

int stack_search(Stack *stack, void *value, ICOMPARATOR){

    if (stack_is_empty(stack))
        return -1;

    for (int i = stack->p_top; i >= 0; --i){
        if (!comparator(stack->items[i].data, value))
            return stack->p_top - i;
    }  
    
    return -1;
}
