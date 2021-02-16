/*
 * main.c
 * C Project
 *
 * Created by ljy on 2021/02/11.
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

#define __EINVAL -1

#define NUM_SUG3(weight) ((weight) / 3)
#define NUM_SUG5(weight) ((weight) / 5)
#define REST_EXCEPT_SUG5(weight, sug5) ((weight) - (sug5 * 5))
#define IS_DIV_SUG3(weight) ((weight) % 3 == 0)

int main(int argc, const char *argv[]) {
    int n_sug5, weight;
    
    scanf("%d", &weight);
    
    for (n_sug5 = NUM_SUG5(weight); n_sug5 >= 0; --n_sug5) {
        if (IS_DIV_SUG3(REST_EXCEPT_SUG5(weight, n_sug5))) {
            printf("%d\n", n_sug5 + NUM_SUG3(REST_EXCEPT_SUG5(weight, n_sug5)));
            return 0;
        }
    }
    printf("%d\n", __EINVAL);
    
    return 0;
}
