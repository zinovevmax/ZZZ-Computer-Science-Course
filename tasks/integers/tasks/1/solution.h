#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

const int64_t NUMBER = 111;  // write the number here

int find_left(int x) {
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

int main() {
    int64_t number = NUMBER;
    int32_t figures = 0;
    int32_t step = 1;
    int16_t left = 0;
    int16_t right = 0;
    while (number > 0) {
        figures += 1;
        number = number / 10;
    }
    number = NUMBER;
    while (step != ((figures / 2) + 1)) {
        left = (number / Degree(10, (figures - step))) % 10;
        right = ((number % Degree(10, step)) / find_left(step));
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
