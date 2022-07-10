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

#define MAX_NAMELEN 127

struct account_t {
    int order;
    int age;
    char name[MAX_NAMELEN];
};

static int compare_account(const void *p1, const void *p2) {
    struct account_t prev, next;
    
    prev = *(struct account_t *)p1;
    next = *(struct account_t *)p2;
    
    if (prev.age != next.age)
        return (prev.age - next.age);
    
    return (prev.order - next.order);
}

static void print_account(struct account_t *data, int ndata) {
    int i;
    
    for (i = 0; i < ndata; ++i)
        printf("%d %s\n", data[i].age, data[i].name);
}

int main(int argc, const char *argv[]) {
    struct account_t *data;
    int ndata, i;
    
    scanf("%d", &ndata);
    
    data = (struct account_t *)malloc(ndata * sizeof(struct account_t));
    for (i = 0; i < ndata; ++i) {
        scanf("%d %s", &data[i].age, data[i].name);
        data[i].order = i;
    }
    
    qsort(data, ndata, sizeof(struct account_t), compare_account);
    print_account(data, ndata);
    free(data);
    
    return (EXIT_SUCCESS);
}
