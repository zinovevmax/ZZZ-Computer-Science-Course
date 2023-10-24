#pragma once

#include <stdint.h>
#include <stdio.h>

int64_t Abs(int64_t a) {
    return (a >= 0) ? a : -a;
} 

int Task() {
    int64_t number;
    scanf("%lu", &number);
    
    int64_t first_val;
    int64_t difference;

    while (number >= 100) {
        first_val = number % 10;
        difference = Abs((number / 100 % 10) - (number % 100 / 10));
        if (first_val == difference) {
            printf("%lu %lu %lu\n", (number / 100 % 10), (number % 100 / 10), first_val);
        }
        number = number / 10;
    }
    return 0;
}