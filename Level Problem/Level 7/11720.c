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

#define FLUSH_STDIN() do {} while(getchar() != '\n')

int main(int argc, const char *argv[]) {
    int i, sum;
    size_t len;
    
    scanf("%zd", &len);
    FLUSH_STDIN();
    
    i = sum = 0;
    while (i < len) {
        sum += (getchar() - '0');
        ++i;
    }
    
    printf("%d\n", sum);
    
    return 0;
}
