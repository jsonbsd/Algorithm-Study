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
backtrack(int *digits, bool *valid, int level, int ndigit, int len) {
    int i;
    
    if (level == len) {
        print_digits(digits, len);
    } else {
        for (i = 0; i < ndigit; ++i) {
            if (valid[i]) {
                digits[level] = i + 1;
                valid[i] = false;
                backtrack(digits, valid, level + 1, ndigit, len);
                valid[i] = true;
            }
        }
    }
}

int main(int argc, const char *argv[]) {
    int *digits, ndigit, len;
    bool *valid;
    
    scanf("%d %d", &ndigit, &len);
    
    digits = (int *)malloc(len * sizeof(*digits));
    valid = (bool *)malloc(ndigit * sizeof(*valid));
    memset(valid, true, ndigit * sizeof(*valid));
    
    backtrack(digits, valid, 0, ndigit, len);
    
    free(digits);
    free(valid);
    
    return (EXIT_SUCCESS);
}
