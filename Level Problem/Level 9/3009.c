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

#define SQ_VERTEX_LEN 4
#define INPUT_LEN (SQ_VERTEX_LEN - 1)
#define LAST_VERTEX (SQ_VERTEX_LEN - 1)

struct upoint16_t {
    uint16_t x, y;
};

static struct upoint16_t rt_last_square_vertex(struct upoint16_t *ver) {
    struct upoint16_t ret;
    
    ret.x = ver[0].x;
    ret.y = ver[0].y;
    
    if (ver[0].x == ver[1].x)
        ret.x = ver[2].x;
    else if (ver[0].x == ver[2].x)
        ret.x = ver[1].x;
    
    if (ver[0].y == ver[1].y)
        ret.y = ver[2].y;
    else if (ver[0].y == ver[2].y)
        ret.y = ver[1].y;
    
    return ret;
}

int main(int argc, const char *argv[]) {
    struct upoint16_t sq_vertex[SQ_VERTEX_LEN];
    int i;
    
    for (i = 0; i < INPUT_LEN; ++i)
        scanf("%hu %hu", &sq_vertex[i].x, &sq_vertex[i].y);
    
    sq_vertex[LAST_VERTEX] = rt_last_square_vertex(sq_vertex);
    printf("%hu %hu\n", sq_vertex[LAST_VERTEX].x, sq_vertex[LAST_VERTEX].y);
    
    return 0;
}
