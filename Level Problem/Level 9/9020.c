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

static void init_prime_mem(bool *mem, size_t len) {
    size_t i, j;
    
    memset(mem, true, len);
    mem[0] = mem[1] = false;
    
    for (i = 2; i <= len / 2; ++i) {
        if (!mem[i])
            continue;
        for (j = i * 2; j < len; j += i)
            mem[j] = false;
    }
}

static bool is_prime(int num) {
    static bool prime_mem[MEM_SIZE];
    static bool initialized = false;
    
    if (!initialized) {
        init_prime_mem(prime_mem, MEM_SIZE);
        initialized = true;
    }
    
    return prime_mem[num];
}

static int rt_gbp_lower_num(int num) {
    int ret;
    
    ret = num / 2;
    while (ret) {
        if (is_prime(ret) && is_prime(num - ret))
            break;
        --ret;
    }
    
    return ret;
}

static void gbp_print(int num) {
    int gbp_low;
    
    gbp_low = rt_gbp_lower_num(num);
    printf("%d %d\n", gbp_low, num - gbp_low);
}

int main(int argc, const char *argv[]) {
    int n_test, num;
    
    scanf("%d", &n_test);
    
    for (; n_test; --n_test) {
        scanf("%d", &num);
        gbp_print(num);
    }
    
    return 0;
}
