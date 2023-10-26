#pragma once

#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

// some black magic (*^.^*)
const int64_t MAGIC_HUNNID = 100;
const int64_t MAGIC_TEN = 10;

int Task() {
    int64_t number = 0;
    scanf("%ld", &number);
    number = abs(number);
    int64_t digit = 0;
    int64_t difference = 0;
    while (number >= MAGIC_HUNNID) {
        digit = number % MAGIC_TEN;
        difference = abs((number / MAGIC_HUNNID % MAGIC_TEN) - (number % MAGIC_HUNNID / MAGIC_TEN));
        if (digit == difference) {
            printf("%lu %lu %lu\n", (number / MAGIC_HUNNID % MAGIC_TEN), (number % MAGIC_HUNNID / MAGIC_TEN), digit);
        }
        number = number / MAGIC_TEN;
    }
    return 0;
}