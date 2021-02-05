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

#define MAX_LEN     80
#define INIT_POINT  1

enum { PASS = 'O', FAIL = 'X' };

static int score(char str[]) {
    int i, tot_score, point;
    size_t len;
    
    len = strlen(str);
    point = INIT_POINT;
    i = tot_score = 0;
    while (i < len) {
        if (str[i] == PASS)
            tot_score += point++;
        else if (str[i] == FAIL)
            point = INIT_POINT;
        ++i;
    }
    
    return tot_score;
}

int main(int argc, const char *argv[]) {
    int i, n_test;
    char str[MAX_LEN];
    
    scanf("%d", &n_test);
    
    for (i = 0; i < n_test; ++i) {
        scanf("%s", str);
        printf("%d\n", score(str));
    }
    
    return 0;
}
