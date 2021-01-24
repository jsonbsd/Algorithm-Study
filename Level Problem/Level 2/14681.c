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
    int16_t x, y;
    
    scanf("%hd %hd", &x, &y);
    printf("%d\n", x > 0 ? (y > 0 ? 1 : 4) : (y > 0 ? 2 : 3));
    
    return 0;
}
