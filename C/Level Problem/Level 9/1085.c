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

static unsigned int
min_dist_boundary(unsigned x, unsigned y, unsigned w, unsigned h) {
    unsigned int min_dist_row, min_dist_col;
    
    min_dist_row = y < (h - y) ? y : h - y;
    min_dist_col = x < (w - x) ? x : w - x;
    
    return min_dist_row < min_dist_col ? min_dist_row : min_dist_col;
}

int main(int argc, const char *argv[]) {
    unsigned int cur_x, cur_y, width, height;
    
    scanf("%u %u %u %u", &cur_x, &cur_y, &width, &height);
    printf("%u\n", min_dist_boundary(cur_x, cur_y, width, height));
    
    return 0;
}
