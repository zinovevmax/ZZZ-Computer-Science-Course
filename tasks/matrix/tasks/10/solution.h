#pragma once

#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

typedef int32_t** Matrix;

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

void ShiftColumnsGroup(Matrix matrix, int32_t n, int32_t group, int32_t shift) {
    shift %= n;

    for (int i = 0; i < n; i++) {
        int32_t temp = matrix[i][group];
        for (int j = group; j < group + shift; j++) {
            if (j + shift < n) {
                matrix[i][j] = matrix[i][j + shift];
            }
        }
        matrix[i][(group + shift) % n] = temp;
    }
}

void ShiftAllColumnsGroups(Matrix matrix, int32_t n, int32_t group_size, int32_t shift) {
    for (int32_t group = 0; group < n; group += group_size) {
        ShiftColumnsGroup(matrix, n, group, shift);
    }
}

void PrintMatrix(Matrix matrix, int32_t n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf("%d ", matrix[j][i]);
        }
        printf("\n");
    }
}

Matrix InitializeMatrixAndShift(const char* filename, int32_t* n) {
    int32_t matrix_shift = 3;  // можно поменять на подходящее значение
    if (matrix_shift < 0) {
        printf("Invalid input\n");
        abort();
    }
    FILE* file = fopen(filename, "r");
    fscanf(file, "%d", n);
    int32_t matrix_size = (*n) * (*n);
    if (matrix_shift > matrix_size) {
        matrix_shift = matrix_shift % matrix_size;
    }
    Matrix matrix = CreateMatrix(*n);
    int32_t* start_elements = (int32_t*)malloc((matrix_size - matrix_shift) * sizeof(int32_t));
    int32_t read_elements_matrix_counter = matrix_size;
    int32_t new_elements_count = 0;
    for (int i = 0; i < matrix_size - matrix_shift; ++i) {
        fscanf(file, "%d", &start_elements[i]);
    }
    for (int i = 0; i < *n; ++i) {
        for (int j = 0; j < *n; ++j) {
            if (read_elements_matrix_counter > matrix_size - matrix_shift) {
                fscanf(file, "%d", &matrix[i][j]);
            } else if (read_elements_matrix_counter <= matrix_size - matrix_shift) {
                matrix[i][j] = start_elements[new_elements_count];
                ++new_elements_count;
            }
            --read_elements_matrix_counter;
        }
    }
    fclose(file);
    free(start_elements);
    return matrix;
}

int Task() {
    int32_t n = 0;
    const char* filename = "../tasks/matrix/tasks/10/matrix.txt";
    Matrix matrix = InitializeMatrixAndShift(filename, &n);
    int32_t group_size = 1;  // можно поменять на подходящее значение
    int32_t shift = 3;       // можно поменять на подходящее значение
    ShiftAllColumnsGroups(matrix, n, group_size, shift);
    PrintMatrix(matrix, n);
    MatrixFree(matrix, n);
    return 0;
}
