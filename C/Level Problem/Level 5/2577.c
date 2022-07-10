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
    int n_digit[10];
    int a, b, c, i;
    
    scanf("%d %d %d", &a, &b, &c);
    
    a *= (b * c);
    memset(n_digit, 0, sizeof(n_digit));
    while (a > 0) {
        ++n_digit[a % 10];
        a /= 10;
    }
    
    for (i = 0; i < 10; ++i)
        printf("%d\n", n_digit[i]);
    
    return 0;
}
