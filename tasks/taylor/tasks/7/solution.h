#pragma once

#include <float.h>
#include <math.h>
#include <stdint.h>
#include <stdio.h>

const double A = 0.0;
const double B = 0.5;
const int64_t MAX_ITERATIONS = 100;
const int64_t N = 10;
const double STEP = (B - A) / N;
const uint64_t K = 100000;

double Func(double x) {
    // write your function here
    return (x * (3 - x)) / pow((1 - x), 3);
}

int Task() {
    // write your solution here
    printf("                f(x) = x(3 - x) / (1 - x)^3\n");
    printf(" ----------------------------------------------------------------\n");
    printf("  x   |     Taylor series      |      Function          | Iters |\n");
    printf(" ----------------------------------------------------------------\n");
    double x = A;
    int iterations_count = 1;
    double sum_of_taylor = 0;
    while (x <= B) {
        while (iterations_count < MAX_ITERATIONS) {
            sum_of_taylor += (iterations_count * (iterations_count + 2)) * pow(x, iterations_count);
            if (fabsl(sum_of_taylor - Func(x)) >= DBL_EPSILON * K) {
                iterations_count += 1;
            } else {
                printf(" %0.2f | %20.20f |% 20.20f | %5d |\n", x, sum_of_taylor, Func(x), iterations_count);
                printf(" ----------------------------------------------------------------\n");
                iterations_count = 1;
                sum_of_taylor = 0;
                break;
            }
        }
        x += STEP;
    }
    return 0;
}
