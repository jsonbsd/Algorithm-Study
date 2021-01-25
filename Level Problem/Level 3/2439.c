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

int main(int argc, const char * argv[]) {
    int i, j, n;
    
    scanf("%d", &n);
    
    for (i = 0; i < n; ++i) {
        for (j = 0; j < n - (i + 1); ++j)
            putchar(' ');
        for (j = 0; j < i + 1; ++j)
            putchar('*');
        putchar('\n');
    }

    return 0;
}
