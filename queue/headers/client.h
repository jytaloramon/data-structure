/**
 * @author: Ytalo Ramon
*/

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