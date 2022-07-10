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

#define MAX_STRLEN      101
#define NON_CRO_ALPHA   1

#define ARRLEN(arr) (sizeof(arr) / sizeof(typeof(*arr)))

static size_t match_cro_alpha(char *str) {
    const char *cro_alpha[] = {"c=", "c-", "dz=", "d-", "lj", "nj", "s=", "z="};
    size_t i, n_cro_alpha, len;
    
    i = 0;
    n_cro_alpha = ARRLEN(cro_alpha);
    while (i < n_cro_alpha) {
        len = strlen(cro_alpha[i]);
        if (!strncmp(cro_alpha[i], str, len))
            return len;
        ++i;
    }
    
    return NON_CRO_ALPHA;
}

static size_t count_cro_alpha(char str[]) {
    size_t i, count, len;
    
    len = strlen(str);
    i = count = 0;
    while (i < len) {
        i += match_cro_alpha(str + i);
        ++count;
    }
    
    return count;
}

int main(int argc, const char *argv[]) {
    char str[MAX_STRLEN];
    
    scanf("%s", str);
    printf("%lu\n", count_cro_alpha(str));
    
    return 0;
}
