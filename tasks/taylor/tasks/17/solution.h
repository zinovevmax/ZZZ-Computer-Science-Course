#pragma once

#include <float.h>
#include <math.h>
#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>

long double Func(long double x) {
    return 0.5 * log(x);
}

long double Degree(long double exp, uint8_t n) {
    long double res_exp = 1.0;
    while (n > 0) {
        res_exp *= exp;
        --n;
    }
    return res_exp;
}

long double CalcPerIter(long double x, int iter) {
    return (long double)1 / (2 * iter + 1) * Degree((x - 1.0) / (x + 1.0), 2 * iter + 1);
}

bool PositiveCalc(long double x, long double tailor_result, uint8_t precision) {
    return fabsl(tailor_result - Func(x)) < DBL_EPSILON * precision;
}

long double TailorResult(long double x, uint16_t iterations, uint8_t precision) {
    long double result = 0.0;
    for (int i = 0; i < iterations; ++i) {
        result += CalcPerIter(x, i);
        if (PositiveCalc(x, result, precision)) {
            break;
        }
    }
    return result;
}

void PrintTable(long double x, long double tailor_result, long double func_result) {
    static int iter = 0;
    printf("iter = %d  x = %.3Lf Tailor = %.12Lf Func = %.12Lf\n", iter, x, tailor_result, func_result);
    ++iter;
}

int Task() {
    uint8_t precision = 40;
    uint8_t n = 10;
    uint16_t iterations_for_tailor = 100;
    const long double a = 0.2;
    const long double b = 0.7;
    long double step = (b - a) / n;
    long double x = a;
    for (int i = 0; i <= n; ++i) {
        PrintTable(x, TailorResult(x, iterations_for_tailor, precision), Func(x));
        x += step;
    }
    return 0;
}