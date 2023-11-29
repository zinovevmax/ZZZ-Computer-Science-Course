#pragma once

#include <stdint.h>
#include <stdio.h>

const uint64_t NUMBER_10 = 10;
const uint64_t NUMBER_100 = 100;
const uint64_t NUMBER_1000 = 1000;

int Task() {
    int flag = 0;
    uint64_t number = 358325775252;
    uint64_t first_number = 0;
    uint64_t second_number = 0;
    uint64_t third_number = 0;

    while (number >= NUMBER_100) {
        first_number = number % NUMBER_10;
        second_number = number % NUMBER_100 / NUMBER_10;
        third_number = number % NUMBER_1000 / NUMBER_100;

        if (first_number == second_number + third_number) {
            printf("%d\n", first_number);
            flag = 1;
        }

        number /= NUMBER_10;
    }

    if (flag == 0) {
        printf("There are no numbers that satisfy the condition");
    }

    return 0;
}
