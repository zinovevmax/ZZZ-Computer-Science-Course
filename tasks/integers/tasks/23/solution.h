#pragma once

#include <stdint.h>
#include <stdio.h>

const uint8_t magic_10 = 10;
const uint8_t magic_1 = 1;
const uint8_t magic_2 = 2;
const uint8_t magic_0 = 0;

uint8_t Count_razr(uint64_t number) {
    uint8_t count = magic_0;
    while (number > 0) {
        ++count;
        number /= magic_10;
    }
    return count;
}

int64_t Pow(uint8_t first, uint8_t second) {
    int temp = magic_1;
    if (second == magic_0) {
        return 1;
    }
    while (second > magic_0) {
        temp *= first;
        --second;
    }
    return temp;
}

int main() {
    uint64_t number = 0;
    scanf("%lu", &number);
    uint8_t rz = number % magic_10;
    uint8_t temp = Count_razr(number);
    uint8_t temp_copy = temp;
    while (temp > magic_1) {
        uint8_t rezult = number / Pow(magic_10, temp - magic_1);
        printf("%u", rezult);
        number %= Pow(magic_10, temp - magic_2);
        temp -= magic_2;
    }
    if (temp_copy % magic_2 != 0) {
        printf("%u", rz);
    }
    return 0;
}
