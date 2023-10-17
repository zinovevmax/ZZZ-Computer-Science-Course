#pragma once

#include <stdint.h>
#include <stdio.h>

int64_t FLAG_ZERO = 0;
int64_t FLAG_ONE = 0;
int64_t FLAG_TWO = 0;
int64_t FLAG_THREE = 0;
int64_t FLAG_FOUR = 0;
int64_t FLAG_FIVE = 0;
int64_t FLAG_SIX = 0;
int64_t FLAG_SEVEN = 0;
int64_t FLAG_EIGTH = 0;
int64_t FLAG_NINE = 0;
const int64_t TEN = 10;
const int64_t ZERO = 0;
const int64_t ONE = 1;
const int64_t TWO = 2;
const int64_t THREE = 3;
const int64_t FOUR = 4;
const int64_t FIVE = 5;
const int64_t SIX = 6;
const int64_t SEVEN = 7;
const int64_t EIGTH = 8;
const int64_t NINE = 9;
const int64_t INT_INPUT = 3251647809;

int64_t Search(int64_t a) {
    do {
        if (a % TEN == ZERO)
            ++FLAG_ZERO;
        if (a % TEN == ONE)
            ++FLAG_ONE;
        if (a % TEN == TWO)
            ++FLAG_TWO;
        if (a % TEN == THREE)
            ++FLAG_THREE;
        if (a % TEN == FOUR)
            ++FLAG_FOUR;
        if (a % TEN == FIVE)
            ++FLAG_FIVE;
        if (a % TEN == SIX)
            ++FLAG_SIX;
        if (a % TEN == SEVEN)
            ++FLAG_SEVEN;
        if (a % TEN == EIGTH)
            ++FLAG_EIGTH;
        if (a % TEN == NINE)
            ++FLAG_NINE;
        a = a / TEN;
    } while (a * TEN / TEN > ZERO);
    if (FLAG_ZERO == ZERO || FLAG_ONE == ZERO || FLAG_TWO == ZERO || FLAG_THREE == ZERO || FLAG_FOUR == ZERO ||
        FLAG_FIVE == ZERO || FLAG_SIX == ZERO || FLAG_SEVEN == ZERO || FLAG_EIGTH == ZERO || FLAG_NINE == ZERO) {
        return 0;
    } else {
        return 1;
    }
}

int Task() {
    int64_t num = INT_INPUT;
    // scanf("%ld", &num);
    if (Search(num) == ZERO)
        printf("There are numbers that do not occur even once");
    else
        printf("There are no numbers that do not occur once");
    return 0;
}
