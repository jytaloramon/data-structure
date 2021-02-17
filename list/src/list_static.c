/**
 * @author Ytalo Ramon
 * @date   14/02/2021
*/

#include "stdio.h"
#include "string.h"
#include "../include/list_static.h"

List *new_list(int size){
    List *list = malloc(sizeof(List) * (size + 1));

    if (!list)
        return NULL;

    list->p_front = list->p_rear = list->length = 0;
    list->size    = size;
    list->items   = malloc(sizeof(ItemList) * list->size);

    if (!list->items){
        free(list);
        return NULL;
    }

    return list;
}

int is_empty(List *list){
    return list->p_front == list->p_rear;
}

int is_full(List *list){
    return mod(list->p_rear + 1, list->size + 1) == list->p_front;
}

int append(List *list, void *elmnt){
    if (is_full(list))
        return 0;

    list->items[list->p_rear].data = elmnt;
    list->p_rear = mod(list->p_rear + 1, list->size + 1);
    list->length++;

    return 1;
}

int insert_at(List *list, int posi, void *elmnt){
    if (is_full(list) || posi < 0 || posi > list->length)
        return 0;

    size_t end_loop = mod(list->p_front + posi, list->size + 1);
    for (size_t idx = list->p_rear; idx != end_loop; idx = mod(idx - 1, list->size + 1))
        list->items[idx].data = list->items[idx - 1].data;
    list->items[end_loop].data = elmnt;
    list->p_rear = mod(list->p_rear + 1, list->size + 1);
    list->length++;

    return 1;    
}

void *remove_first(List *list){
    if (is_empty(list))
        return NULL;

    void *data = list->items[list->p_front].data;
    list->items[list->p_front].data = NULL;
    list->p_front = mod(list->p_front + 1, list->size + 1);
    list->length--;

    return data;
}

void *remove_at(List *list, int posi){
    if (is_empty(list) || posi < 0 && posi != -1 || posi > (int) list->length)
        return NULL;

    if (posi == -1)
        posi = list->length - 1;
    
    void *data = list->items[posi].data;
    size_t end_loop = mod(list->p_rear - 1, list->size + 1);
    for (size_t idx = mod(list->p_front + posi, list->size + 1); idx != end_loop; 
            idx = mod(idx + 1, list->size + 1))
        list->items[idx].data = list->items[mod(idx + 1, list->size + 1)].data;
    
    list->p_rear = mod(list->p_rear - 1, list->size + 1);
    list->items[list->p_rear].data = NULL;
    list->length--;

    return data;    
}

void clear(List *list){
    while (!is_empty(list)){
        free(list->items[list->p_front].data);
        list->items[list->p_front].data = NULL;
        list->p_front = mod(list->p_front + 1, list->size + 1);
    }
}

int index_of(List *list, void *value, COMPARATOR){
    size_t i = list->p_front;

    while (i != list->p_rear && comparator(value, list->items[i].data))
        i = mod(i + 1, list->size + 1);

    if (i == list->p_rear)
        return -1;

    return (i >= list->p_front ? i - list->p_front : list->size - list->p_front + i);
}

void *find(List *list, void *value, COMPARATOR){
    size_t posi = index_of(list, value, comparator);
    return posi != -1 ? list->items[mod(list->p_front + posi, list->size + 1)].data : NULL;
}

size_t count(List *list, void *value, COMPARATOR){
    size_t count = 0;

    for (size_t i = list->p_front; i != list->p_rear; i = mod(i + 1, list->size + 1))
        if (!comparator(value, list->items[i].data))
            count++;

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

    for (size_t i = list->p_front,  idx = 0, length_str = 0, length_row = 0;
            i != list->p_rear; i = mod(i + 1, list->size + 1), idx++){
        char  idx_str[16],
                *payload = to_string(list->items[i].data);

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
    }
    
    for (size_t i = 0; i < max_seq; i++) content[count_str++] = '-';
    content[count_str] = '\0';

    return content;
}