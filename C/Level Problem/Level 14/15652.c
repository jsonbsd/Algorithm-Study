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

static void print_digits(int *digits, int len) {
    int i;
    
    for (i = 0; i < len; ++i)
        printf("%d ", digits[i]);
    putchar('\n');
}

static void
backtrack(int *digits, int level, int value, int ndigit, int len) {
    int i;
    
    if (level == len) {
        print_digits(digits, len);
    } else {
        for (i = value; i < ndigit; ++i) {
            digits[level] = i + 1;
            backtrack(digits, level + 1, i, ndigit, len);
        }
    }
}

int main(int argc, const char *argv[]) {
    int *digits, ndigit, len;
    
    scanf("%d %d", &ndigit, &len);
    
    digits = (int *)malloc(len * sizeof(*digits));
    backtrack(digits, 0, 0, ndigit, len);
    free(digits);
    
    return (EXIT_SUCCESS);
}
