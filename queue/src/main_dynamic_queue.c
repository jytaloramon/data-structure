/**
 * @author Ytalo Ramon
 * @date   12/06/2021
*/

#include "stdio.h"
#include "stdlib.h"
#include "../include/dynamic_queue.h"

#define INPUTSIZE 30 // Input size for test.

enum options {
    ENQUEUE,
    DEQUEUE,
    PEEK,
    FIND,
    CLEAR
};

int comparator(void *const a, void *const b);

void queue_show(Queue *queue);

int main(int argc, char const *argv[]){

    int op, rs;
    char *value1, *value2;
    char test_cases[INPUTSIZE][2] = {
        {DEQUEUE, '_'},
        {ENQUEUE, 'A'},
        {ENQUEUE, 'B'},
        {DEQUEUE, '_'},
        {DEQUEUE, '_'},
        {DEQUEUE, '_'},
        {ENQUEUE, 'C'},
        {ENQUEUE, 'D'},
        {DEQUEUE, '_'},
        {ENQUEUE, 'E'},
        {DEQUEUE, '_'},
        {ENQUEUE, 'F'},
        {DEQUEUE, '_'},
        {ENQUEUE, 'G'},
        {ENQUEUE, 'H'},
        {ENQUEUE, 'G'},
        {DEQUEUE, '_'},
        {ENQUEUE, 'H'},
        {ENQUEUE, 'H'},
        {ENQUEUE, 'K'},
        {ENQUEUE, 'G'},
        {PEEK, '_'},
        {DEQUEUE, '_'},
        {FIND, 'G'},
        {FIND, 'H'},
        {FIND, 'K'},
        {FIND, 'T'},
        {ENQUEUE, 'T'},
        {FIND, 'T'},
        {DEQUEUE, '_'},
    };

    Queue *queue = queue_new();

    printf("+++++ DYNAMIC STACK +++++\n\n");
    queue_show(queue);
    
    for (int i = 0; i < INPUTSIZE; ++i){
        op = test_cases[i][0];
        value1 = &test_cases[i][1];

        printf("* ");
        switch (op){
        case ENQUEUE:    
            printf("ENQUEUE: %c: ", *value1);
            rs = queue_enqueue(queue, value1);
            rs == 1 ? printf("Success\n") : printf("Fail!\n");
            queue_show(queue);
            break;
        case DEQUEUE:
            value2 = queue_dequeue(queue);
            printf("DEQUEUE: ");
            value2 ? printf("%c\n", *value2) : printf("Fail!\n");
            queue_show(queue);
            break;
        case PEEK:
            printf("PEEK: ");
            value2 = queue_peek(queue);
            value2 ? printf("%c\n", *value2) : printf("Empty!\n");
            break;
        case FIND:
            printf("FIND (%c): ", *value1);
            rs = queue_find(queue, value1, comparator);
            rs != -1 ? printf("%d\n", rs) : printf("Not Found!\n");
            break;
        default:
            printf("CLEAR\n");
            queue_clear(queue);
            queue_show(queue);
            break;
        }
    }
    
    printf("\n");

    return 0;
}

int comparator(void *const a, void *const b){
    
    return *((char *) a) - *((char *) b);
}

void queue_show(Queue *queue){
    
    printf("\n @ Queue SHOW: ");

    if (!queue_is_empty(queue)){

        for (ItemQueue *item_r = queue->head.next; item_r; item_r = item_r->next)
            printf("%c, ", *((char *) item_r->data));
        printf("[%d]\n-------------", queue->length);

        for (int i = 0; i < queue->length; i++)
            printf("----");
    } else {
        printf("Empty!\n");
        printf("-------------");
    }

    printf("\n\n");
}
