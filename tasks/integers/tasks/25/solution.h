#include <stdint.h>
#include <stdio.h>

const int64_t INPUT_NUMBER = -402345;
const int32_t TEN = 10;

// Function of exponentiation
int Power(int32_t start_number, uint32_t degree) {
    uint32_t i = 0;
    int32_t result = 1;
    for (i = 1; i <= degree; ++i) {
        result *= start_number;
    }
    return result;
}

int Task() {
    int32_t count_of_index = 0;
    int64_t input_number = INPUT_NUMBER;
    while (input_number) {
        input_number /= TEN;
        ++count_of_index;
    }
    input_number = INPUT_NUMBER;
    if (INPUT_NUMBER >= 0) {
        for (uint16_t k = count_of_index; k >= 1; --k) {
            int64_t digit = (input_number / (Power(TEN, (k - 1))) % Power(TEN, 1));
            if (digit % 2 == 0 && digit != 0) {
                --digit;
            }
            printf("%ld", digit);
        }
    } else {
        for (uint16_t k = count_of_index; k >= 1; --k) {
            if (k == count) {
                int64_t digit = (input_number / (Power(TEN, (k - 1))) % Power(TEN, 1));
                if (digit % 2 == 0 && digit != 0) {
                    ++digit;
                }
                printf("%ld", digit);
            } else {
                int64_t digit = -(input_number / (Power(TEN, (k - 1))) % Power(TEN, 1));
                if (digit % 2 == 0 && digit != 0) {
                    --digit;
                }
                printf("%ld", digit);
            }
        }
    }
    return 0;
}
