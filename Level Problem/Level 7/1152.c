/*
 * main.c
 * C Project
 *
 * Created by ljy on 2021/01/14.
 * Copyright © 2021 ljy. All rights reserved.
 *
*/
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <stdbool.h>
#include <stddef.h>
#include <time.h>
#include <ctype.h>
#include <string.h>
#include <float.h>
#include <errno.h>
#include <math.h>

#define MAX_STRLEN 1000001
#define WHITE_SPACE_CHAR ' '

enum { NON_WORD, WORD };

static size_t rm_newline_char(char str[]) {
    size_t len;
    
    len = strlen(str);
    if (len > 0)
        str[--len] = '\0';
    
    return len;
}

static int num_words(char str[], size_t len) {
    int i, n_word, state;
    
    i = n_word = 0;
    state = NON_WORD;
    while (i < len) {
        if (state == NON_WORD && str[i] != WHITE_SPACE_CHAR) {
            state = WORD;
            ++n_word;
        } else if (state == WORD && str[i] == WHITE_SPACE_CHAR) {
            state = NON_WORD;
        }
        ++i;
    }
    
    return n_word;
}

int main(int argc, const char *argv[]) {
    char str[MAX_STRLEN];
    size_t len;
    
    fgets(str, sizeof(str), stdin);
    len = rm_newline_char(str);
    
    printf("%d\n", num_words(str, len));
    
    return 0;
}
