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

static inline int max_num_per_dist(int dist) {
    return 3 * dist * (dist - 1) + 1;
}

int main(int argc, const char *argv[]) {
    int i, n;
    
    scanf("%d", &n);
    
    for (i = 1; max_num_per_dist(i) < n; ++i)
        ;
    
    printf("%d\n", i);
    
    return 0;
}
