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
    int num1, num2, result;
    
    scanf("%d %d", &num1, &num2);
    result = num1 * num2;
    
    while (num2) {
        printf("%d\n", num1 * (num2 % 10));
        num2 /= 10;
    }
    printf("%d\n", result);
    
    return 0;
}
