#pragma once

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
    double root = 0.5 * (lower_bound + upper_bound);
    int max_iterations = 100000;
    for (int i = 0; i < max_iterations; i++) {
        if (Func1(root) == 0.0 || (upper_bound - lower_bound) <= tolerance) {
            break;
        }
        if (Func1(lower_bound) * Func1(root) <= 0) {
            upper_bound = root;
        } else {
            lower_bound = root;
        }
        root = 0.5 * (lower_bound + upper_bound);
    }
    return root;
}

double IterationMethod(double initial_guess, double tolerance) {
    double root = initial_guess;
    int max_iterations = 100000;
    for (int i = 0; i < max_iterations; i++) {
        double delta = Func2(root) / (1.0 - 1.0 / (3.0 + sin(3.6 * root)));
        root = root - delta;
        if (delta < 0) {
            delta = -delta;
        }
        if (delta <= tolerance) {
            break;
        }
    }
    return root;
}

int Task() {
    double lower_bound = 0.4;
    double upper_bound = 1.0;
    double tolerance = 1e-6;
    double root1 = DichotomyMethod(lower_bound, upper_bound, tolerance);
    double root2 = IterationMethod((lower_bound + upper_bound) / 2.0, tolerance);
    printf("%f\n", root1);
    printf("%f\n", root2);
    return 0;
}
