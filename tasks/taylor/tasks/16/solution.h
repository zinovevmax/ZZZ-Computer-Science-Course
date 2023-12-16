#pragma once

#include <stdio.h>
#include <stdbool.h>
#include <math.h>
#include <float.h>
#include <stdint.h>

long double calculateFunction(long double x) {
    return (1 + 2 * pow(x, 2)) * exp(pow(x, 2));
}

long double calculateSeriesTerm(int n, long double x) {
    long double numerator = 2 * n + 1;
    long double denominator = 1;
    
    for (int i = 1; i <= n; i++) {
        denominator *= i;
    }
    
    long double power = pow(x, 2 * n);
    long double term = numerator / denominator * power;
    
    return term;
}

bool shouldBreakCalculation(long double x, long double taylorResult, int precision) {
    long double epsilon = DBL_EPSILON * precision;
    long double diff = taylorResult - calculateFunction(x);
    
    if (diff < 0) {
        diff = -diff;
    }
    
    return diff < epsilon;
}

long double calculateTaylorResult(long double x, int iterations, int precision, int* numTaylorIterations) {
    *numTaylorIterations = 0;
    long double result = 0.0;
    
    for (int i = 0; i < iterations; ++i) {
        ++(*numTaylorIterations);
        result += calculateSeriesTerm(i, x);
        
        if (shouldBreakCalculation(x, result, precision)) {
            break;
        }
    }
    
    return result;
}

void printTableHeader() {
    printf(" ----------------------------------------------------\n");
    printf("|    x   |   Taylor Series |     Function    | Iters \n");
    printf("---------+-----------------+-----------------+-------\n");
}

void printTable(double x, double taylorResult, double functionResult, int numTaylorIterations) {
    printf("| %.4lf | %.13lf | %.13lf | %4d \n", x, taylorResult, functionResult, numTaylorIterations);
}

int Task() {
    int precision = 40;
    int numTaylorIterations = 0;
    const int n = 10;
    const int iterationsForTaylor = 100;
    const long double a = 0.0;
    const long double b = 1.0;
    
    long double step = (b - a) / n;
    long double x = a;
    
    long double taylorResult = 0.0;

    printTableHeader();

    for (int i = 0; i <= n; ++i) {
        taylorResult = calculateTaylorResult(x, iterationsForTaylor, precision, &numTaylorIterations);
        printTable(x, taylorResult, calculateFunction(x), numTaylorIterations);
        x += step;
    }
    
    return 0;
}
