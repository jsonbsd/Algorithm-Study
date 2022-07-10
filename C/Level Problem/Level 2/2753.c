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
    int16_t year;
    
    scanf("%hd", &year);
    
    if (year % 4 == 0) {
        if (year % 400 == 0)
            puts("1");
        else if (year % 100 == 0)
            puts("0");
        else
            puts("1");
    } else {
        puts("0");
    }
    
    return 0;
}
