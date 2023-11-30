#pragma once

#include <float.h>
#include <math.h>
#include <stdint.h>
#include <stdio.h>

double Func(double x) {
    // write your function here
    double function = cosh(x);
    return function;
}

int64_t Factorial(int32_t x) {
    if (x == 0) {
        return 1;
    }
    return x * Factorial(x - 1);
}

double Taylor(double x, int32_t iterations) {
    double taylor_row_sum = 0.0;
    for (int32_t i = 0; i <= iterations; i += 2) {
        taylor_row_sum += pow(x, i) / (double)Factorial(i);
    }
    return taylor_row_sum;
}

void PrintComparison(double current_x, int32_t precision, int32_t iterations) {
    while (iterations <= 20) {  // 20 так как используется функция факториала
        if (fabs(Taylor(current_x, iterations) - Func(current_x)) < DBL_EPSILON * precision) {
            // 13 знаков после запятой, так как тогда видно различия у всех итераций
            printf(" %.2lf  |  %.13lf   |  %.13lf  |         %d        |\n", current_x, Taylor(current_x, iterations),
                   Func(current_x), iterations);
            break;
        }
        ++iterations;
    }
}

void PrintAnswer(double lower_edge, double upper_edge, int32_t number_of_divisions, int32_t precision) {
    printf("=====================================================================\n");
    printf("   x   |       Taylor       |       cosh        |      iteration    |\n");

    int32_t iterations = 0;
    double current_x = lower_edge;
    double step = (upper_edge - lower_edge) / number_of_divisions;

    for (int32_t i = 0; i <= number_of_divisions; ++i) {
        iterations = 0;
        PrintComparison(current_x, precision, iterations);
        current_x += step;
    }
}

int Task() {
    // write your solution here
    double lower_edge = 0.0;
    double upper_edge = 0.0;
    int32_t number_of_divisions = 0;
    int32_t precision = 0;
    FILE* file = fopen("../tasks/taylor/tasks/19/data.txt", "r");
    fscanf(file, "%d", &number_of_divisions);
    fscanf(file, "%lf", &lower_edge);
    fscanf(file, "%lf", &upper_edge);
    fscanf(file, "%d", &precision);
    fclose(file);
    printf("%lf %lf %d %d\n", lower_edge, upper_edge, number_of_divisions, precision);
    PrintAnswer(lower_edge, upper_edge, number_of_divisions, precision);
    return 0;
}