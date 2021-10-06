/**
 * @author Ytalo Ramon
 * @date 06/07/2021
 *
 */

#include "stdio.h"
#include "stdlib.h"
#include "string.h"

#define LENTABLE 256
#define INPUTSIZE 5 // Input size for test.

int search_pattern(char *text, int len_text, char *pattern, int len_patt,
                   int *alf_table);

int main(int argc, char const *argv[]) {

    char test_cases[INPUTSIZE][2][LENTABLE] = {
        {"WELCOMETOSURANACOLLEGE", "COLLEGE"},
        {"WELCOMETOSURANACOLLEGE", "SURANA"},
        {"WELCOMETOSURANACOLLEGE", "METO"},
        {"ABCABDAB", "ABDAB"},
        {"ABCABDAB", "ABDB"},
    };

    printf("+++++ BOYER MOORE (Algorithm for Pattern Searching) +++++\n\n");

    char *text = NULL, *text_pattern = NULL;
    int alf_table[LENTABLE], len_text = 0, len_patte = 0, rs = 0;

    // Tests
    for (int i = 0; i < INPUTSIZE; ++i) {
        text = test_cases[i][0];
        text_pattern = test_cases[i][1];

        len_text = strlen(text), len_patte = strlen(text_pattern);
        memset(alf_table, -1, sizeof(int) * LENTABLE);

        for (int i = 0; i < len_patte - 1; ++i)
            alf_table[text_pattern[i]] = len_patte - i - 1;
        alf_table[text_pattern[len_patte - 1]] = 1;

        rs = search_pattern(text, len_text, text_pattern, len_patte, alf_table);

        printf(" * Text: %s; Pattern: %s => ", text, text_pattern);
        (rs != -1 ? printf("[%d - %d[\n\n", rs, rs + len_patte)
                  : printf("Not Found!\n\n"));
    }

    return 0;
}

int search_pattern(char *text, int len_text, char *pattern, int len_patt,
                   int *alf_table) {

    for (int i = 0, j = 0, p = 0; i < len_text - len_patt + 1; i += p) {
        for (j = len_patt - 1; j >= 0 && pattern[j] == text[i + j]; --j);

        if (j < 0)
            return i;

        if (alf_table[text[i + j]] == -1) {
            p = j + 1;
        } else {
            p = (alf_table[pattern[j]] == -1 ? alf_table[text[i + j]]
                                             : alf_table[pattern[j]]);
        }
    }

    return -1;
}