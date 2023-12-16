#pragma once

#include <float.h>
#include <math.h>
#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>

long double CalculateFunction(long double x) {
    return (1 + 2 * pow(x, 2)) * exp(pow(x, 2));
}

long double CalculateSeriesTerm(int n, long double x) {
    long double numerator = 2 * n + 1;
    long double denominator = 1;
    for (int i = 1; i <= n; i++) {
        denominator *= i;
    }
    long double power = pow(x, 2 * n);
    long double term = numerator / denominator * power;
    return term;
}

bool ShouldBreakCalculation(long double x, long double taylor_result, int precision) {
    long double epsilon = DBL_EPSILON * precision;
    long double diff = taylor_result - CalculateFunction(x);
    if (diff < 0) {
        diff = -diff;
    }
    return diff < epsilon;
}

long double CalculateTaylorResult(long double x, int iterations, int precision, int* num_teylor_iterations) {
    *num_teylor_iterations = 0;
    long double result = 0.0;
    for (int i = 0; i < iterations; ++i) {
        ++(*num_teylor_iterations);
        result += CalculateSeriesTerm(i, x);
        if (ShouldBreakCalculation(x, result, precision)) {
            break;
        }
    }
    return result;
}

void PrintTableHeader() {
    printf(" ----------------------------------------------------\n");
    printf("|    x   |   Taylor Series |     Function    | Iters \n");
    printf("---------+-----------------+-----------------+-------\n");
}

void PrintTable(long double x, long double taylor_result, long double function_result, int num_teylor_iterations) {
    printf("| %.6Lf | %.20Lf | %.20Lf | %4d \n", x, taylor_result, function_result, num_teylor_iterations);
}

int Task() {
    int precision = 80;
    int num_teylor_iterations = 0;
    const int n = 10;
    const int iterations_for_taylor = 100;
    const long double a = 0.0;
    const long double b = 1.0;

    long double step = (b - a) / n;
    long double x = a;

    long double taylor_result = 0.0;

    PrintTableHeader();

    for (int i = 0; i <= n; ++i) {
        taylor_result = CalculateTaylorResult(x, iterations_for_taylor, precision, &num_teylor_iterations);
        PrintTable(x, taylor_result, CalculateFunction(x), num_teylor_iterations);
        x += step;
    }

    return 0;
}
