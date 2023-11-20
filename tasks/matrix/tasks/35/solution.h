#pragma once

#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

typedef int32_t** Matrix;

/* Чтение матрицы из файла, где первые два числа - строки и столбцы матрицы, остальные символы - эл-ты матрицы */

void MatrixReading(Matrix matrix, FILE* matrix_file, int32_t columns, int32_t strings) {
    for (int i = 0; i < strings; ++i) {
        matrix[i] = (int32_t*)malloc(sizeof(int32_t) * columns);
        for (int j = 0; j < columns; ++j) {
            fscanf(matrix_file, "%d", &matrix[i][j]);
        }
    }
}

/* Поворот матрицы на 90° против часовой */

void MatrixRotation(Matrix matrix_begin, Matrix matrix_end, int32_t strings, int32_t columns) {
    for (int i = 0; i < strings; ++i) {
        for (int j = 0; j < columns; ++j) {
            matrix_end[i][j] = matrix_begin[j][columns - 1 - i];
        }
    }
}

/* Освобождение памяти */
void FreeingUpMatrixMemory(Matrix matrix, int32_t strings) {
    for (int i = 0; i < strings; ++i) {
        free(matrix[i]);
    }
    free(matrix);
}

int Task() {
    FILE* matrix_file = nullptr;
    matrix_file = fopen("matrix.txt", "r");
    // if file open error
    if (matrix_file == NULL) {
        fprintf(stderr, "Не удалось выделить память\n");
        return 1;
    }
    // else
    int32_t columns = 0;
    int32_t strings = 0;
    fscanf(matrix_file, "%d%d", &strings, &columns);
    Matrix given_matrix = (Matrix)malloc(sizeof(int32_t*) * strings);
    if (given_matrix == NULL) {
        fprintf(stderr, "Не удалось выделить память\n");
        return 1;
    }
    MatrixReading(given_matrix, matrix_file, columns, strings);
    Matrix final_matrix = (Matrix)malloc(sizeof(int32_t*) * strings);
    if (final_matrix == NULL) {
        fprintf(stderr, "Не удалось выделить память\n");
        return 1;
    }
    for (int i = 0; i < strings; ++i) {
        final_matrix[i] = (int32_t*)malloc(sizeof(int32_t) * columns);
    }
    MatrixRotation(given_matrix, final_matrix, strings, columns);
    for (int i = 0; i < strings; ++i) {
        for (int j = 0; j < columns; ++j) {
            printf("%d ", final_matrix[i][j]);
        }
        printf("\n");
    }
    FreeingUpMatrixMemory(given_matrix, strings);
    FreeingUpMatrixMemory(final_matrix, strings);
    fclose(matrix_file);
    return 0;
}
