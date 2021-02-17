/**
 * @author Ytalo Ramon
 * @date   12/02/2021
*/

#include "stdlib.h"

/**
 * Comparison function signature
 * @param value1
 * @param value2
 * @return Result of the comparison of the two values
*/
#define COMPARATOR int(comparator)(void *const, void *const)

#define DATATOSTRING char* (data_to_string)(void *const)

#define BUFFER 1024

/**
 * Define the prototype of the struct.
 * struct _Queue Queue.
*/
typedef struct _Queue Queue;

/**
 * Define the prototype of the struct.
 * struct _item Item.
*/
typedef struct _Item Item;

/**
 * Checks if the queue is empty.
 * @param queue Queue pointer.
 * @return Or 1 if empty or 0 if not empty.
*/
int is_empty(Queue *queue);

/**
 * Removes all items from the queue.
 * @param queue Queue pointer.
*/
void clear(Queue *queue);

/**
 * Instance a new item.
 * @param data Void pointer.
 * @return The instance of a new Item
*/
Item *new_item(void *data);

/**
 * Enqueue a new item.
 * @param queue Queue pointer.
 * @param data void pointer.
 * @return Or 1 if added or 0 if not added.
*/
int enqueue(Queue *queue, void *data);

/**
 * Dequeue a item.
 * @param queue Queue pointer.
 * @return The instance dequeued or NULL if queue is empty.
*/
void *dequeue(Queue *queue);

/**
 * Return the item on the front of the queue.
 * @param queue Queue pointer.
 * @return The intance of the front item.
*/
void *peek(Queue *queue);

/**
 * Find for a queue value
 * @param queue Queue pointer.
 * @param value Searched value.
 * @param Comparator Function comparator.
 * @return Item offset from top.
*/
size_t find(Queue *queue, void *value, COMPARATOR);

/**
 * Print all elements in queue.
 * @param queue Queue pointer.
*/
char *queue_to_string(Queue *queue, DATATOSTRING);