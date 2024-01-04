#pragma once

#include <stdint.h>
#include <stdio.h>

int Task() {
    uint32_t number = 0;
    scanf("%u", &number);
    uint32_t first_digit = 10;
    uint32_t length_counter = 10;
    while (first_digit > 9) {
        first_digit = number / length_counter;
        length_counter *= 10;
    }
    length_counter = length_counter / 10;
    uint32_t last_digit = number % 10;
    uint32_t new_number = last_digit * length_counter + ((number % length_counter) / 10) * 10 + first_digit;
    if (length_counter == 1) {
        new_number = new_number / 2;
    }
    printf("%u", new_number);
    return 0;
}
