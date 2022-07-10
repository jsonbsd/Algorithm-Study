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

#define MIN_DIVIDER 2
#define MAX_DIVIDER(num) (num / 2)

int main(int argc, const char *argv[]) {
    int i, num;

    scanf("%d", &num);

    for (i = MIN_DIVIDER; i <= MAX_DIVIDER(num); ++i) {
        if (num % i == 0) {
            printf("%d\n", i);
            num /= i;
            i = MIN_DIVIDER - 1;
        }
    }

    if (num > 1)
        printf("%d\n", num);

    return 0;
}
