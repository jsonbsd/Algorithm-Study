/*
 * main.c
 * C Project
 *
 * Created by ljy on 2021/02/11.
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

static inline int climb_day(int asc, int desc, int height) {
    if ((height - asc) % (asc - desc))
        return (height - asc) / (asc - desc) + 2;
    else
        return (height - asc) / (asc - desc) + 1;
}

int main(int argc, const char *argv[]) {
    int asc, desc, height;
    
    scanf("%d %d %d", &asc, &desc, &height);
    printf("%d\n", climb_day(asc, desc, height));
    
    return 0;
}
