/**
 * @author Ytalo Ramon
 * @date   13/02/2021
*/

#include "stdio.h"
#include "stdlib.h"
#include "string.h"
#include "../include/queue_dynamic.h"

/* Input size for test. */
#define INPUTSIZE 23

/**
 * struct __ItemQueue ItemQueue.
 * Queue information.
 * attr: struct _client *clients - data.
 * attr: struct _ItemQueue *next - pointer next item.
*/
struct _ItemQueue{
    struct _client *client;
    struct _ItemQueue *next;
};

/**
 * struct _Queue Queue.
 * Queue information.
 * attr: struct _ItemQueue head - save global to first item instance.
 * attr: struct _ItemQueue *back - pointer to the last item instance.
*/
struct _Queue{
    struct _ItemQueue head, *back;
};


/**
 * struct __Item Item.
 * attr: void *data - payload of data 
*/
struct _Item{
    void *data;
    
};

/**
 * struct _Queue Queue.
 * attr: int p_front - position of the current first element in the queue.
 * attr: int p_back - position of the current last element in the queue.
 * attr: int length - length queue.
 * attr: struct _Item - array of queue elements.
*/
struct _Queue{
    size_t p_front, p_back, length;
    struct _Item *items;
};
