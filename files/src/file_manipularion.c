/**
 * @author Ytalo Ramon
 * @date   16/02/2021
*/

#include "stdio.h"
#include "stdlib.h"
#include "string.h"
#include "../include/file_manipularion.h"
#include "../../includes/macro.h"

int main(int argc, char const *argv[]){
    printf("%s\n", read_file("/home/jytaloramon/Projetos/data-structure/files/src/data.in", "rw"));
    return 0;
}

char [][BUFFER / 4]read_file(char *name, size_t n_line, char *mode){
    FILE *file = fopen(name, mode);

    if (!file)
        return NULL;

    char data_raw[n_line][BUFFER / 4];

    for (size_t i = 0; i < n_line; i++){
        fgets(data_raw[i], BUFFER / 4, file);
    }

    fclose(file);

    return data_raw;
}

int *write_file(char *name, char *mode){

}