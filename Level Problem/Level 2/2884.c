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
    int8_t hour, minute;
    
    scanf("%hhd %hhd", &hour, &minute);
    
    hour = minute >= 45 ? hour : hour - 1;
    hour = hour < 0 ? hour + 24 : hour;
    minute = minute >= 45 ? minute - 45 : minute + 15;
    printf("%d %d\n", hour, minute);
    
    return 0;
}
