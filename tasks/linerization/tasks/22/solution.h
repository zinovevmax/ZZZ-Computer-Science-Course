#pragma once

#include <stdio.h>
#include <stdlib.h>

typedef int32_t** Matrix;

Matrix CreateMatrix(int32_t lenght, int32_t hight) {
    Matrix matrix = (Matrix)malloc(lenght * sizeof(int32_t*));
    for (int32_t i = 0; i < lenght; ++i) {
        matrix[i] = (int32_t*)malloc(hight * sizeof(int32_t));
    }

    return matrix;
}

void MatrixFree(Matrix matrix, int32_t hight) {
    for (int32_t i = 0; i < hight; ++i) {
        free(matrix[i]);
    }
    free(matrix);
}

void MatrixInitiate(Matrix matrix) {
    matrix[0][0] = 1;
    matrix[0][1] = 12;
    matrix[0][2] = 11;
    matrix[0][3] = 10;
    matrix[1][0] = 2;
    matrix[1][1] = 13;
    matrix[1][2] = 16;
    matrix[1][3] = 9;
    matrix[2][0] = 3;
    matrix[2][1] = 14;
    matrix[2][2] = 15;
    matrix[2][3] = 8;
    matrix[3][0] = 4;
    matrix[3][1] = 5;
    matrix[3][2] = 6;
    matrix[3][3] = 7;
}

int32_t* LinealMatrix(int32_t** matrix, int32_t lenght, int32_t hight) {
    int32_t* lineal_matrix = (int32_t*)malloc(lenght * hight * sizeof(int32_t));
    int32_t top = 0;
    int32_t bottom = lenght - 1;
    int32_t left = 0;
    int32_t right = hight - 1;
    int32_t index_of_lineal = 0;
    int32_t direction = 0;

    while (top <= bottom && left <= right) {
        if (direction == 0) {
            for (int32_t i = left; i <= right; i++) {
                lineal_matrix[index_of_lineal] = matrix[i][top];
                ++index_of_lineal;
            }
            top++;
        } else if (direction == 1) {
            for (int32_t i = top; i <= bottom; i++) {
                lineal_matrix[index_of_lineal] = matrix[right][i];
                ++index_of_lineal;
            }
            right--;
        } else if (direction == 2) {
            for (int32_t i = right; i >= left; i--) {
                lineal_matrix[index_of_lineal] = matrix[i][bottom];
                ++index_of_lineal;
            }
            bottom--;
        } else if (direction == 3) {
            for (int32_t i = bottom; i >= top; i--) {
                lineal_matrix[index_of_lineal] = matrix[left][i];
                ++index_of_lineal;
            }
            left++;
        }
        direction = (direction + 1) % 4;
    }
    return lineal_matrix;
}

int Task() {
    int32_t lenght = 4;
    int32_t hight = 4;
    Matrix matrix = CreateMatrix(lenght, hight);
    MatrixInitiate(matrix);
    int32_t* lineal_matrix = LinealMatrix(matrix, lenght, hight);

    for (int32_t i = 0; i < hight; ++i) {
        for (int32_t j = 0; j < lenght; ++j) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
    for (int32_t i = 0; i < hight * lenght; ++i) {
        printf("%d ", lineal_matrix[i]);
    }

    free(lineal_matrix);
    MatrixFree(matrix, lenght);
    return 0;
}