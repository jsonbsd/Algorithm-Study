/*
 * main.c
 * C Project
 *
 * Created by ljy on 2021/02/08.
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

static unsigned int fib(unsigned int num) {
    if (num == 0 || num == 1)
        return num;
    else
        return fib(num - 2) + fib(num - 1);
}

int main(int argc, const char *argv[]) {
    uint8_t num;
    
    scanf("%hhu", &num);
    printf("%u\n", fib(num));
    
    return 0;
}
