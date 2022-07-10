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

#define MAX_INPUT 1000
#define MEM_SIZE MAX_INPUT + 1

static void init_prime_mem(bool *mem, size_t len) {
    size_t i, j;
    
    memset(mem, true, len);
    mem[1] = false;
    
    for (i = 2; i < len; ++i)
        for (j = i * 2; j < len; j += i)
            mem[j] = false;
}

static int is_prime(unsigned int num) {
    static bool prime[MEM_SIZE];
    static bool initialized = false;
    
    if (!initialized) {
        init_prime_mem(prime, MEM_SIZE);
        initialized = true;
    }
    
    return prime[num];
}

int main(int argc, const char *argv[]) {
    ssize_t n_num;
    unsigned int num, count;
    
    scanf("%zd", &n_num);
    
    count = 0;
    while (n_num--) {
        scanf("%u", &num);
        count += is_prime(num);
    }
    
    printf("%u\n", count);
    
    return 0;
}
