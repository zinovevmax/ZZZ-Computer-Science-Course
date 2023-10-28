#pragma once

#include <stdint.h>
#include <stdio.h>

int Task() {
    int64_t number = 0;
    int64_t reversed_result = 0;
    int64_t result = 0;
    int8_t digit = 0;
    int8_t sign_of_number = 0;
    scanf("%li", &number);
    if (number < 0) {
        sign_of_number = -1;
        number = -number;
    } else if (number > 0) {
        sign_of_number = 1;
    } else {
        printf("%li", number);
        return 0;
    }
    while (number > 0) {
        digit = number % 10;
        number /= 10;
        if (digit % 2 == 0) {
            reversed_result *= 10;
            reversed_result += digit;
        }
    }
    while (reversed_result > 0) {
        digit = reversed_result % 10;
        reversed_result /= 10;
        result *= 10;
        result += digit;
    }
    result = sign_of_number * result;
    printf("%li", result);
    return 0;
}