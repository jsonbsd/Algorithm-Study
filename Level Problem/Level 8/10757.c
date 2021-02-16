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

#define MAX_NUMLEN 10001
#define MAX_SUMLEN MAX_NUMLEN + 1

#define TO_DIGIT(ch) (ch - '0')
#define TO_CHAR(num) (num + '0')

static void __strlshift(char str[]) {
    ssize_t i;
    
    for (i = (ssize_t)strlen(str); i >= 0; --i)
        str[i + 1] = str[i];
    str[0] = '0';
}

static void strlshift(char str[], ssize_t shamt) {
    for (; shamt; --shamt)
        __strlshift(str);
}

static void strsum(char sum[], char num1[], char num2[]) {
    ssize_t i, len1, len2;
    int8_t carry, tmp;
    
    len1 = (ssize_t)strlen(num1);
    len2 = (ssize_t)strlen(num2);
    
    if (len1 > len2) {
        strlshift(num2, len1 - len2);
        len2 = len1;
    } else {
        strlshift(num1, len2 - len1);
        len1 = len2;
    }
    
    i = len1 - 1;
    carry = 0;
    while (i >= 0) {
        tmp = TO_DIGIT(num1[i]) + TO_DIGIT(num2[i]) + carry;
        
        if (tmp >= 10) {
            tmp -= 10;
            carry = 1;
        } else {
            carry = 0;
        }
        
        sum[i] = TO_CHAR(tmp);
        --i;
    }
    
    if (carry) {
        strlshift(sum, 1);
        sum[0] = '1';
    }
}

int main(int argc, const char *argv[]) {
    char num1[MAX_NUMLEN], num2[MAX_NUMLEN], sum[MAX_SUMLEN];
    
    scanf("%s", num1);
    scanf("%s", num2);
    
    memset(sum, 0, sizeof(sum));
    strsum(sum, num1, num2);
    
    printf("%s\n", sum);
    
    return 0;
}
