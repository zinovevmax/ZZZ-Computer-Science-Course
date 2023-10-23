#include <stdint.h>
#include <stdio.h>

const int64_t TEN = 10;
const int64_t INT_INPUT = 325167809;

int64_t Search(int64_t a) {
    int arr[10] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    int temps[10] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
    int temps_size = 10;
    do {
        ++temps[a % 10];
        a = a / TEN;
    } while (a > 0);
    for (int k = 0; k < temps_size; ++k) {
        if (!temps[k]) return 0;
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
