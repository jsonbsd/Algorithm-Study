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

static void getdata(int16_t *arr, size_t len) {
    size_t i;
    
    for (i = 0; i < len; ++i)
        scanf("%hd", arr + i);
}

static int int16_compare(const void *p1, const void *p2) {
    int16_t left, right;
    
    left = *(const int16_t *)p1;
    right = *(const int16_t *)p2;
    
    return (left > right) - (right > left);
}

static int average(int16_t *arr, size_t len) {
    double sum;
    size_t i;
    
    sum = i = 0;
    while (i < len) {
        sum += (double)arr[i];
        ++i;
    }
    
    return (int)round(sum / (double)len);
}

static inline int median(int16_t *arr, size_t len) {
    return arr[len / 2];
}

static size_t num_element(int16_t *arr, size_t pos, size_t len) {
    size_t count;
    
    count = 1;
    while (pos < len - 1 && arr[pos] == arr[pos + 1]) {
        ++count;
        ++pos;
    }
    
    return count;
}

static int mode(int16_t *arr, size_t len) {
    int mode1, mode2;
    size_t i, count, maxcount;
    
    i = maxcount = 0;
    mode1 = mode2 = INT32_MIN;
    while (i < len) {
        if ((count = num_element(arr, i, len)) > maxcount) {
            maxcount = count;
            mode1 = (int)i;
            mode2 = INT32_MIN;
        } else if (count == maxcount && mode2 < 0) {
            mode2 = (int)i;
        }
        i += count;
    }
    
    return mode2 < 0 ? arr[mode1] : arr[mode2];
}

static inline int range(int16_t *arr, size_t len) {
    return arr[len - 1] - arr[0];
}

int main(int argc, const char *argv[]) {
    int16_t *data;
    size_t ndata;
    
    scanf("%zu", &ndata);
    data = (int16_t *)malloc(sizeof(*data) * ndata);
    
    getdata(data, ndata);
    qsort(data, ndata, sizeof(*data), int16_compare);
    
    printf("%d\n", average(data, ndata));
    printf("%d\n", median(data, ndata));
    printf("%d\n", mode(data, ndata));
    printf("%d\n", range(data, ndata));
    free(data);
    
    return (EXIT_SUCCESS);
}
