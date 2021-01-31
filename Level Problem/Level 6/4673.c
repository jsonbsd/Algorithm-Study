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

#define PRINT_LEN 10001

static int d(int num) {
    int sum;
    
    sum = num;
    while (num) {
        sum += num % 10;
        num /= 10;
    }
    
    return sum;
}

int main(int argc, const char * argv[]) {
    bool self_num[PRINT_LEN];
    int i;
    
    i = 1;
    memset(self_num, true, sizeof(self_num));
    while (i < PRINT_LEN) {
        if (d(i) < PRINT_LEN)
            self_num[d(i)] = false;
        ++i;
    }
    
    for (i = 1; i < PRINT_LEN; ++i)
        if (self_num[i])
            printf("%d\n", i);
    
    return 0;
}
