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
    int a, b, c;
    
    scanf("%d %d %d", &a, &b, &c);
    printf("%d\n", (a + b) % c);
    printf("%d\n", ((a % c) + (b % c)) % c);
    printf("%d\n", (a * b) % c);
    printf("%d\n", ((a % c) * (b % c)) % c);
    
    return 0;
}
