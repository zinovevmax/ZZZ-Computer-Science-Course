#pragma once

#include <float.h>
#include <math.h>
#include <stdint.h>
#include <stdio.h>

uint32_t Factorial(uint32_t n) {
    uint32_t fact = 1u;
    for (uint32_t i = 1u; i < n + 1u; ++i) {
        fact *= i;
    }
    return fact;
}

long double Func(long double x) {
    long double y = sin(x) * sin(x);
    return y;
}

long double FirstFactor(uint32_t iteration) {
    return pow(-1.0, (long double)(iteration - 1));
}

long double Numerator(uint32_t iteration, long double x) {
    return (pow(2.0, (long double)(2u * iteration - 1u))) * pow(x, (long double)(2u * iteration));
}

long double Denumerator(uint32_t iteration) {
    return (double)Factorial(2u * iteration);
}

long double Taylor(long double x, uint32_t iterations, long double y_func) {
    long double y = 0;
    iterations = 0u;
    long double rate = 0.0000001;
    printf("Lf epsilon = %.25Lf\n", LDBL_EPSILON);
    printf("lf epsilon = %.25lf\n", DBL_EPSILON);
    printf("f epsilon  = %.25f\n", FLT_EPSILON);
    printf("set rate   = %.25Lf\n", rate);
    for (uint32_t iteration = 1u; iteration < 100; ++iteration) {
        ++iterations;
        y += FirstFactor(iteration) * Numerator(iteration, x) / Denumerator(iteration);
        printf("difference:  %.25Lf     ", abs(y_func - y));
        printf("taylor = %Lf     sin = %Lf\n", y, y_func);
        if (abs(y_func - y) < rate) {
            break;
        }
    }
    printf("iterations = %u\n", iterations);
    return y;
}

int Task() {
    uint32_t iterations = 0u;
    long double x = 1;
    long double y_func = Func(x);
    long double y_taylor = Taylor(x, iterations, y_func);
    printf("Sin(x)^2:            %.25Lf\n", y_func);
    printf("Значение по тейлору: %.25Lf\n", y_taylor);
    printf("Количество итераций: %u\n", iterations);
    return 0;
}