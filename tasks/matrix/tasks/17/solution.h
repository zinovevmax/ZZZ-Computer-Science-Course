#pragma once

#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

typedef int32_t** Matrix;

Matrix CreateMatrix(uint32_t size) {
    Matrix matrix = (int32_t **)malloc(sizeof(int32_t *) * size);
    for (uint32_t i = 0; i < size; ++i) {
        matrix[i] = (int32_t *)malloc(sizeof(int32_t) * size);
    }
    return matrix;
}

Matrix ReadMatrixFromFile(const char *file_name, uint32_t size) {
    FILE *file = fopen(file_name, "r");
    Matrix matrix = CreateMatrix(size);
    if (file != NULL) {
        for (uint32_t i = 0; i < size; ++i) {
            for (uint32_t j = 0; j < size; ++j) {
                fscanf(file, "%i", &matrix[i][j]);
            }
        }
        fclose(file);
    }
    return matrix;
}

int32_t MinElement(Matrix matrix, uint32_t size) {
    int32_t min_element = INT32_MAX;
    for (uint32_t i = 0; i < size; ++i) {
        for (uint32_t j = 0; j < size; ++j) {
            if (min_element > matrix[i][j]) {
                min_element = matrix[i][j];
            }
        }
    }
    return min_element;
}

int32_t MaxElement(Matrix matrix, uint32_t size) {
    int32_t max_element = INT32_MIN;
    for (uint32_t i = 0; i < size; ++i) {
        for (uint32_t j = 0; j < size; ++j) {
            if (max_element < matrix[i][j]) {
                max_element = matrix[i][j];
            }
        }
    }
    return max_element;
}

uint32_t FindMinCols(Matrix matrix, uint32_t size) {
    for (uint32_t i = 0; i < size; ++i) {
        for (uint32_t j = 0; j < size; ++j) {
            if (matrix[i][j] == MinElement(matrix, size)) {
                return i;
            }
        }
    }
    return 0;
}

uint32_t FindMaxRows(Matrix matrix, uint32_t size) {
    for (uint32_t i = 0; i < size; ++i) {
        for (uint32_t j = 0; j < size; ++j) {
            if (matrix[i][j] == MaxElement(matrix, size)) {
                return j;
            }
        }
    }
    return 0;
}

uint32_t Solution(Matrix matrix_old, uint32_t size) {
    uint32_t matrix_new = 0;
    uint32_t max_rows = FindMaxRows(matrix_old, size);
    uint32_t min_cols = FindMinCols(matrix_old, size);
    for (uint32_t i = 0; i < size; i++) {
        matrix_new += matrix_old[i][max_rows] * matrix_old[min_cols][i];
        printf("%d\n", matrix_old[i][max_rows] * matrix_old[min_cols][i]);
    }
    return matrix_new;
}

void PrintMatrix(Matrix matrix, uint32_t size) {
    for (uint32_t i = 0; i < size; ++i) {
        for (uint32_t j = 0; j < size; ++j) {
            printf("%i ", matrix[i][j]);
        }
        printf("\n");
    }
}

void ClearMemory(Matrix matrix, uint32_t size) {
    for (uint32_t i = 0; i < size; ++i) {
        free(matrix[i]);
    }
    free(matrix);
}

int Task() {
    // write your solution here
    uint32_t size = 3;  // for example
    const char *file_name = "..//test.txt";
    Matrix matrix_from_file = ReadMatrixFromFile(file_name, size);
    uint32_t matrix_new = Solution(matrix_from_file, size);
    printf("Matrix from file :\n");
    PrintMatrix(matrix_from_file, size);
    printf("Answer:\n");
    printf("%d", matrix_new);
    ClearMemory(matrix_from_file, size);
    return 0;
}
