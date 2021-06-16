/**
 * @author Ytalo Ramon
 * @date   13/02/2021
*/

#include "queue.h"
#include "../../math/include/arithmetic.h"

/**
 * struct __Item Item.
 * attr: void *data - payload of data 
*/
struct _ItemQueue {
    void *data;
};

/**
 * struct _Queue Queue.
 * attr: int p_front - position of the current first element in the queue.
 * attr: int p_back - position of the current last element in the queue.
 * attr: length - number of elements currently present in the queue.
 * attr: int size - size queue.
 * attr: struct _Item - array of queue elements.
*/
struct _Queue {
    int p_front, p_back, length, size;
    struct _ItemQueue *items;
};

/**
 * Instance a new queue.
 * @param size size of queue.
 * @return Or a instance of a queue or NULL on error.
*/
Queue *queue_new(int size);

/**
 * Checks if the queue is full.
 * @param queue Queue pointer.
 * @return Or 1 if full or 0 if not full.
*/
int queue_is_full(Queue *queue);
