#pragma once

#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

typedef int32_t* Matrix;

int32_t const M = 4;
int32_t const N = 4;

Matrix ResultMatrix(int size) {
    Matrix result = (int32_t*)malloc(sizeof(int32_t) * size);
    return result;
}

Matrix IteratingOverMatrix(int32_t lines, int32_t collumns, int32_t input_matrix[M][N], Matrix result) {
    int32_t index = 1;
    int32_t steps = (lines * 2) - 1;            // кол-во поворотов
    *(result) = input_matrix[0][collumns - 1];  // закидываем первый элемент
    while (steps > 0) {
        if (steps % 4 == 3) {  // движение вниз
            for (int32_t line = 1; line < lines; ++line) {
                *(result + index) = input_matrix[line][collumns - 1];
                ++index;
            }
            --collumns;
            --steps;

        } else if (steps % 4 == 2) {  //движение влево
            for (int32_t collumn = (collumns - 1); collumn >= (M - collumns - 1); --collumn) {
                *(result + index) = input_matrix[lines - 1][collumn];
                ++index;
            }
            --lines;
            --steps;

        } else if (steps % 4 == 1) {  //движение вверх
            for (int32_t line = (lines - 1); line >= (N - lines - 1); --line) {
                *(result + index) = input_matrix[line][(N - 1) - collumns];
                ++index;
            }
            --steps;

        } else if (steps % 4 == 0) {  //движение вправо
            for (int32_t collumn = (M - collumns); collumn < collumns; ++collumn) {
                *(result + index) = input_matrix[(M - 1) - lines][collumn];
                ++index;
            }
            --steps;
        }
    }
    return result;
}

void PrintInputMatrix(int32_t m, int32_t n, int32_t input_matrix[M][N]) {
    for (int32_t i = 0; i < m; ++i) {
        for (int32_t j = 0; j < n; ++j) {
            printf("%d ", input_matrix[i][j]);
        }
        printf("\n");
    }
}

void PrintResult(int32_t size, Matrix result) {
    for (int32_t i = 0; i < size; ++i) {
        printf("%d ", result[i]);
    }
    printf("\n");
}

int Task() {
    // write your solution here
    int32_t input_matrix[4][4] = {{10, 11, 12, 1}, {9, 16, 13, 2}, {8, 15, 14, 3}, {7, 6, 5, 4}};
    Matrix result = ResultMatrix(N * M);
    result = IteratingOverMatrix(M, N, input_matrix, result);
    printf("Input matrix\n");
    PrintInputMatrix(M, N, input_matrix);
    printf("------------------\n");
    printf("The result of running through the matrix\n");
    PrintResult(M * N, result);
    free(result);
    return 0;
}