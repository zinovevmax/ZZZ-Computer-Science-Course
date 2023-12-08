#pragma once

#include <float.h>
#include <math.h>
#include <stdint.h>
#include <stdio.h>

double Func(double x) {
    return sin(x) * sin(x);
}

double Indent(double a, double b, int32_t n) {
    return (b - a) / (double)n;
}

void Taylor(double x, double y_func) {
    double y = 0;
    double previous_y = pow(x, 2.0);
    double new_y = 0;
    int32_t iterations = 1;
    y += previous_y;
    for (int32_t iteration = 2u; iteration < 100; ++iteration) {
        if (abs(y_func - y) < DBL_EPSILON) {
            break;
        }
        ++iterations;
        new_y = previous_y * (double)((-4) * pow(x, 2.0)) / (double)((iteration * 2 - 1) * (iteration * 2));
        y += new_y;
        previous_y = new_y;
    }
    printf("%.25lf     |%i\n", y, iterations);
}

int Task() {
    int32_t n = 10;  // for example
    double a = 0.0;
    double b = 1.0;
    double x = a;
    double indent = Indent(a, b, n);
    printf("x                |func                            |taylor                          |iterations\n");
    for (int32_t k = 0; k < n + 1; ++k) {
        printf("%.10lf     |%.25lf     |", x, Func(x));
        Taylor(x, Func(x));
        x += indent;
    }
    return 0;
}