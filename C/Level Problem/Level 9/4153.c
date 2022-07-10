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

#define NUM_TRIANGLE_EDGES 3

#define IS_RIGHT_TRIANGLE(e1, e2, e3)           \
((e1) * (e1) + (e2) * (e2) == (e3) * (e3))

static int get_tri_edges(unsigned arr[]) {
    return scanf("%u %u %u", &arr[0], &arr[1], &arr[2]);
}

static bool end_of_test(unsigned arr[]) {
    return arr[0] == 0 ? true : false;
}

static void swap(unsigned *p1, unsigned *p2) {
    unsigned int tmp;
    
    tmp = *p1;
    *p1 = *p2;
    *p2 = tmp;
}

static void arrsort(unsigned arr[]) {
    int i, argmax;
    
    i = argmax = 0;
    while (i < NUM_TRIANGLE_EDGES) {
        if (arr[i] > arr[argmax])
            argmax = i;
        ++i;
    }
    
    swap(&arr[argmax], &arr[NUM_TRIANGLE_EDGES - 1]);
}

static void print_right_triangle(unsigned arr[]) {
    if (IS_RIGHT_TRIANGLE(arr[0], arr[1], arr[2]))
        printf("right\n");
    else
        printf("wrong\n");
}

int main(int argc, const char *argv[]) {
    unsigned int tri_edges[NUM_TRIANGLE_EDGES];
    
    while (get_tri_edges(tri_edges) && !end_of_test(tri_edges)) {
        arrsort(tri_edges);
        print_right_triangle(tri_edges);
    }
    
    return 0;
}
