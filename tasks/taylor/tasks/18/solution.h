#pragma once

#include <float.h>
#include <math.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

#define BoundaryRowsTable printf("------------------------------------------------------------\n");
#define StringNamesTableElements printf("|  x  |       Taylor       |        Func        | Iteration|\n");

double Func(double x) {
    double function_value = ((1 + pow(x, 2)) / 2) * atan(x) - x / 2;
    return function_value;
}

double Taylor(double x, int32_t iterations) {
    double partial_sum_series = 0.0;
    for (int32_t i = 1; i <= iterations; ++i) {
        partial_sum_series += pow(-1, i + 1) * (pow(x, 2 * i + 1) / (4 * pow(i, 2) - 1));
    }
    return partial_sum_series;
}

void OutputTable(double start_segment, double end_segment, int32_t number_partitions, int32_t accuracy_factor) {
    BoundaryRowsTable;
    StringNamesTableElements;
    BoundaryRowsTable;
    double current_x = start_segment;
    for (int32_t i = 0; i <= number_partitions; ++i) {
        int32_t iteration = 1;
        while (iteration <= 100) {
            if (fabs(Taylor(current_x, iteration) - Func(current_x)) < DBL_EPSILON * accuracy_factor) {
                printf("|%.3lf| %.17lf| %.17lf| %9d|\n", current_x, Taylor(current_x, iteration), Func(current_x),
                       iteration);
                break;
            }
            ++iteration;
        }
        current_x += ((end_segment - start_segment) / number_partitions);
    }
    BoundaryRowsTable;
}

int Task() {
    FILE *file = nullptr;
    file = fopen("../tasks/taylor/tasks/18/example.txt", "r");
    double start_segment = 0.1;
    double end_segment = 0.6;
    int32_t number_partitions = 0;
    int32_t accuracy_factor = 0;
    // Если данные вводятся из консоли. Я буду брать из файла
    // printf("Enter the number you want to split the segment into\n");
    // scanf("%d", &number_partitions);
    // printf("Enter a number - the accuracy factor\n");
    // scanf("%d", &accuracy_factor);
    fscanf(file, "%d", &number_partitions);
    fscanf(file, "%d", &accuracy_factor);
    OutputTable(start_segment, end_segment, number_partitions, accuracy_factor);
    fclose(file);
    return 0;
}