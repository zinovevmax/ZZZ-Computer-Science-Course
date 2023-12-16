#pragma once

#include <float.h>
#include <stdint.h>
#include <stdio.h>

float Func1(float x) {
    return x + sqrt(x) + pow(x, 1.0 / 3.0) - 2.5;
}

float Func2(float x) {
    return x - 1.0 / (3.0 + sin(3.6 * x));
}

float DichotomyMethod(float lower_bound, float upper_bound, float tolerance) {
    float root = 0.5 * (lower_bound + upper_bound);
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

float IterationMethod(float initial_guess, float tolerance) {
    float root = initial_guess;
    int max_iterations = 100000;
    for (int i = 0; i < max_iterations; i++) {
        float delta = Func2(root) / (1.0 - 1.0 / (3.0 + sin(3.6 * root)));
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
    float lower_bound = 0.4, upper_bound = 1.0, tolerance = 1e-6;
    float root1 = DichotomyMethod(lower_bound, upper_bound, tolerance);
    float root2 = IterationMethod((lower_bound + upper_bound) / 2.0, tolerance);
    printf("%f\n", root1);
    printf("%f\n", root2);
    return 0;
}
