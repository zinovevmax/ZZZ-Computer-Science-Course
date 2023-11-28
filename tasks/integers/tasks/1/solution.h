#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

const int64_t NUMBER = 42352356;  // write the number here

int divis(int x) {
    if ((x - 1) == 0) {
        return 1;
    } else {
        return degree(10, (x - 1));
    }
}

int degree(int a, int b) {
    int varible = a;
    b -= 1;
    while (b > 0) {
        a = a * varible;
        b -= 1;
    }
    return a;
}

int test() {
    int64_t number = NUMBER;
    int32_t figurs = 0;
    int32_t step = 1;
    int8_t left;
    int8_t right;
    int8_t answer = 0;
    while (number > 0) {
        figurs += 1;
        number = number / 10;
    }
    number = NUMBER;
    while (step != ((figurs / 2) + 1)) {
        left = (number / degree(10, (figurs - step))) % 10;
        right = ((number % degree(10, step)) / divis(step));
        if (left == right) {
            step += 1;
        } else {
            printf("this is not a palindrome\n");
            answer += 1;
            break;
        }
    }
    if (answer == 0) {
        printf("this is a palindrome\n");
    }
    return 0;
}
