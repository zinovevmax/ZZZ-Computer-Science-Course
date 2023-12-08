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

double Func(double x) {
    double y = sin(x) * sin(x);
    return y;
}

double FirstFactor(uint32_t iteration) {
    if (iteration % 2 == 0) {
        return -1.0;
    } else {
        return 1.0;
    }
}

double Numerator(uint32_t iteration, double x) {
    return (pow(2.0, (double)(2u * iteration - 1u))) * pow(x, (double)(2u * iteration));
}

double Denumerator(uint32_t iteration) {
    return (double)Factorial(2u * iteration);
}

double Taylor(double x, uint32_t iterations, double y_func) {
    double y = 0;
    iterations = 0u;
    // double rate = 0.00000001;
    // printf("Lf epsilon = %.50f\n", EPSILON);
    printf("Lf epsilon = %.50Lf\n", LDBL_EPSILON);
    printf("lf epsilon = %.50lf\n", DBL_EPSILON);
    printf("f epsilon  = %.50f\n", FLT_EPSILON);
    // printf("set rate   = %.25lf\n", rate);
    for (uint32_t iteration = 1u; iteration < 100; ++iteration) {
        ++iterations;
        y += FirstFactor(iteration) * Numerator(iteration, x) / Denumerator(iteration);
        printf("difference:  %.25lf     ", abs(y_func - y));
        printf("taylor = %lf     sin = %lf\n", y, y_func);
        if (abs(y_func - y) < DBL_EPSILON) {
            break;
        }
        if (abs(y) > 100.0) {
            break;
        }
    }
    printf("iterations = %u\n", iterations);
    return y;
}

int Task() {
    uint32_t iterations = 0u;
    double x = 0.5;
    double y_func = Func(x);
    double y_taylor = Taylor(x, iterations, y_func);
    printf("Sin(x)^2:            %.25lf\n", y_func);
    printf("Значение по тейлору: %.25lf\n", y_taylor);
    // printf("Количество итераций: %u\n", iterations);
    return 0;
}