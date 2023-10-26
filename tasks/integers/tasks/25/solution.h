#pragma once

#include <stdint.h>
#include <stdio.h>

const int64_t INPUT_NUMBER = 12345;
const int8_t ONE = 1;
const int32_t TEN = 10;

// Function of exponentiation
int Power(int32_t start_number, int32_t degree) {
    int32_t i = 0;
    int32_t result = 1;
    for (i = 1; i <= degree; ++i) {
        result *= start_number;
    }
    return result;
}

int Task() {
    int32_t count = 0;
    int64_t number = INPUT_NUMBER;
    while (number) {
        number /= TEN;
        ++count;
    }
    number = INPUT_NUMBER;
    if (INPUT_NUMBER >= 0) {
        for (uint16_t k = count; k >= ONE; --k) {
        int64_t digit_number = (number / (Power(TEN, (k - 1))) % Power(TEN, 1));
        if (digit_number % 2 == 0) {
            --digit_number;
        }
            printf("%ld", digit_number);
        }
    } else {
        printf("%s", "-");
        for (uint16_t k = count; k >= ONE; --k) {
        int64_t digit_number = -(number / (Power(TEN, (k - 1))) % Power(TEN, 1));
        if (digit_number % 2 == 0) {
            --digit_number;
        }
            printf("%ld", digit_number);
        }
    }
    return 0;
}
