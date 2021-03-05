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

static inline double euclidian_circle_area(double r) {
    return M_PI * pow(r, 2.0);
}

static inline double taxicab_circle_area(double r) {
    return 2.0 * pow(r, 2.0);
}

int main(int argc, const char *argv[]) {
    double radius;
    
    scanf("%lf", &radius);
    
    printf("%.6lf\n", euclidian_circle_area(radius));
    printf("%.6lf\n", taxicab_circle_area(radius));
    
    return 0;
}
