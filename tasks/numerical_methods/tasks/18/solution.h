#pragma once

#define Ans_1 0.7376
#define Ans_2 0.2624
#include <float.h>
#include <math.h>
#include <stdint.h>
#include <stdio.h>

double Func1(double x) {
    return x + sqrt(x) + pow(x, 1.0 / 3.0) - 2.5;
}

double Func2(double x) {
    return x - 1.0 / (3.0 + sin(3.6 * x));
}

double DichotomyMethod(double lower_bound, double upper_bound, double tolerance) {
    double root = (lower_bound + upper_bound) / 2.0;
    while (fabs(Func1(root)) > tolerance && fabs(upper_bound - lower_bound) > tolerance) {
        if (Func1(lower_bound) * Func1(root) <= 0) {
            upper_bound = root;
        } else {
            lower_bound = root;
        }
        root = (lower_bound + upper_bound) / 2.0;
    }
    return root;
}

double IterationMethod(double initial_guess, double lower_bound, double upper_bound, double tolerance) {
    double root = initial_guess;
    while (fabs(Func2(root)) > tolerance) {
        root = root - Func2(root) / (1.0 - 1.0 / (3.0 + sin(3.6 * root)));
        if (root < lower_bound) {
            root = lower_bound;
        } else if (root > upper_bound) {
            root = upper_bound;
        }
    }
    return root;
}

int main() {
    double lower_bound_dichotomy = 0.4;
    double upper_bound_dichotomy = 1.0;
    double lower_bound_iteration = 0.0;
    double upper_bound_iteration = 0.85;
    double tolerance = DBL_EPSILON;
    double root1 = DichotomyMethod(lower_bound_dichotomy, upper_bound_dichotomy, tolerance);
    double root2 = IterationMethod((lower_bound_iteration + upper_bound_iteration) / 2.0, lower_bound_iteration, upper_bound_iteration, tolerance);
    printf("%f, %f\n", root1, Ans_1);
    printf("%f, %f\n", root2, Ans_2);
    return 0;
}
