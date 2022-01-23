/**
 * @author: Ytalo Ramon
 * @date:   16/06/2021
 */

#include "../../includes/istructure_utils.h"
#include "../../math/include/arithmetic.h"
#include "../include/static_stack.h"
#include "stdio.h"
#include "stdlib.h"

#define INPUTSIZE 30 // Input size for test.

enum options {
    PUSH,
    POP,
    PEEK,
    OFFSET,
};

typedef struct _Cel {
    char data;
    SlItem item_stack;
} Cel;

int comparator(void *const a, void *const b);

void stack_show(SList *stack);

int main(int argc, char const *argv[]) {

    int op, rs;
    char *value1;

    Cel *cel_aux = NULL;
    SlItem *item_sst_aux = NULL;

    char test_cases[INPUTSIZE][2] = {
        {POP, '_'},    {PUSH, 'A'},   {PUSH, 'B'}, {POP, '_'},    {POP, '_'},
        {POP, '_'},    {PUSH, 'C'},   {PUSH, 'D'}, {POP, '_'},    {PUSH, 'E'},
        {POP, '_'},    {PUSH, 'F'},   {POP, '_'},  {PUSH, 'G'},   {PUSH, 'H'},
        {PUSH, 'G'},   {POP, '_'},    {PUSH, 'H'}, {PUSH, 'H'},   {PUSH, 'K'},
        {PUSH, 'G'},   {PEEK, '_'},   {POP, '_'},  {OFFSET, 'G'}, {OFFSET, 'H'},
        {OFFSET, 'K'}, {OFFSET, 'T'}, {PUSH, 'T'}, {OFFSET, 'T'}, {POP, '_'},
    };

    SList *stack = sst_new(7);

    printf("+++++ STATIC STACK +++++\n\n");
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

            rs = sst_push(stack, &cel_aux->item_stack);
            rs == 1 ? printf("Success\n") : printf("Fail!\n");
            stack_show(stack);

            break;
        case POP:
            printf("POP: ");
            item_sst_aux = sst_pop(stack);

            item_sst_aux
                ? printf("%c\n",
                         ((Cel *)GETSTRUCTFROM(item_sst_aux, Cel, item_stack))
                             ->data)
                : printf("Fail!\n");
            stack_show(stack);

            break;
        case PEEK:
            printf("PEEK: ");
            item_sst_aux = sst_peek(stack);
            item_sst_aux
                ? printf("%c\n",
                         ((Cel *)GETSTRUCTFROM(item_sst_aux, Cel, item_stack))
                             ->data)
                : printf("Empty!\n");
            break;
        case OFFSET:
            printf("OFFSET (%c): ", *value1);
            rs = sst_offset(stack, value1, comparator);
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

void stack_show(SList *stack) {

    printf("\n @ Stack SHOW\n");

    if (sst_is_empty(stack)) {
        printf("| Empty!\n");
        printf("----------\n\n");

        return;
    }

    for (int i = stack->p_front; i != stack->p_rear;
         i = divmodular(i + 1, stack->size)) {
        printf("| -> %c\n",
               ((Cel *)GETSTRUCTFROM(stack->items[i], Cel, item_stack))->data);
    }
    printf("----------\n   [%lu/%lu]", stack->length, stack->size - 1);
    printf("\n\n");
}
