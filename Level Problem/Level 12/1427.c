/*
 * main.c
 * C Project
 *
 * Created by ljy on 2021/09/10.
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

#define MAX_DIGIT 9
#define N_DIGIT 10

static void count_digit(unsigned int n, size_t *arr) {
    while (n) {
        ++arr[n % 10];
        n /= 10;
    }
}

static void print_digit_desc(size_t *arr) {
    int digit;
    size_t digitlen;
    
    for (digit = MAX_DIGIT; digit >= 0; --digit)
        for (digitlen = arr[digit]; digitlen > 0; --digitlen)
            printf("%d", digit);
    putchar('\n');
}

int main(int argc, const char *argv[]) {
    unsigned int data;
    size_t ndigit[N_DIGIT];
    
    scanf("%u", &data);
    
    memset(ndigit, 0, sizeof(ndigit));
    count_digit(data, ndigit);
    print_digit_desc(ndigit);
    
    return (EXIT_SUCCESS);
}
