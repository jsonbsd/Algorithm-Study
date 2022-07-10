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

#define BASE_ROOM 101

#define DIS_FROM_ELV(height, cli_no) ((cli_no - 1) / height)
#define DIS_FROM_FLR(height, cli_no) ((cli_no - 1) % height * 100)

static int which_room(int h, int w, int cli_no) {
    const int base_room = BASE_ROOM;
    
    return base_room + DIS_FROM_FLR(h, cli_no) + DIS_FROM_ELV(h, cli_no);
}

int main(int argc, const char *argv[]) {
    int height, width, cli_no;
    int n_test;
    
    scanf("%d", &n_test);
    for (; n_test; --n_test) {
        scanf("%d %d %d", &height, &width, &cli_no);
        printf("%d\n", which_room(height, width, cli_no));
    }
    
    return 0;
}
