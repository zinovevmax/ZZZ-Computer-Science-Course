#pragma once

#include <limits.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

typedef int32_t** Matrix;

Matrix MemoryAllocate(size_t* matrix_order) {
    Matrix matrix = (Matrix)malloc(sizeof(int32_t*) * *matrix_order);
    for (size_t i = 0; i < *matrix_order; ++i) {
        matrix[i] = (int32_t*)malloc(sizeof(int32_t) * *matrix_order);
    }
    return matrix;
}

void Swap(int32_t* a, int32_t* b) {
    *a = *a ^ *b;
    *b = *b ^ *a;
    *a = *a ^ *b;
}

Matrix Replace(Matrix matrix, size_t* matrix_order, size_t num_min_comp, size_t num_max_comp) {
    for (size_t i = 0; i < *matrix_order; ++i) {
        Swap(&matrix[num_min_comp][i], &matrix[num_max_comp][i]);
    }
    return matrix;
}

Matrix ReadMatrix(const char* file_name, size_t* matrix_order) {
    FILE* file = fopen(file_name, "r");
    fscanf(file, "%lu", matrix_order);
    Matrix matrix = MemoryAllocate(matrix_order);
    for (size_t i = 0; i < *matrix_order; ++i) {
        for (size_t j = 0; j < *matrix_order; ++j) {
            fscanf(file, "%d", &matrix[i][j]);
        }
    }
    fclose(file);
    return matrix;
}
void PrintBeforeMatrix(Matrix matrix, size_t matrix_order) {
    printf("\n\nMatrix Before\n\n");
    for (size_t i = 0; i < matrix_order; ++i) {
        for (size_t j = 0; j < matrix_order; ++j) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
}
Matrix NewMatrix(Matrix matrix, size_t* matrix_order) {
    size_t max_num_min_composition = 0;
    size_t max_num_max_composition = 0;
    int32_t max = INT_MIN;
    int32_t min = INT_MAX;
    if (*matrix_order == 1) {
        printf("\n Not availible");
        return matrix;
    }
    for (size_t i = 0; i < *matrix_order; ++i) {
        int32_t string_composition = 1;
        for (size_t j = 0; j < *matrix_order; ++j) {
            string_composition *= matrix[i][j];
        }
        if (string_composition >= max) {
            max = string_composition;
            max_num_max_composition = i;
        }
        if (string_composition <= min) {
            min = string_composition;
            max_num_min_composition = i;
        }
    }
    Replace(matrix, matrix_order, max_num_min_composition, max_num_max_composition);
    return matrix;
}
void PrintAfterMatrix(Matrix matrix, size_t matrix_order) {
    printf("\n\nMatrix After\n\n");
    for (size_t i = 0; i < matrix_order; ++i) {
        for (size_t j = 0; j < matrix_order; ++j) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
}
Matrix CleanerMemory(Matrix matrix, size_t matrix_order) {
    for (size_t i = 0; i < matrix_order; ++i) {
        free(matrix[i]);
    }
    free(matrix);
    matrix = NULL;
    return matrix;
}

int Task() {
    const char* file_name = "matr.txt";
    size_t matrix_order = 0;
    Matrix matrix = ReadMatrix(file_name, &matrix_order);
    PrintBeforeMatrix(matrix, matrix_order);
    NewMatrix(matrix, &matrix_order);
    PrintAfterMatrix(matrix, matrix_order);
    CleanerMemory(matrix, matrix_order);
    return 0;
}