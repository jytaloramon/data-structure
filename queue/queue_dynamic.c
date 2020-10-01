/**
 * @author: Ytalo Ramon
*/

#include "stdio.h"
#include "stdlib.h"
#include "string.h"
#include "./headers/queue.h"

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
    queue->head.next = NULL;
    queue->back = &queue->head;
}

int is_empty(Queue *queue){
    return !queue->head.next;
}

void clear(Queue *queue){
    if(is_empty(queue)){
        ItemQueue *item_actual = queue->head.next, *item_next;
        while (item_actual){
            item_next = item_actual->next;
            free(item_actual->client);
            free(item_actual);
            item_actual = item_next;
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

ItemQueue *new_item(Client *client){
    ItemQueue *item_queue = malloc(sizeof(ItemQueue));
    if(!item_queue) return NULL;

    item_queue->client = client;
    item_queue->next = NULL;
    return item_queue;
}

int enqueue(Queue *queue, Client *client){
    ItemQueue *item_new = new_item(client);
    if(!item_new) return 0;

    queue->back->next = item_new;
    queue->back = queue->back->next;
    return 1;
}

Client *dequeue(Queue *queue){
    if(is_empty(queue)) return NULL;

    ItemQueue *item_front = queue->head.next;
    Client *client = item_front->client;
    queue->head.next = item_front->next;
    free(item_front);

    if (is_empty(queue)) queue->back = &queue->head;
    
    return client; 
}

Client *peek(Queue *queue){
    if (is_empty(queue)) return NULL;
    
    return queue->head.next->client;
}

void show(Queue *queue){
    printf("\n\nQUEUE SHOW:\n");

    if(is_empty(queue)) printf("Empty!\n");
    else {
        ItemQueue *item_actual = queue->head.next;
        int idx = 0;
        while (item_actual){
            printf("| %d - (%s, %d)\n", idx++, item_actual->client->name, item_actual->client->age);
            item_actual = item_actual->next;
        }
    }

    for(int i = 0; i < NAMESIZE + 4; i++) printf("-");
    printf("\n\n");
}