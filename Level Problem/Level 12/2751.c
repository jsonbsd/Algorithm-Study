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

static void get_data(int *arr, size_t len) {
    size_t i;
    
    for (i = 0; i < len; ++i)
        scanf("%d", arr + i);
}

static int int_compare(const void *p1, const void *p2) {
    int left, right;
    
    left = *(const int *)p1;
    right = *(const int *)p2;
    
    return ((left > right) - (right > left));
}

static void print_data(int *arr, size_t len) {
    size_t i;
    
    for (i = 0; i < len; ++i)
        printf("%d\n", arr[i]);
}

int main(int argc, const char *argv[]) {
    int *data, n_data;
    
    scanf("%d", &n_data);
    data = (int *)malloc(sizeof(*data) * n_data);
    
    get_data(data, n_data);
    qsort(data, n_data, sizeof(*data), int_compare);
    print_data(data, n_data);
    free(data);
    
    return (EXIT_SUCCESS);
}
