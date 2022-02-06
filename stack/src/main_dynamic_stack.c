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
    OFFSET,
};

typedef struct _Cel {
    char data;
    LlItem item_stack;
} Cel;

int comparator(void *const a, void *const b);

void stack_show(LList *stack);

int main(int argc, char const *argv[]) {

    char test_cases[INPUTSIZE][2] = {
        {POP, '_'},    {PUSH, 'A'},   {PUSH, 'B'}, {POP, '_'},    {POP, '_'},
        {POP, '_'},    {PUSH, 'C'},   {PUSH, 'D'}, {POP, '_'},    {PUSH, 'E'},
        {POP, '_'},    {PUSH, 'F'},   {POP, '_'},  {PUSH, 'G'},   {PUSH, 'H'},
        {PUSH, 'G'},   {POP, '_'},    {PUSH, 'H'}, {PUSH, 'H'},   {PUSH, 'K'},
        {PUSH, 'G'},   {PEEK, '_'},   {POP, '_'},  {OFFSET, 'G'}, {OFFSET, 'H'},
        {OFFSET, 'K'}, {OFFSET, 'T'}, {PUSH, 'T'}, {OFFSET, 'T'}, {POP, '_'},
    };

    int op, rs;
    char *value1;
    Cel *cel_aux = NULL;
    LlItem *item_stack_aux = NULL;
    LList *stack = dst_new();

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

            rs = dst_push(stack, &cel_aux->item_stack);
            rs == 1 ? printf("Success\n") : printf("Fail!\n");
            stack_show(stack);
            break;
        case POP:
            printf("POP: ");
            item_stack_aux = dst_pop(stack);

            item_stack_aux
                ? printf("%c\n",
                         ((Cel *)GETSTRUCTFROM(item_stack_aux, Cel, item_stack))
                             ->data)
                : printf("Fail!\n");
            stack_show(stack);
            break;
        case PEEK:
            printf("PEEK: ");
            item_stack_aux = dst_peek(stack);
            item_stack_aux
                ? printf("%c\n",
                         ((Cel *)GETSTRUCTFROM(item_stack_aux, Cel, item_stack))
                             ->data)
                : printf("Empty!\n");
            break;
        case OFFSET:
            printf("OFFSET (%c): ", *value1);
            rs = dst_offset(stack, value1, comparator);
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

void stack_show(LList *stack) {

    printf("\n @ Stack SHOW\n");

    if (dst_is_empty(stack)) {
        printf("| Empty!\n----------");
    } else {
        for (LlItem *item_r = stack->head.next; item_r; item_r = item_r->next) {
            printf("| -> %c\n",
                   ((Cel *)GETSTRUCTFROM(item_r, Cel, item_stack))->data);
        }
        printf("----------\n   [%lu]", stack->length);
    }

    printf("\n\n");
}
