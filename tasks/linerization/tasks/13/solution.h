#pragma once

#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

typedef int32_t** Matrix;

void InitializationMatrix(Matrix matrix) {
    matrix[0][0] = 1;
    matrix[0][1] = 2;
    matrix[0][2] = 3;
    matrix[0][3] = 4;
    matrix[1][0] = 5;
    matrix[1][1] = 6;
    matrix[1][2] = 7;
    matrix[1][3] = 8;
    matrix[2][0] = 9;
    matrix[2][1] = 10;
    matrix[2][2] = 11;
    matrix[2][3] = 12;
    matrix[3][0] = 13;
    matrix[3][1] = 14;
    matrix[3][2] = 15;
    matrix[3][3] = 16;
}

// ЛИНЕРИЗУЕМ МАТРИЦУ(ПЕРЕТАСУЕМ ЭЛ-ТЫ)
int32_t* LinerizationMatrix(Matrix matrix, int32_t* final_matrix, int32_t strings, int32_t columns) {
    int32_t i = 0;
    int32_t j = columns - 1;
    int32_t temp = 0;  // идет по финальному массиву;
    int32_t k11 = 0;
    int32_t k12 = 0;
    int32_t k21 = 0;
    int32_t k22 = 0;
    // k11, k12 - сохраняют позицию эл-та при проходе в верхней части, k21, k22 - в нижней части
    int32_t condition = -1;  // для прохода вверх - 1, вниз - 0, по диагонали - -1;
    // запишем главную диагональ:
    while (k11 != -1 && k21 != -1) {
        if (condition == -1) {
            while (strings - i - 1 >= 0 && j >= 0) {
                final_matrix[temp] = matrix[i][j];
                --j;
                ++i;
                ++temp;
            }
            condition = 1;
            // сохраним исходное положение
            k11 = i - 1;
            k21 = i - 1;
            k12 = j + 1;
            k22 = j + 1;
        }
        if (condition == 1) {
            // идем вверх поверху:
            i = k11;
            j = k12;
            if (j - 1 >= 0) {
                --j;
            } else {
                --i;
            }
            // цикл для прохода вверх по диагонале сверху
            while (i >= 0) {
                final_matrix[temp] = matrix[i][j];
                ++j;
                --i;
                ++temp;
            }
            k11 = i + 1;
            k12 = j - 2;
            // идем понизу:
            i = k21;
            j = k22;
            if (i + 1 < strings) {
                ++i;
            } else {
                ++j;
            }
            // цикл для прохода вверх по диагонале снизу
            while (columns > j) {
                final_matrix[temp] = matrix[i][j];
                ++j;
                --i;
                ++temp;
            }
            k21 = i + 2;
            k22 = j - 1;
            condition = 0;
        }
        // идем вниз
        if (condition == 0) {
            // понизу
            i = k21;
            j = k22;
            while (strings - i - 1 >= 0 && j >= 0) {
                final_matrix[temp] = matrix[i][j];
                --j;
                ++i;
                ++temp;
            }
            k21 = i - 1;
            k22 = j + 1;
            i = k11;
            j = k12;
            // поверху
            while (strings - i - 1 >= 0 && j >= 0) {
                final_matrix[temp] = matrix[i][j];
                --j;
                ++i;
                ++temp;
            }
            k11 = i - 1;
            k12 = j + 1;
            condition = 1;
        }
    }
    return final_matrix;
}

int Task() {
    int32_t strings = 4;
    int32_t columns = 4;
    Matrix matrix = (Matrix)malloc(sizeof(int32_t*) * strings * columns);
    int32_t* final_matrix = (int32_t*)malloc(sizeof(int32_t) * strings * columns);
    // выделим место под каждую строчку матрицы:
    for (int i = 0; i < strings; ++i) {
        matrix[i] = (int32_t*)malloc(sizeof(int32_t) * columns);
    }
    // записываем матрицу в двоичный массив
    InitializationMatrix(matrix);
    final_matrix = LinerizationMatrix(matrix, final_matrix, strings, columns);
    // Вывод изначальной матрицы
    for (int i = 0; i < strings; ++i) {
        for (int j = 0; j < columns; ++j) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
    // Вывод одномерного массива
    for (int i = 0; i < 16; i++) {
        printf("%d ", final_matrix[i]);
    }
    printf("\n");
    for (int k = 0; k < strings; ++k) {
        free(matrix[k]);
    }
    free(matrix);
    free(final_matrix);
    return 0;
}
