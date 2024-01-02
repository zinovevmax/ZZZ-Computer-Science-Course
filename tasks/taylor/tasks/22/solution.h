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
        if (i % 2 == 0){
            taylor_result -= temp_value;
        } else {
            taylor_result += temp_value;
        }
        ++i;
    }

    *counter = i;
    return taylor_result;
}

void Print_Start_Row() {
    printf("------------------------------------------------------------------\n");
    printf("|   X   |    Taylor Series    |      Function       | Iterations |\n");
    printf("------------------------------------------------------------------\n");
} 

void Print_Table_Row(long double x, long double taylor, long double func, int iter) {
    printf("| %5.2Lf | %19.15Lf | %19.15Lf | %10d |\n", x, taylor, func, iter);
}

int Task() {
    const long double A = 0.0;
    const long double B = 1.0;
    const long double step = (B - A) / N;
    Print_Start_Row();

    int32_t iterations = 0;
    long double taylor_result = 0;
    long double func_result = 0;


    for(long double x = A; x <= B + PRECISION; x += step) {
        iterations = 0;
        taylor_result = Taylor(x, &iterations);
        func_result = Func(x);

        Print_Table_Row(x, taylor_result, func_result, iterations);
    }
    printf("------------------------------------------------------------------");
    return 0;
}