/*
 * main.c
 * C Project
 *
 * Created by ljy on 2021/02/08.
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

#define INPUT_NUM_MIN   1
#define INPUT_NUM_MAX   10000
#define MEMSIZE_MAX     (INPUT_NUM_MAX + 1)

static void countsort(unsigned int *arr, size_t len) {
    unsigned int num;
    size_t i;
    
    for (i = 0; i < len; ++i) {
        scanf("%u", &num);
        ++arr[num];
    }
}

static void nprintdata(unsigned int num, size_t len) {
    size_t i;
    
    for (i = 0; i < len; ++i)
        printf("%u\n", num);
}

static void printdata(unsigned int *arr, size_t len) {
    size_t i;
    
    for (i = INPUT_NUM_MIN; i < len; ++i) {
        if (arr[i])
            nprintdata((unsigned int)i, arr[i]);
    }
}

int main(int argc, const char *argv[]) {
    unsigned int ndata, counter[MEMSIZE_MAX];
    
    scanf("%u", &ndata);
    
    memset(counter, 0, sizeof(counter));
    countsort(counter, ndata);
    printdata(counter, MEMSIZE_MAX);
    
    return (EXIT_SUCCESS);
}
