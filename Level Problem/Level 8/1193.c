/*
 * main.c
 * C Project
 *
 * Created by ljy on 2021/02/11.
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

#define IS_ASCENT(shape) (shape % 2 == 0 ? true : false)

struct frac_t {
    int d, n;          /* Denominator, Numerator */
};

/* Shape is the sum of the denominator and numberator. */
static int get_shape(int pos) {
    int shape;
    
    for (shape = 2; pos > shape * (shape - 1) / 2; ++shape)
        ;
    
    return shape;
}

/* Rank is the position of the shape. */
static int get_rank(int pos, int shape) {
    return pos - (shape - 1) * (shape - 2) / 2 - 1;
}

static struct frac_t get_frac(int pos) {
    struct frac_t frac;
    int shape, rank;
    
    shape = get_shape(pos);
    rank = get_rank(pos, shape);
    
    if (IS_ASCENT(shape)) {
        frac.d = rank + 1;
        frac.n = shape - rank - 1;
    } else {
        frac.d = shape - rank - 1;
        frac.n = rank + 1;
    }
    
    return frac;
}

int main(int argc, const char *argv[]) {
    struct frac_t frac;
    int x;
    
    scanf("%d", &x);
    
    frac = get_frac(x);
    printf("%d/%d\n", frac.n, frac.d);
    
    return 0;
}
