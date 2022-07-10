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

#define IS_ODD(num) (num % 2)

/*
 * Max distance with min operations is fixed by the number of operations.
 *  Odd n_op -> 1, 121, 12321, ...
 *  Even n_op -> 11, 1221, 123321, ...
 */
static unsigned int max_dist(unsigned n_op) {
    unsigned int tmp;
    
    tmp = (n_op + 1) / 2;
    
    if (IS_ODD(n_op))
        return tmp * tmp;
    else
        return tmp * (tmp + 1);
}

static unsigned int n_operation(unsigned from, unsigned to) {
    unsigned int n_op, dist;
    
    n_op = 1;
    dist = to - from;
    while (dist > max_dist(n_op))
        ++n_op;
    
    return n_op;
}

int main(int argc, const char *argv[]) {
    unsigned int from, to;
    int n_test;
    
    scanf("%d", &n_test);
    
    for (; n_test; --n_test) {
        scanf("%u %u", &from, &to);
        printf("%u\n", n_operation(from, to));
    }
    
    return 0;
}
