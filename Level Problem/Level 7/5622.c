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

#define MAX_STRLEN 16
#define NUM_DIAL 8
#define TIME_TO_BASE 3

static int time_to_each_dial(char ch) {
    char dial_tbl[NUM_DIAL] = {'C', 'F', 'I', 'L', 'O', 'S', 'V', 'Z'};
    int i;
    
    for (i = 0; i < NUM_DIAL; ++i)
        if (ch <= dial_tbl[i])
            return TIME_TO_BASE + i;
    
    return -EINVAL;
}

static int time_to_dial(char str[]) {
    int i, dial_time;
    size_t len;

    len = strlen(str);
    i = dial_time = 0;
    while (i < len) {
        dial_time += time_to_each_dial(str[i]);
        ++i;
    }

    return dial_time;
}

int main(int argc, const char *argv[]) {
    char str[MAX_STRLEN];
    
    scanf("%s", str);
    printf("%d\n", time_to_dial(str));
    
    return 0;
}
