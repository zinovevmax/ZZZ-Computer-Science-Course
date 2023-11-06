#pragma once

#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

typedef int32_t** Matrix;

const int32_t M = 4;
const int32_t N = 4;

Matrix MatrixCreate() {
    Matrix matrix = (int32_t**)malloc(4 * sizeof(int32_t*));
    for (int i = 0; i < 4; ++i) {
        matrix[i] = (int32_t*)malloc(4 * sizeof(int32_t));
    }
    return matrix;
}

Matrix MatrixFill(Matrix matrix) {
    for (int32_t i = 0; i < 4; ++i) {
        for (int32_t j = 0; j < 4; ++j) {
            scanf("%d", &matrix[i][j]);
        }
    }
    return matrix;
}

int Task() {
    // write your solution here
    int32_t a[16];
    Matrix matrix = MatrixCreate();
    matrix = MatrixFill(matrix);
    *(a) = matrix[M - 1][N - 1];
    *(a + 1) = matrix[M - 2][N - 1];
    *(a + 2) = matrix[M - 2][N - 2];
    *(a + 3) = matrix[M - 1][N - 2];
    *(a + 4) = matrix[M - 1][N - 3];
    *(a + 5) = matrix[M - 2][N - 3];
    *(a + 6) = matrix[M - 3][N - 3];
    *(a + 7) = matrix[M - 3][N - 2];
    *(a + 8) = matrix[M - 3][N - 1];
    *(a + 9) = matrix[M - 4][N - 1];
    *(a + 10) = matrix[M - 4][N - 2];
    *(a + 11) = matrix[M - 4][N - 3];
    *(a + 12) = matrix[M - 4][N - 4];
    *(a + 13) = matrix[M - 3][N - 4];
    *(a + 14) = matrix[M - 2][N - 4];
    *(a + 15) = matrix[M - 1][N - 4];
    for (int32_t i = 0; i < 16; ++i) {
        printf("%d ", a[i]);
    }
    printf("\n");
    for (size_t i = 0; i < 4; ++i) {
        free(matrix[i]);
    }
    free(matrix);
    return 0;
}