#pragma once

#include <stdint.h>
#include <stdio.h>

const uint8_t MAGIC_10 = 10;
const uint8_t MAGIC_1 = 1;
const uint8_t MAGIC_2 = 2;
const uint8_t MAGIC_0 = 0;

uint8_t CountRazr(uint64_t number) {
    uint8_t count = MAGIC_0;
    while (number > 0) {
        ++count;
        number /= MAGIC_10;
    }
    return count;
}

int64_t Pow(uint8_t first, uint8_t second) {
    int temp = MAGIC_1;
    if (second == MAGIC_0) {
        return 1;
    }
    while (second > MAGIC_0) {
        temp *= first;
        --second;
    }
    return temp;
}

int Task() {
    uint64_t number = 0;
    scanf("%lu", &number);
    uint8_t rz = number % MAGIC_10;
    uint8_t temp = CountRazr(number);
    uint8_t temp_copy = temp;
    while (temp > MAGIC_1) {
        uint8_t rezult = number / Pow(MAGIC_10, temp - MAGIC_1);
        printf("%u", rezult);
        number %= Pow(MAGIC_10, temp - MAGIC_2);
        temp -= MAGIC_2;
    }
    if (temp_copy % MAGIC_2 != 0) {
        printf("%u", rz);
    }
    return 0;
}
