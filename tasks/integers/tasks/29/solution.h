#pragma once

#include <stdint.h>
#include <stdio.h>

int SquareOfTen(int cycle_counter) {
    int result_of_function = 1;
    for (size_t degree_counter = 1; degree_counter <= cycle_counter; ++degree_counter) {
        result_of_function = result_of_function * 10;
    }
    return result_of_function;
}

int ConvertFromDecimalToOctal(int input_number) {
    int output_number = 0;
    int cycle_counter = 0;
    while (input_number > 0) {
        output_number += (input_number % 8) * SquareOfTen(cycle_counter);
        ++cycle_counter;
        input_number /= 8;
    }
    return output_number;
}

int Task() {
    uint64_t input_number = 3456748945;  // input number here
    uint64_t result = ConvertFromDecimalToOctal(input_number);
    printf("The result: %u\n", result);
    return 0;
}