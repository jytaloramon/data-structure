/**
 * @author: Ytalo Ramon
 * @date:   16/06/2021
*/

#include "stdlib.h"
#include "stdio.h"
#include "../include/dynamic_stack.h"

Stack *stack_new(){

    Stack *stack = malloc(sizeof(Stack));

    if (!stack)
        return NULL;

    stack->length = 0;
    stack->head.data = stack->head.next = NULL;

    return stack;
}

ItemStack *stack_new_item(void *data){

    ItemStack *item = malloc(sizeof(ItemStack));

    if (!item)
        return NULL;
    
    item->data = data;
    item->next = NULL;

    return item;
}

int stack_is_empty(Stack *stack){

    return stack->head.next == NULL;
}

int stack_push(Stack *stack, void *data){
   
    ItemStack *item = stack_new_item(data);

    if (!item)
        return 0;
    
    item->next = stack->head.next;
    stack->head.next = item;
    stack->length++;

    return 1;
}

void *stack_pop(Stack *stack){
    
    if(stack_is_empty(stack))
        return NULL;

    ItemStack *item = stack->head.next;
    void *data = item->data;
    stack->head.next = item->next;
    stack->length--;
    free(item);

    return data;
}

void stack_clear(Stack *stack){

    for (ItemStack *item_r = stack->head.next, *item_n = NULL; item_r; item_r = item_n){
        item_n = item_r->next;
        free(item_r->data);
        free(item_r);
    }

    stack->head.next = NULL;
    stack->length = 0;
}

void *stack_peek(Stack *stack){

    if(stack_is_empty(stack))
        return NULL;

    return stack->head.next->data;
}

int stack_search(Stack *stack, void *value, ICOMPARATOR){

    if (stack_is_empty(stack))
        return -1;
        
    int i = 0;
    ItemStack *item_r = stack->head.next;

    while (item_r && comparator(item_r->data, value)){
        item_r = item_r->next;
        i++;
    }

    return item_r ? i : -1;
}
