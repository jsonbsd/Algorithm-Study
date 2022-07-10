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

static inline double fix_sum(double sum, double max) {
    return sum / max * 100;
}

int main(int argc, const char *argv[]) {
    int i, n_score, score, max_score;
    double sum;
    
    scanf("%d", &n_score);
    
    sum = max_score = i = 0;
    while (i < n_score) {
        scanf("%d", &score);
        sum += (double)score;
        if (score > max_score)
            max_score = score;
        ++i;
    }
    
    printf("%.3f\n", fix_sum(sum, (double)max_score) / (double)n_score);
    
    return 0;
}
