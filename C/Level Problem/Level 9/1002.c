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

enum n_case {
    N_CONGRUENCE = -1,
    N_DISJOINT,
    N_CONTACT,
    N_INTERSECT
};

struct circle_t {
    double x, y;
    unsigned int r;
};

static inline double
dist_circle_center(struct circle_t c1, struct circle_t c2) {
    return sqrt(pow(c1.x - c2.x, 2.0) + pow(c1.y - c2.y, 2.0));
}

static int
num_intersect_point(struct circle_t c1, struct circle_t c2) {
    double dist, r_sub, r_sum;
    
    r_sub = c1.r > c2.r ? (double)(c1.r - c2.r) : (double)(c2.r - c1.r);
    r_sum = (double)(c1.r + c2.r);
    dist = dist_circle_center(c1, c2);
    
    if (dist == 0 && r_sub == 0)
        return N_CONGRUENCE;
    else if (dist < r_sub || dist > r_sum)
        return N_DISJOINT;
    else if (dist == r_sub || dist == r_sum)
        return N_CONTACT;
    
    return N_INTERSECT;
}

int main(int argc, const char *argv[]) {
    struct circle_t c1, c2;
    int n_test;
    
    scanf("%d", &n_test);
    
    for (; n_test; --n_test) {
        scanf("%lf %lf %u", &c1.x, &c1.y, &c1.r);
        scanf("%lf %lf %u", &c2.x, &c2.y, &c2.r);
        printf("%d\n", num_intersect_point(c1, c2));
    }
    
    return 0;
}
