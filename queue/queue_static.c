/**
 * @author: Ytalo Ramon
*/

#include "stdio.h"
#include "stdlib.h"
#include "string.h"
#include "./headers/queue.h"

/* Queue size. Real size is (QUEUESUZE - 1). */
#define QUEUESIZE 6
/* Input size for test. */
#define INPUTSIZE 23

/**
 * Macro for calculate next position in modular arithmetic.
 * @param value int
 * @return int
*/
#define CALNEXTPOSITION(value) ((value + 1) % QUEUESIZE)

/**
 * struct __ItemQueue ItemQueue.
 * Queue information.
 * attr: struct _client *clients - data.
*/
struct _ItemQueue{
    struct _client *client;
};

/**
 * struct _Queue Queue.
 * Queue information.
 * attr: int p_front - position of the current first element in the queue.
 * attr: int p_back - position of the current last element in the queue.
 * attr: struct _ItemQueue items - array with queue elements.
*/
struct _Queue{
    int p_front, p_back;
    struct _ItemQueue items[QUEUESIZE];
};

/**
 * function main 
*/
int main(int argc, char const *argv[]){

    Queue queue;
    initialize_queue(&queue);

    Client *client_aux;
    int rs;

    char inputs[INPUTSIZE][3][NAMESIZE] = {
        {"0", "", ""},
        {"1", "Ramon", "21"},
        {"1", "Jack", "35"},
        {"0", "", ""},
        {"1", "Maria", "51"},
        {"0", "", ""},
        {"2", "", ""},
        {"0", "", ""},
        {"0", "", ""},
        {"1", "Fanny", "47"},
        {"1", "Calos", "75"},
        {"0", "", ""},
        {"2", "", ""},
        {"1", "Vick", "56"},
        {"1", "Rock", "17"},
        {"1", "Hellen", "11"},
        {"1", "Chris", "27"},
        {"2", "", ""},
        {"1", "SuperCam", "66"},
        {"0", "", ""},
        {"1", "Derik", "22"},
        {"2", "", ""},
        {"0", "", ""}};

    for (int i = 0; i < INPUTSIZE; i++){
        switch (inputs[i][0][0]){
        case '0': // DEQUEUE
            printf("DEQUEUE:\n");
            client_aux = dequeue(&queue);
            client_aux ? printf("-> (%s, %d) <-\n", client_aux->name, client_aux->age) : printf("-> Queue Empty! <-\n");
            free(client_aux);
            break;
        case '1': // ENQUEUE
            client_aux = new_client(inputs[i][1], atoi(inputs[i][2]));
            printf("ENQUEUE:\n(%s, %d)\n", client_aux->name, client_aux->age);
            rs = enqueue(&queue, client_aux);
            rs ? printf("-> OK <-\n") : printf("-> Error, Full Queue! <-\n");
            break;
        default: // PEEK
            printf("PEEK:\n");
            client_aux = peek(&queue);
            client_aux ? printf("-> (%s, %d) <-\n", client_aux->name, client_aux->age) : printf("-> Stack Empty! <-\n");
            break;
        }
    
        show(&queue);
    }

    printf("-> CLEAR QUEUE <-\n");
    clear(&queue);
    show(&queue);

    return 0;
}

void initialize_queue(Queue *queue){
    queue->p_front = queue->p_back = 0;
}

int is_empty(Queue *queue){
    return queue->p_front == queue->p_back;
}

int is_full(Queue *queue){
    return queue->p_front == CALNEXTPOSITION(queue->p_back);
}

void clear(Queue *queue){
    if(!is_empty(queue)){
        while (queue->p_front != queue->p_back){
            free(queue->items[queue->p_front].client);
            queue->items[queue->p_front].client = NULL;
            queue->p_front = CALNEXTPOSITION(queue->p_front);
        }
    }

    initialize_queue(queue);
}

Client *new_client(char *name, int age){
    Client *client = malloc(sizeof(Client));
    if(!client) return NULL;

    strncpy(client->name, name, NAMESIZE);
    client->age = age;
    return client;
}

int enqueue(Queue *queue, Client *client){
    if (is_full(queue)) return 0;

    queue->items[queue->p_back].client = client;
    queue->p_back = CALNEXTPOSITION(queue->p_back);
    return 1;
}

Client *dequeue(Queue *queue){
    if(is_empty(queue)) return NULL;

    Client *client = queue->items[queue->p_front].client;
    queue->items[queue->p_front].client = NULL;
    queue->p_front = CALNEXTPOSITION(queue->p_front);
    return client;
}

Client *peek(Queue *queue){
    if (is_empty(queue)) return NULL;

    return queue->items[queue->p_front].client;
}

void show(Queue *queue){
    printf("\n\nQUEUE SHOW:\n");
    
    if(is_empty(queue)) printf("Empty!\n");
    else {
        for (int i = queue->p_front, idx = 0; i != queue->p_back; i = CALNEXTPOSITION(i), idx++)
            printf("| %d - (%s, %d)\n", idx, queue->items[i].client->name, queue->items[i].client->age);
    }

    for(int i = 0; i < NAMESIZE + 4; i++) printf("-");
    printf("\n\n");
}
