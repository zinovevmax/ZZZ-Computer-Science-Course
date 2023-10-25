#pragma once

#include <stdint.h>
#include <stdio.h>

const int64_t NUMBER = 15551;  // comment this line
const int64_t TEN = 10;

int Task() {
    // scanf("%ld", &number); // uncomment this line
    int64_t number = NUMBER;  // comment this line

    if (number < 0) {
        number = -number;  // Обработка отрицательных чисел
    }

    if (number < TEN) {
        printf("%ld\n", number);
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
