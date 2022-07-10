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

#define MAX_CARD_COUNT 100

#define __list_for_each(iter, from, to) \
    for (iter = from; iter < to; ++iter)

#define list_for_three_binomial_entry(iter1, iter2, iter3, from, to)    \
    __list_for_each(iter1, from, to - 2)                                \
        __list_for_each(iter2, iter1 + 1, to - 1)                       \
            __list_for_each(iter3, iter2 + 1, to)

static inline bool ishigher(unsigned sum, unsigned max, unsigned goal) {
    return sum > max && sum <= goal;
}

static unsigned int blackjack(unsigned *arr, size_t len, unsigned goal) {
    unsigned int c1, c2, c3, sum, max;
    
    sum = max = 0;
    list_for_three_binomial_entry(c1, c2, c3, 0, len) {
        sum = arr[c1] + arr[c2] + arr[c3];
        max = ishigher(sum, max, goal) ? sum : max;
    }
    
    return max;
}

int main(int argc, const char *argv[]) {
    uint8_t n_card;
    unsigned int i, goal, card[MAX_CARD_COUNT];
    
    scanf("%hhu %u", &n_card, &goal);
    for (i = 0; i < n_card; ++i)
        scanf("%u", card + i);
    
    printf("%u\n", blackjack(card, n_card, goal));
    
    return 0;
}
