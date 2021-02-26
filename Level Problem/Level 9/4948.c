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

#define MAX_INPUT 123456
#define MEM_SIZE ((MAX_INPUT * 2) + 1)

static void init_prime_mem(bool *mem, size_t len) {
    size_t i, j;
    
    memset(mem, true, len);
    mem[0] = mem[1] = false;
    
    for (i = 2; i <= len / 2; ++i)
        for (j = i * 2; j < len; j += i)
            mem[j] = false;
}

static int is_prime(int num) {
    static bool prime_mem[MEM_SIZE];
    static bool initialized = false;
    
    if (!initialized) {
        init_prime_mem(prime_mem, MEM_SIZE);
        initialized = true;
    }
    
    return prime_mem[num] ? 1 : 0;
}

static int count_prime(int from, int to) {
    int count;
    
    count = 0;
    while (from <= to) {
        count += is_prime(from);
        ++from;
    }
    
    return count;
}

int main(int argc, const char *argv[]) {
    int num;
    
    while (scanf("%d", &num) && num != 0)
        printf("%d\n", count_prime(num + 1, num * 2));
    
    return 0;
}
