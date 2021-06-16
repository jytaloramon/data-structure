/**
 * @author Ytalo Ramon
 * @date   12/06/2021
*/

#include "stdio.h"
#include "stdlib.h"
#include "string.h"
#include "../include/dynamic_queue.h"

Queue *queue_new(){

    Queue *queue = malloc(sizeof(Queue));

    if (!queue)
        return NULL;

    queue->head.next = NULL;
    queue->back = &queue->head;
    queue->length = 0;

    return queue;
}

ItemQueue *queue_new_item(void *data){
    
    ItemQueue *item = malloc(sizeof(ItemQueue));

    if (!item)
        return NULL;

    item->data = data;
    item->next = NULL;

    return item;
}

int queue_is_empty(Queue *queue){

    return queue->head.next == NULL;
}

void queue_clear(Queue *queue){

    for (ItemQueue *item_r = queue->head.next, *item_n = NULL; item_r; item_r = item_n){
        item_n = item_r->next;
        free(item_r->data);
        free(item_r);
    }

    queue->head.next = NULL;
    queue->back = &queue->head;
    queue->length = 0;
}

int queue_enqueue(Queue *queue, void *data){

    ItemQueue *item = queue_new_item(data);

    if (!item)
        return 0;

    queue->back->next = item;
    queue->back = queue->back->next;
    queue->length++;

    return 1;
}

void *queue_dequeue(Queue *queue){

    if (queue_is_empty(queue))
        return NULL;

    ItemQueue *item = queue->head.next;
    void *data = item->data;
    queue->head.next = item->next;
    queue->length--;
    
    free(item);

    if (queue_is_empty(queue))
        queue->back = &queue->head;

    return data;
}

void *queue_peek(Queue *queue){

    if (queue_is_empty(queue))
        return NULL;

    return queue->head.next->data;
}

int queue_find(Queue *queue, void *value, ICOMPARATOR){

    if (queue_is_empty(queue))
        return -1;

    ItemQueue *item_r = queue->head.next;
    int i = 0;

    while (item_r && comparator(value, item_r->data)){
        item_r = item_r->next;
        i++;
    }

    return item_r ? i : -1;
}