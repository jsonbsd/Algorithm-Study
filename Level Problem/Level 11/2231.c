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

#define MAX_DIGIT       9
#define MIN_GENERATOR   1

static size_t digitlen(unsigned int n) {
    size_t len;
    
    len = 0;
    while (n) {
        ++len;
        n /= 10;
    }
    
    return len;
}

static unsigned int digitsum(unsigned int n) {
    unsigned int sum;
    
    sum = n;
    while (n) {
        sum += n % 10;
        n /= 10;
    }
    
    return sum;
}

static inline unsigned int do_min_generator(unsigned int n) {
    return n - MAX_DIGIT * (unsigned int)digitlen(n) <= 0 ?
        MIN_GENERATOR : n - MAX_DIGIT * (unsigned int)digitlen(n);
}

static unsigned int min_generator(unsigned int n) {
    unsigned int gen;
    
    gen = do_min_generator(n);
    while (gen < n) {
        if (digitsum(gen) == n)
            return gen;
        ++gen;
    }
    
    return 0;
}

int main(int argc, const char *argv[]) {
    unsigned int num;
    
    scanf("%u", &num);
    printf("%u\n", min_generator(num));
    
    return 0;
}
