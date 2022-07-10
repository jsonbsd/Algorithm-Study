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

#define MAX_MEM_SIZE(to) (to + 1)

static inline bool *create_prime_mem(int to) {
    return (bool *)malloc(sizeof(bool) * MAX_MEM_SIZE(to));
}

static void init_prime_mem(bool *mem, int to) {
    int i, j;
    
    memset(mem, true, MAX_MEM_SIZE(to));
    mem[0] = mem[1] = false;
    
    for (i = 2; i <= to / 2; ++i) {
        if (!mem[i])
            continue;
        for (j = i * 2; j <= to; j += i)
            mem[j] = false;
    }
}

static void print_all_primes(bool *mem, int from, int to) {
    while (from <= to) {
        if (mem[from])
            printf("%d\n", from);
        ++from;
    }
}

static void free_prime_mem(bool *mem) {
    if (!mem)
        free(mem);
}

int main(int argc, const char *argv[]) {
    bool *prime_mem;
    int from, to;
    
    scanf("%d %d", &from, &to);
    
    prime_mem = create_prime_mem(to);
    init_prime_mem(prime_mem, to);
    print_all_primes(prime_mem, from, to);
    free_prime_mem(prime_mem);
    
    return 0;
}
