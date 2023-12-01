#pragma once

#include <float.h>
#include <math.h>
#include <stdint.h>
#include <stdio.h>

long double Func(long double x) {
    return (exp(x) - exp(-x)) / 2;
}

int Task() {
    double a = 0.0;
    double b = 1.0;
    int32_t n = 6;
    int32_t k = 100;
    int32_t count_iterations = 0;
    long double factorial = 0;
    long double row_of_taylor = 0;

    if (n <= 1 || k <= 1 || k > 100) {
        printf("Incorrect values have been entered.");
    } else {
        // printing table
        printf("-----------------------------------------------------------------\n");
        printf("|     X     |       Taylor      |      Function     | Iteration |\n");
        printf("-----------------------------------------------------------------\n");
        long double step = (b - a) / (double)(n - 1);
        long double x = a;
        for (int i = 0; i < n; ++i) {
            factorial = 1.0;
            count_iterations = 0;
            row_of_taylor = 0;
            for (int j = 1; j <= k; ++j) {
                factorial = factorial * j;
                if (j % 2 != 0 && j <= (2 * n - 1)) {
                    row_of_taylor = row_of_taylor + pow(x, j) / factorial;
                    count_iterations = count_iterations + 1;
                }
            }
            printf("| %.7Lf | %.15Lf | %.15Lf | %.9d |\n", x, row_of_taylor, Func(x), count_iterations);
            x = x + step;
            printf("-----------------------------------------------------------------\n");
        }
    }
    return 0;
}