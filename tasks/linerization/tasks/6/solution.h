#pragma once

#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

const int32_t ROWS = 4;
const int32_t COLS = 4;

void AllocateMarix(int32_t*** matrix) {
    *matrix = (int32_t**)malloc(ROWS * sizeof(int32_t*));
    for (int32_t i = 0; i < ROWS; i++) {
        (*matrix)[i] = (int32_t*)malloc(COLS * sizeof(int32_t));
    }
}

void FreeMatrix(int32_t** matrix) {
    for (int32_t i = 0; i < ROWS; i++) {
        free(matrix[i]);
    }
    free(matrix);
}

void InitializeMatrix(int32_t** matrix, int32_t rows, int32_t cols) {
    matrix[0][0] = 10;
    matrix[0][1] = 4;
    matrix[0][2] = 3;
    matrix[0][3] = 1;
    matrix[1][0] = 11;
    matrix[1][1] = 9;
    matrix[1][2] = 5;
    matrix[1][3] = 2;
    matrix[2][0] = 15;
    matrix[2][1] = 12;
    matrix[2][2] = 8;
    matrix[2][3] = 6;
    matrix[3][0] = 16;
    matrix[3][1] = 14;
    matrix[3][2] = 13;
    matrix[3][3] = 7;
}

void Lineralize(int32_t** matrix) {
    for (int32_t i = 0; i < ROWS + COLS - 1; i++) {
        int32_t row;
        int32_t col;
        if (i < COLS) {
            row = 0;
            col = COLS - 1 - i;
        } else {
            row = i - COLS + 1;
            col = 0;
        }

        int32_t diagonal[ROWS < COLS ? ROWS : COLS];
        int32_t diagonal_length = 0;
        while (row < ROWS && col < COLS) {
            diagonal[diagonal_length++] = matrix[row][col];
            row++;
            col++;
        }

        if (i % 2 != 0) {
            for (int32_t j = diagonal_length - 1; j >= 0; j--) {
                printf("%d ", diagonal[j]);
            }
        } else {
            for (int32_t j = 0; j < diagonal_length; j++) {
                printf("%d ", diagonal[j]);
            }
        }
    }
}

int Task() {
    int32_t** matrix;
    AllocateMatrix(&matrix);
    InitializeMatrix(matrix, ROWS, COLS);
    Lineralize(matrix);
    FreeMatrix(matrix);
    return 0;
}
