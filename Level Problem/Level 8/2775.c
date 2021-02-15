/*
 * main.c
 * C Project
 *
 * Created by ljy on 2021/02/11.
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

static int n_people(int level, int room) {
    if (level == 0 || room == 1) {
        return room;
    } else {
        return n_people(level, room - 1) + n_people(level - 1, room);
    }
}

int main(int argc, const char *argv[]) {
    int level, room;
    int n_test;
    
    scanf("%d", &n_test);
    for (; n_test; --n_test) {
        scanf("%d %d", &level, &room);
        printf("%d\n", n_people(level, room));
    }
    
    return 0;
}
