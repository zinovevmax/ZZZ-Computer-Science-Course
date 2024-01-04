#pragma once

#include <float.h>
#include <math.h>
#include <stdint.h>
#include <stdio.h>

const int32_t MAX_ITERATIONS = 100;
const int64_t K = 6669;
const double A = 0.1;
const long double B = 0.6;
const int N = 10;
const int NUMBER_OF_DASHES = 72;

long double TylorCounting(long double x, int *counter_of_iterations) {
    long double tylor_result = 0.0;
    long double power = 1;
    int n = -3;
    long double tylor_member = 0;
    for (int i = 0; i < MAX_ITERATIONS; ++i) {
        *counter_of_iterations += 1;
        tylor_member = n * power;
        tylor_result += tylor_member;
        if (fabsl((long double)((2 * x - 3) / pow((x - 1), 2)) - tylor_result) < K * LDBL_EPSILON) {
            printf("%.25Lf %.25Lf", K * LDBL_EPSILON, LDBL_EPSILON);
            return tylor_result;
        }
        power *= x;
        n -= 1;
    }

    return 1.0;
}

void Output(long double tylor, long double func, int counter, long double x) {
    printf("|  %.2Lf  | %.20Lf | %.20Lf |     %d     |\n", x, tylor, func, counter);
}

void PrintDashs(int n) {
    for (int i = 0; i < n; ++i) {
        printf("~");
    }
    printf("\n");
}

int Task() {
    // write your solution here
    long double step = (B - A) / N;
    long double tylor_result = 0.0;
    int counter_of_iterations = 0;
    printf("| Number |          Tylor         |          Real          | Iteration |\n");
    PrintDashs(NUMBER_OF_DASHES);
    for (long double x = A; x <= B + step; x += step) {
        counter_of_iterations = 0;
        tylor_result = TylorCounting(x, &counter_of_iterations);
        Output(tylor_result, (2 * x - 3) / pow(x - 1, 2), counter_of_iterations, x);
    }
    return 0;
}
