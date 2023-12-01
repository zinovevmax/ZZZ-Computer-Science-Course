#pragma once

#include <stdint.h>
#include <stdio.h>

int Task() {
    int number = 0;
    scanf("%d", &number);
    int big_number = 10;
    int length_counter = 10;
    while (big_number > 9) {
        big_number = number / length_counter;
        length_counter *= 10;
    }
    int small_number = number % 10;
    int new_number = small_number * length_counter + ((number % length_counter) / 10) * 10 + big_number;
    printf("%p", (void*)&new_number);
    return 0;
}