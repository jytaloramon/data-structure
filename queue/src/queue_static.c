/**
 * @author Ytalo Ramon
 * @date   13/02/2021    
*/

#include "stdio.h"
#include "stdlib.h"
#include "string.h"
#include "../include/queue_static.h"

Queue *new_queue(size_t length){
    Queue *queue = malloc(sizeof(Queue));
    if (!queue)
        return NULL;

    queue->p_front = queue->p_back = 0;
    queue->length = length + 1;
    queue->items = malloc(sizeof(Item) * (queue->length));

    if (!queue->items){
        free(queue);
        return NULL;
    }

    return queue;
}

int is_empty(Queue *queue){
    return queue->p_front == queue->p_back;
}

int is_full(Queue *queue){
    return MOD(queue->p_back + 1, queue->length) == queue->p_front;
}

void clear(Queue *queue){
    while (!is_empty(queue)){
        free(queue->items[queue->p_front].data);
        queue->items[queue->p_front].data = NULL;
        queue->p_front = MOD(queue->p_front + 1, queue->length);
    }
}

Item *new_item(void *data){
    Item *item = malloc(sizeof(Item));
    item->data = data;

    return item;
}

int enqueue(Queue *queue, void *data){
    if (is_full(queue))
        return 0;

    queue->items[queue->p_back].data = data;
    queue->p_back = MOD(queue->p_back + 1, queue->length);
    printf("- %d\n", queue->p_back);
    return 1;
}

void *dequeue(Queue *queue){
    if (is_empty(queue))
        return NULL;

    void *data = queue->items[queue->p_front].data;
    queue->items[queue->p_front].data = NULL;
    queue->p_front = MOD(queue->p_front + 1, queue->length);

    return data;
}

void *peek(Queue *queue){
    if (is_empty(queue))
        return NULL;

    return queue->items[queue->p_front].data;
}

size_t find(Queue *queue, void *value, COMPARATOR){
    size_t i = queue->p_front;

    while (i != queue->p_back && comparator(value, queue->items[i].data))
        i = MOD(i + 1, queue->length);

    return i == queue->p_back ? 0 : 
        (i >= queue->p_front ? i - queue->p_front:queue->length - queue->p_front + i); 
}


char *queue_to_string(Queue *queue, DATATOSTRING){
    char *content = malloc(sizeof(char) * BUFFER);

    if (!content)
        return NULL;

    int count_str = 14, max_seq = count_str;
    strcpy(content, "\n\nQUEUE SHOW:\n");

    if (is_empty(queue)){
        strcpy(&content[count_str], "Empty!\n\0");
        return content;
    }

    for (size_t i = queue->p_front,  idx = 0, length_str = 0, length_row = 0;
            i != queue->p_back; i = MOD(i + 1, queue->length), idx++){

        char *payload = data_to_string(queue->items[i].data), idx_str[16];
        sprintf(idx_str, "| %d - ", idx);

        strcpy(&content[count_str], idx_str);
        length_row = length_str = strlen(idx_str);
        strcpy(&content[count_str + length_str], payload);
        length_row += length_str = strlen(payload);

        if (length_row > max_seq)
            max_seq = length_row;
        count_str += length_row + 1;
        content[count_str - 1] = '\n';
        
        free(payload);
    }
    
    for (size_t i = 0; i < max_seq; i++) content[count_str++] = '-';
    content[count_str] = '\0';

    return content;
}