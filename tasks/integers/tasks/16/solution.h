#pragma once

#include <stdint.h>
#include <stdio.h>

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
    int64_t flag_zero = 0;
    int64_t flag_one = 0;
    int64_t flag_two = 0;
    int64_t flag_three = 0;
    int64_t flag_four = 0;
    int64_t flag_five = 0;
    int64_t flag_six = 0;
    int64_t flag_seven = 0;
    int64_t flag_eight = 0;
    int64_t flag_nine = 0;
    do {
        if (a % TEN == ZERO) {
            ++flag_zero;
        }
        if (a % TEN == ONE) {
            ++flag_one;
        }
        if (a % TEN == TWO) {
            ++flag_two;
        }
        if (a % TEN == THREE) {
            ++flag_three;
        }
        if (a % TEN == FOUR) {
            ++flag_four;
        }
        if (a % TEN == FIVE) {
            ++flag_five;
        }
        if (a % TEN == SIX) {
            ++flag_six;
        }
        if (a % TEN == SEVEN) {
            ++flag_seven;
        }
        if (a % TEN == EIGTH) {
            ++flag_eight;
        }
        if (a % TEN == NINE) [
            ++flag_nine;
        }
        a = a / TEN;
    } while (a * TEN / TEN > ZERO);
    if (flag_zero == ZERO || flag_one == ZERO || flag_two == ZERO || flag_three == ZERO || flag_four == ZERO ||
        flag_five == ZERO || flag_six == ZERO || flag_seven == ZERO || flag_eight == ZERO || flag_nine == ZERO) {
        return 0;
    } else {
        return 1;
    }
}

int Task() {
    int64_t num = INT_INPUT;
    // scanf("%ld", &num);
    if (Search(num) == ZERO) {
        printf("There are numbers that do not occur even once");
    } else {
        printf("There are no numbers that do not occur once");
    }
    return 0;
}
