/**
 * @author Ytalo Ramon
 * @date   12/02/2021
*/

#include "stdlib.h"
#include "../../includes/icomparator.h"

/**
 * Define the prototype of the struct.
 * struct _Queue Queue.
*/
typedef struct _Queue Queue;

/**
 * Define the prototype of the struct.
 * struct _item Item.
*/
typedef struct _ItemQueue ItemQueue;

/**
 * Checks if the queue is empty.
 * @param queue Queue pointer.
 * @return Or 1 if empty or 0 if not empty.
*/
int queue_is_empty(Queue *queue);

/**
 * Removes all items from the queue.
 * @param queue Queue pointer.
*/
void queue_clear(Queue *queue);

/**
 * Enqueue a new item.
 * @param queue Queue pointer.
 * @param data void pointer.
 * @return Or 1 if added or 0 if not added.
*/
int queue_enqueue(Queue *queue, void *data);

/**
 * Dequeue a item.
 * @param queue Queue pointer.
 * @return The instance dequeued or NULL if queue is empty.
*/
void *queue_dequeue(Queue *queue);

/**
 * Return the item on the front of the queue.
 * @param queue Queue pointer.
 * @return The intance of the front item.
*/
void *queue_peek(Queue *queue);

/**
 * Find for a queue value
 * @param queue Queue pointer.
 * @param value Searched value.
 * @param Comparator Function comparator.
 * @return Item offset from top, or -1 if not found.
*/
int queue_find(Queue *queue, void *value, ICOMPARATOR);
