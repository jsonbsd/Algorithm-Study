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

#define MIN_CYLINDER 1

enum { COL1 = '1', COL2 = '2', COL3 = '3' };

static unsigned int
hanoi(unsigned n_cylinder, char from, char tmp, char to, bool verbose) {
    unsigned int mvcount;
    
    mvcount = 0;
    if (n_cylinder == MIN_CYLINDER) {
        ++mvcount;
        if (verbose)
            printf("%c %c\n", from, to);
        return mvcount;
    }
    
    mvcount += hanoi(n_cylinder - 1, from, to, tmp, verbose);
    mvcount += hanoi(1, from, tmp, to, verbose);
    mvcount += hanoi(n_cylinder - 1, tmp, from, to, verbose);
    
    return mvcount;
}

int main(int argc, const char *argv[]) {
    uint8_t n_cylinder;
    
    scanf("%hhu", &n_cylinder);
    
    printf("%u\n", hanoi(n_cylinder, COL1, COL2, COL3, false));
    hanoi(n_cylinder, COL1, COL2, COL3, true);
    
    return 0;
}
