#pragma once

#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

const int64_t BASE = 10;
const int64_t EXAMPLE = 1234;

int Task() {
    // write your solution here
    int64_t number_with_znak = EXAMPLE;
    int64_t znak = 0;
    if (number_with_znak < 0) {
        znak = -1;
    } else {
        znak = 1;
    }
    int64_t number = abs(EXAMPLE);
    int64_t copy_number = abs(EXAMPLE);
    int64_t second = 0;
    int64_t penultimate = (number / BASE) % BASE;
    int64_t n = 1;
    while (copy_number > BASE) {
        second = copy_number % BASE;
        copy_number = copy_number / BASE;
        n = n * BASE;
    }
    n = n / BASE;
    int64_t new_number = (number - second * n - penultimate * BASE + penultimate * n + second * BASE) * znak;
    printf("%ld/n", new_number);
    return 0;
}