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

static int reverse_num(int num) {
    int rev_num;
    
    rev_num = 0;
    while (num) {
        rev_num = rev_num * 10 + num % 10;
        num /= 10;
    }
    
    return rev_num;
}

int main(int argc, const char *argv[]) {
    int num1, num2, rev_num1, rev_num2;
    
    scanf("%d %d", &num1, &num2);
    
    rev_num1 = reverse_num(num1);
    rev_num2 = reverse_num(num2);
    printf("%d\n", rev_num1 > rev_num2 ? rev_num1 : rev_num2);
    
    return 0;
}
