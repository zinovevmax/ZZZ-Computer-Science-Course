#pragma once

#include <stdint.h>
#include <stdio.h>

const int64_t NUMBER = 15551;  // comment this line

int Task() {
    // scanf("%lld", &number); // uncomment this line
    int64_t number = NUMBER;  // comment this line

    if (number < 0) {
        number = -number;  // Обработка отрицательных чисел
    }

    if (number < 10) {
        printf("%lld\n", number);
        return 0;  // Числа до трех разрядов без изменений
    }

    // Отсекаем последнюю цифру
    number /= 10;

    // Отсекаем первую цифру
    int64_t number_of_digits = 1;
    while (number / (number_of_digits * 10) > 0) {
        number_of_digits *= 10;
    }
    number %= number_of_digits;

    printf("%lld\n", number);

    return 0;
}
