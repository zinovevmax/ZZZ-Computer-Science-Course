#include <stdint.h>
#include <stdio.h>

const int64_t INPUT_NUMBER = -9223;
const int32_t TEN = 10;
const int64_t MINUS_ONE = -1;

int Abs(int64_t num) {
    return (num >= 0) ? num : num * MINUS_ONE;
}

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
    // write your solution here
    int32_t count_of_index = 0;
    int64_t input_number = INPUT_NUMBER;
    while (input_number) {
        input_number /= TEN;
        ++count_of_index;
    }
    input_number = INPUT_NUMBER;
    for (uint16_t k = count_of_index; k >= 1; --k) {
        if (k == count_of_index && input_number < 0) {
            int64_t digit = (input_number / (Power(TEN, (k - 1))) % Power(TEN, 1));
            if (digit % 2 == 0 && digit != 0) {
                ++digit;
            }
            printf("%ld", digit);
        } else {
            int64_t digit = Abs((input_number / (Power(TEN, (k - 1))) % Power(TEN, 1)));
            if (digit % 2 == 0 && digit != 0) {
                --digit;
            }
            printf("%ld", digit);
        }
    }
    return 0;
}
