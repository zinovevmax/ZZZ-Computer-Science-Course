#pragma once

#include <float.h>
#include <math.h>
#include <stdint.h>
#include <stdio.h>

long double Func(long double x) {
    return exp(cos(x)) * cos(sin(x));
}

int Task() {
    double a = 0.1;
    double b = 0.6;
    int32_t n = 5;
    int32_t k = 100;
    long double factorial = 0;
    long double tailor = 0;
    // scanf("%d %d", &n, &k);

    if (n <= 1 || k <= 1 || k > 100) {
        printf("Incorrect values have been entered.");
    } else {
        // printing the table header
        printf("=======================================\n");
        printf("TABLE FOR n = %d AND k = %d\n", n, k);
        printf("=======================================\n");
        printf("    X    |    Taylor    |   Function\n");
        // calculating values and filling the table with them
        long double step = (b - a) / (double)(n - 1);
        long double x = a;
        for (int i = 0; i < n; ++i) {
            factorial = 1.0;
            tailor = 1.0;
            for (int j = 1; j < k; ++j) {
                factorial *= j;
                tailor += cos(j * x) / factorial;
            }
            printf("%Lf | %.10Lf | %.10Lf\n", x, tailor, Func(x));
            x += step;
        }
    }
    return 0;
}