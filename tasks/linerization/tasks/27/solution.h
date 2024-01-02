#pragma once

#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

typedef int32_t** Matrix;
typedef int32_t* Array;

const int32_t M = 4;
const int32_t N = 4;

Matrix InputMatrix(int32_t m, int32_t n) {
    int32_t** input_matrix = (int32_t**)malloc(sizeof(int32_t*) * m);
    for (int32_t i = 0; i < m; ++i) {
        input_matrix[i] = (int32_t*)malloc(sizeof(int32_t) * n);
    }
    return input_matrix;
}

Matrix CreateMatrix(Matrix input_matrix, int32_t m, int32_t n) {
    int32_t a = 1;
    for (int32_t i = 0; i < m; ++i) {
        for (int32_t j = 0; j < n; ++j) {
            input_matrix[i][j] = a;
            ++a;
        }
    }
    return input_matrix;
}

Array ResultMatrix(int size) {
    Array result = (int32_t*)malloc(sizeof(int32_t) * size);
    return result;
}

Array IteratingOverMatrix(int32_t lines, int32_t collumns, Matrix input_matrix, Array result) {
    int32_t index = 0;
    int32_t steps = (lines * 2) - 1;  // кол-во поворотов
    int32_t direction = 0;
    while (steps > 0) {
        if (direction == 0) {  // движение вниз
            for (int32_t line = (M - lines); line < lines; ++line) {
                *(result + index) = input_matrix[line][collumns - 1];
                ++index;
            }
            --collumns;
            --steps;
            ++direction;

        } else if (direction == 1) {  //движение влево
            for (int32_t collumn = (collumns - 1); collumn >= (M - collumns - 1); --collumn) {
                *(result + index) = input_matrix[lines - 1][collumn];
                ++index;
            }
            --lines;
            --steps;
            ++direction;

        } else if (direction == 2) {  //движение вверх
            for (int32_t line = (lines - 1); line >= (N - lines - 1); --line) {
                *(result + index) = input_matrix[line][(N - 1) - collumns];
                ++index;
            }
            --steps;
            ++direction;

        } else if (direction == 3) {  //движение вправо
            for (int32_t collumn = (M - collumns); collumn < collumns; ++collumn) {
                *(result + index) = input_matrix[(M - 1) - lines][collumn];
                ++index;
            }
            --steps;
            direction = 0;
        }
    }
    return result;
}

void PrintInputMatrix(int32_t m, int32_t n, Matrix input_matrix) {
    for (int32_t i = 0; i < m; ++i) {
        for (int32_t j = 0; j < n; ++j) {
            printf("%d ", input_matrix[i][j]);
        }
        printf("\n");
    }
}

void PrintResult(int32_t size, Array result) {
    for (int32_t i = 0; i < size; ++i) {
        printf("%d ", result[i]);
    }
    printf("\n");
}

int Task() {
    // write your solution here
    Matrix input_matrix = InputMatrix(M, N);
    input_matrix = CreateMatrix(input_matrix, M, N);
    Array result = ResultMatrix(N * M);
    result = IteratingOverMatrix(M, N, input_matrix, result);
    printf("Input matrix\n");
    PrintInputMatrix(M, N, input_matrix);
    printf("------------------\n");
    printf("The result of running through the matrix\n");
    PrintResult(M * N, result);
    free(result);
    return 0;
}