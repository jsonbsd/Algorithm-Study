/*
 * main.c
 * C Project
 *
 * Created by ljy on 2021/09/10.
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

struct point_t {
    int x;
    int y;
};

static int compare_point(const void *p1, const void *p2) {
    struct point_t prev, next;
    
    prev = *(struct point_t *)p1;
    next = *(struct point_t *)p2;
    
    return prev.y != next.y ? prev.y - next.y : prev.x - next.x;
}

static void print_point(struct point_t *data, int ndata) {
    int i;
    
    for (i = 0; i < ndata; ++i)
        printf("%d %d\n", data[i].x, data[i].y);
}

int main(int argc, const char *argv[]) {
    struct point_t *data;
    int ndata, i;
    
    scanf("%d", &ndata);
    
    data = (struct point_t *)malloc(ndata * sizeof(struct point_t));
    for (i = 0; i < ndata; ++i)
        scanf("%d %d", &data[i].x, &data[i].y);
    
    qsort(data, ndata, sizeof(struct point_t), compare_point);
    print_point(data, ndata);
    free(data);
    
    return (EXIT_SUCCESS);
}
