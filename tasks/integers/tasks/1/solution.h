#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

const int64_t NUMBER = 111;  // write the number here

int Figures(int y) {
    int z = 0;
    while (y > 0) {
        z += 1;
        y = y / 10;
    }
    return z;
}

int FindLeft(int x) {
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
    int32_t number = NUMBER;
    int32_t figures = 0;
    int32_t step = 1;
    int64_t left = 0;
    int64_t right = 0;
    figures = Figures(number);
    number = NUMBER;
    while (step != ((figures / 2) + 1)) {
        left = (number / Degree(10, (figures - step))) % 10;
        right = ((number % Degree(10, step)) / FindLeft(step));
        if (left == right) {
            step += 1;
        } else {
            printf("this is not a palindrome\n");
            return 0;
            break;
        }
    }
    printf("this is a palindrome\n");
    return 0;
}
