#pragma once

#include <float.h>
#include <math.h>
#include <stdint.h>
#include <stdio.h>

const double ROOT_1 = 2.0267;
const double ROOT_2 = 0.6533;

double FuncIterations(double x) {
    return x * x - log(1 + x) - 3;
}

double FuncNewton(double x) {
    return 2 * x * sin(x) - cos(x);
}

double IterationsMethod(double x_0, double (*func_iterations)(double x)) {
    double x_n = func_iterations(x_0);
    double x_n_plus_1 = func_iterations(x_n);
    while (fabs((x_n_plus_1 - x_n) / (1 - (x_n_plus_1 - x_n) / (x_n - x_0))) >= DBL_EPSILON) {
        x_0 = x_n;
        x_n = x_n_plus_1;
        x_n_plus_1 = func_iterations(x_n_plus_1);
    }
    return x_n;
}

double DerivativeNewton(double x) {
    return 2 * x * cos(x) + 3 * sin(x);
}


double NewtonMethod(double x_0, double (*func_newton)(double x)) {
    double x_n = x_0 - (func_newton(x_0) / DerivativeNewton(x_0));
    double x_n_plus_1 = x_n - (func_newton(x_n) / DerivativeNewton(x_n));
    while (fabs((x_n_plus_1 - x_n) / (1 - (x_n_plus_1 - x_n) / (x_n - x_0))) >= DBL_EPSILON) {
        x_0 = x_n;
        x_n = x_n_plus_1;
        x_n_plus_1 = x_n - (func_newton(x_n) / DerivativeNewton(x_n));
    }
    return x_n;
}

void PrintAnswer(double x, double root) {
    printf("Найденный корень = %lf\nПогрешность = %lf - %lf = %lf\n", x, root, x, fabs(root - x));
}

int Task() {
    // write your solution here
    double beginning_1 = 2;
    double ending_1 = 3;
    double beginning_2 = 0.4;
    double ending_2 = 1;
    double x1 = IterationsMethod((ending_1 + beginning_1) / 2, FuncIterations);
    PrintAnswer(x1, ROOT_1);
    double x2 = NewtonMethod((ending_2 + beginning_2) / 2, FuncNewton);
    PrintAnswer(x2, ROOT_2);
    return 0;
}