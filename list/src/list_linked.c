/**
 * @author Ytalo Ramon
 * @date   16/02/2021
*/

#include "stdio.h"
#include "string.h"
#include "../include/list_linked.h"

List *new_list(){
    List *list = malloc(sizeof(List));

    if (!list)
        return NULL;

    list->rear       = &list->front;
    list->front.next = NULL;
    list->length     = 0;

    return list;
}

ItemList *new_item_list(void *data){
    ItemList *item = malloc(sizeof(ItemList));

    if (!item)
        return NULL;

    item->data = data;

    return item;
}

int is_empty(List *list){
    return list->front.next == NULL;
}

int append(List *list, void *elmnt){
    ItemList *item = new_item_list(elmnt);

    if(!item)
        return 0;

    list->rear->next = item;
    list->rear       = list->rear->next;
    list->length++;

    return 1;
}

int insert_at(List *list, int posi, void *elmnt){
    if (posi < 0 || posi > list->length)
        return 0;

    int idx = -1;
    ItemList *item_run = &list->front, *item = new_item_list(elmnt);
    while (idx++ != posi - 1)
        item_run = item_run->next;

    item->next = item_run->next;
    item_run->next = item;
    list->length++;

    return 1;
}

void *remove_first(List *list){
    if (is_empty(list))
        return NULL;

    ItemList *item = list->front.next;
    void *data = item->data;

    list->front.next = item->next;
    list->length--;
    free(item);

    if (is_empty(list))
        list->rear = &list->front;

    return data;
}

void *remove_at(List *list, int posi){
    if (posi < 0 || posi >= list->length)
        return NULL;

    int idx = -1;
    ItemList *item_run = &list->front;
    while (idx++ != posi - 1)
        item_run = item_run->next;
    
    ItemList *item = item_run->next;
    void *data = item->data;
    item_run->next = item->next;
    list->length--;
    free(item);
    
    if (is_empty(list))
        list->rear = &list->front;

    return data;
}

void clear(List *list){
    ItemList *item_run = NULL;
    while (!is_empty(list)){
        item_run = list->front.next;
        list->front.next = item_run->next;
        free(item_run->data);
        free(item_run);
    }
    list->rear = &list->front;
}

int index_of(List *list, void *value, COMPARATOR){
    size_t i = 0;
    ItemList *item_run = list->front.next;
    while (item_run && comparator(value, item_run->data)){ 
        item_run = item_run->next;
        i++;
    }
    return i != list->length ? i : -1;
}

void *find(List *list, void *value, COMPARATOR){
    ItemList *item_run = list->front.next;
    while (item_run){
        if (!comparator(value, item_run->data)) 
            return item_run->data;
        item_run = item_run->next;
    }

    return NULL;
}

size_t count(List *list, void *value, COMPARATOR){
    ItemList *item_run = list->front.next;
    size_t count = 0;

    while (item_run){
        if (!comparator(value, item_run->data)) 
            count++;
        item_run = item_run->next;
    }

    return count;
}

char *list_to_string(List *list, TOSTRING){
    char *content = malloc(sizeof(char) * BUFFER);

    if (!content)
        return NULL;

    int count_str = 13, max_seq = count_str;
    strcpy(content, "\n\nList SHOW:\n");

    if (is_empty(list)){
        strcpy(&content[count_str], "Empty!\n\0");
        return content;
    }

    int idx = 0, length_str = 0, length_row = 0;
    ItemList *item_run = list->front.next;
    while (item_run){
        char idx_str[16],
            *payload = to_string(item_run->data);

        sprintf(idx_str, "| %d - ", idx);

        strcpy(&content[count_str], idx_str);
        length_row = length_str = strlen(idx_str);
        strcpy(&content[count_str + length_str], payload);
        length_row += length_str = strlen(payload);

        if (length_row > max_seq)
            max_seq = length_row;
        count_str += length_row + 1;
        content[count_str - 1] = '\n';
        
        free(payload);

        item_run = item_run->next;
        idx++;
    }
    
    for (size_t i = 0; i < max_seq; i++) content[count_str++] = '-';
    content[count_str] = '\0';

    return content;
}