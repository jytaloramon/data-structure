/**
 * @author Ytalo Ramon
 * @date   12/06/2021
 */

#include "../../includes/istructure_utils.h"
#include "../include/dynamic_queue.h"
#include "stdio.h"
#include "stdlib.h"

#define INPUTSIZE 30 // Input size for test.

enum options { ENQUEUE, DEQUEUE, PEEK, OFFSET };

typedef struct _Cel {
    char data;
    struct _LlItem item_queue;
} Cel;

int comparator(void *const a, void *const b);

void queue_show(LList *queue);

int main(int argc, char const *argv[]) {

    char test_cases[INPUTSIZE][2] = {
        {DEQUEUE, '_'}, {ENQUEUE, 'A'}, {ENQUEUE, 'B'}, {DEQUEUE, '_'},
        {DEQUEUE, '_'}, {DEQUEUE, '_'}, {ENQUEUE, 'C'}, {ENQUEUE, 'D'},
        {DEQUEUE, '_'}, {ENQUEUE, 'E'}, {DEQUEUE, '_'}, {ENQUEUE, 'F'},
        {DEQUEUE, '_'}, {ENQUEUE, 'G'}, {ENQUEUE, 'H'}, {ENQUEUE, 'G'},
        {DEQUEUE, '_'}, {ENQUEUE, 'H'}, {ENQUEUE, 'H'}, {ENQUEUE, 'K'},
        {ENQUEUE, 'G'}, {PEEK, '_'},    {DEQUEUE, '_'}, {OFFSET, 'G'},
        {OFFSET, 'H'},  {OFFSET, 'K'},  {OFFSET, 'T'},  {ENQUEUE, 'T'},
        {OFFSET, 'T'},  {DEQUEUE, '_'},
    };

    int op, rs;
    char *value1;
    Cel *cel_aux = NULL;
    LlItem *item_aux = NULL;
    LList *queue = dq_new();

    printf("+++++ DYNAMIC STACK +++++\n\n");
    queue_show(queue);

    for (int i = 0; i < INPUTSIZE; ++i) {
        op = test_cases[i][0];
        value1 = &test_cases[i][1];

        printf("* ");
        switch (op) {
        case ENQUEUE:
            printf("ENQUEUE: %c: ", *value1);

            cel_aux = malloc(sizeof(Cel));
            cel_aux->data = *value1;

            rs = dq_enqueue(queue, &cel_aux->item_queue);
            rs == 1 ? printf("Success\n") : printf("Fail!\n");
            queue_show(queue);
            break;
        case DEQUEUE:
            item_aux = dq_dequeue(queue);
            printf("DEQUEUE: ");

            item_aux
                ? printf(
                      "%c\n",
                      ((Cel *)GETSTRUCTFROM(item_aux, Cel, item_queue))->data)
                : printf("Fail!\n");
            queue_show(queue);
            break;
        case PEEK:
            printf("PEEK: ");
            item_aux = dq_peek(queue);

            item_aux
                ? printf(
                      "%c\n",
                      ((Cel *)GETSTRUCTFROM(item_aux, Cel, item_queue))->data)
                : printf("Empty!\n");
            break;
        case OFFSET:
            printf("OFFSET (%c): ", *value1);
            rs = dq_offset(queue, value1, comparator);
            rs != -1 ? printf("%d\n", rs) : printf("Not Found!\n");
            break;
        default:
            printf("NOT OPTION\n");
            break;
        }
    }

    printf("\n");

    return 0;
}

int comparator(void *const a, void *const b) {

    char elmnt = *((char *)a);
    Cel *cel = GETSTRUCTFROM(b, Cel, item_queue);

    return elmnt - cel->data;
}

void queue_show(LList *queue) {

    printf("\n @ Queue SHOW: ");

    if (dq_is_empty(queue)) {
        printf("Empty!\n");
        printf("-------------");
    } else {
        for (LlItem *item_r = queue->head.next; item_r; item_r = item_r->next) {
            printf("%c, ",
                   ((Cel *)GETSTRUCTFROM(item_r, Cel, item_queue))->data);
        }

        printf("[%lu]\n-------------", queue->length);

        for (int i = 0; i < queue->length; i++)
            printf("----");
    }

    printf("\n\n");
}
