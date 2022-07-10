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
    int n, num, min, max;
    int i;
    
    scanf("%d", &n);
    
    i = 0;
    min = INT32_MAX;
    max = INT32_MIN;
    while (i < n) {
        scanf("%d", &num);
        if (num < min)
            min = num;
        if (num > max)
            max = num;
        ++i;
    }
    
    printf("%d %d\n", min, max);
    
    return 0;
}
