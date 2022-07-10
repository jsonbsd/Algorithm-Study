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

#define MAX_STRLEN 101
#define ALPHA_LEN 26

#define DIS_LOWER_ALPHA(alpha) (alpha - 'a')

static int is_group_word(char str[]) {
    bool alpha_exist[ALPHA_LEN];
    char cur_alpha;
    int i, len;
    
    memset(alpha_exist, false, sizeof(alpha_exist));
    
    i = 0;
    cur_alpha = str[0];
    len = (int)strlen(str);
    while (i < len) {
        if (str[i] != cur_alpha) {
            if (alpha_exist[DIS_LOWER_ALPHA(str[i])])
                return 0;
            alpha_exist[DIS_LOWER_ALPHA(cur_alpha)] = true;
            cur_alpha = str[i];
        }
        ++i;
    }
    
    return 1;
}

int main(int argc, const char *argv[]) {
    char str[MAX_STRLEN];
    int i, n_word, n_grp_word;
    
    scanf("%d", &n_word);

    i = n_grp_word = 0;
    while (i < n_word) {
        scanf("%s", str);
        n_grp_word += is_group_word(str);
        ++i;
    }
    
    printf("%d\n", n_grp_word);
    
    return 0;
}
