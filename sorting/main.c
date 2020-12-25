#include "stdio.h"
#include "stdlib.h"
#include "string.h"
#include "./headers/bubble_sort.c"

int c(void *const a, void *const b){
    char *str1 = (char *)a, *str2 = (char *)b;
    return strcmp(str1, str2);
}

int main(int argc, char const *argv[]){

    
    char a[5][5] = {"5560", "2579", "3654", "1658", "5454"};

    for (int i = 0; i < 5; i++)
    {
        printf("%s\n", a[i]);
    }
    
    printf("\n\n");
    b_sort(a, 5, sizeof(char) * 5, &c);

    for (int i = 0; i < 5; i++)
    {
        printf("%s\n", a[i]);
    }

    return 0;
}
