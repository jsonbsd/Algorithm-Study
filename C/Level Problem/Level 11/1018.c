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

#define CHESS_ROW_SIZE 8
#define CHESS_COL_SIZE 8

#define FLUSH_STDIN() \
    do {} while (getchar() != '\n')

#define list_for_each(iter, from, to) \
    for (iter = from; iter < to; ++iter)

#define list_for_each2(iter, from, to) \
    for (iter = from; iter < to; iter += 2)

static char **create_board(size_t row, size_t col) {
    char **ret;
    int i;
    
    ret = (char **)malloc(sizeof(*ret) * row);
    for (i = 0; i < row; ++i)
        ret[i] = (char *)malloc(sizeof(**ret) * col);
    
    return ret;
}

static void get_board_color(char **arr, size_t row, size_t col) {
    int i, j;
    
    for (i = 0; i < row; ++i) {
        FLUSH_STDIN();
        for (j = 0; j < col; ++j)
            scanf("%c", &arr[i][j]);
    }
}

static unsigned int do_min_repaint_board(char **arr, size_t lx, size_t ly) {
    const char white = 'W', black = 'B';
    unsigned int wcount, bcount;
    size_t i, j;
    
    wcount = bcount = 0;
    list_for_each(i, lx, lx + CHESS_ROW_SIZE) {
        list_for_each2(j, ly + i % 2, ly + CHESS_COL_SIZE) {
            wcount = arr[i][j] != white ? wcount + 1 : wcount;
            bcount = arr[i][j] != black ? bcount + 1 : bcount;
        }
        list_for_each2(j, ly + (i + 1) % 2, ly + CHESS_COL_SIZE) {
            wcount = arr[i][j] == white ? wcount + 1 : wcount;
            bcount = arr[i][j] == black ? bcount + 1 : bcount;
        }
    }
        
    return wcount < bcount ? wcount : bcount;
}

static unsigned int min_repaint_board(char **arr, size_t row, size_t col) {
    unsigned int lx, ly, maxlx, maxly;
    unsigned int min, nrep;
    
    min = UINT32_MAX;
    maxlx = (unsigned int)row - (CHESS_ROW_SIZE - 1);
    maxly = (unsigned int)col - (CHESS_COL_SIZE - 1);
    
    list_for_each(lx, 0, maxlx) {
        list_for_each(ly, 0, maxly) {
            if ((nrep = do_min_repaint_board(arr, lx, ly)) < min)
                min = nrep;
        }
    }
    
    return min;
}

static void free_board(char **arr, size_t row) {
    int i;
    
    for (i = 0; i < row; ++i)
        free(arr[i]);
    free(arr);
}

int main(int argc, const char *argv[]) {
    char **board;
    uint8_t row, col;
    
    scanf("%hhu %hhu", &row, &col);
    
    board = create_board(row, col);
    get_board_color(board, row, col);
    printf("%u\n", min_repaint_board(board, row, col));
    free_board(board, row);
    
    return 0;
}
