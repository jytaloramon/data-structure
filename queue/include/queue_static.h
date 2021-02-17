/**
 * @author Ytalo Ramon
 * @date   13/02/2021
*/

#include "queue.h"

/**
 * Calculate modular arithmetic.
 * @param value int
 * @param div_value int
 * @return int
*/
#define MOD(value, div_value) (value % div_value)

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

/**
 * Instance a new queue.
 * @param length Length of queue.
 * @return Or a instance of a queue or NULL on error.
*/
Queue *new_queue(size_t length);

/**
 * Checks if the queue is full.
 * @param queue Queue pointer.
 * @return Or 1 if full or 0 if not full.
*/
int is_full(Queue *queue);
