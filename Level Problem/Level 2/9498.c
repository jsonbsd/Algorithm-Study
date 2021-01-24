/*
 * main.c
 * C Project
 *
 * Created by ljy on 2021/01/14.
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

int main(int argc, const char * argv[]) {
    int8_t score;
    
    scanf("%hhd", &score);
    
    switch (score / 10) {
        case 10:
        case 9:
            printf("%c\n", 'A');
            break;
        case 8:
            printf("%c\n", 'B');
            break;
        case 7:
            printf("%c\n", 'C');
            break;
        case 6:
            printf("%c\n", 'D');
            break;
        default:
            printf("%c\n", 'F');
            break;
    }
    
    return 0;
}
