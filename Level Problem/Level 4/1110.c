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

static inline int right_digit_of_sum(int num) {
    return (num + num / 10) % 10;
}

static inline int right_digit(int num) {
    return num % 10;
}

int main(int argc, const char * argv[]) {
    int init_n, next_n, n_cycle;
    
    scanf("%d", &init_n);

    next_n = init_n;
    n_cycle = 0;
    do {
        next_n = right_digit(next_n) * 10 + right_digit_of_sum(next_n);
        ++n_cycle;
    } while (next_n != init_n);
    
    printf("%d\n", n_cycle);
    
    return 0;
}
