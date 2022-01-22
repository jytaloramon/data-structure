/**
 * @author Ytalo Ramon
 * @date   12/06/2021
 */

#include "../../includes/istructure_utils.h"
#include "../../math/include/arithmetic.h"
#include "../include/static_queue.h"
#include "stdio.h"
#include "stdlib.h"

#define INPUTSIZE 30 // Input size for test.

enum options { ENQUEUE, DEQUEUE, PEEK, OFFSET, CLEAR };

typedef struct _Cel {
    char data;
    struct _SlItem item_queue;
} Cel;

int comparator(void *const a, void *const b);

void queue_show(SList *queue);

int main(int argc, char const *argv[]) {

    int op, rs;
    char *value1;

    Cel *cel_aux = NULL;
    SlItem *sq_item_aux = NULL;

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

    SList *queue = sq_new(7);

    printf("+++++ STATIC QUEUE +++++\n\n");
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

            rs = sq_enqueue(queue, &cel_aux->item_queue);
            rs == 1 ? printf("Success\n") : printf("Fail!\n");
            queue_show(queue);

            break;
        case DEQUEUE:
            printf("DEQUEUE: ");
            sq_item_aux = sq_dequeue(queue);

            if (!sq_item_aux) {
                printf("Fail!\n");
            } else {
                printf(
                    "%c\n",
                    ((Cel *)GETSTRUCTFROM(sq_item_aux, Cel, item_queue))->data);
            }

            queue_show(queue);

            break;
        case PEEK:
            printf("PEEK: ");
            sq_item_aux = sq_peek(queue);

            if (!sq_item_aux) {
                printf("Empty!\n");
            } else {
                printf(
                    "%c\n",
                    ((Cel *)GETSTRUCTFROM(sq_item_aux, Cel, item_queue))->data);
            }

            break;
        case OFFSET:
            printf("OFFSET (%c): ", *value1);
            rs = sq_offset(queue, value1, comparator);
            rs != -1 ? printf("%d\n", rs) : printf("Not Found!\n");

            break;
        default:
            printf("NOT OPTION!");
            break;
        }
    }

    printf("\n");

    return 0;
}

int comparator(void *const a, void *const b) {

    Cel *cel = GETSTRUCTFROM(b, Cel, item_queue);

    return *((char *)a) - cel->data;
}

void queue_show(SList *queue) {

    printf("\n @ Queue SHOW: ");

    if (sq_is_empty(queue)) {
        printf("Empty!\n");
        printf("-------------\n\n");

        return;
    }

    for (int i = queue->p_front; i != queue->p_rear;
         i = divmodular(i + 1, queue->size)) {

        printf("%c, ",
               ((Cel *)GETSTRUCTFROM(queue->items[i], Cel, item_queue))->data);
    }
    printf("[%lu/%lu]\n-------------", queue->length, queue->size - 1);

    for (int i = 0; i < queue->length; i++)
        printf("----");

    printf("\n\n");
}
