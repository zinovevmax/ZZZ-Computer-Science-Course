#pragma once

#include <float.h>
#include <math.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>


const int MAX_ITERATIONS = 100;
const long long K = 277;
const long double A = 0.0;
const long double B = 0.5;
const int N = 10;
typedef long long ll;
typedef long double ld;

ld Tylor_counting(ld x, int* counter_of_iterations) {
    ld tylor_result = 0.0;
    ld power = x;
    int n = 1;
    ll factorial = 1;
    ld one_tylor_member = 0;
    for (int i = 0; i < MAX_ITERATIONS; ++i) {
        *counter_of_iterations += 1;
        one_tylor_member = (power / factorial);
        if (i % 2) {
            one_tylor_member *= -1;
        }
        tylor_result += one_tylor_member;
        if (fabsl((ld)sin(x) - tylor_result) < K * LDBL_EPSILON) {
            return tylor_result;
        }
        power *= (x * x);
        factorial *= (n + 1) * (n + 2);
        n += 2;
    }
    return 1.0;
}

void Output(ld tylor, double sinus, int counter, double x) {
    printf("|  %.2f  | %.20Lf | %.20f |     %d     |\n", x, tylor, sinus, counter);
}

void Print_dashs(int n) {
    for (int i = 0; i < n; ++i) {
        printf("~");
    }
    printf("\n");
}

int Task() {
    ld step = (B - A) / N;
    ld tylor_result = 0.0;
    int counter_of_iterations = 0;
    printf("| Number |          Tylor         |          Real          | Iteration |\n");
    Print_dashs(72);
    for (ld x = A; x <= B + step; x += step) {
        counter_of_iterations = 0;
        tylor_result = Tylor_counting(x, &counter_of_iterations);
        double sinus = sin(x);
        Output(tylor_result, sin(x), counter_of_iterations, x);
    }
    return 0;
}
