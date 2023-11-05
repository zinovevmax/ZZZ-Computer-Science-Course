#pragma once

#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

const int64_t BASE = 10;
const int64_t EXAMPLE = 1234;
const int64_t MIN_OR_MAX_INT_WITHOUT_SIGN = 9223372036854775808;

int Task() {
    // write your solution here
    int64_t number_with_sign = EXAMPLE;
    int64_t sign = 0;
    if (number_with_sign < 0) {
        sign = -1;
    } else {
        sign = 1;
    }
    if (EXAMPLE == MIN_OR_MAX_INT_WITHOUT_SIGN) {
        int64_t new_int64_with_permutations = 9023372036854775828;
        printf("%ld\n", new_int64_with_permutations * sign);
    } else {
        int64_t number = abs(EXAMPLE);
        int64_t copy_number = abs(EXAMPLE);
        int64_t second = 0;
        int64_t penultimate = (number / BASE) % BASE;
        int64_t position_of_second = 1;
        while (copy_number > BASE) {
            second = copy_number % BASE;
            copy_number = copy_number / BASE;
            position_of_second = position_of_second * BASE;
        }
        position_of_second = position_of_second / BASE;
        int64_t new_number = (number - second * position_of_second - penultimate * BASE +
                              penultimate * position_of_second + second * BASE) *
                             sign;
        printf("%ld\n", new_number);
    }
    return 0;
}