/**
 * @author Ytalo Ramon
 * @date   13/02/2021    
*/

#include "stdio.h"
#include "stdlib.h"
#include "string.h"
#include "../include/static_queue.h"

Queue *queue_new(int size){

    Queue *queue = malloc(sizeof(Queue));
    
    if (!queue)
        return NULL;

    queue->p_front = queue->p_back = queue->length = 0;
    queue->size = size + 1;
    queue->items = malloc(sizeof(ItemQueue) * queue->size);

    if (!queue->items){
        free(queue);
        return NULL;
    }

    return queue;
}

int queue_is_empty(Queue *queue){

    return queue->p_front == queue->p_back;
}

int queue_is_full(Queue *queue){

    return divmodular(queue->p_back + 1, queue->size) == queue->p_front;
}

void queue_clear(Queue *queue){

    for (int i = queue->p_front; i != queue->p_back; i = divmodular(i + 1, queue->size)){
        free(queue->items[i].data);
        queue->items[i].data = NULL;
    }

    queue->p_front = queue->p_back = 0;
}

int queue_enqueue(Queue *queue, void *data){

    if (queue_is_full(queue))
        return 0;

    queue->items[queue->p_back].data = data;
    queue->p_back = divmodular(queue->p_back + 1, queue->size);
    queue->length++;

    return 1;
}

void *queue_dequeue(Queue *queue){

    if (queue_is_empty(queue))
        return NULL;

    void *data = queue->items[queue->p_front].data;
    queue->items[queue->p_front].data = NULL;
    queue->p_front = divmodular(queue->p_front + 1, queue->size);
    queue->length--;
    
    return data;
}

void *queue_peek(Queue *queue){

    if (queue_is_empty(queue))
        return NULL;

    return queue->items[queue->p_front].data;
}

int queue_find(Queue *queue, void *value, ICOMPARATOR){
    
    if (queue_is_empty(queue))
        return -1;

    int i = queue->p_front;

    while (i != queue->p_back && comparator(value, queue->items[i].data))
        i = divmodular(i + 1, queue->size);

    if (i == queue->p_back)
        return -1;

    return i >= queue->p_front ? i - queue->p_front : queue->size - queue->p_front + i;
}
