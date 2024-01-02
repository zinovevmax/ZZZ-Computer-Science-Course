#pragma once

#include <stdint.h>
#include <stdio.h>

uint8_t CountNumbers(uint64_t number) {
    uint8_t count = 0;
    while (number > 0) {
        ++count;
        number /= 10;
    }
    return count;
}

int64_t Pow(uint8_t first, uint8_t second) {
    int temp = 1;
    if (second == 0) {
        return 1;
    }
    while (second > 0) {
        temp *= first;
        --second;
    }
    return temp;
}

int Task() {
    uint64_t number = 0;
    scanf("%lu", &number);
    uint8_t rz = number % 10;
    uint8_t temp = CountNumbers(number);
    uint8_t temp_copy = temp;
    while (temp > 1) {
        uint8_t rezult = number / Pow(10, temp - 1);
        printf("%u", rezult);
        number %= Pow(10, temp - 2);
        temp -= 2;
    }
    if (temp_copy % 2 != 0) {
        printf("%u", rz);
    }
    return 0;
}
