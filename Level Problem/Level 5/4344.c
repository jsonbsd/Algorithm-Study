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

#define SCORE_LEN 101

#define GET_AVG_DOUBLE(sum, len) ((double)sum / (double)len)
#define SUBS_ABOVE_AVG(avg) ((int)avg + 1)

static double per_above_avg(void) {
    int i, n_score, score, sum;
    int score_counter[SCORE_LEN];
    
    scanf("%d", &n_score);
    
    i = sum = 0;
    memset(score_counter, 0, sizeof(score_counter));
    while (i < n_score) {
        scanf("%d", &score);
        sum += score;
        ++score_counter[score];
        ++i;
    }
    
    i = SUBS_ABOVE_AVG(GET_AVG_DOUBLE(sum, n_score));
    sum = 0;
    while (i < SCORE_LEN) {
        sum += score_counter[i];
        ++i;
    }
    
    return GET_AVG_DOUBLE(sum, n_score) * 100.0;
}

int main(int argc, const char * argv[]) {
    int i, n_test;
    
    scanf("%d", &n_test);
    
    for (i = 0; i < n_test; ++i)
        printf("%.3f%%\n", per_above_avg());
    
    return 0;
}
