#pragma once

#include <stdint.h>
#include <stdio.h>

const uint8_t TEN = 10;
const uint8_t EIGHT = 8;

int SquareOfTen(uint8_t TEN, uint32_t cycle_counter) {
    uint32_t result_of_function = 1;
    for (size_t degree_counter = 1; degree_counter <= cycle_counter; ++degree_counter) {
        result_of_function = result_of_function * TEN;
    }
    return result_of_function;
}

int Mod(uint32_t input_number, uint8_t EIGHT) {
    return input_number % EIGHT;
}

int ConvertFromDecimalToOctal(uint32_t input_number) {
    uint32_t output_number = 0;
    uint32_t cycle_counter = 0;
    while (input_number > 0) {
        output_number += Mod(input_number, EIGHT) * SquareOfTen(TEN, cycle_counter);
        ++cycle_counter;
        input_number /= EIGHT;
    }
    return output_number;
}
int Task() {
    uint32_t input_number = 0;
    printf("Enter a number:\n");
    scanf("%lu", &input_number);
    int result = ConvertFromDecimalToOctal(input_number);
    printf("The result: %d\n", result);
    return 0;
}