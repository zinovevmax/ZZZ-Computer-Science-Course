#pragma once

#include <float.h>
#include <math.h>
#include <stdint.h>
#include <stdio.h>

const double PRECISION = LDBL_EPSILON;
const int32_t MAX_ITERATIONS = 100;
const double N = 10.0;
const double K = 10.0;

long double Func(long double x) {
    return (1 + x) * exp(-x);
}

long double Factorial(int32_t x) {
    if (x == 0 || x == 1) {
        return 1.0;
    }
    return x * Factorial(x - 1);
}

long double Taylor(long double x, int32_t* counter) {
    long double taylor_result = 1.0;
    long double temp_value = 0.0;
    int32_t i = 0;
    while (i < MAX_ITERATIONS && fabsl(Func(x) - taylor_result) >= PRECISION * K) {
        temp_value = ((i + 1) * pow(x, i + 2)) / Factorial(i + 2);
        if (i % 2 == 0) {
            taylor_result -= temp_value;
        } else {
            taylor_result += temp_value;
        }
        ++i;
    }
    *counter = i;
    return taylor_result;
}

void PrintStartRow() {
    printf("------------------------------------------------------------------\n");
    printf("|   X   |    Taylor Series    |      Function       | Iterations |\n");
    printf("------------------------------------------------------------------\n");
}

void PrintTableRow(long double x, long double taylor, long double func, int iter) {
    printf("| %5.2Lf | %19.15Lf | %19.15Lf | %10d |\n", x, taylor, func, iter);
}

int Task() {
    const long double a = 0.0;
    const long double b = 1.0;
    const long double step = (b - a) / N;
    PrintStartRow();

    int32_t iterations = 0;
    long double taylor_result = 0;
    long double func_result = 0;

    for (long double x = a; x <= b + PRECISION; x += step) {
        iterations = 0;
        taylor_result = Taylor(x, &iterations);
        func_result = Func(x);

        PrintTableRow(x, taylor_result, func_result, iterations);
    }
    printf("------------------------------------------------------------------");
    return 0;
}