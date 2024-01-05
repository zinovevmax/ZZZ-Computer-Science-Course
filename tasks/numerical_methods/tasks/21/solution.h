#pragma once

#include <float.h>
#include <math.h>
#include <stdint.h>
#include <stdio.h>

const int32_t MAX_ITERATIONS = 100;

double DichotomyFunc(double x) {
    return (tan(x) - (1.0 / 3.0) * pow(tan(x), 3) + (1.0 / 5.0) * pow(tan(x), 5) - (1.0 / 3.0));
}

double DichotomyMethod(double x0, double x1, double (*func)(double)) {
    double mid = 0.0;
    for (int32_t i = 0; i < MAX_ITERATIONS; ++i) {
        if (fabs(x1 - x0) >= DBL_EPSILON) {
            mid = (x1 - x0) / 2.0;
            if (func(x0) * func(mid) < 0.0) {
                x1 = mid;
            } else {
                x0 = mid;
            }
        }
    }
    return x0;
}

double IterationMethod(double x0, double x1, double (*func)(double)) {
    double prev_x = 0.0;
    double approximation = (x0 + x1) / 2;
    while (fabs(approximation - prev_x) >= DBL_EPSILON) {
        prev_x = approximation;
        approximation = func(prev_x);
    }
    return approximation;
}

double Phi(double x) {
    return cos(sqrt(1 - 0.3 * pow(x, 3)));
}

int Task() {
    double dichotomy_result = DichotomyMethod(0, 0.8, DichotomyFunc);
    double iteration_result = IterationMethod(0.0, 1.0, Phi);
    printf("--------------------------------------------------\n");
    printf("|  Method           |   Result   | Approximation |\n");
    printf("==================================================\n");
    printf("| Dichotomy method  | %10.8lf | 0.3333        |\n", dichotomy_result);
    printf("| Iteration method  | %10.8lf | 0.5629        |\n", iteration_result);
    printf("==================================================\n");

    return 0;
}