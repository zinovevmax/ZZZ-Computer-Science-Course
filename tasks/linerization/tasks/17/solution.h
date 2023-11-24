#pragma once

#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

typedef int32_t** Matrix;

Matrix CreateMatrix(const int32_t rows, const int32_t columns) {
    Matrix matrix = (Matrix)malloc(rows * sizeof(int32_t*));
    for (size_t i = 0; i < rows; ++i) {
        matrix[i] = (int32_t*)malloc(columns * sizeof(int32_t));
    }
    return matrix;
}

void FreeMatrix(Matrix matrix, const int32_t rows) {
    for (size_t i = 0; i < rows; ++i) {
        free(matrix[i]);
    }
    free(matrix);
}

void InitMatrix(Matrix matrix) {
    matrix[0][0] = 7;
    matrix[0][1] = 6;
    matrix[0][2] = 5;
    matrix[0][3] = 16;
    matrix[1][0] = 8;
    matrix[1][1] = 1;
    matrix[1][2] = 4;
    matrix[1][3] = 15;
    matrix[2][0] = 9;
    matrix[2][1] = 2;
    matrix[2][2] = 3;
    matrix[2][3] = 14;
    matrix[3][0] = 10;
    matrix[3][1] = 11;
    matrix[3][2] = 12;
    matrix[3][3] = 13;
}

void InitMatrixSimple(Matrix matrix, const int32_t rows, const int32_t columns) {
    for (size_t i = 0; i < rows; ++i) {
        for (size_t j = 0; j < columns; ++j) {
            matrix[i][j] = i * 4 + j;
        }
    }
}

int32_t* linearMatrix(int32_t** matrix, const int32_t rows, const int32_t columns) {
    // Рабоает только для квадратной матрицы четного порядка, т.к. начальная позиция выбирается специфично
    int32_t* linear_matrix = (int32_t*)malloc(rows * columns * sizeof(int32_t));
    int32_t linear_index = 0;
    const int32_t linear_size = rows * columns;
    // Cтартовая позиция 
    int32_t row = (rows / 2) - 1;
    int32_t column = (columns / 2) - 1;
    int32_t step_length = 0;
    int32_t step_border = 0;
    // d, r,  u, u, l, l,   d, d, d, r, r, r,  u, u, u, u, l, l, l, l ....
    while (linear_index < linear_size) {
        step_length += 1;
        // Вниз
        for (step_border = linear_index + step_length; ((linear_index < linear_size) && (linear_index < step_border)); ++linear_index) {
            linear_matrix[linear_index] = matrix[row][column];
            row += 1;
        }
        // Вправо
        for (step_border = linear_index + step_length; ((linear_index < linear_size) && (linear_index < step_border)); ++linear_index) {
            linear_matrix[linear_index] = matrix[row][column];
            column += 1;
        }
        step_length += 1;
        // Вверх
        for (step_border = linear_index + step_length; ((linear_index < linear_size) && (linear_index < step_border)); ++linear_index) {
            linear_matrix[linear_index] = matrix[row][column];
            row -= 1;
        }
        // Влево
        for (step_border = linear_index + step_length; ((linear_index < linear_size) && (linear_index < step_border)); ++linear_index) {
            linear_matrix[linear_index] = matrix[row][column];
            column -= 1;
        }
    }
    return linear_matrix;
}

int Task() {
    // Инициализация матрицы
    int32_t rows = 4;
    int32_t columns = 4;
    Matrix matrix = CreateMatrix(rows, columns);
    InitMatrix(matrix);
    // InitMatrixSimple(matrix, rows, columns);
    // Преобразование в линейную матрицу
    int32_t* linear_matrix = linearMatrix(matrix, rows, columns);
    // Вывод
    for (int i = 0; i < rows * columns; ++i) {
        printf("%d ", linear_matrix[i]);
    }
    printf("\n");
    // Освобождаем память
    free(linear_matrix);
    FreeMatrix(matrix, rows);
    return 0;
}