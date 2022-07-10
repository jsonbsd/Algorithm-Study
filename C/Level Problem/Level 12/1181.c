/*
 * main.c
 * C Project
 *
 * Created by ljy on 2021/09/10.
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

#define MAX_CHRLEN 64

static int compare_str(const void *p1, const void *p2) {
    char *prev, *next;
    int prevlen, nextlen, i;
    
    prev = *(char **)p1;
    next = *(char **)p2;
    
    prevlen = (int)strlen(prev);
    nextlen = (int)strlen(next);
    
    if (prevlen != nextlen)
        return prevlen - nextlen;
    
    for (i = 0; i < nextlen; ++i)
        if (prev[i] != next[i])
            return prev[i] - next[i];
    
    return 0;
}

static void print_str(char **data, int ndata) {
    char buf[MAX_CHRLEN];
    int i;
    
    memset(buf, 0, sizeof(buf));
    for (i = 0; i < ndata; ++i) {
        if (!strcmp(buf, data[i]))
            continue;
        strcpy(buf, data[i]);
        printf("%s\n", data[i]);
    }
}

int main(int argc, const char *argv[]) {
    char **data;
    int ndata, i;
    
    scanf("%d", &ndata);
    
    data = (char **)malloc(ndata * sizeof(*data));
    for (i = 0; i < ndata; ++i) {
        data[i] = (char *)malloc(MAX_CHRLEN * sizeof(**data));
        scanf("%s", data[i]);
    }
    
    qsort(data, ndata, sizeof(*data), compare_str);
    print_str(data, ndata);
    
    for (i = 0; i < ndata; ++i)
        free(data[i]);
    free(data);
    
    return (EXIT_SUCCESS);
}
