#pragma once

#include <float.h>
#include <math.h>
#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>

#define db double

const double COMPARISON_VALUE_1 = 0.5629;
const double COMPARISON_VALUE_2 = 3.23;

double CalculatingDerivatie(double x) {
    return 3 - (4 / x);
}

double Func1(double x) {
    return acos(x) - sqrt(1 - 0.3 * pow(x, 3));
}

double Func2(double x) {
    return 3 * x - 4 * log(x) - 5;
}

double NewtonMethod(double x0, double x1, double (*func)(double)) {
    double xn0 = (x0 + x1) / 2.0;
    double xn1 = xn0 - func(xn0) / CalculatingDerivatie(xn0);
    while (fabs((xn1 - xn0) / (1.0 - ((xn1 - xn0) / (xn1 - xn0)))) >= DBL_EPSILON) {
        xn0 = xn1;
        xn1 = xn0 - func(xn0) / CalculatingDerivatie(xn0);
    }
    return xn1;
}

double IterativeMethod(double x0, double x1, double (*func)(double)) {
    double x = (x0 + x1) / 2.0;
    double prev_x = x0;
    while (fabs((func(x) - x) / (1 - ((func(x) - x) / (x - prev_x)))) >= DBL_EPSILON) {
        prev_x = x;
        x = func(x) + x;
    }
    return func(x) + x;
}

void SolveEquation(db x0, db x1, db (*func)(db), db (*method)(db, db, db (*)(db)), uint8_t precision, const db ex_val) {
    printf("Найденный корень:%.*f Значение для сравнения:%g\n", precision, method(x0, x1, func), ex_val);
}

int Task() {
    double start_segment_1 = 0.0;
    double end_segment_1 = 1.0;
    double start_segmetn_2 = 2.0;
    double end_segment_2 = 4.0;
    SolveEquation(start_segment_1, end_segment_1, Func1, IterativeMethod, 10, COMPARISON_VALUE_1);
    SolveEquation(start_segmetn_2, end_segment_2, Func2, NewtonMethod, 10, COMPARISON_VALUE_2);
    return 0;
}
