#include <stdio.h>
#include <stdint.h>

const int32_t TEN = 10;
const int32_t ZERO = 0;

int32_t MaxSum(int32_t num) {
    int32_t max_sum = ZERO;
    int32_t current_sum = ZERO;

    int32_t first_digit = num % TEN;
    num /= TEN;
    int32_t second_digit = num % TEN;
    num /= TEN;

    while (num > ZERO) {
        int32_t third_digit = num % TEN;

        current_sum = first_digit + second_digit + third_digit;
        if (current_sum > max_sum) {
            max_sum = current_sum;
        }

        first_digit = second_digit;
        second_digit = third_digit;
        num /= TEN;
    }

    return max_sum;
}

int Task() {
    int32_t num = 0;
    printf("Enter a number: ");
    scanf("%d", &num);

    int32_t max_sum = MaxSum(num);
    printf("Maximum sum of triplets: %d\n", max_sum);

    return 0;
}
