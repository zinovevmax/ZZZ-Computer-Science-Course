#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

const int64_t NUMBER = 42352356;  // write the number here

int Divis(int x) {
    if ((x - 1) == 0) {
        return 1;
    } else {
        int a = 10;
        int b = (x - 1);
        int varible_1 = a;
        b -= 1;
        while (b > 0) {
            a = a * varible_1;
            b -= 1;
        }
        return a;
    }
}

int Degree(int a, int b) {
    int varible = a;
    b -= 1;
    while (b > 0) {
        a = a * varible;
        b -= 1;
    }
    return a;
}

int Task() {
    int64_t number = NUMBER;
    int32_t figurs = 0;
    int32_t step = 1;
    int64_t left = 0;
    int64_t right = 0;
    int8_t answer = 0;
    while (number > 0) {
        figurs += 1;
        number = number / 10;
    }
    number = NUMBER;
    while (step != ((figurs / 2) + 1)) {
        left = (number / Degree(10, (figurs - step))) % 10;
        right = ((number % Degree(10, step)) / Divis(step));
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
