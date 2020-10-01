/**
 * @author: Ytalo Ramon
*/

#include "client.h"

/**
 * Define the prototype of the struct.
 * struct _Queue Queue.
*/
typedef struct _Queue Queue;

/**
 * Define the prototype of the struct.
 * struct _ItemQueue ItemQueue;
*/
typedef struct _ItemQueue ItemQueue;

/**
 * Initialize the queue, set value default.
 * @param queue Queue pointer.
*/
void initialize_queue(Queue *queue);

/**
 * Checks if the queue is empty.
 * @param queue Queue pointer.
 * @return int, or 1 if empty or 0 if not empty.
*/
int is_empty(Queue *queue);

/**
 * Checks if the queue is full.
 * @param queue Queue pointer.
 * @return int, or 1 if full or 0 if not full.
*/
int is_full(Queue *queue);

/**
 * Removes all items from the queue.
 * @param queue Queue pointer.
*/
void clear(Queue *queue);

/**
 * Instance a new item.
 * @param client Client pointer.
 * @return ItemQueue pointer, to new instance.
*/
ItemQueue *new_item(Client *client);

/**
 * Enqueue a new client.
 * @param queue Queue pointer.
 * @param client Client pointer.
 * @return int, or 1 if added or 0 if not added.
*/
int enqueue(Queue *queue, Client *client);

/**
 * Dequeue a client.
 * @param queue Queue pointer.
 * @return Client pointer, to instance dequeued or NULL if queue is empty.
*/
Client *dequeue(Queue *queue);

/**
 * Return the item on the front of the queue.
 * @param queue Queue pointer.
 * @return Client pointer, front item.
*/
Client *peek(Queue *queue);

/**
 * Print all elements in queue.
 * @param queue Queue pointer.
*/
void show(Queue *queue);