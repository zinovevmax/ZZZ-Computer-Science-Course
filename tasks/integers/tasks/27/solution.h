#pragma once

#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

const int64_t MAGIC_HUNDRED = 100;
const int64_t NUMBER = 21356789;
const int64_t MAGIC_TEN = 10;

int Task() {
    int64_t number = NUMBER;
    int64_t first_num = 0;
    int64_t second_num = 0;
    int64_t third_num = 0;
    int stop = 1;
    while (stop <= number) {
        stop *= MAGIC_TEN;
    }
    stop /= MAGIC_TEN;
    for (int i = stop; i >= MAGIC_TEN; i /= MAGIC_HUNDRED) {
        first_num = (number / i) % MAGIC_TEN;
        second_num = (number / (i / MAGIC_TEN)) % MAGIC_TEN;
        third_num = abs(first_num - second_num);
        printf("%lu%lu%lu", first_num, second_num, third_num);
    }
    return 0;
}