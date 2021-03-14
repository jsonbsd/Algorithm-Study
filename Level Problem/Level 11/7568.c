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

#define MIN_GRADE 1

#define list_for_each(iter, from, to) \
    for (iter = from; iter < to; ++iter)

#define list_for_each_except(iter, from, to, except)        \
    for (iter = from == except ? from + 1 : from;           \
        iter < to;                                          \
        ++iter == except ? ++iter : iter)

struct pinfo_t {
    uint8_t weight;
    uint8_t height;
    uint8_t grade;
};

static inline struct pinfo_t *create_pinfo_table(size_t n) {
    return (struct pinfo_t *)calloc(n, sizeof(struct pinfo_t));
}

static void get_pinfo_data(struct pinfo_t *p, size_t n) {
    int i;
    
    for (i = 0; i < n; ++i)
        scanf("%hhu %hhu", &p[i].weight, &p[i].height);
}

static inline bool issmaller(struct pinfo_t p1, struct pinfo_t p2) {
    return p1.weight < p2.weight && p1.height < p2.height;
}

static void update_pinfo_grade(struct pinfo_t *p, size_t n) {
    int i, j;
    
    list_for_each(i, 0, n) {
        p[i].grade = MIN_GRADE;
        list_for_each_except(j, 0, n, i) {
            if (issmaller(p[i], p[j]))
                ++p[i].grade;
        }
    }
}

static void print_pinfo_grade(struct pinfo_t *p, size_t n) {
    int i;
    
    for (i = 0; i < n; ++i)
        printf("%hhu ", p[i].grade);
    printf("\n");
}

static void free_pinfo_table(struct pinfo_t *p) {
    if (p != NULL)
        free(p);
}

int main(int argc, const char *argv[]) {
    struct pinfo_t *pdata;
    uint8_t ndata;
    
    scanf("%hhu", &ndata);
    if ((pdata = create_pinfo_table(ndata)) == NULL)
        return -ENOMEM;
    
    get_pinfo_data(pdata, ndata);
    update_pinfo_grade(pdata, ndata);
    print_pinfo_grade(pdata, ndata);
    free_pinfo_table(pdata);
    
    return 0;
}
