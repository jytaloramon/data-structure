/**
 * @author: Ytalo Ramon
 * @date:   16/06/2021
 */

#include "../../includes/istructure_utils.h"
#include "../include/dynamic_stack.h"
#include "stdio.h"
#include "stdlib.h"

#define INPUTSIZE 30 // Input size for test.

enum options {
    PUSH,
    POP,
    PEEK,
    SEARCH,
};

typedef struct _Cel {
    char data;
    ItemStack item_stack;
} Cel;

int comparator(void *const a, void *const b);

void stack_show(Stack *stack);

int main(int argc, char const *argv[]) {

    int op, rs;
    char *value1;
    Cel *cel_aux = NULL;
    ItemStack *item_stack_aux = NULL;

    char test_cases[INPUTSIZE][2] = {
        {POP, '_'},    {PUSH, 'A'},   {PUSH, 'B'}, {POP, '_'},    {POP, '_'},
        {POP, '_'},    {PUSH, 'C'},   {PUSH, 'D'}, {POP, '_'},    {PUSH, 'E'},
        {POP, '_'},    {PUSH, 'F'},   {POP, '_'},  {PUSH, 'G'},   {PUSH, 'H'},
        {PUSH, 'G'},   {POP, '_'},    {PUSH, 'H'}, {PUSH, 'H'},   {PUSH, 'K'},
        {PUSH, 'G'},   {PEEK, '_'},   {POP, '_'},  {SEARCH, 'G'}, {SEARCH, 'H'},
        {SEARCH, 'K'}, {SEARCH, 'T'}, {PUSH, 'T'}, {SEARCH, 'T'}, {POP, '_'},
    };

    Stack *stack = stack_new();

    printf("+++++ DYNAMIC STACK +++++\n\n");
    stack_show(stack);

    for (int i = 0; i < INPUTSIZE; ++i) {
        op = test_cases[i][0];
        value1 = &test_cases[i][1];

        printf("* ");
        switch (op) {
        case PUSH:
            printf("PUSH %c: ", *value1);

            cel_aux = malloc(sizeof(Cel));
            cel_aux->data = *value1;

            rs = stack_push(stack, &cel_aux->item_stack);
            rs == 1 ? printf("Success\n") : printf("Fail!\n");
            stack_show(stack);
            break;
        case POP:
            printf("POP: ");
            item_stack_aux = stack_pop(stack);

            item_stack_aux
                ? printf("%c\n",
                         ((Cel *)GETSTRUCTFROM(item_stack_aux, Cel, item_stack))
                             ->data)
                : printf("Fail!\n");
            stack_show(stack);
            break;
        case PEEK:
            printf("PEEK: ");
            item_stack_aux = stack_peek(stack);
            item_stack_aux
                ? printf("%c\n",
                         ((Cel *)GETSTRUCTFROM(item_stack_aux, Cel, item_stack))
                             ->data)
                : printf("Empty!\n");
            break;
        case SEARCH:
            printf("SEARCH (%c): ", *value1);
            rs = stack_search(stack, value1, comparator);
            rs != -1 ? printf("%d\n", rs) : printf("Not Found!\n");
            break;
        default:
            printf("OPTION NOT FOUND\n");
        }
    }

    printf("\n");

    return 0;
}

int comparator(void *const a, void *const b) {

    char elmnt = *((char *)a);
    Cel *cel = ((Cel *)GETSTRUCTFROM(b, Cel, item_stack));

    return elmnt - cel->data;
}

void stack_show(Stack *stack) {

    printf("\n @ Stack SHOW\n");

    if (stack_is_empty(stack)) {
        printf("| Empty!\n");
        printf("----------\n\n");

        return;
    }

    for (ItemStack *item_r = stack->head.next; item_r; item_r = item_r->next) {
        printf("| -> %c\n",
               ((Cel *)GETSTRUCTFROM(item_r, Cel, item_stack))->data);
    }
    printf("----------\n   [%d]", stack->length);

    printf("\n\n");
}
