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

#define MAX_INPUT   10000
#define MEM_SIZE    MAX_INPUT + 1
#define NO_PRIME    -1

static void prime_memset(bool *mem, size_t len) {
    size_t i, j;
    
    memset(mem, true, len);
    mem[0] = mem[1] = false;
    
    for (i = 2; i < len; ++i)
        for (j = i * 2; j < len; j += i)
            mem[j] = false;
}

static bool is_prime(int num) {
    static bool prime[MEM_SIZE];
    static bool initialized = false;
    
    if (!initialized) {
        prime_memset(prime, MEM_SIZE);
        initialized = true;
    }
    
    return prime[num];
}

static int min_prime(int from, int to) {
    for (; from <= to && !is_prime(from); ++from)
        ;
    
    return from > to ? NO_PRIME : from;
}

int main(int argc, const char *argv[]) {
    int from, to, sum, min;
    
    scanf("%d %d", &from, &to);
    
    if ((min = min_prime(from, to)) == NO_PRIME) {
        printf("%d\n", NO_PRIME);
        return 0;
    }
    
    sum = 0;
    while (from <= to) {
        sum += is_prime(from) ? from : 0;
        ++from;
    }
    printf("%d\n%d\n", sum, min);
    
    return 0;
}

