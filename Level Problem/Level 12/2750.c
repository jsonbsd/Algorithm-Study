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

#define list_for_each_bubble(i, j, from, len)   \
    for (i = len - 1; i > from; --i)            \
        for (j = from; j < i; ++j)

static void get_data(int16_t *arr, int len) {
    int i;
    
    for (i = 0; i < len; ++i)
        scanf("%hd", arr + i);
}

static void swap(int16_t *p1, int16_t *p2) {
    int16_t tmp;
    
    tmp = *p1;
    *p1 = *p2;
    *p2 = tmp;
}

static void bubblesort(int16_t *arr, int len) {
    int i, j;
    
    list_for_each_bubble(i, j, 0, len) {
        if (arr[j] > arr[j + 1])
            swap(arr + j, arr + j + 1);
    }
}

static void print_data(int16_t *arr, int len) {
    int i;
    
    for (i = 0; i < len; ++i)
        printf("%hd\n", arr[i]);
}

int main(int argc, const char *argv[]) {
    int16_t *data;
    int n_data;
    
    scanf("%d", &n_data);
    data = (int16_t *)malloc(sizeof(*data) * n_data);
    
    get_data(data, n_data);
    bubblesort(data, n_data);
    print_data(data, n_data);
    free(data);
    
    return 0;
}
