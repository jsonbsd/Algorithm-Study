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
    int n, x, a_val;
    int i;
    
    scanf("%d %d", &n, &x);
    
    for (i = 0; i < n; ++i) {
        scanf("%d", &a_val);
        
        if (a_val < x)
            printf("%d ", a_val);
    }
    putchar('\n');

    return 0;
}
