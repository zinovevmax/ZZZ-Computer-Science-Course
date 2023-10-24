#pragma once

#include <stdint.h>
#include <stdio.h>

// some black magic (*^.^*)
const int64_t MAGIC_HUNNID = 100;
const int64_t MAGIC_TEN = 10;

int64_t Abs(int64_t a) {
    return (a >= 0) ? a : -a;
}

int Task() {
    int64_t number = 0;
    scanf("%d", &number);
    int64_t first_val = 0;
    int64_t difference = 0;
    while (number >= MAGIC_HUNNID) {
        first_val = number % MAGIC_TEN;
        difference = Abs((number / MAGIC_HUNNID % MAGIC_TEN) - (number % MAGIC_HUNNID / MAGIC_TEN));
        if (first_val == difference) {
            printf("%lu %lu %lu\n", (number / MAGIC_HUNNID % MAGIC_TEN), (number % MAGIC_HUNNID / MAGIC_TEN),
                   first_val);
        }
        number = number / MAGIC_TEN;
    }
    return 0;
}