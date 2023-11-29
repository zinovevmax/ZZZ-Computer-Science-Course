#pragma once

#include <stdint.h>
#include <stdio.h>

int Task() {
    int flag = 0;
    uint64_t number = 358325775252;
    uint64_t first_number = 0;
    uint64_t second_number = 0;
    uint64_t third_number = 0;  

    while (number >= 100) {
        first_number = number % 10;
        second_number = number % 100 / 10;
        third_number = number % 1000 / 100;

        if (first_number == second_number + third_number) {
            printf("%d\n", first_number);
            flag = 1;
        }

        number /= 10;
    }

    if (flag == 0) {
        printf("There are no numbers that satisfy the condition");
    }

    return 0;
}
