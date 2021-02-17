#include "stdio.h"
#include "stdlib.h"
#include "string.h"
#include "../include/queue_static.h"

/* Maximum name size.  Real capacity is SIZENAME - 1. */
#define NAMESIZE 21

/**
 * struct _cliente Client.
 * group client information.
 * attr: char array - name.
 * attr: int value - age.
*/
typedef struct _client{
    char name[NAMESIZE];
    int age;
} Client;


/**
 * Instance a new client.
 * @param name char pointer to variable name.
 * @param age int value age.
 * @return Client, pointer to new instance.
*/
Client *new_client(char *name, int age);

char *to_string(void *const data);

/**
 * function main 
*/
int main(int argc, char const *argv[]){

    Queue *queue = new_queue(6);
    
    enqueue(queue, new_client("Ramon", 18));
    printf("%s\n", queue_to_string(queue, to_string));
    enqueue(queue, new_client("Isadora", 28));
    printf("%s\n", queue_to_string(queue, to_string));
    dequeue(queue);
    printf("%s\n", queue_to_string(queue, to_string));
    dequeue(queue);
    printf("%s\n", queue_to_string(queue, to_string));
    enqueue(queue, new_client("Ramon", 18));
    printf("%s\n", queue_to_string(queue, to_string));
    enqueue(queue, new_client("Ramon", 18));
    printf("%s\n", queue_to_string(queue, to_string));
    enqueue(queue, new_client("Ramon", 18));
    printf("%s\n", queue_to_string(queue, to_string));
    enqueue(queue, new_client("Ramon", 18));
    printf("%s\n", queue_to_string(queue, to_string));
    enqueue(queue, new_client("Ramon", 18));
    printf("%s\n", queue_to_string(queue, to_string));
    enqueue(queue, new_client("Ramon", 18));
    printf("%s\n", queue_to_string(queue, to_string));
    enqueue(queue, new_client("Ramon", 18));
    printf("%s\n", queue_to_string(queue, to_string));
    enqueue(queue, new_client("Ramon", 18));
    printf("%s\n", queue_to_string(queue, to_string));
    enqueue(queue, new_client("Ramon", 18));
    printf("%s\n", queue_to_string(queue, to_string));

    return 0;
}

Client *new_client(char *name, int age){
    Client *client = malloc(sizeof(Client));
    if(!client) return NULL;

    strncpy(client->name, name, NAMESIZE);
    client->age = age;
    return client;
}


char *to_string(void *const data){
    char *str = malloc(sizeof(char) * BUFFER / 16); // Max 64 character

    if (!str)
        return "";
    
    Client *client = (Client *) data;
    sprintf(str, "(%s, %d)", client->name, client->age);

    return str;
}
