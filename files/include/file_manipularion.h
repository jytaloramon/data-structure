/**
 * @author Ytalo Ramon
 * @date   15/02/2021
*/

typedef struct _FileContent {
    char **content;
} FileContent;

char *read_file(char *name, char *mode);

int *write_file(char *name, char *mode);