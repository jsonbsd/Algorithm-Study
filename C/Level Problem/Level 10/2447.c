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

#define BASELEN     1
#define ROW_CPLEN   3
#define COL_CPLEN   3

#define BLANK       ' '
#define STAR        '*'

#define PREVLEN(len) (len / 3)
#define CPPOS(iter, len) (iter * len)

#define NEED_COPY(i, j)                         \
    !((i == 0 && j == 0) || (i == 1 && j == 1))
#define __LIST_FOREACH(iter, from, to)          \
    for (iter = from; iter < to; ++iter)

static void init_board(char **arr, size_t len) {
    size_t i, j;
    
    __LIST_FOREACH(i, 0, len) {
        __LIST_FOREACH(j, 0, len) {
            arr[i][j] = BLANK;
        }
    }
    
    arr[0][0] = STAR;
}

static char **create_board(size_t len) {
    char **ret;
    size_t i;
    
    ret = (char **)malloc(sizeof(*ret) * len);
    for (i = 0; i < len; ++i)
        ret[i] = (char *)malloc(sizeof(**ret) * len);
    
    init_board(ret, len);
    
    return ret;
}

static void __copy_board(char **arr, size_t len, size_t i, size_t j) {
    size_t cpi, cpj;
    
    __LIST_FOREACH(cpi, 0, len) {
        __LIST_FOREACH(cpj, 0, len) {
            arr[CPPOS(i, len) + cpi][CPPOS(j, len) + cpj] = arr[cpi][cpj];
        }
    }
}

static void copy_board(char **arr, size_t len) {
    size_t i, j;
    
    __LIST_FOREACH(i, 0, ROW_CPLEN) {
        __LIST_FOREACH(j, 0, COL_CPLEN) {
            if (NEED_COPY(i, j))
                __copy_board(arr, len, i, j);
        }
    }
}

static void draw_board(char **arr, size_t len) {
    if (len == BASELEN)
        return;
    
    draw_board(arr, PREVLEN(len));
    copy_board(arr, PREVLEN(len));
}

static void print_board(char **arr, size_t len) {
    size_t i, j;
    
    __LIST_FOREACH(i, 0, len) {
        __LIST_FOREACH(j, 0, len) {
            printf("%c", arr[i][j]);
        }
        printf("\n");
    }
}

static void free_board(char **arr, size_t len) {
    int i;
    
    for (i = 0; i < len; ++i)
        free(arr[i]);
    free(arr);
}

int main(int argc, const char *argv[]) {
    char **board;
    unsigned int num;
    
    scanf("%u", &num);
    
    board = create_board(num);
    draw_board(board, num);
    print_board(board, num);
    free_board(board, num);
    
    return 0;
}
