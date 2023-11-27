#pragma once

#include <float.h>
#include <math.h>
#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>

double NatyralLog(double x) {
    return 0.5 * log(x);
}

double Degree(double exp, uint8_t n) {
    double copy_exp = 1.0;
    while (n > 0) {
        copy_exp *= exp;
        --n;
    }
    return copy_exp;
}
double ResultInPoint(double x, uint16_t iterations, uint8_t precision) {
    double result = 0.0;
    for (int i = 0; i < iterations; ++i) {
        result += (double)1 / (2 * i + 1) * Degree((x - 1.0) / (x + 1.0), 2 * i + 1);
        if (fabs(result - NatyralLog(x)) < DBL_EPSILON * precision) {
            break;
        }
    }
    return result;
}
void PrintString(double x, double tailor_result, double func_result) {
    static int iter = 0;
    printf("iter = %d  x = %.2lf Tailor = %.10lf Func = %.10lf\n", iter, x, tailor_result, func_result);
    ++iter;
}

int Task() {
    uint8_t n = 10;
    uint16_t iterations_for_tailor = 100;
    uint8_t precision = 10;
    const double a = 0.2;
    const double b = 0.7;
    double step = (b - a) / n;
    double x = a;
    for (int i = 0; i <= n; ++i) {
        PrintString(x, ResultInPoint(x, iterations_for_tailor, precision), NatyralLog(x));
        x += step;
    }
    return 0;
}