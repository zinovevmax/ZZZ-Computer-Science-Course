#pragma once

#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

typedef int32_t** Matrix;

const int32_t SHIFT = 7;

Matrix CreateMatrix(int32_t n) {
    Matrix matrix = (Matrix)malloc(n * sizeof(int32_t*));
    for (int i = 0; i < n; i++) {
        matrix[i] = (int32_t*)malloc(n * sizeof(int32_t));
    }
    return matrix;
}

void MatrixFree(Matrix matrix, int32_t n) {
    for (int i = 0; i < n; i++) {
        free(matrix[i]);
    }
    free(matrix);
}
// Считываем матрицу и сразу начинаем решать задачу, считывая (n * n - SHIFT) элементы в массив, остальным элементами
// заполняя матрицу
Matrix InitializeMatrixAndShift(const char* filename, int32_t* n) {
    FILE* file = fopen(filename, "r");
    fscanf(file, "%d", n);
    int32_t matrix_size = *n * *n;
    Matrix matrix = CreateMatrix(*n);
    int32_t* start_elements = (int32_t*)malloc((matrix_size - SHIFT) * sizeof(int32_t));
    int32_t index_scanf_matrix = matrix_size;
    int32_t count_of_new_elements = 0;
    for (int i = 0; i < matrix_size - SHIFT; ++i) {
        fscanf(file, "%d", &start_elements[i]);
    }
    for (int i = 0; i < *n; ++i) {
        for (int j = 0; j < *n; ++j) {
            if (index_scanf_matrix > matrix_size - SHIFT) {
                fscanf(file, "%d", &matrix[i][j]);
            } else if (index_scanf_matrix <= matrix_size - SHIFT) {
                matrix[i][j] = start_elements[count_of_new_elements];
                ++count_of_new_elements;
            }
            --index_scanf_matrix;
        }
    }
    fclose(file);
    free(start_elements);
    return matrix;
}

int Task() {
    int32_t n = 0;
    const char* filename = "../tasks/matrix/tasks/9/matrix.txt";
    Matrix matrix = InitializeMatrixAndShift(filename, &n);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
    MatrixFree(matrix, n);
    return 0;
}