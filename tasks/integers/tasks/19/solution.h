#pragma once

#include <stdint.h>
#include <stdio.h>

const int64_t NUMBER = 15551;  // comment this line
const int64_t TEN = 10;

int64_t IsLessThenTwoDigits(int64_t num) {
    if (num < TEN) {
        printf("%ld\n", num);
        return 0;
    }
    return 1;
}

int Abs(int64_t x) {
    if (x > 0) {
        return x;
    } else {
        return x * (-1);
    }
}

int Task() {
    // scanf("%ld", &number); // uncomment this line
    int64_t number = Abs(NUMBER);  // comment this line

    if (IsLessThenTwoDigits(number) == 0) {
        return 0;  // Числа до трех разрядов без изменений
    }

    // Отсекаем последнюю цифру
    number /= TEN;

    // Отсекаем первую цифру
    int64_t number_of_digits = 1;
    while (number / (number_of_digits * TEN) > 0) {
        number_of_digits *= TEN;
    }
    number %= number_of_digits;

    printf("%ld\n", number);

    return 0;
}
