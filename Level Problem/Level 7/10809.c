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

#define MAX_STR_LEN 100
#define ALPHA_LEN   26

#define dis_alpha(alpha) (alpha - 'a')

int main(int argc, const char *argv[]) {
    char str[MAX_STR_LEN];
    ssize_t i, len, alpha_pos[ALPHA_LEN];
    
    scanf("%s", str);
    
    i = 0;
    len = (ssize_t)strlen(str);
    memset(alpha_pos, -1, sizeof(alpha_pos));
    while (i < len) {
        if (alpha_pos[dis_alpha(str[i])] == -1)
            alpha_pos[dis_alpha(str[i])] = i;
        ++i;
    }
    
    for (i = 0; i < ALPHA_LEN; ++i)
        printf("%zd ", alpha_pos[i]);
    putchar('\n');
    
    return 0;
}
