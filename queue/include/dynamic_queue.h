/**
 * @author Ytalo Ramon
 * @date   13/02/2021
*/

#include "queue.h"

/**
 * struct __ItemQueue ItemQueue.
 * Queue information.
 * attr: void *data - payload of data
 * attr: struct _ItemQueue *next - pointer next item.
*/
struct _ItemQueue {
    void *data;
    struct _ItemQueue *next;
};

/**
 * struct _Queue Queue.
 * Queue information.
 * attr: struct _ItemQueue head - save global to first item instance.
 * attr: struct _ItemQueue *back - pointer to the last item instance.
 * attr: int length - length queue.
*/
struct _Queue {
    struct _ItemQueue head, *back;
    int length;
};


/**
 * Instance a new queue.
 * @return Or a instance of a queue or NULL on error.
*/
Queue *queue_new();

/**
 * Instance a new item.
 * @param data Void pointer.
 * @return The instance of a new Item
*/
ItemQueue *queue_new_item(void *data);