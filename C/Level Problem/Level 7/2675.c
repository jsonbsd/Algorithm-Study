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

#define MAX_STR_LEN 20

static void print_repeat_str(char str[], int n_repeat) {
    int i, j, len;
    
    len = (int)strlen(str);
    for (i = 0; i < len; ++i)
        for (j = 0; j < n_repeat; ++j)
            putchar(str[i]);
}

int main(int argc, const char *argv[]) {
    int i, n_test, n_repeat;
    char str[MAX_STR_LEN];
    
    scanf("%d", &n_test);
    
    for (i = 0; i < n_test; ++i) {
        scanf("%d %s", &n_repeat, str);
        print_repeat_str(str, n_repeat);
        putchar('\n');
    }
    
    return 0;
}
