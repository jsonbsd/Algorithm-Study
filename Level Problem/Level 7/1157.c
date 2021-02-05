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

#define ALPHA_LEN   26
#define MAX_STR_LEN 1000000

#define dis_lower_alpha(alpha) (alpha - 'a')
#define dis_to_upper_alpha(dis) (dis + 'A')

static int update_num_alpha(char str[], size_t n_alpha[], size_t len) {
    int i, max_idx;
    
    for (i = 0; i < len; ++i)
        ++n_alpha[dis_lower_alpha(tolower(str[i]))];
    
    i = max_idx = 0;
    while (i < ALPHA_LEN) {
        if (n_alpha[i] > n_alpha[max_idx])
            max_idx = i;
        ++i;
    }
    
    return max_idx;
}

static void print_max_alpha(size_t n_alpha[], int max_idx) {
    int i;
    
    for (i = 0; i < ALPHA_LEN; ++i)
        if (i != max_idx && n_alpha[i] == n_alpha[max_idx]) {
            printf("%c\n", '?');
            return;
        }
    printf("%c\n", dis_to_upper_alpha(max_idx));
}

int main(int argc, const char *argv[]) {
    char str[MAX_STR_LEN];
    size_t len, n_alpha[ALPHA_LEN];
    int max_idx;
    
    scanf("%s", str);
    
    len = strlen(str);
    memset(n_alpha, 0, sizeof(n_alpha));
    max_idx = update_num_alpha(str, n_alpha, len);
    print_max_alpha(n_alpha, max_idx);
    
    return 0;
}
