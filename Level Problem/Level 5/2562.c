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

int main(int argc, const char *argv[]) {
    int num, max, max_pos;
    int i;
    
    i = max = max_pos = 0;
    while (i < 9) {
        scanf("%d", &num);
        if (num > max) {
            max = num;
            max_pos = i + 1;
        }
        ++i;
    }
    
    printf("%d\n%d\n", max, max_pos);
    
    return 0;
}
