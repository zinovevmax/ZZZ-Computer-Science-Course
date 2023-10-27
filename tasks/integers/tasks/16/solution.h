#pragma once

#include <stdint.h>
#include <stdio.h>

const int64_t TEN = 10;
const int64_t INT_INPUT = 3425167809;

int64_t Search(int64_t a) {
    int arr[TEN] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
    int arr_size = TEN;
    do {
        ++arr[a % TEN];
        a = a / TEN;
    } while (a > 0);
    for (int k = 0; k < arr_size; ++k) {
        if (!arr[k]) {
            return 0;
        }
    }
    return 1;
}

int Task() {
    int64_t num = INT_INPUT;
    // scanf("%ld", &num);
    if (!Search(num)) {
        printf("There are numbers that do not occur even once");
    } else {
        printf("There are no numbers that do not occur once");
    }
    return 0;
}
