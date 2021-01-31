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

#define two_digit_diff(num) (((num) % 10) - ((num) / 10 % 10))

bool is_han_num(int num) {
    while (num >= 100) {
        if (two_digit_diff(num) != two_digit_diff(num / 10))
            return false;
        num /= 10;
    }
    
    return true;
}

int main(int argc, const char * argv[]) {
    int i, n, n_han_num;
    
    scanf("%d", &n);
    
    i = 1;
    n_han_num = 0;
    while (i <= n) {
        if (is_han_num(i))
            ++n_han_num;
        ++i;
    }
    
    printf("%d\n", n_han_num);
    
    return 0;
}
