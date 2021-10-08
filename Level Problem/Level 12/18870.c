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

#define ARRAY_LAST_SUBSCRIPT(len) ((len) - 1)

static void input_data(int *data, int ndata) {
    int i;
    
    for (i = 0; i < ndata; ++i)
        scanf("%d", data + i);
}

static int compare_data(const void *p1, const void *p2) {
    return (*(int *)p1 - *(int *)p2);
}

static int rm_duplicate_data(int *data, int ndata) {
    int *tmp, oldpos, newpos;
    
    if (ndata == 0 || ndata == 1)
        return ndata;
    
    tmp = (int *)malloc(ndata * sizeof(*tmp));
    oldpos = newpos = 0;
    while (oldpos < ARRAY_LAST_SUBSCRIPT(ndata)) {
        if (data[oldpos] != data[oldpos + 1])
            tmp[newpos++] = data[oldpos];
        ++oldpos;
    }
    
    tmp[newpos++] = data[ARRAY_LAST_SUBSCRIPT(ndata)];
    memcpy(data, tmp, newpos * sizeof(*tmp));
    free(tmp);
    
    return newpos;
}

static int
binary_search(int *lookup, int *data, int nlookup, int ndata, int target) {
    int left, mid, right;
    
    left = 0;
    right = nlookup;
    while (left <= right) {
        mid = (left + right) / 2;
        if (lookup[mid] > target)
            right = mid - 1;
        else if (lookup[mid] < target)
            left = mid + 1;
        else
            break;
    }
    
    return mid;
}

static void print_data(int *lookup, int *data, int nlookup, int ndata) {
    int i;
    
    for (i = 0; i < ndata; ++i)
        printf("%d ", binary_search(lookup, data, nlookup, ndata, data[i]));
    putchar('\n');
}

int main(int argc, const char *argv[]) {
    int *lookup, *data, nlookup, ndata;
    
    scanf("%d", &ndata);
    
    data = (int *)malloc(ndata * sizeof(*data));
    lookup = (int *)malloc(ndata * sizeof(*lookup));
    
    input_data(data, ndata);
    memcpy(lookup, data, ndata * sizeof(*data));
    qsort(lookup, ndata, sizeof(*lookup), compare_data);
    nlookup = rm_duplicate_data(lookup, ndata);
    print_data(lookup, data, nlookup, ndata);
    
    free(lookup);
    free(data);
    
    return (EXIT_SUCCESS);
}
