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

int main(int argc, const char *argv[]) {
    int n_digit[42];
    int num, count, i;
    
    i = count = 0;
    memset(n_digit, 0, sizeof(n_digit));
    while (i < 10) {
        scanf("%d", &num);
        if (!(n_digit[num % 42]++))
            ++count;
        ++i;
    }
    
    printf("%d\n", count);
    
    return 0;
}
