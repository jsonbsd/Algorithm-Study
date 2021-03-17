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

#define ENDIGIT 6
#define ENDIGIT_COUNT 3
#define MIN_ENDNUM 666

#define DIGIT(n) (n % 10)

static int isend(unsigned int num) {
    int ncont;
    
    ncont = 0;
    while (num) {
        if (DIGIT(num) == ENDIGIT && ++ncont >= ENDIGIT_COUNT)
            return 1;
        else if (DIGIT(num) != ENDIGIT)
            ncont = 0;
        num /= 10;
    }
    
    return 0;
}

static unsigned int endnum(unsigned int rank) {
    unsigned int i, ret;
    
    i = 0;
    ret = MIN_ENDNUM;
    while ((i += isend(ret)) < rank)
        ++ret;
    
    return ret;
}

int main(int argc, const char *argv[]) {
    int rank;
    
    scanf("%d", &rank);
    printf("%u\n", endnum(rank));
    
    return 0;
}
